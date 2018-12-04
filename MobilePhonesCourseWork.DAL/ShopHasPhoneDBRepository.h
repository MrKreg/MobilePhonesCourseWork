#pragma once
#include "ShopHasPhone.h"
#include "IShopHasPhoneRepository.h"

using namespace Entities;
using namespace System;
using namespace System::Data::SqlClient;

namespace Repositories 
{
	ref class ShopHasPhoneDBRepository : IShopHasPhoneRepository
	{
	public:
		ShopHasPhoneDBRepository(SqlConnection^ connection)
		{
			this->connection = connection;
		}

		~ShopHasPhoneDBRepository()
		{
		}

		bool InsertShopHasPhone(ShopHasPhone^ shopHasPhone) override
		{
			String^ query = "INSERT INTO dbo.shop_has_phone (phone_id, shop_id, price, shipping_cost, available) VALUES(@phone_id,@shop_id,@price,@shipping_cost,@available)";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@phone_id", shopHasPhone->GetPhoneId()));
			command->Parameters->Add(gcnew SqlParameter("@shop_id", shopHasPhone->GetShopId()));
			command->Parameters->Add(gcnew SqlParameter("@price", shopHasPhone->GetPrice()));
			command->Parameters->Add(gcnew SqlParameter("@sipping_cost", shopHasPhone->GetShippingCost()));
			command->Parameters->Add(gcnew SqlParameter("@available", shopHasPhone->GetAvailable()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool UpdateShopHasPhone(ShopHasPhone^ shopHasPhone) override
		{
			ShopHasPhone^ item = this->GetShopHasPhoneById(shopHasPhone->GetId());
			String^ query = "UPDATE dbo.shop_has_phone SET phone_id=@phone_id, shop_id=@shop_id, price=@price, shipping_cost=@shipping_cost, available=@available WHERE id=@id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", shopHasPhone->GetId()));
			command->Parameters->Add(gcnew SqlParameter("@shop_id", shopHasPhone->GetShopId()));
			command->Parameters->Add(gcnew SqlParameter("@price", shopHasPhone->GetPrice()));
			command->Parameters->Add(gcnew SqlParameter("@sipping_cost", shopHasPhone->GetShippingCost()));
			command->Parameters->Add(gcnew SqlParameter("@available", shopHasPhone->GetAvailable()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}		

		bool DeleteShopHasPhone(ShopHasPhone^ shopHasPhone) override
		{
			String^ query = "DELETE FROM dbo.shop_has_phone WHERE dbo.shop_has_phone.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", shopHasPhone->GetId()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		List<ShopHasPhone^>^ GetAllShopHasPhones() override
		{
			List<ShopHasPhone^>^ list = gcnew List<ShopHasPhone^>();
			String^ query = "SELECT shop_has_phone.*, phone.model, shop.name FROM shop_has_phone \
				INNER JOIN phone ON phone.id = phone_id \
				INNER JOIN shop ON shop.id = shop_id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew ShopHasPhone(reader->GetInt32(0), reader->GetInt32(1), reader->GetString(6), reader->GetInt32(2), reader->GetString(7), reader->GetInt32(3), reader->GetInt32(4), reader->GetInt32(5)));
			}
			reader->Close();
			return list;
		}

		List<ShopHasPhone^>^ GetShopHasPhonesByPhoneId(int phoneId) override
		{
			List<ShopHasPhone^>^ list = gcnew List<ShopHasPhone^>();
			String^ query = "SELECT shop_has_phone.*, phone.model, shop.name FROM shop_has_phone \
				INNER JOIN phone ON phone.id = phone_id \
				INNER JOIN shop ON shop.id = shop_id WHERE phone_id = @phoneId";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@phoneId", phoneId));
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew ShopHasPhone(reader->GetInt32(0), reader->GetInt32(1), reader->GetString(6), reader->GetInt32(2), reader->GetString(7), reader->GetInt32(3), reader->GetInt32(4), reader->GetInt32(5)));
			}
			reader->Close();
			return list;
		}

		ShopHasPhone^ GetShopHasPhoneById(int id) override
		{
			ShopHasPhone^ item = nullptr;
			String^ query = "SELECT * FROM dbo.shop_has_phone WHERE dbo.shop_has_phone.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", id));
			SqlDataReader^ reader = command->ExecuteReader();
			if (reader->Read())
			{
				item = gcnew ShopHasPhone(reader->GetInt32(0), reader->GetInt32(1), reader->GetString(6), reader->GetInt32(2), reader->GetString(7), reader->GetInt32(3), reader->GetInt32(4), reader->GetInt32(5));
			}
			reader->Close();
			return item;
		}

		String^ GetAvgPriceByPhoneId(int phone_id) override
		{
			String^ item = nullptr;
			String^ query = "SELECT CONCAT(MIN(price),' - ',MAX(price)) FROM shop_has_phone \
				GROUP BY phone_id \
				HAVING phone_id = @phone_id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@phone_id", phone_id));
			SqlDataReader^ reader = command->ExecuteReader();
			if (reader->Read())
			{
				item = reader->GetString(0);
			}
			else
			{
				item = "No info";
			}
			reader->Close();
			return item;
		}

	private:
		String^ CONNECTION_STRING = "Server=(localdb)\\mssqllocaldb;Database=mobile_phones;Trusted_Connection=True;";
		SqlConnection^ connection;
	};
}
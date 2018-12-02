#pragma once
#include "Shop.h"
#include "IShopRepository.h"

using namespace System;
using namespace Entities;
using namespace System::Data::SqlClient;

namespace Repositories
{
	ref class ShopDBRepository:IShopRepository
	{
	public:
		ShopDBRepository(SqlConnection^ connection)
		{
			this->connection = connection;
		}

		~ShopDBRepository()
		{
		}

		bool InsertShop(Shop^ shop) override
		{
			String^ query = "INSERT INTO dbo.shop (name, rating, website) VALUES(@name,@rating,@website)";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@name", shop->GetName()));
			command->Parameters->Add(gcnew SqlParameter("@rating", shop->GetRating()));
			command->Parameters->Add(gcnew SqlParameter("@website", shop->GetWebsite()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool UpdateShop(Shop^ shop) override
		{
			Shop^ item = this->GetShopById(shop->GetId());
			if (shop->GetName() == item->GetName() && shop->GetRating() == item->GetRating() && shop->GetWebsite() == item->GetWebsite())
			{
				return false;
			}
			String^ query = "UPDATE dbo.shop SET name=@name, rating=@rating, website=@website WHERE id=@id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", shop->GetId()));
			command->Parameters->Add(gcnew SqlParameter("@name", shop->GetName()));
			command->Parameters->Add(gcnew SqlParameter("@rating", shop->GetRating()));
			command->Parameters->Add(gcnew SqlParameter("@website", shop->GetWebsite()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool DeleteShop(Shop^ shop) override
		{
			String^ query = "DELETE FROM dbo.shop WHERE dbo.shop.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", shop->GetId()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		List<Shop^>^ GetAllShops() override
		{
			List<Shop^>^ list = gcnew List<Shop^>();
			String^ query = "SELECT * FROM dbo.shop";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew Shop(reader->GetInt32(0), reader->GetString(1), reader->GetDouble(2), reader->GetString(3)));
			}
			reader->Close();
			return list;
		}

		Shop^ GetShopById(int id) override
		{
			Shop^ item = nullptr;
			String^ query = "SELECT * FROM dbo.shop WHERE dbo.shop.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", id));
			SqlDataReader^ reader = command->ExecuteReader();
			if (reader->Read())
			{
				item = gcnew Shop(reader->GetInt32(0), reader->GetString(1), reader->GetDouble(2), reader->GetString(3));
			}
			reader->Close();
			return item;
		}

		List<Shop^>^ GetShopByName(String^ name) override
		{
			List<Shop^>^ list = gcnew List<Shop^>();
			String^ query = "SELECT * FROM dbo.shop WHERE name LIKE '%'@name'%'";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@name", name));
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew Shop(reader->GetInt32(0), reader->GetString(1), reader->GetDouble(2), reader->GetString(3)));
			}
			reader->Close();
			return list;
		}

	private:
		String^ CONNECTION_STRING = "Server=(localdb)\\mssqllocaldb;Database=mobile_phones;Trusted_Connection=True;";
		SqlConnection^ connection;
	};
}
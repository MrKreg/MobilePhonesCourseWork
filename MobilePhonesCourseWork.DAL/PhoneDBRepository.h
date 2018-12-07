#pragma once
#include "Phone.h"
#include "IPhoneRepository.h"
#include "Feature.h"

using namespace System;
using namespace Entities;
using namespace System::Data::SqlClient;

namespace Repositories {
	public ref class PhoneDBRepository:IPhoneRepository
	{
	public:
		PhoneDBRepository(SqlConnection^ connection)
		{
			this->connection = connection;
		}

		~PhoneDBRepository()
		{
		}

		bool InsertPhone(Phone^ phone) override
		{
			String^ query = "INSERT INTO dbo.Phone (creator_id, model, processor_id, storage, RAM, resolution, screen_size, screen_type, os_id) VALUES(@creator_id, @model, @processor_id, @storage, @RAM, @resolution, @screen_size, @screen_type, os_id)";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@creator_id", phone->GetCreatorId()));
			command->Parameters->Add(gcnew SqlParameter("@model", phone->GetModel()));
			command->Parameters->Add(gcnew SqlParameter("@processor_id", phone->GetProcessorId()));
			command->Parameters->Add(gcnew SqlParameter("@storage", phone->GetStorage()));
			command->Parameters->Add(gcnew SqlParameter("@RAM", phone->GetRAM()));
			command->Parameters->Add(gcnew SqlParameter("@resolution", phone->GetResolution()));
			command->Parameters->Add(gcnew SqlParameter("@screen_size", phone->GetScreenSize()));
			command->Parameters->Add(gcnew SqlParameter("@screen_type", phone->GetScreenType()));
			command->Parameters->Add(gcnew SqlParameter("@os_is", phone->GetOsId()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool UpdatePhone(Phone^ phone) override
		{
			Phone^ item = this->GetPhoneById(phone->GetId());
			if (phone->GetCreatorId() == item->GetCreatorId() && phone->GetModel() == item->GetModel() && phone->GetProcessorId() == item->GetProcessorId() && phone->GetStorage() == item->GetStorage() && phone->GetRAM() == item->GetRAM() && phone->GetResolution() == item->GetResolution() && phone->GetScreenSize() == item->GetScreenSize() && phone->GetScreenType() == item->GetScreenType() && phone->GetOsId() == item->GetOsId())
			{
				return false;
			}
			String^ query = "UPDATE dbo.phone SET id=@id, creator_id=@creator_id, model=@model, processor_id=@processor_id, storage=@storage, RAM=@RAM, resolution=@resolution, screen_size=@screen_size, screen_type=@screen_type, os_id=@os_id WHERE id=@id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", phone->GetId()));
			command->Parameters->Add(gcnew SqlParameter("@creator_id", phone->GetCreatorId()));
			command->Parameters->Add(gcnew SqlParameter("@model", phone->GetModel()));
			command->Parameters->Add(gcnew SqlParameter("@processor_id", phone->GetProcessorId()));
			command->Parameters->Add(gcnew SqlParameter("@storage", phone->GetStorage()));
			command->Parameters->Add(gcnew SqlParameter("@RAM", phone->GetRAM()));
			command->Parameters->Add(gcnew SqlParameter("@resolution", phone->GetResolution()));
			command->Parameters->Add(gcnew SqlParameter("@screen_size", phone->GetScreenSize()));
			command->Parameters->Add(gcnew SqlParameter("@screen_type", phone->GetScreenType()));
			command->Parameters->Add(gcnew SqlParameter("@os_is", phone->GetOsId()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool DeletePhone(Phone^ phone) override
		{
			String^ query = "DELETE FROM dbo.phone WHERE dbo.phone.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", phone->GetId()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		List<Phone^>^ GetAllPhones() override
		{
			List<Phone^>^ list = gcnew List<Phone^>();
			String^ query = "SELECT phone.*, creator.name, processor.name, os.name FROM phone \
				INNER JOIN creator ON creator.id = creator_id \
				INNER JOIN processor ON processor.id = processor_id \
				INNER JOIN os ON os.id = os_id"; 
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew Phone(reader->GetInt32(0), reader->GetInt32(1), reader->GetString(10), reader->GetString(2), reader->GetInt32(3), reader->GetString(11), reader->GetInt32(4), reader->GetInt32(5), reader->GetString(6), reader->GetString(7), reader->GetString(8), reader->GetInt32(9), reader->GetString(12)));
			}
			reader->Close();
			return list;
		}

		Phone^ GetPhoneById(int id) override
		{
			Phone^ item = nullptr;
			String^ query = "SELECT phone.*, creator.name, processor.name, os.name FROM dbo.phone \
				INNER JOIN creator ON creator.id = creator_id \
				INNER JOIN processor ON processor.id = processor_id \
				INNER JOIN os ON os.id = os_id WHERE dbo.phone.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", id));
			SqlDataReader^ reader = command->ExecuteReader();
			if (reader->Read())
			{
				item = gcnew Phone(reader->GetInt32(0), reader->GetInt32(1), reader->GetString(10), reader->GetString(2), reader->GetInt32(3), reader->GetString(11), reader->GetInt32(4), reader->GetInt32(5), reader->GetString(6), reader->GetString(7), reader->GetString(8), reader->GetInt32(9), reader->GetString(12));
			}
			reader->Close();
			return item;
		}

		List<Phone^>^ GetPhoneByName(String^ name) override
		{
			List<Phone^>^ list = gcnew List<Phone^>();
			String^ query = "SELECT phone.*, creator.name, processor.name, os.name FROM dbo.phone \
				INNER JOIN creator ON creator.id = creator_id \
				INNER JOIN processor ON processor.id = processor_id \
				INNER JOIN os ON os.id = os_id \
				WHERE model LIKE '%'+@name+'%'";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@name", name));
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew Phone(reader->GetInt32(0), reader->GetInt32(1), reader->GetString(10), reader->GetString(2), reader->GetInt32(3), reader->GetString(11), reader->GetInt32(4), reader->GetInt32(5), reader->GetString(6), reader->GetString(7), reader->GetString(8), reader->GetInt32(9), reader->GetString(12)));
			}
			reader->Close();
			return list;
		}

		List<Phone^>^ GetPhoneByCreatorId(int creator_id)
		{
			List<Phone^>^ list = gcnew List<Phone^>();
			String^ query = "SELECT phone.*, creator.name, processor.name, os.name FROM phone \
				INNER JOIN creator ON creator.id = creator_id \
				INNER JOIN processor ON processor.id = processor_id \
				INNER JOIN os ON os.id = os_id WHERE creator_id = @creator";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@creator", creator_id));
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew Phone(reader->GetInt32(0), reader->GetInt32(1), reader->GetString(10), reader->GetString(2), reader->GetInt32(3), reader->GetString(11), reader->GetInt32(4), reader->GetInt32(5), reader->GetString(6), reader->GetString(7), reader->GetString(8), reader->GetInt32(9), reader->GetString(12)));
			}
			reader->Close();
			return list;
		}

	private:
		String^ CONNECTION_STRING = "Server=(localdb)\\mssqllocaldb;Database=mobile_phones;Trusted_Connection=True;";
		SqlConnection^ connection;
	};
}
#pragma once
#include "IOsRepository.h"
#include "OS.h"

using namespace Entities;
using namespace System;
using namespace System::Data::SqlClient;

namespace Repositories {
	ref class OsDBReopistory : public IOsRepository
	{
	public:
		OsDBReopistory(SqlConnection^ connection)
		{
			this->connection = connection;
		}

		~OsDBReopistory()
		{
		}

		bool InsertOs(OS^ os) override
		{
			String^ query = "INSERT INTO dbo.os (name, description, create_year) VALUES(@name,@description,@create_year)";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@name", os->GetName()));
			command->Parameters->Add(gcnew SqlParameter("@description", os->GetDescription()));
			command->Parameters->Add(gcnew SqlParameter("@create_year", os->GetCreateYear()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool UpdateOs(OS^ os) override
		{
			OS^ item = this->GetOsById(os->GetId());
			if (os->GetName() == item->GetName() && os->GetDescription() == item->GetDescription() && os->GetCreateYear() == item->GetCreateYear()) {
				return false;
			}
			String^ query = "UPDATE dbo.os SET name=@name, description=@description, create_year=@create_year WHERE id=@id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", os->GetId()));
			command->Parameters->Add(gcnew SqlParameter("@name", os->GetName()));
			command->Parameters->Add(gcnew SqlParameter("@description", os->GetDescription()));
			command->Parameters->Add(gcnew SqlParameter("@create_year", os->GetCreateYear()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool DeleteOs(OS^ os) override
		{
			String^ query = "DELETE FROM dbo.os WHERE dbo.os.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", os->GetId()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		List<OS^>^ GetAllOs() override
		{
			List<OS^>^ list = gcnew List<OS^>();
			String^ query = "SELECT * FROM dbo.os";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew OS(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetInt32(3)));
			}
			reader->Close();
			return list;
		}

		OS^ GetOsById(int id) override
		{
			OS^ item = nullptr;
			String^ query = "SELECT * FROM dbo.os WHERE dbo.os.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", id));
			SqlDataReader^ reader = command->ExecuteReader();
			if (reader->Read())
			{
				item = gcnew OS(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetInt32(3));
			}
			reader->Close();
			return item;
		}

		List<OS^>^ GetOsByName(String^ name) override
		{
			List<OS^>^ list = gcnew List<OS^>();
			String^ query = "SELECT * FROM dbo.os WHERE name LIKE '%'@name'%'";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@name", name));
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew OS(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetInt32(3)));
			}
			reader->Close();
			return list;
		}

	private:
		SqlConnection^ connection;
	};
}
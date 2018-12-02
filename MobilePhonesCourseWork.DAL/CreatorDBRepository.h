#pragma once
#include "Creator.h"
#include "ICreatorRepository.h"

using namespace System;
using namespace Entities;
using namespace System::Data::SqlClient;

namespace Repositories
{
	ref class CreatorDBRepository:ICreatorRepository
	{
	public:
		CreatorDBRepository(SqlConnection^ connection)
		{
			this->connection = connection;
		}

		~CreatorDBRepository()
		{
		}

		bool InsertCreator(Creator^ creator) override
		{
			String^ query = "INSERT INTO dbo.creator (name, email, owner, country) VALUES(@name,@email,@owner,@countr)";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@name", creator->GetName()));
			command->Parameters->Add(gcnew SqlParameter("@email", creator->GetEmail()));
			command->Parameters->Add(gcnew SqlParameter("@owner", creator->GetOwner()));
			command->Parameters->Add(gcnew SqlParameter("@country", creator->GetCountry()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool UpdateCreator(Creator^ creator) override
		{
			Creator^ item = this->GetCreatorById(creator->GetId());
			if (creator->GetName() == item->GetName() && creator->GetEmail() == item->GetEmail() && creator->GetOwner() == item->GetOwner() && creator->GetCountry() == item->GetCountry())
			{
				return false;
			}
			String^ query = "UPDATE dbo.creator SET name=@name, email=@email, owner=@owner, country=@country WHERE id=@id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", creator->GetId()));
			command->Parameters->Add(gcnew SqlParameter("@name", creator->GetName()));
			command->Parameters->Add(gcnew SqlParameter("@email", creator->GetEmail()));
			command->Parameters->Add(gcnew SqlParameter("@owner", creator->GetOwner()));
			command->Parameters->Add(gcnew SqlParameter("@country", creator->GetCountry()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool DeleteCreator(Creator^ creator) override
		{
			String^ query = "DELETE FROM dbo.creator WHERE dbo.creator.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", creator->GetId()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		List<Creator^>^ GetAllCreators() override
		{
			List<Creator^>^ list = gcnew List<Creator^>();
			String^ query = "SELECT * FROM dbo.creator";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew Creator(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetString(3), reader->GetString(4)));
			}
			reader->Close();
			return list;
		}

		Creator^ GetCreatorById(int id) override
		{
			Creator^ item = nullptr;
			String^ query = "SELECT * FROM dbo.creator WHERE dbo.creator.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", id));
			SqlDataReader^ reader = command->ExecuteReader();
			if (reader->Read())
			{
				item = gcnew Creator(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetString(3), reader->GetString(4));
			}
			reader->Close();
			return item;
		}

		List<Creator^>^ GetCreatorByName(String^ name) override
		{
			List<Creator^>^ list = gcnew List<Creator^>();
			String^ query = "SELECT * FROM dbo.creator WHERE name LIKE '%'@name'%'";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@name", name));
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew Creator(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetString(3), reader->GetString(4)));
			}
			reader->Close();
			return list;
		}

	private:
		String^ CONNECTION_STRING = "Server=(localdb)\\mssqllocaldb;Database=mobile_phones;Trusted_Connection=True;";
		SqlConnection^ connection;
	};
}
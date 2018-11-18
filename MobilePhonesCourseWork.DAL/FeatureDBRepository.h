#pragma once
#include "Feature.h"
#include "IFeatureRepository.h"

using namespace Entities;
using namespace System;
using namespace System::Data::SqlClient;

namespace Repositories
{
	ref class FeatureDBRepository:IFeatureRepository
	{
	public:
		FeatureDBRepository()
		{
			this->connection = gcnew SqlConnection(this->CONNECTION_STRING);
			this->connection->Open();
		}

		~FeatureDBRepository()
		{
			this->connection->Close();
		}

		bool InsertFeature(Feature^ feature) override
		{
			String^ query = "INSERT INTO dbo.features (name, usage) VALUES(@name,@usage)";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@name", feature->GetName()));
			command->Parameters->Add(gcnew SqlParameter("@usage", feature->GetUsage()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool UpdateFeature(Feature^ feature) override
		{
			Feature^ item = this->GetFeatureById(feature->GetId());
			if (feature->GetName() == item->GetName() && feature->GetUsage() == item->GetUsage())
			{
				return false;
			}
			String^ query = "UPDATE dbo.features SET name=@name, usage=@usage WHERE id=@id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", feature->GetId()));
			command->Parameters->Add(gcnew SqlParameter("@name", feature->GetName()));
			command->Parameters->Add(gcnew SqlParameter("@usage", feature->GetUsage()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool DeleteFeature(Feature^ feature) override
		{
			String^ query = "DELETE FROM dbo.features WHERE dbo.features.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", feature->GetId()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		List<Feature^>^ GetAllFeatures() override
		{
			List<Feature^>^ list = gcnew List<Feature^>();
			String^ query = "SELECT * FROM dbo.features";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew Feature(reader->GetInt32(0), reader->GetString(1), reader->GetString(2)));
			}
			reader->Close();
			return list;
		}

		Feature^ GetFeatureById(int id) override
		{
			Feature^ item = nullptr;
			String^ query = "SELECT * FROM dbo.features WHERE dbo.features.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", id));
			SqlDataReader^ reader = command->ExecuteReader();
			if (reader->Read())
			{
				item = gcnew Feature(reader->GetInt32(0), reader->GetString(1), reader->GetString(2));
			}
			reader->Close();
			return item;
		}

		List<Feature^>^ GetFeatureByName(String^ name) override
		{
			List<Feature^>^ list = gcnew List<Feature^>();
			String^ query = "SELECT * FROM dbo.features WHERE name LIKE '%'@name'%'";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@name", name));
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew Feature(reader->GetInt32(0), reader->GetString(1), reader->GetString(2)));
			}
			reader->Close();
			return list;
		}

	private:
		String^ CONNECTION_STRING = "Server=(localdb)\\mssqllocaldb;Database=mobile_phones;Trusted_Connection=True;";
		SqlConnection^ connection;
	};
}
#pragma once
#include "IProcessorRepository.h"
#include "Processor.h"

using namespace Entities;
using namespace System;
using namespace System::Data::SqlClient;

namespace Repositories {
	ref class ProcessorDBRepository:IProcessorRepository
	{
	public:
		ProcessorDBRepository()
		{
			this->connection = gcnew SqlConnection(this->CONNECTION_STRING);
			this->connection->Open();
		}

		~ProcessorDBRepository()
		{
			this->connection->Close();
		}

		bool InsertProcessor(Processor^ processor) override
		{
			String^ query = "INSERT INTO dbo.processor (name, frequency, count_of_cores, maker) VALUES(@name,@frequency,@count_of_cores,@maker)";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@name", processor->GetName()));
			command->Parameters->Add(gcnew SqlParameter("@frequency", processor->GetFrequency()));
			command->Parameters->Add(gcnew SqlParameter("@count_of_cores", processor->GetCountOfCores()));
			command->Parameters->Add(gcnew SqlParameter("@maker", processor->GetMaker()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool UpdateProcessor(Processor^ processor) override
		{
			Processor^ item = this->GetProcessorById(processor->GetId());
			if (processor->GetName() == item->GetName() && processor->GetFrequency() == item->GetFrequency() && processor->GetCountOfCores() == item->GetCountOfCores() && processor->GetMaker() == item->GetMaker())
			{
				return false;
			}
			String^ query = "UPDATE dbo.processor SET name=@name, frequency=@frequency, count_of_cores=@count_of_cores, maker=@maker WHERE id=@id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", processor->GetId()));
			command->Parameters->Add(gcnew SqlParameter("@name", processor->GetName()));
			command->Parameters->Add(gcnew SqlParameter("@frequency", processor->GetFrequency()));
			command->Parameters->Add(gcnew SqlParameter("@count_of_cores", processor->GetCountOfCores()));
			command->Parameters->Add(gcnew SqlParameter("@maker", processor->GetMaker()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool DeleteProcessor(Processor^ processor) override
		{
			String^ query = "DELETE FROM dbo.processor WHERE dbo.processor.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", processor->GetId()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		List<Processor^>^ GetAllProcessors() override
		{
			List<Processor^>^ list = gcnew List<Processor^>();
			String^ query = "SELECT * FROM dbo.processor";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew Processor(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetInt32(3), reader->GetString(4)));
			}
			reader->Close();
			return list;
		}

		Processor^ GetProcessorById(int id) override
		{
			Processor^ item = nullptr;
			String^ query = "SELECT * FROM dbo.processor WHERE dbo.processor.id = @id";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@id", id));
			SqlDataReader^ reader = command->ExecuteReader();
			if (reader->Read())
			{
				item = gcnew Processor(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetInt32(3), reader->GetString(4));
			}
			reader->Close();
			return item;
		}

		List<Processor^>^ GetProcessorByName(String^ name) override
		{
			List<Processor^>^ list = gcnew List<Processor^>();
			String^ query = "SELECT * FROM dbo.processor WHERE name LIKE '%'@name'%'";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@name", name));
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew Processor(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetInt32(3), reader->GetString(4)));
			}
			reader->Close();
			return list;
		}

	private:
		String^ CONNECTION_STRING = "Server=(localdb)\\mssqllocaldb;Database=mobile_phones;Trusted_Connection=True;";
		SqlConnection^ connection;
	};
}
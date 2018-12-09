#pragma once
#include "User.h"

using namespace Entities;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;

namespace Repositories {
	ref class UserDBRepository
	{
	public:
		UserDBRepository(SqlConnection^ connection)
		{
			this->connection = connection;
		}

		~UserDBRepository()
		{
		}

		bool InsertUser(User^ user)
		{
			String^ query = "INSERT INTO dbo.users (username, password) VALUES(@username, @password)";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@username", user->GetUsername()));
			command->Parameters->Add(gcnew SqlParameter("@password", user->GetEncodedPassword()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool UpdateUser(User^ user)
		{
			User^ item = this->GetUserByUsername(user->GetUsername());
			if (user->GetPassword() == item->GetPassword()) {
				return false;
			}
			String^ query = "UPDATE dbo.users SET password=@password WHERE username=@username";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@username", user->GetUsername()));
			command->Parameters->Add(gcnew SqlParameter("@password", user->GetEncodedPassword()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		bool DeleteUser(User^ user)
		{
			String^ query = "DELETE FROM dbo.users WHERE dbo.users.username = @username";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@username", user->GetUsername()));
			if (command->ExecuteNonQuery() == 0)
			{
				return false;
			}
			return true;
		}

		List<User^>^ GetAllUsers()
		{
			List<User^>^ list = gcnew List<User^>();
			String^ query = "SELECT * FROM dbo.users";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			SqlDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				list->Add(gcnew User(reader->GetString(0), reader->GetString(1)));
			}
			reader->Close();
			return list;
		}

		User^ GetUserByUsername(String^ username)
		{
			User^ item = nullptr;
			String^ query = "SELECT * FROM dbo.users WHERE dbo.users.username = @username";
			SqlCommand^ command = gcnew SqlCommand(query, connection);
			command->Parameters->Add(gcnew SqlParameter("@username", username));
			SqlDataReader^ reader = command->ExecuteReader();
			if (reader->Read())
			{
				item = gcnew User(reader->GetString(0), reader->GetString(1));
			}
			reader->Close();
			return item;
		}

	private:
		SqlConnection^ connection;
	};
}
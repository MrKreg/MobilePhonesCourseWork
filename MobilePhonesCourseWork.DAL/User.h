#pragma once

using namespace System;

namespace Entities {
	ref class User
	{
	private:
		String^ username;
		String^ password;

	public:
		User()
		{

		}

		User(String^ username, String^ password)
		{
			this->username = username;
			SetPassword(password);
		}

		String^ GetUsername()
		{
			return this->username;
		}

		String^ GetPassword()
		{
			return DecodeFrom64(this->password);
		}

		void SetUsername(String^ username)
		{
			this->username = username;
		}

		void SetPassword(String^ password)
		{
			this->password = EncodeTo64(password);
		}

		String^ EncodeTo64(String^ toEncode)
		{
			array<Byte>^ toEncodeBytes = System::Text::ASCIIEncoding::ASCII->GetBytes(toEncode);
			String^ returnValue = System::Convert::ToBase64String(toEncodeBytes);
			return returnValue;
		}

		String^ DecodeFrom64(String^ encodedData)
		{
			array<Byte>^ encodedDataAsBytes= System::Convert::FromBase64String(encodedData);
			String^ returnValue = System::Text::ASCIIEncoding::ASCII->GetString(encodedDataAsBytes);
			return returnValue;
		}
	};
}
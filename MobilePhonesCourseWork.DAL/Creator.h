#pragma once

using namespace System;

namespace Entities {
	ref class Creator
	{
	private:
		int id;
		String^ name;
		String^ email;
		String^ owner;
		String^ country;

	public:
		Creator()
		{
			
		}

		Creator(String^ name, String^ email, String^ owner, String^ country)
		{
			this->name = name;
			this->email = email;
			this->owner = owner;
			this->country;
		}

		Creator(int id, String^ name, String^ email, String^ owner, String^ country) :Creator(name, email, owner, country)
		{
			this->id = id;
		}

		int GetId()
		{
			return this->id;
		}

		String^ GetName()
		{
			return this->name = name;
		}

		String^ GetEmail()
		{
			return this->email;
		}

		String^ GetOwner()
		{
			return this->owner;
		}

		String^ GetCountry()
		{
			return this->country;
		}

		void SetId(int id)
		{
			this->id = id;
		}

		void SetName(String^ name)
		{
			this->name = name;
		}

		void SetEmail(String^ email)
		{
			this->email = email;
		}

		void SetOwner(String^ owner)
		{
			this->owner = owner;
		}

		void SetCountry(String^ country)
		{
			this->country = country;
		}
	};
}
#pragma once

using namespace System;

namespace Entities {
	ref class OS
	{
	private:
		int id;
		String^ name;
		String^ description;
		int create_year;

	public:
		OS() 
		{

		}

		OS(String^ name, String^ description, int create_year)
		{
			this->name = name;
			this->description = description;
			this->create_year = create_year;
		}

		OS(int id, String^ name, String^ description, int create_year) : OS(name, description, create_year)
		{
			this->id = id;
		}

		int GetId() 
		{
			return this->id;
		}

		String^ GetName()
		{
			return this->name;
		}

		String^ GetDescription()
		{
			return this->description;
		}

		int GetCreateYear()
		{
			return this->create_year;
		}

		void SetId(int id)
		{
			this->id = id;
		}

		void SetName(String^ name)
		{
			this->name = name;
		}

		void SetDescription(String^ description)
		{
			this->description = description;
		}

		void SetCreateYear(int create_year)
		{
			this->create_year = create_year;
		}
	};
}
#pragma once


using namespace System;

namespace Entities {
	ref class Feature
	{
	private:
		int id;
		String^ name;
		String^ usage;

	public:
		Feature()
		{

		}

		Feature(String^ name, String^ usage)
		{
			this->name = name;
			this->usage = usage;
		}

		Feature(int id, String^ name, String^ usage) :Feature(name, usage)
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

		String^ GetUsage()
		{
			return this->usage;
		}

		void SetId(int id)
		{
			this->id = id;
		}

		void SetName(String^ name)
		{
			this->name = name;
		}

		void SetUsage(String^ usage)
		{
			this->usage = usage;
		}

		String^ ToString() override
		{
			return this->GetName();
		}
	};
}
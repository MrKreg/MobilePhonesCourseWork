#pragma once


using namespace System;

namespace Entities {
	ref class Shop
	{
	private:
		int id;
		String^ name;
		double rating;
		String^ website;

	public:
		Shop()
		{

		}

		Shop(String^ name, double rating, String^ website)
		{
			this->name = name;
			this->rating = rating;
			this->website = website;
		}

		Shop(int id, String^ name, double rating, String^ website) :Shop(name, rating, website)
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

		double GetRating()
		{
			return this->rating;
		}

		String^ GetWebsite()
		{
			return this->website;
		}

		void SetId(int id)
		{
			this->id = id;
		}

		void SetName(String^ name)
		{
			this->name = name;
		}

		void SetRating(double rating)
		{
			this->rating = rating;
		}

		void SetWebsite(String^ website)
		{
			this->website = website;
		}

		String^ ToString() override
		{
			return GetName();
		}
	};
}
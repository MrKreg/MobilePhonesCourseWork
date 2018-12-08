#pragma once

using namespace System;

namespace Entities {
	ref class Processor
	{
	private:
		int id;
		String^ name;
		String^ frequency;
		int countOfCores;
		String^ maker;

	public:
		Processor()
		{

		}

		Processor(String^ name, String^ frequency, int countOfCores, String^ maker)
		{
			this->name = name;
			this->frequency = frequency;
			this->countOfCores = countOfCores;
			this->maker = maker;
		}

		Processor(int id, String^ name, String^ frequency, int countOfCores, String^ maker) :Processor(name, frequency, countOfCores, maker)
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

		String^ GetFrequency()
		{
			return this->frequency;
		}

		int GetCountOfCores()
		{
			return this->countOfCores;
		}

		String^ GetMaker()
		{
			return this->maker;
		}

		void SetId(int id)
		{
			this->id = id;
		}

		void SetName(String^ name)
		{
			this->name = name;
		}

		void SetFrequency(String^ frequency)
		{
			this->frequency = frequency;
		}

		void SetCountOfCores(int countOfCores)
		{
			this->countOfCores = countOfCores;
		}

		void SetMaker(String^ maker)
		{
			this->maker = maker;
		}

		String^ ToString() override
		{
			return this->name;
		}
	};
}
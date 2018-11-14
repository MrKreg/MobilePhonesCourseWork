#pragma once
#include "Creator.h";

using namespace System;
using namespace Entities;
using namespace System::Collections::Generic;

namespace Repositories {
	public ref class ICreatorRepository
	{
	public:
		virtual bool InsertCreator(Creator^ creator) = 0;
		virtual bool UpdateCreator(Creator^ creator) = 0;
		virtual bool DeleteCreator(Creator^ creator) = 0;
		virtual List<Creator^>^ GetAllCreators() = 0;
		virtual Creator^ GetCreatorById(int id) = 0;
		virtual List<Creator^>^ GetCreatorByName(String^ name) = 0;
		virtual List<Creator^>^ GetCreatorByCountry(String^ country) = 0;
	};
}
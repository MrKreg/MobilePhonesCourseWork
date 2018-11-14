#pragma once
#include "Phone.h"
#include "Creator.h"

using namespace System;
using namespace Entities;
using namespace System::Collections::Generic;

namespace Repositories {
	public ref class IPhoneRepository
	{
	public:
		virtual bool InsertPhone(Phone^ Phone) = 0;
		virtual bool UpdatePhone(Phone^ Phone) = 0;
		virtual bool DeletePhone(Phone^ Phone) = 0;
		virtual List<Phone^>^ GetAllPhones() = 0;
		virtual Phone^ GetPhoneById(int id) = 0;
		virtual List<Phone^>^ GetPhoneByName(String^ name) = 0;
	};
}
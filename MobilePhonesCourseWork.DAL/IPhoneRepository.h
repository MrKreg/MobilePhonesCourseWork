#pragma once
#include "Phone.h"

using namespace System;
using namespace Entities;
using namespace System::Collections::Generic;

namespace Repositories {
	public ref class IPhoneRepository
	{
	public:
		virtual bool InsertPhone(Phone^ phone) = 0;
		virtual bool UpdatePhone(Phone^ phone) = 0;
		virtual bool DeletePhone(Phone^ phone) = 0;
		virtual List<Phone^>^ GetAllPhones() = 0;
		virtual Phone^ GetPhoneById(int id) = 0;
		virtual List<Phone^>^ GetPhoneByModel(String^ model) = 0;
	};
}
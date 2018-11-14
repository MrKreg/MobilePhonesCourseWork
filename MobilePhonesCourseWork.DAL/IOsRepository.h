#pragma once
#include "OS.h"

using namespace System;
using namespace Enteties;
using namespace System::Collections::Generic;

namespace Repositories {
	public ref class IOsRepository
	{
	public:
		virtual bool InsertOs(OS^ os) = 0;
		virtual bool UpdateOs(OS^ os) = 0;
		virtual bool DeleteOs(OS^ os) = 0;
		virtual List<OS^>^ GetAllOs() = 0;
		virtual OS^ GetOsById(int id) = 0;
		virtual List<OS^>^ GetOsByName(String^ name) = 0;
	};
}
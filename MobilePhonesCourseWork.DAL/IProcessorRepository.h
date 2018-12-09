#pragma once
#include "Processor.h"

using namespace System;
using namespace Entities;
using namespace System::Collections::Generic;

namespace Repositories {
	public ref class IProcessorRepository
	{
	public:
		virtual bool InsertProcessor(Processor^ processor) = 0;
		virtual bool UpdateProcessor(Processor^ processor) = 0;
		virtual bool DeleteProcessor(Processor^ processor) = 0;
		virtual List<Processor^>^ GetAllProcessors() = 0;
		virtual Processor^ GetProcessorById(int id) = 0;
		virtual List<Processor^>^ GetProcessorByName(String^ name) = 0;
	};
}
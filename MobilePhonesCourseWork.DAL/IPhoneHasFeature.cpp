#pragma once
#include "PhoneHasFeature.h"

using namespace System;
using namespace Entities;
using namespace System::Collections::Generic;

namespace Repositories {
	public ref class IPhoneHasFeatureRepository
	{
	public:
		virtual bool InsertPhoneHasFeature(PhoneHasFeature^ phoneHasFeature) = 0;
		virtual bool UpdatePhoneHasFeature(PhoneHasFeature^ phoneHasFeature) = 0;
		virtual bool DeletePhoneHasFeature(PhoneHasFeature^ phoneHasFeature) = 0;
		virtual List<PhoneHasFeature^>^ GetAllPhoneHasFeatures() = 0;
		virtual PhoneHasFeature^ GetPhoneHasFeatureById(int id) = 0;
	};
}
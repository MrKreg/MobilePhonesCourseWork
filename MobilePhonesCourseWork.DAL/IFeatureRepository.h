#pragma once
#include "Feature.h"

using namespace System;
using namespace Entities;
using namespace System::Collections::Generic;

namespace Repositories {
	public ref class IFeatureRepository
	{
	public:
		virtual bool InsertFeature(Feature^ feature) = 0;
		virtual bool UpdateFeature(Feature^ feature) = 0;
		virtual bool DeleteFeature(Feature^ feature) = 0;
		virtual List<Feature^>^ GetAllFeatures() = 0;
		virtual Feature^ GetFeatureById(int id) = 0;
		virtual List<Feature^>^ GetFeatureByName(String^ name) = 0;
	};
}
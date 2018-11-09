#pragma once

using namespace System;

namespace Entities {
	ref class PhoneHasFeature
	{
	private:
		int id;
		int phoneId;
		int featureId;

	public:
		PhoneHasFeature()
		{

		}

		PhoneHasFeature(int phoneId, int featureId)
		{
			this->phoneId = phoneId;
			this->featureId = featureId;
		}

		PhoneHasFeature(int id, int phoneId, int featureId) :PhoneHasFeature(phoneId, featureId)
		{
			this->id = id;
		}

		int GetId()
		{
			return this->id;
		}

		int GetPhoneId()
		{
			return this->phoneId;
		}

		int GetFeatureId()
		{
			return this->featureId;
		}

		void SetId(int id)
		{
			this->id = id;
		}

		void SetPhoneId(int phoneId)
		{
			this->phoneId = phoneId;
		}

		void SetFeatureId(int featureId)
		{
			this->featureId = featureId;
		}
	};
}
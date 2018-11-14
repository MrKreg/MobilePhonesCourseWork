#pragma once
#include "ShopHasPhone.h"

using namespace System;
using namespace Entities;
using namespace System::Collections::Generic;

namespace Repositories {
	public ref class IShopHasPhoneRepository
	{
	public:
		virtual bool InsertShopHasPhone(ShopHasPhone^ ShopHasPhone) = 0;
		virtual bool UpdateShopHasPhone(ShopHasPhone^ ShopHasPhone) = 0;
		virtual bool DeleteShopHasPhone(ShopHasPhone^ ShopHasPhone) = 0;
		virtual List<ShopHasPhone^>^ GetAllShopHasPhones() = 0;
		virtual ShopHasPhone^ GetShopHasPhoneById(int id) = 0;
	};
}
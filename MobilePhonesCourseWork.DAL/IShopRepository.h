#pragma once
#include "Shop.h"

using namespace System;
using namespace Entities;
using namespace System::Collections::Generic;

namespace Repositories {
	public ref class IShopRepository
	{
	public:
		virtual bool InsertShop(Shop^ shop) = 0;
		virtual bool UpdateShop(Shop^ shop) = 0;
		virtual bool DeleteShop(Shop^ shop) = 0;
		virtual List<Shop^>^ GetAllShops() = 0;
		virtual Shop^ GetShopById(int id) = 0;
		virtual List<Shop^>^ GetShopByName(String^ name) = 0;
	};
}
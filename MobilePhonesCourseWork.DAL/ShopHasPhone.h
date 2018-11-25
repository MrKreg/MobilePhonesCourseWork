#pragma once

using namespace System;

namespace Entities {
	ref class ShopHasPhone
	{
	private:
		int id;
		int phoneId;
		String^ phoneName;
		int shopId;
		String^ shopName;
		int price;
		int shippingCost;
		int available;

	public:
		ShopHasPhone()
		{

		}

		ShopHasPhone(int phoneId, String^ phoneName, int shopId, String^ shopName, int price, int shippingCost, int available)
		{
			this->phoneId = phoneId;
			this->phoneName = phoneName;
			this->shopId = shopId;
			this->shopName = shopName;
			this->price = price;
			this->shippingCost = shippingCost;
			this->available = available;
		}

		ShopHasPhone(int id, int phoneId, String^ phoneName, int shopId, String^ shopName, int price, int shippingCost, int available) :ShopHasPhone(phoneId, phoneName, shopId, shopName, price, shippingCost, available)
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

		String^ GetPhoneName()
		{
			return this->phoneName;
		}

		int GetShopId()
		{
			return this->shopId;
		}

		String^ GetShopName()
		{
			return this->shopName;
		}

		int GetPrice()
		{
			return this->price;
		}

		int GetShippingCost()
		{
			return this->shippingCost;
		}

		int GetAvailable()
		{
			this->available;
		}

		void SetId(int id)
		{
			this->id = id;
		}

		void SetPhoneId(int phoneId)
		{
			this->phoneId = phoneId;
		}

		void SetPhoneName(String^ phoneName)
		{
			this->phoneName = phoneName;
		}

		void SetShopId(int shopId)
		{
			this->shopId = shopId;
		}

		void SetPhoneName(String^ phoneName)
		{
			this->phoneName = phoneName;
		}

		void SetPrice(int price)
		{
			this->price = price;
		}

		void SetShippingCost(int shippingCost)
		{
			this->shippingCost = shippingCost;
		}

		void SetAvailable(int available)
		{
			this->available = available;
		}
	};
}
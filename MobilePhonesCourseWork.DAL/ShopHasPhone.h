#pragma once

using namespace System;

namespace Entities {
	ref class ShopHasPhone
	{
	private:
		int id;
		int phoneId;
		int shopId;
		int price;
		int shippingCost;
		int available;

	public:
		ShopHasPhone()
		{

		}

		ShopHasPhone(int phoneId, int shopId, int price, int shippingCost, int available)
		{
			this->phoneId = phoneId;
			this->shopId = shopId;
			this->price = price;
			this->shippingCost = shippingCost;
			this->available = available;
		}

		ShopHasPhone(int id, int phoneId, int shopId, int price, int shippingCost, int available) :ShopHasPhone(phoneId, shopId, price, shippingCost, available)
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

		int GetShopId()
		{
			return this->shopId;
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

		void SetShopId(int shopId)
		{
			this->shopId = shopId;
		}

		void SetPrice(int Price)
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
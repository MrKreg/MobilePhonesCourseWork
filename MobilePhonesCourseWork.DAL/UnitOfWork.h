#pragma once
#include "OsDBRepository.h"
#include "CreatorDBRepository.h"
#include "FeatureDBRepository.h"
#include "PhoneDBRepository.h"
#include "ProcessorDBRepository.h"
#include "ShopDBRepository.h"
#include "ShopHasPhoneDBRepository.h"
#include "UserDBRepository.h"

using namespace System;
using namespace Repositories;
using namespace System::Data::SqlClient;

namespace Repositories
{
	ref class UnitOfWork
	{
	public:
		UnitOfWork()
		{
			this->connection = gcnew SqlConnection(this->CONNECTION_STRING);
			connection->Open();
		}

		~UnitOfWork()
		{
			connection->Close();
		}

		OsDBReopistory^ Os()
		{
			if (osRepository == nullptr)
			{
				osRepository = gcnew OsDBReopistory(this->connection);
			}
			return osRepository;
		}

		CreatorDBRepository^ Creator()
		{
			if (creatorRepository == nullptr)
			{
				creatorRepository = gcnew CreatorDBRepository(this->connection);
			}
			return creatorRepository;
		}

		FeatureDBRepository^ Feature()
		{
			if (featureRepository == nullptr)
			{
				featureRepository = gcnew FeatureDBRepository(this->connection);
			}
			return featureRepository;
		}

		PhoneDBRepository^ Phone()
		{
			if (phoneRepository == nullptr)
			{
				phoneRepository = gcnew PhoneDBRepository(this->connection);
			}
			return phoneRepository;
		}

		ProcessorDBRepository^ Processor()
		{
			if (processorRepository == nullptr)
			{
				processorRepository = gcnew ProcessorDBRepository(this->connection);
			}
			return processorRepository;
		}

		ShopDBRepository^ Shop()
		{
			if (shopRepository == nullptr)
			{
				shopRepository = gcnew ShopDBRepository(this->connection);
			}
			return shopRepository;
		}

		ShopHasPhoneDBRepository^ ShopHasPhone()
		{
			if (shopHasPhoneRepository == nullptr)
			{
				shopHasPhoneRepository = gcnew ShopHasPhoneDBRepository(this->connection);
			}
			return shopHasPhoneRepository;
		}

		UserDBRepository^ User()
		{
			if (userRepository == nullptr)
			{
				userRepository = gcnew UserDBRepository(this->connection);
			}
			return userRepository;
		}
	private:
		String^ CONNECTION_STRING = "Server=(localdb)\\mssqllocaldb;Database=mobile_phones;Trusted_Connection=True;";
		SqlConnection^ connection;
		OsDBReopistory^ osRepository = nullptr;
		CreatorDBRepository^ creatorRepository = nullptr;
		FeatureDBRepository^ featureRepository = nullptr;
		PhoneDBRepository^ phoneRepository = nullptr;
		ProcessorDBRepository^ processorRepository = nullptr;
		ShopDBRepository^ shopRepository = nullptr;
		ShopHasPhoneDBRepository^ shopHasPhoneRepository = nullptr;
		UserDBRepository^ userRepository = nullptr;
	};
}
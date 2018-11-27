#pragma once
#include "OsDBRepository.h"
#include "CreatorDBRepository.h"
#include "FeatureDBRepository.h"
#include "PhoneDBRepository.h"
#include "ProcessorDBRepository.h"
#include "ShopDBRepository.h"
#include "ShopHasPhoneDBRepository.h"

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
		}

		~UnitOfWork()
		{
		}

		OsDBReopistory^ Os()
		{
			if (osRepository == nullptr)
			{
				osRepository = gcnew OsDBReopistory(this->connection);
			}
			return osRepository;
		}

		FeatureDBRepository^ Feature()
		{
			if (featureRepository == nullptr)
			{
				featureRepository = gcnew FeatureDBRepository(this->connection);
			}
			return featureRepository;
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
	};
}
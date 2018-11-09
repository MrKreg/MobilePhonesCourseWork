#pragma once

using namespace System;

namespace Entities {
	ref class Phone
	{
	private:
		int id;
		int creatorId;
		String^ model;
		int processorId;
		int storage;
		int ram;
		String^ resolution;
		String^ screenSize;
		String^ screenType;
		int osId;

	public:
		Phone()
		{

		}

		Phone(int creatorId, String^ model, int processorId, int storage, int ram, String^ resolution, String^ screenSize, String^ screenType, int osId)
		{
			this->creatorId = creatorId;
			this->model = model;
			this->processorId = processorId;
			this->storage = storage;
			this->ram = ram;
			this->resolution = resolution;
			this->screenSize = screenSize;
			this->screenType = screenType;
			this->osId = osId;
		}

		Phone(int id, int creatorId, String^ model, int processorId, int storage, int ram, String^ resolution, String^ screenSize, String^ screenType, int osId) :Phone(creatorId, model, processorId, storage, ram, resolution, screenSize, screenType, osId)
		{
			this->id = id;
		}

		int GetId()
		{
			return this->id;
		}

		int GetCreatorId()
		{
			return this->creatorId;
		}

		String^ GetModel()
		{
			return this->model;
		}

		int GetProcessorId()
		{
			return this->processorId;
		}

		int GetStorage()
		{
			return this->storage;
		}

		int GetRAM()
		{
			return this->ram = ram;
		}

		String^ GetResolution()
		{
			return this->resolution = resolution;
		}

		String^ GetScreenSize()
		{
			return this->screenSize;
		}

		String^ GetScreenType()
		{
			return this->screenType;
		}

		int GetOsId()
		{
			return this->osId;
		}

		void SetId(int id)
		{
			this->id = id;
		}

		void SetCreatorId(int creatorId)
		{
			this->creatorId = creatorId;
		}

		void SetModel(String^ model)
		{
			this->model = model;
		}

		void SetProcessorId(int processorId)
		{
			this->processorId = processorId;
		}

		void SetStorage(int storage)
		{
			this->storage = storage;
		}

		void SetRAM(int ram)
		{
			this->ram = ram;
		}

		void SetResolution(String^ resolution)
		{
			this->resolution = resolution;
		}

		void SetScreenSize(String^ screenSize)
		{
			this->screenSize = screenSize;
		}

		void SetScreenType(String^ screenType)
		{
			this->screenType = screenType;
		}

		void SetOsId(int osId)
		{
			this->osId = osId;
		}
	};
}
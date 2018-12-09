#pragma once

using namespace System;

namespace Entities {
	ref class Phone
	{
	private:
		int id;
		int creatorId;
		String^ creatorName;
		String^ model;
		int processorId;
		String^ processorName;
		int storage;
		int ram;
		String^ resolution;
		String^ screenSize;
		String^ screenType;
		int osId;
		String^ osName;

	public:
		Phone()
		{

		}

		Phone(int creatorId, String^ creatorName, String^ model, int processorId, String^ processorName, int storage, int ram, String^ resolution, String^ screenSize, String^ screenType, int osId, String^ osName)
		{
			this->creatorId = creatorId;
			this->creatorName = creatorName;
			this->model = model;
			this->processorId = processorId;
			this->processorName = processorName;
			this->storage = storage;
			this->ram = ram;
			this->resolution = resolution;
			this->screenSize = screenSize;
			this->screenType = screenType;
			this->osId = osId;
			this->osName = osName;
		}

		Phone(int id, int creatorId, String^ creatorName, String^ model, int processorId, String^ processorName, int storage, int ram, String^ resolution, String^ screenSize, String^ screenType, int osId, String^ osName) :Phone(creatorId, creatorName, model, processorId, processorName, storage, ram, resolution, screenSize, screenType, osId, osName)
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

		String^ GetCreatorName()
		{
			return this->creatorName;
		}

		String^ GetModel()
		{
			return this->model;
		}

		int GetProcessorId()
		{
			return this->processorId;
		}

		String^ GetProcessorName()
		{
			return this->processorName;
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

		String^ GetOsName()
		{
			return this->osName;
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

		String^ ToString() override
		{
			return GetCreatorName() + " " + GetModel();
		}
	};
}
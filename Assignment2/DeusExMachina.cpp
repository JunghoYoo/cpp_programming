#include "DeusExMachina.h"

namespace assignment2
{
	// initial outer class for static member 
	DeusExMachina* DeusExMachina::mInstance = NULL;
	bool DeusExMachina::mbInstlanceExist = false;
	bool DeusExMachina::mbRenew = false;
	unsigned int DeusExMachina::mNumVehicle = 0;

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mbInstlanceExist == false)
		{
			static DeusExMachina deus;

			mInstance = &deus;
			mbInstlanceExist = true;
		}
		else
		{
			// clear
			mbRenew = true;
		}

		return mInstance;
	}

	void DeusExMachina::Travel() const
	{
		if (mbRenew == true)
			DeusExMachina::~DeusExMachina();

		if (mNumVehicle > 0)
		{
			for (unsigned int k = 0; k < mNumVehicle; k++)
			{
				mVehicle[k]->Travel();
			}
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mbRenew == true)
			DeusExMachina::~DeusExMachina();

		if (vehicle != NULL)
		{
			for (unsigned int i = 0; i < mNumVehicle; i++)
			{
				// Same person is already added
				if (this->mVehicle[i] == vehicle)
				{
					return false;
				}
			}

			if (mNumVehicle <= MAX_NUM_OF_VEHICLE1)
			{
				// clear position when add
				vehicle->mTravelStep = 0;
				vehicle->mTravelDistance = 0;

				mVehicle[mNumVehicle] = vehicle;
				mNumVehicle++;

				return true;
			}
			else //full
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (mbRenew == true)
			DeusExMachina::~DeusExMachina();

		if (i < mNumVehicle)
		{
			delete mVehicle[i];

			mNumVehicle--;
			for (unsigned int k = i; k < mNumVehicle; k++)
			{
				unsigned int m;
				m = k + 1;

				mVehicle[k] = mVehicle[m];
			}

			return true;
		}
		else
		{
			return false;
		}
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mbRenew == true)
			DeusExMachina::~DeusExMachina();

		unsigned int maxtraveldistance;
		Vehicle* maxtravelvehicle;

		if (mNumVehicle > 0)
		{
			maxtravelvehicle = mVehicle[0];
			maxtraveldistance = mVehicle[0]->GetTravelDistance();

			for (unsigned int k = 1; k < mNumVehicle; k++)
			{
				if (maxtraveldistance < mVehicle[k]->GetTravelDistance())
				{
					maxtraveldistance = mVehicle[k]->GetTravelDistance();
					maxtravelvehicle = mVehicle[k];
				}
			}

			return maxtravelvehicle;
		}
		else
		{
			// No vehicle
			return NULL;
		}
	}

	Vehicle* DeusExMachina::GetVehicle(unsigned int i) const
	{
		if (mbRenew == true)
			DeusExMachina::~DeusExMachina();

		if (i < mNumVehicle)
		{
			return mVehicle[i];
		}
		else
		{
			// No vehicle
			return NULL;
		}
	}

	DeusExMachina::DeusExMachina()
	{
		mNumVehicle = 0;
		for (unsigned int i = 0; i < 10; i++)
		{
			mVehicle[i] = NULL;
		}
	}

	DeusExMachina::~DeusExMachina()
	{
		if (mbInstlanceExist == true)
		{
			for (unsigned int i = 0; i < mNumVehicle; i++)
			{
				delete mVehicle[i];
			}

			mNumVehicle = 0;
			mbRenew = false;

			//mInstance = NULL;
			//mbInstlanceExist = false;
		}
	}
}
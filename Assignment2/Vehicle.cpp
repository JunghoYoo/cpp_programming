#include "Vehicle.h"
#include <cassert>

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
	{
		// Check limit 
		if (maxPassengersCount <= 100)
			mMaxPassengersCount = maxPassengersCount;
		else
			mMaxPassengersCount = 100;

		mNumPerson = 0;
		mTravelStep = 0;
		mTravelDistance = 0;

		mPerson = new const Person* [mMaxPassengersCount];
	}

	Vehicle::Vehicle(const Vehicle& other)
	{
		mMaxPassengersCount = other.mMaxPassengersCount;
		mNumPerson = other.mNumPerson;
		mTravelStep = other.mTravelStep;
		mTravelDistance = other.mTravelDistance;

		mPerson = new const Person * [mMaxPassengersCount];

		// deep copy
		if (mNumPerson <= mMaxPassengersCount)
		{
			if (mNumPerson > 0)
			{
				for (unsigned int i = 0; i < mNumPerson; i++)
				{
					mPerson[i] = new Person(*other.mPerson[i]);
				}
			}
		}
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mNumPerson; i++)
		{
			delete this->mPerson[i];
		}

		delete[] mPerson;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (person != NULL)
		{
			for (unsigned int i = 0; i < mNumPerson; i++)
			{
				// Same person is already added
				if (this->mPerson[i] == person)
				{
					return false;
				}
			}

			if (mNumPerson < mMaxPassengersCount)
			{
				mPerson[mNumPerson] = person;
				mNumPerson++;

				return true;
			}
			else // full
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i < mNumPerson)
		{
			delete mPerson[i];
			mNumPerson--;

			if (mNumPerson > 0)
			{
				for (unsigned int k = i; k < mNumPerson; k++)
				{
					unsigned int m;
					m = k + 1;

					mPerson[k] = mPerson[m];
				}
			}

			return true;
		}
		else 
		{
			return false;
		}
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mNumPerson;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i < mNumPerson)
		{
			return mPerson[i];
		}
		else
		{
			return NULL;
		}
	}

	unsigned int Vehicle::getTotalWeight() const
	{
		unsigned int totalweight;

		totalweight = 0;

		if (mNumPerson > 0)
		{
			for (unsigned int i = 0; i < mNumPerson; i++)
			{
				totalweight += mPerson[i]->GetWeight();
			}
		}

		return totalweight;
	}

	unsigned int Vehicle::GetTravelDistance() const
	{
		return mTravelDistance;
	}

	Vehicle& Vehicle::operator=(Vehicle& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		else
		{
			// delete previous
			for (unsigned int i = 0; i < mNumPerson; i++)
			{
				delete this->mPerson[i];
			}

			delete[] mPerson;

			// copy 
			mMaxPassengersCount = rhs.mMaxPassengersCount;
			mNumPerson = rhs.mNumPerson;
			mTravelStep = rhs.mTravelStep;
			mTravelDistance = rhs.mTravelDistance;

			mPerson = new const Person* [mMaxPassengersCount];

			// deep copy
			if (mNumPerson <= mMaxPassengersCount)
			{
				if (mNumPerson > 0)
				{
					for (unsigned int i = 0; i < mNumPerson; i++)
					{
						mPerson[i] = new Person(*rhs.mPerson[i]);
					}
				}
			}

			return *this;
		}
	}
}
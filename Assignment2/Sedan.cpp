#include "Sedan.h"
#include "Trailer.h"
#
namespace assignment2
{
	Sedan::Sedan() 
		: Vehicle(4)
	{
		mbHasTrailer = false;
		mTrailer = NULL;
	}

	Sedan::Sedan(const Sedan& other) 
		: Vehicle(4)
	{
		mMaxPassengersCount = 4;
		mNumPerson = other.mNumPerson;
		mTravelStep = other.mTravelStep;
		mTravelDistance = other.mTravelDistance;

		mbHasTrailer = other.mbHasTrailer;

		// deep copy
		if (mNumPerson <= mMaxPassengersCount)
		{
			if (mNumPerson > 0)
			{
				for (unsigned int i = 0; i < mNumPerson; i++)
				{
					Vehicle::mPerson[i] = new Person(*other.mPerson[i]);
				}
			}
		}
		
		// deep copy
		if (mbHasTrailer == true)
		{
			mTrailer = new Trailer(other.mTrailer->GetWeight());
		}
		else
		{
			mTrailer = NULL;
		}
	}

	Sedan::~Sedan()
	{
		if (mbHasTrailer == true)
		{
			delete mTrailer;
			mTrailer = NULL;

			mbHasTrailer = false;
		}
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int speed;
		unsigned int totalweight;

		totalweight = getTotalWeight();

		if (mbHasTrailer == true)
		{
			totalweight += mTrailer->GetWeight();
		}
		
		if (totalweight > 350)
		{
			speed = 300;
		}
		else if (totalweight > 260)
		{
			speed = 380;
		}
		else if (totalweight > 160)
		{
			speed = 400;
		}
		else if (totalweight > 80)
		{
			speed = 458;
		}
		else if (totalweight <= 80)
		{
			speed = 480;
		}

		return speed;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (trailer != NULL)
		{
			if (mbHasTrailer == false)
			{
				mbHasTrailer = true;

				// shallow copy
				mTrailer = trailer;

				// reset position
				mTravelStep = 0;
				mTravelDistance = 0;

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

	bool Sedan::RemoveTrailer()
	{
		if (mbHasTrailer == true)
		{
			mbHasTrailer = false;
			delete mTrailer;
			mTrailer = NULL;

			// reset position
			mTravelStep = 0;
			mTravelDistance = 0;

			return true;
		}
		else
		{
			return false;
		}
	}

	bool Sedan::Travel(void)
	{
		mTravelStep++;

		if (mbHasTrailer == true)
		{
			if (mTravelStep <= 5)
			{
				mTravelDistance += GetMaxSpeed();

				return true;
			}
			else if (mTravelStep >= 7)
			{
				mTravelStep = 0;
				return false;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (mTravelStep <= 5)
			{
				mTravelDistance += GetMaxSpeed();

				return true;
			}
			else if (mTravelStep >= 6)
			{
				mTravelStep = 0;
				return false;
			}
			else
			{
				return false;
			}
		}
	}

	Sedan& Sedan::operator=(Sedan& rhs)
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
			
			if (mbHasTrailer == true)
			{
				delete mTrailer;
				mTrailer = NULL;

				mbHasTrailer = false;
			}

			// copy
			mMaxPassengersCount = rhs.mMaxPassengersCount;
			mNumPerson = rhs.mNumPerson;
			mTravelStep = rhs.mTravelStep;
			mTravelDistance = rhs.mTravelDistance;

			mbHasTrailer = rhs.mbHasTrailer;

			mPerson = new const Person* [mMaxPassengersCount];

			// deep copy
			if (mNumPerson <= mMaxPassengersCount)
			{
				if (mNumPerson > 0)
				{
					for (unsigned int i = 0; i < mNumPerson; i++)
					{
						Vehicle::mPerson[i] = new Person(*rhs.mPerson[i]);
					}
				}
			}

			// deep copy
			if (mbHasTrailer == true)
			{
				mTrailer = new Trailer(rhs.mTrailer->GetWeight());
			}
			else
			{
				mTrailer = NULL;
			}

			return *this;
		}
	}
}
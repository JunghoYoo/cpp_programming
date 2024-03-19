#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount) 
		: Vehicle(maxPassengersCount)
	{
	}
	Boatplane::~Boatplane()
	{
	}
	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int flyspeed;
		unsigned int sailspeed;

		flyspeed = GetFlySpeed();
		sailspeed = GetSailSpeed();

		if (flyspeed > sailspeed)
		{
			return flyspeed;
		}
		else
		{
			return sailspeed;
		}
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		// 150 * e ^ ((-x + 500) / 300)
		unsigned int speed;
		unsigned int totalweight;

		totalweight = getTotalWeight();

		float pow;
		pow = (-1.0f * totalweight + 500.0f) / 300.0f;
		speed = static_cast<unsigned int>(150.0f * exp(pow) + 0.5f); // round 

		return speed;
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		// MAX((800 - 1.7x), 20)
		unsigned int speed;
		unsigned int totalweight;

		totalweight = getTotalWeight();

		if (totalweight > (780.0f / 1.7f))
		{
			speed = 20;
		}
		else
		{
			speed = static_cast<unsigned int>(800 - 1.7f * totalweight + 0.5f); // round
		}
		
		return speed;
	}
	bool Boatplane::Travel(void)
	{
		mTravelStep++;

		if (mTravelStep <= 1)
		{
			mTravelDistance += GetMaxSpeed();

			return true;
		}
		else if (mTravelStep >= 4)
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
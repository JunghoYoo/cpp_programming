#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat() 
		: Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}
	
	unsigned int UBoat::GetMaxSpeed() const
	{
		unsigned int divespeed;
		unsigned int sailspeed;

		divespeed = GetDiveSpeed();
		sailspeed = GetSailSpeed();

		if (divespeed > sailspeed)
			return divespeed;
		else
			return sailspeed;
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		unsigned int speed;
		unsigned int totalweight;

		totalweight = getTotalWeight();

		// MAX((550 - x/10), 200)
		float pow;
		pow = 550.0f - totalweight / 10.0f;
		speed = static_cast<unsigned int>(pow + 0.5f); // round + 0.5);
		if (speed < 200)
			speed = 200;

		return speed;
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		// 500 * log((x + 150)/150) + 30
		unsigned int speed;
		unsigned int totalweight;

		totalweight = getTotalWeight();

		float pow;
		pow = (totalweight + 150.0f) / 150.0f;
		speed = static_cast<unsigned int>(500 * log(pow) + 30);

		return speed;
	}
	bool UBoat::Travel(void)
	{
		mTravelStep++;

		if (mTravelStep <= 2)
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
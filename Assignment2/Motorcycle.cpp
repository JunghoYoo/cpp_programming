#include "Motorcycle.h"

#include <cmath>

namespace assignment2
{
	Motorcycle::Motorcycle() 
		: Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		// MAX((-(x/15)^3 + 2x + 400), 0)
		unsigned int speed;
		int speedsigned;
		unsigned int totalweight;
		unsigned int powterm;

		totalweight = getTotalWeight();
		powterm = static_cast<unsigned int>(pow(-1 * (totalweight / 15.0f), 3));
		speedsigned = static_cast<int>(powterm + 2 * totalweight + 400);
		if (speedsigned < 0)
			speed = 0;
		else
			speed = static_cast<unsigned int>(speedsigned);

		return speed;
	}

	bool Motorcycle::Travel(void)
	{
		mTravelStep++;

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
#include "Boat.h"

#include "Vehicle.h"
#include "DeusExMachina.h"
#include "Person.h"
#include "Airplane.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount) 
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		unsigned int maxPassengersCount;
		const Person* transferperson;

		maxPassengersCount = this->GetMaxPassengersCount() + plane.GetMaxPassengersCount();

		Boatplane bp(maxPassengersCount);

		// move passenger - airplane (shallow copy)
		for (unsigned int i = 0; i < plane.GetPassengersCount(); i++)
		{
			transferperson = plane.GetPassenger(i);
			bp.AddPassenger(transferperson);
		}
		// clear link
		plane.mNumPerson = 0;

		// move passenger - boat (shallow copy)
		for (unsigned int i = 0; i < this->GetPassengersCount(); i++)
		{
			transferperson = this->GetPassenger(i);
			bp.AddPassenger(transferperson);
		}
		// clear link
		this->mNumPerson = 0;

		return bp;
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	unsigned int Boat::GetSailSpeed() const
	{
		// MAX((800 - 10x), 20)
		unsigned int speed;
		unsigned int totalweight;

		totalweight = getTotalWeight();

		// avoid - into unsigned int speed
		if (totalweight >= 78)
		{
			speed = 20;
		}
		else
		{
			speed = (800 - 10 * totalweight);
		}

		return speed;
	}
	bool Boat::Travel(void)
	{
		mTravelStep++;

		if (mTravelStep <= 2)
		{
			mTravelDistance += GetMaxSpeed();

			return true;
		}
		else if (mTravelStep >= 3)
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
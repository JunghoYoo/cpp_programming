#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

#include "Vehicle.h"
#include "DeusExMachina.h"
#include "Person.h"

#include <cmath>

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount) 
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
		// parent's destructor is called
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		unsigned int maxPassengersCount;
		const Person* transferperson;

		maxPassengersCount = this->GetMaxPassengersCount() + boat.GetMaxPassengersCount();

		Boatplane bp(maxPassengersCount);

		// move passenger - airplane (shallow copy)
		for (unsigned int i = 0; i < this->GetPassengersCount(); i++)
		{
			transferperson = this->GetPassenger(i);
			bp.AddPassenger(transferperson);
		}
		// clear link
		this->mNumPerson = 0;

		// move passenger - boat (shallow copy)
		for (unsigned int i = 0; i < boat.GetPassengersCount(); i++)
		{
			transferperson = boat.GetPassenger(i);
			bp.AddPassenger(transferperson);
		}
		// clear link
		boat.mNumPerson = 0;

		return bp;
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int flyspeed;
		unsigned int drivespeed;

		flyspeed = GetFlySpeed();
		drivespeed = GetDriveSpeed();

		if (flyspeed > drivespeed)
			return flyspeed;
		else
			return drivespeed;
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		unsigned int speed;
		unsigned int totalweight;

		totalweight = getTotalWeight();

		// 200 * e^((-x + 800) / 500)
		float pow;
		pow = (-1.0f * totalweight + 800.0f) / 500.0f;
		speed = static_cast<unsigned int>(200.0f * exp(pow) + 0.5f);// round + 0.5

		return speed;
	}
	unsigned int Airplane::GetDriveSpeed() const
	{
		unsigned int speed;
		unsigned int totalweight;

		totalweight = getTotalWeight();

		// 4 * e^((-x + 400) / 70)
		float pow;
		pow = (-1.0f * totalweight + 400.0f) / 70.0f;
		speed = static_cast<unsigned int>(4.0f * exp(pow) + 0.5f); // round + 0.5

		return speed;
	}

	bool Airplane::Travel(void)
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
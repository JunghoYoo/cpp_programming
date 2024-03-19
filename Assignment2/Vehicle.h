#pragma once

#include "Person.h"

namespace assignment2
{
	class Person;

	class Vehicle
	{
		friend class DeusExMachina;
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(const Vehicle& other);
		virtual ~Vehicle();
				
		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;

		virtual bool Travel(void) = 0;
		unsigned GetTravelDistance() const;

		Vehicle& operator=(Vehicle& rhs);

	protected:

		unsigned int getTotalWeight() const;
		unsigned int mNumPerson;
		unsigned int mMaxPassengersCount;
		unsigned int mTravelStep;
		unsigned int mTravelDistance;

		const Person** mPerson;
	};
}
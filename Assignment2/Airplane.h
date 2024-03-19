#pragma once

#include "Vehicle.h"
#include "Boatplane.h"
#include "IFlyable.h"
#include "IDrivable.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
		friend class Boat;
	public:
		Airplane(unsigned int maxPassengersCount);
		virtual ~Airplane();

		virtual unsigned int GetMaxSpeed() const;

		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetDriveSpeed() const;

		Boatplane operator+(Boat& boat);

		bool Travel(void);
	};
}
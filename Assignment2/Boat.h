#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "ISailable.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
		friend class Airplane;
	public:
		Boat(unsigned int maxPassengersCount);
		virtual ~Boat();

		Boatplane operator+(Airplane& plane);

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetSailSpeed() const;
		bool Travel(void);
	};
}
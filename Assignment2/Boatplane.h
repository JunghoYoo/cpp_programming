#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public ISailable, public IFlyable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		virtual ~Boatplane();

		virtual unsigned int GetMaxSpeed() const;

		virtual unsigned int GetSailSpeed() const;
		virtual unsigned int GetFlySpeed() const;

		bool Travel(void);
	};
}
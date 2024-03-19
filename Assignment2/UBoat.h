#pragma once

#include "Vehicle.h"
#include "IDivable.h"
#include "ISailable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public ISailable, public IDivable
	{
	public:
		UBoat();
		virtual ~UBoat();

		virtual unsigned int GetMaxSpeed() const;

		virtual unsigned int GetSailSpeed() const;
		virtual unsigned int GetDiveSpeed() const;
		bool Travel(void);
	};
}
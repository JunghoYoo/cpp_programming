#include "Lawn.h"
#include <cassert>

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		unsigned int grassprice;
		double grasspricedouble;
		double grassunitprice;

		switch (grassType)
		{
		case BERMUDA:
			grassunitprice = 8;
			break;

		case BAHIA:
			grassunitprice = 5;
			break;

		case BENTGRASS:
			grassunitprice = 3;
			break;

		case PERENNIAL_RYEGRASS:
			grassunitprice = 2.5;
			break;

		case ST_AUGUSTINE:
			grassunitprice = 4.5;
			break;
			
		default:
			assert(0);// "CHECK GRASSS TYPE");
		}

		grasspricedouble = mArea * grassunitprice;
		grassprice = static_cast<unsigned int>(grasspricedouble);

		if (grasspricedouble > grassprice)
			grassprice++;

		return grassprice;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		unsigned int minSodRollsCountR;
		double minSodRollsCount;

		minSodRollsCount = mArea / 0.3;
		
		minSodRollsCountR = static_cast<unsigned int>(minSodRollsCount);
		
		if (minSodRollsCount > minSodRollsCountR)
			minSodRollsCountR++;

		return minSodRollsCountR;
	}
}
#include "EquilateralTriangleLawn.h"
#include <cassert>
#include <math.h>

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int x)
	{
		mX = x;
		mAreaDouble = static_cast<double>(mX) * static_cast<double>(mX) * sqrt(3.0) / 4.0 + 0.5;
		mArea = static_cast<unsigned int>(mAreaDouble);
	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return static_cast<unsigned int>(mArea) ;
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		unsigned int roundlength;

		roundlength = mX * 4 * 3;

		return roundlength;
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int fenceunitprice;
		unsigned int fenceprice;

		switch (fenceType)
		{
		case RED_CEDAR:
			fenceunitprice = 6;
			break;

		case SPRUCE:
			fenceunitprice = 7;
			break;

		default:
			assert(0);
		}

		fenceprice = fenceunitprice * (mX * 3);

		return fenceprice;
	}
}
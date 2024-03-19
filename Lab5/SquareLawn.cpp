#include "SquareLawn.h"
#include <cassert>

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int x) : RectangleLawn(x, x)
	{
		mX = x;
		mAreaDouble = static_cast<double>(mX) * static_cast<double>(mX);
		mArea = static_cast<unsigned int>(mAreaDouble);
	}

	SquareLawn::~SquareLawn()
	{
	}

	unsigned int SquareLawn::GetArea() const
	{
		return static_cast<unsigned int>(mArea);
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		unsigned int roundlength;

		roundlength = 2 * (mX * 4 * 2);

		return roundlength;
	}

	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
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

		fenceprice = fenceunitprice * 4 * mX;

		return fenceprice;
	}
}
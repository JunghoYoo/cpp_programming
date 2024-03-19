#include "RectangleLawn.h"
#include <cassert>

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int x, unsigned int y)
	{
		mX = x;
		mY = y;

		mAreaDouble = static_cast<double>(mX) * static_cast<double>(mY);
		mArea = static_cast<unsigned int>(mAreaDouble);
	}

	RectangleLawn::~RectangleLawn()
	{
	}

	unsigned int RectangleLawn::GetArea() const
	{
		return static_cast<unsigned int>(mArea);
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		unsigned int roundlength;
		
		roundlength = 2 * (mX * 4 + mY * 4);

		return roundlength;
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
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

		fenceprice = fenceunitprice * 2 * (mX + mY);

		return fenceprice;
	}
}
#include "CircleLawn.h"
#include <cassert>

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int x)
	{
		mX = x;
		mAreaDouble = static_cast<double>(mX) * static_cast<double>(mX) * 3.14 + 0.5;
		mArea = static_cast<unsigned int>(mAreaDouble);
	}

	CircleLawn::~CircleLawn()
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		unsigned int areaR;

		areaR = static_cast<unsigned int>(mArea);

		if (areaR < mArea)
			areaR++;

		return areaR;
	}
}
#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class EquilateralTriangleLawn : public IFenceable, public Lawn
	{
	public:
		EquilateralTriangleLawn(unsigned int x);
		virtual ~EquilateralTriangleLawn();
		virtual unsigned int GetArea() const;

		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mX;
	};
}


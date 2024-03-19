#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class RectangleLawn : public IFenceable, public  Lawn
	{
	public:
		RectangleLawn(unsigned int x, unsigned int y);
		virtual ~RectangleLawn();
		virtual unsigned int GetArea() const;

		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mX;
		unsigned int mY;
	};
}
#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned int x);
		virtual ~CircleLawn();
		virtual unsigned int GetArea() const;

	private:
		unsigned int mX;
	};
}



#include <cstring>
#include <cmath>
#include "PolyLine.h"
#include <limits>

namespace lab4
{
	PolyLine::PolyLine()
	{
		mIndex = 0;
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		for (unsigned int i = 0; i < other.mIndex; i++)
		{
			// Deep Copy
			this->mPoint[i] = new Point(other.mPoint[i]->GetX(), other.mPoint[i]->GetY());
		}

		mIndex = other.mIndex;
	}

	PolyLine::~PolyLine()
	{
		for (unsigned int i = 0; i < mIndex; i++)
		{
			delete this->mPoint[i];
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mIndex < MAXPOINT)
		{
			this->mPoint[mIndex] = new Point(x, y);
			mIndex++;

			return true;
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mIndex < MAXPOINT)
		{
			this->mPoint[mIndex] = point;
			mIndex++;

			return true;
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::RemovePoint(unsigned int index)
	{
		if (index >= 0)
		{
			if (index < mIndex)
			{
				delete this->mPoint[index];
				mIndex--;

				for (unsigned int i = index; i < mIndex; i++)
				{
					unsigned int k;
					k = i + 1;

					// shallow copy
					this->mPoint[i] = this->mPoint[k];
				}

				return true;
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	
	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		float minX, maxX;
		float minY, maxY;

		minX = std::numeric_limits<float>::max();
		minY = std::numeric_limits<float>::max();

		maxX = std::numeric_limits<float>::min();
		maxY = std::numeric_limits<float>::min();

		for (unsigned int i = 0; i < mIndex; i++)
		{
			if (minX > mPoint[i]->GetX())
				minX = mPoint[i]->GetX();

			if (minY > mPoint[i]->GetY())
				minY = mPoint[i]->GetY();

			if (maxX < mPoint[i]->GetX())
				maxX = mPoint[i]->GetX();

			if (maxY < mPoint[i]->GetY())
				maxY = mPoint[i]->GetY();
		}

		if (mIndex > 0)
		{
			outMin->mX = minX;
			outMin->mY = minY;

			outMax->mX = maxX;
			outMax->mY = maxY;
			
			return true;
		}
		else
		{
			return false;
		}

	}

	const Point* PolyLine::operator[](unsigned int index) const
	{
		if (index >= 0)
		{
			if (index < mIndex)
			{
				return this->mPoint[index];
			}
			return NULL;
		}
		else
		{
			return NULL;
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		else
		{
			for (unsigned int i = 0; i < rhs.mIndex; i++)
			{
				// Deep Copy
				this->mPoint[i] = new Point(rhs.mPoint[i]->GetX(), rhs.mPoint[i]->GetY());
			}

			mIndex = rhs.mIndex;

			return *this;
		}
	}

}
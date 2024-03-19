#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y)
	{
		mX = x;
		mY = y;
	}

	Point::Point(const Point& other)
	{
		mX = other.mX;
		mY = other.mY;
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{
		Point newPoint(*this);

		newPoint.mX += other.mX;
		newPoint.mY += other.mY;

		return newPoint;
	}

	Point Point::operator-(const Point& other) const
	{
		Point newPoint(*this);

		newPoint.mX -= other.mX;
		newPoint.mY -= other.mY;

		return newPoint;
	}

	float Point::Dot(const Point& other) const
	{
		float dot;

		dot = this->mX * other.mX + this->mY * other.mY;

		return dot;
	}

	Point Point::operator*(float operand) const
	{
		Point newPoint(*this);

		newPoint.mX *= operand;
		newPoint.mY *= operand;

		return newPoint;
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}
	
	Point operator*(float operand, Point& other)
	{
		lab4::Point newPoint(other);

		newPoint.mX *= operand;
		newPoint.mY *= operand;

		return newPoint;
	}
	
}

#pragma once

namespace lab4
{
	class Point
	{
		friend lab4::Point operator*(float operand, lab4::Point& other);
		friend class PolyLine;

	public:
		Point(float x, float y);
		Point(const Point& other);
		~Point();

		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		float Dot(const Point& other) const;
		Point operator*(float operand) const;

		float GetX() const;
		float GetY() const;

	private:

		float mX;
		float mY;
	};

	Point operator*(float operand, Point& other);
}


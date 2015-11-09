#include "Point.h"
#include <iostream>

Point::Point(const Point& p)
{
	x = p.x;
	y = p.y;
}

Point::Point(const int _x, const int _y)
{
	x = _x;
	y = _y;
}

	const Point& Point::operator=(const Point& p)
	{
		x = p.x;
		y = p.y;
		return *this;
	}

	bool Point::operator==(const Point& p) const
	{
		if (x == p.x || y == p.y)
			return true;

		else
			return false;
	}

	bool Point::operator!=(const Point& p) const
	{
		if (x != p.x || y != p.y)
			return true;

		else
			return false;
	}

	const Point& Point::operator+=(const Point& p)
	{
		x = x + p.x;
		y = y + p.y;
		return *this;
	}

	const Point& Point::operator-=(const Point& p)
	{
		x = x - p.x;
		y = y - p.y;
		return *this;
	}

	Point Point::operator+(const Point& p) const
	{
		Point result;
		result.x = x + p.x;
		result.y = y + p.y;

		return result;
	}

	Point Point::operator-(const Point& p) const
	{
		Point result;
		result.x = x - p.x;
		result.y = y - p.y;

		return result;
	}

	Point Point::operator+(int a) const
	{
		Point result;
		result.x = x + a;
		result.y = y + a;
		return result;
	}

	bool Point::IsZero() const
	{
		if (x == 0 || y == 0)
			return true;

		else
			return false;
	}

	void Point::SetZero()
	{
		x = 0;
		y = 0;
	}

	void Point::Negate()
	{
		x = -x;
		y = -y;
	}

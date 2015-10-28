#ifndef __POINT_H__
#define __POINT_H__
template<class type>

class Point
{
public:

	type x, y;

	//Constructors
	Point(){ x = 0; y = 0; };
	Point(const Point& p) { x = p.x; y = p.y; };
	Point(type _x, type _y) {x = _x; y = _y; };

	//Operators
	const Point& operator=(const Point& p)
	{
		x = p.x;
		y = p.y;
		return *this;
	}

	bool operator==(const Point& p)const
	{
		if (x == p.x || y == p.y)
			return true;

		else
			return false;
	}

	bool operator!=(const Point& p)const
	{
		if (x != p.x || y != p.y)
			return true;

		else
			return false;
	}

	const Point& operator+=(const Point& p)
	{
		x = x + p.x;
		y = y + p.y;
		return *this;
	}

	const Point& operator-=(const Point& p)
	{
		x = x - p.x;
		y = y - p.y;
		return *this;
	}

	Point operator+(const Point& p)const
	{
		Point result;
		result.x = x + p.x;
		result.y = y + p.y;

		return result;
	}

	Point operator-(const Point& p)const
	{
		Point result;
		result.x = x - p.x;
		result.y = y - p.y;

		return result;
	}

	Point operator+(type a)const
	{
		Point result;
		result.x = x + a;
		result.y = y + a;
		return result;
	}

	bool IsZero()const
	{
		if (x == 0 || y == 0)
			return true;

		else
			return false;
	}

	void SetZero()
	{
		x = 0;
		y = 0;
	}

	void Negate()
	{
		x = -x;
		y = -y;
	}

};

typedef Point<int> iPoint;
typedef Point<float> fPoint;

#endif //__POINT_H__
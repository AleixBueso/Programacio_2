#include <iostream>
#include "Circle.h"

 const Circle& Circle::operator=(const Circle& c)
{
	 r = c.r;
	 return *this;
}

 bool Circle::operator==(const Circle& c) const
 {
	 if (r == c.r)
		 return true;

	 else
		 return false;
 }

 bool Circle::operator!=(const Circle& c)const
 {
	 if (r != c.r)
		 return true;

	 else
		 return false;
 }

 const Circle& Circle::operator+=(const Circle& c)
 {
	 r = r + c.r;
	 return *this;
 }

 const Circle& Circle::operator-=(const Circle& c)
 {
	 r = r - c.r;
	 return *this;
 }

 Circle Circle::operator+(const Circle& c)const
 {
	 Circle result;
	 result.r = r + c.r;
	 return result;
 }

 Circle Circle::operator-(const Circle& c)const
 {
	 Circle result;
	 result.r = r - c.r;
	 return result;
 }

 float Circle::GetArea()const
 {
	 return(3.14159 * (r * r));
 }
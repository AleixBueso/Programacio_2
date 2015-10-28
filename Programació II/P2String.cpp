#include "p2String.h"
#include <iostream>

P2String::P2String(const P2String &string)
{
	str = string.str;
	capacity = string.capacity;
}

P2String::P2String(const char* string)
{
	P2String* new_string = new P2String;
	*new_string->str = *string;

}

P2String::P2String(uint new_capacity)
{
	P2String* new_string = new P2String;
	new_string->capacity = new_capacity;
}

P2String::~P2String()
{
	if (str != NULL)
		delete[] str;
}

const char* P2String::GetString()const
{
	return str;
}

const uint P2String::GetCapacity()const
{
	return capacity;
}

bool P2String::operator==(const char* string)const
{
	if (string == str)
		return true;
	else
		return false;
}

bool P2String::operator!=(const char* string)const
{
	if (string != str)
		return true;
	else
		return false;
}

bool P2String::operator!=(const char* string)const
{
	if (string != str)
		return true;
	else
		return false;
}

bool P2String::operator!=(const P2String &string)const
{
	if (string.str != str)
		return true;
	else
		return false;
}

bool P2String::operator!=(const P2String &string)const
{
	if (string.str != str)
		return true;
	else
		return false;
}
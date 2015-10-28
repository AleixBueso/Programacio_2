#include "p2String.h"
#include <iostream>

P2String::P2String()
{
	str = NULL;
	capacity = 0;
}

P2String::P2String(const P2String &string)
{
	str = string.str;
	capacity = string.capacity;
}

P2String::P2String(const char* string)
{
	capacity = GetLength(string);
	str = new char[capacity + 1];

	for (uint i = 0; i <= capacity; i++)
		str[i] = string[i];
}

P2String::P2String(uint new_capacity)
{
	P2String* new_string = new P2String;
	new_string->capacity = new_capacity;
}

P2String::~P2String()
{
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

const uint P2String::GetLength(const char* string)
{
	uint count = 0;
	uint i = 0;

	if (str = NULL)
		return 0;

	else
	{
		while (str[i] != 0 && str[i]!=NULL)
		{
			i++;
			count++;
		}
	return count;
	}

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

bool P2String::operator==(const P2String &string)const
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
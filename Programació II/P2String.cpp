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

	if (string == NULL)
		return 0;

	else
	{
		while (string[i] != '\0')
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

P2String P2String::operator=(const P2String &string)
{
	unsigned int need_size = string.GetCapacity() + 1;
	if (need_size > capacity)
	{
		delete[] str;
		capacity = need_size;
		str = new char[need_size];
	}
	strcpy_s(str, capacity, string.str);
	return(*this);
}

P2String P2String::operator+=(const char* string)
{
	uint k = 0;
	uint i = 0;
	if (GetLength(string) + capacity > capacity)
	{
		uint new_length = GetLength(string) + capacity + 1;
		char* tmp;
		tmp = new char[new_length];
		strcpy_s(tmp, new_length, str);
		delete[]str;
		
		for (i = 0; i <= capacity - 1; i++)
			str[i] = tmp[i];

		capacity = new_length;
		for (i; i <= capacity; i++)
			str[i] = string[k++];

		//delete[] tmp;
		return *this;
	}

	else
	{
		for (uint i = 0; i <= capacity; i++)
			str[i] = string[k++];
		str[GetLength(str)] = '\0';
	}

	
}
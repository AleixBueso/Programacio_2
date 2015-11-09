#include "p2String.h"

P2String::P2String(P2String &string)
{
	str = string.str;
	capacity = string.capacity;
}

P2String::P2String(char* string)
{
	P2String* new_string = new P2String;
	new_string->str = string;

}

P2String::P2String(uint new_capacity)
{
	P2String* new_string = new P2String;
	new_string->capacity = new_capacity;
}

P2String::~P2String()
{

}

char* P2String::GetString()
{
	return str;
}

uint P2String::GetCapacity()
{
	return capacity;
}

bool P2String::operator==(P2String &string)
{
	if (string.str == str && string.capacity == capacity)
		return true;
	else
		return false;
}

bool P2String::operator!=(P2String &string)
{
	if (string.str != str && string.capacity != capacity)
		return true;
	else
		return false;
}
#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

#include "Globals.h"

template <class type>
class DynArray
{
	type* data;
	uint capacity;
	uint num_elements;

public:

	//Homework:
	//at()
	//capacity()
	//size()
	//Clear()
	//ctr(capacity)
	//empty() (bool true si esta buida)

	DynArray() : capacity(CHUNK), num_elements(0)
	{
		data = new type[CHUNK];
	}

	DynArray(const DynArray &Array) : num_elements(Array.num_elements)
	{
		data = new type[Array.capacity];
		capacity = MAX(Array.capacity, CHUNK);
		memccpy(data, Array.data, Array.num_elements * sizeof(type));
	}

	DynArray(type* Array) : num_elements(sizeof(Array))
	{
		data = new type[sizeof(Array)];
		capacity = MAX(CHUNK, sizeof(Array));
		memccpy(data, Array, sizeof(Array) * sizeof(type));
	}

	~DynArray()
	{
		if (data)
			delete[] data;
	}

	uint GetCapacity()
	{
		return capacity;
	}

	uint GetSize()
	{
		return num_elements;
	}

	bool IsEmpty()
	{
		if (data == NULL)
			return true;
		else
			return false;
	}

	void PushBack(const type &item)
	{
		if (num_elements++ < capacity)
			data[num_elements++] = item;
		else
		{
			type* tmp = new type[capacity];
			memcpy(tmp, data, capacity);
			data = new type[capacity + 1];
			memcpy(data, tmp, num_elements + 1);
			delete[] tmp;
		}
	}

	bool At(uint position, const type &item)
	{
		if (position <= capacity)
		{
			type* tmp = new type[num_elements + 1];
			for (uint i = 0; i <= position; i++)
				tmp[i] = data[i];
			tmp->PushBack(item);
			for (uint i = position + 1; i <= num_elements + 1; i++)
				tmp[i] = data[i - 1];
			data = new type[tmp->num_elements + 1];
			memcpy(data, tmp, num_elements + 1);
			delete[]tmp;
			return true;
		}
		else
			return false;
	}

	bool ctr(uint new_capacity)
	{
		if (new_capacity < num_elements)
			return false;
		else
		{
			type* tmp = new type[new_capacity];
			memcpy(tmp, data, new_capacity);
			data = new type[new_capacity];
			memcpy(data, tmp, num_elements + 1);
			delete[] tmp;
			return true;
		}
	}

	void Clear()
	{
		data = NULL;
		num_elements = 0;
		capacity = 0;
	}

};

#endif

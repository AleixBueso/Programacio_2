#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

#include "Globals.h"

typedef unsigned int uint;
#define CHUNK 16

template <class TYPE>
class DynArray
{
	TYPE* data = NULL;
	uint capacity = 0;
	uint num_elements = 0;

public:
	//Homework:
	//at()
	//capacity()
	//size()
	//Clear()
	//ctr(capacity)
	//empty() (bool true si esta buida)
	//operador[]
	//operador=
	//pop_back
	//shrink_to_fit (si sobra mem, es talla)
	//flip
	//insert

	DynArray() : capacity(CHUNK) {
		data = new TYPE[CHUNK];
	}

	DynArray(const DynArray &Array) : num_elements(Array.num_elements)
	{
		data = new TYPE[Array.capacity];
		capacity = MAX(Array.capacity, CHUNK);
		memccpy(data, Array.data, Array.num_elements * sizeof(TYPE));
	}
	
	DynArray(uint new_capacity)
	{
		data = new TYPE[new_capacity];
		memcpy(data, tmp, num_elements * sizeof(TYPE));
		cacpacity = new_capacity;
		delete[] tmp;
	}

	~DynArray()
	{
		if (data)
			delete[] data;
	}

	uint GetCapacity() const
	{
		return capacity;
	}

	uint GetSize() const
	{
		return num_elements;
	}

	bool IsEmpty() const
	{
		if (data == NULL)
			return true;
		else
			return false;
	}
	
	TYPE* c_str() const
	{
		return data;
	}
	
	const TYPE& At(unsigned int position) const
	{
		if(positon <= num_elements)
			return data[position];
			else
		return 0;
	}

	void PushBack(const TYPE &item)
	{
		if (num_elements + 1 >= capacity)
		{
			TYPE* tmp = data;
			memcpy(tmp, data, capacity);
			data = new TYPE[capacity + CHUNK];
			memcpy(data, tmp, num_elements * sizeof(TYPE));
			delete[] tmp;
		}
			data[num_elements++] = item;
	}

	bool Insert(uint position, const TYPE &item)
	{
		if (position <= capacity)
		{
			TYPE* tmp = data;
			strcpy(tmp, data, capacity);
			data = new TYPE[tmp->num_elements + 1];

			for (uint i = 0; i <= position; i++)
				data[i] = tmp[i];
			
			data.Pushback(item);

			for (uint i = position + 1; i <= num_elements + 1; i++)
				data[i + 1] = tmp[i];
			
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
			TYPE* tmp = new TYPE[new_capacity];
			memcpy(tmp, data, new_capacity);
			data = new TYPE[new_capacity];
			memcpy(data, tmp, num_elements + 1);
			delete[] tmp;
			return true;
		}
	}

	void Clear()
	{
		num_elements = 0;
	}

};

#endif

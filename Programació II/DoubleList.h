#ifndef __DList_H__
#define __DList_H__

#include "Globals.h"

template <class TYPE>
struct DList_Node
{
	DList_Node<TYPE>* next = NULL;
	DList_Node<TYPE>* prev = NULL;
	TYPE data;

	DList_Node(const TYPE& data) : data(data){}
	~DList_Node(){}
};

template <class TYPE>
class DList
{
	DList_Node<TYPE>* start = NULL;
	DList_Node<TYPE>* end = NULL;

public:
	DList(){}
	~DList(){ Clear(); }

	const DList_Node<TYPE>* GetFirst(){ return start; }

	DList_Node<TYPE>* GetLast(){ return end; }

	/*const DList_Node<TYPE>* GetLast()
	{
	DList_Node<TYPE>* tmp = start;
	while (tmp->next != NULL)
	{
	tmp = tmp->next;
	}
	return tmp;
	}
	*/

	void PushBack(const TYPE& item)
	{
		DList_Node<TYPE>* new_node = new DList_Node<TYPE>(item);

		if (start == NULL)
			end = start = new_node;
		else
		{
			DList_Node<TYPE>* tmp = GetLast();
			tmp->next = new_node;
			new_node->prev = tmp;
			end = new_node;
		}
	}

	void PushFront(const TYPE& item)
	{
		DList_Node<TYPE>* new_node = new DList_Node<TYPE>(item);
		start->prev = new_node;
		new_node->next = start;
		start = new_node;
	};

	 bool PopBack(TYPE& ret)
	{
		if (start == NULL)
			return false;
		else
		{
			ret = end->data;
			if (end->prev != NULL)
			{
				end = end->prev;
				delete end->next;
				end->next = NULL;
			}
			else
			{
				delete start;
				start = end = NULL;
			}
				
			return true;
		}
	}

	bool PopFront(TYPE& ret)
	{
		if (start == NULL)
			return false;
		else
		{
			ret = end->data;
			if (start->next != NULL)
			{
				start = start->next;
				delete start->prev;
				start->prev = NULL;
			}
			else
			{
				delete end;
				start = end = NULL;
			}

			return true;
		}
	}

	void Insert(const TYPE& item, uint pos)
	{
		if (pos <= Count())
		{
			if (pos == 0)
				PushFront(item);
			else if (pos == Count())
				PushBack(item);
			else
			{
				DList_Node<TYPE>* new_node = new DList_Node<TYPE>(item);
				DList_Node<TYPE>* tmp = start;
				for (uint i = 0; i < pos; i++)
					tmp = tmp->next;
				tmp->next->prev = new_node;
				new_node->next = tmp->next;
				new_node->prev = tmp;
				tmp->next = new_node;
			}
		}
	}

	void Remove(uint pos)
	{
		if (pos <= Count())
		{
			int a = 0;
			if (pos == 0)
				PopFront(a);
			else if (pos == Count())
				PopBack(a);
			else
			{
				DList_Node<TYPE>* tmp = start;
				for (uint i = 0; i < pos; i++)
					tmp = tmp->next;
				tmp->next->prev = tmp->prev;
				tmp->prev->next = tmp->next;
				delete tmp;
			}
		}

	}

	const TYPE& At(uint pos)
	{
		DList_Node<TYPE>* tmp = start;
		for (uint i = 0; i <= pos; i++)
			tmp = tmp->next;
		return tmp->data;
	}

	void Clear()
	{
		while (end != NULL)
		{
			DList_Node<TYPE>* node_to_delete = end;
			end = end->prev;
			delete node_to_delete;
		}
		start = end = NULL;
	}

	uint Count() const
	{
		uint ret = 0;
		DList_Node<TYPE>* tmp = start;

		while (tmp != NULL)
		{
			tmp = tmp->next;
			ret++;
		}

		return ret;
	}

	bool Empty(){ return(start == end == NULL); }
};

#endif //__DList_H__

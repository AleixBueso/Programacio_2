#ifndef __DList_H__
#define __DList_H__

#include "Globals.h"

template <class TYPE>
class DList_Node
{
	DList_Node<TYPE>* next;
	DList_Node<TYPE>* prev;
	TYPE* data;

public:
	DList_Node() : next(NULL), prev(NULL), data(NULL){}
	DList_Node(const TYPE& data) : next(NULL), prev(NULL), data(data){}
	~DList_node() :data(NULL){}
};

template <class TYPE>
class DList
{
	DList_Node<TYPE>* start;
	DList_Node<TYPE>* end;

public:
	DList() : start(NULL), end(NULL){}
	~DList(){ start = end = NULL; }

	const DList_Node<TYPE>& GetFirst(){ return start; }
	const DList_Node<TYPE>& GetLast(){ return end; }
	void PushBack(const TYPE& item)
	{
		DList_Node<TYPE>* new_node = new DList_Node<TYPE>;
		new_node->data = item;

		if (Count() == 0)
			end = start = new_node;
		else
		{
			end->next = new_node;
			end = new_node;
		}
	}
	void Clear()
	{
		while (start != end)
		{
			DList_Node<TYPE>* node_to_delete = end;
			end = end->prev;
			delete node_to_delete;
		}
	}
	uint Count()
	{
		uint ret = 0;
		DList_Node<TYPE*>* tmp = new DList_Node<TYPE>;
		tmp = start;
		while (tmp!=end)
		{
			ret++;
			tmp = tmp->next;
		}

		return ret;
	}
	bool Empty(){ return(start=end=NULL) }
};

#endif //__DList_H__
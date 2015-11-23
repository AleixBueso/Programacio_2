#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "p2String.h"
#include "DoubleList.h"
#include "DynamicArray.h"
using namespace std;

template<typename type>
void Swap(type& a, type& b)
{
	type tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	cout << "=============================== PROGRAMACIO II ================================" << endl;
	cout << endl;
	cout << endl;

	DList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushFront(5);
	list.Insert(8, 3);
	list.Remove(0);

	cout << "Count: " << list.Count() << endl;
	cout << "First: " << list.GetFirst()->data << endl;
	list.PopBack(c);
	cout << "Pop Last: " << c << endl;
	cout << "Count: " << list.Count() << endl;
	list.PopFront(a);
	cout << "Pop Front: " << a << endl;
	cout << "Count: " << list.Count() << endl;
	list.PopFront(b);
	cout << "Pop Front: " << b << endl;
	cout << "Count: " << list.Count() << endl;

	cout << endl;
	cout << endl;
	cout << "===============================================================================" << endl;
	system("pause");
	return 0;
}

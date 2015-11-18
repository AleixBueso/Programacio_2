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

	cout << "Count: " << list.Count() << endl;
	cout << "First: " << list.GetFirst()->data << endl;

	cout << endl;
	cout << endl;
	cout << "===============================================================================" << endl;
	system("pause");
	return 0;
}
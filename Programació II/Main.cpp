#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "p2String.h"
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

	DynArray<int> array1;
	array1.PushBack(1);
	array1.PushBack(2);
	array1.PushBack(3);

	cout << array1.c_str() << endl;

	cout << endl;
	cout << endl;
	cout << "===============================================================================" << endl;
	system("pause");
	return 0;
}
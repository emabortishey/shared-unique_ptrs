#include <iostream>
#include "user_shared_ptr.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int ff = 5;
	int zz = 6;
	user_shared_ptr<int> test{ ff };

	cout << "Первый указатель до изменений: " << *test.get() << ' ';

	test.reset(&zz);

	cout << "\nПервый указатель после изменений: " << *test.get() << ' '; 

	cout << "\nТип первого указателя: " << test.get_typename();

	user_shared_ptr<int> test2{ ff };

	cout << "\nВторой указатель до изменений: " << *test2.get();

	test.swapp(test2);

	cout << "\nПервый указатель после свапа: " << *test.get() << "\nВторой указатель после свапа: " << *test2.get();

	cout << "\nИспытание перегрузки оператора * на первом классе: " << * test;

	cout << "\nИспытание перегрузки оператора -> на первом классе: " << *test.operator->();

	return 0;
}
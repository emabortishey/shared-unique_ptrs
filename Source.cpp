#include "user_shared_ptr.h"
#include "user_unique_ptr.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "РАБОТА С SHARED PTR: ";

	int ff = 5;
	int zz = 6;
	user_shared_ptr<int> test{ ff };

	cout << "\n\nПервый указатель до изменений: " << *test.get() << ' ';

	test.reset(&zz);

	cout << "\nПервый указатель после изменений: " << *test.get() << ' '; 

	cout << "\nТип первого указателя: " << test.get_typename();

	user_shared_ptr<int> test2{ ff };

	cout << "\nВторой указатель до изменений: " << *test2.get();

	test.swapp(test2);

	cout << "\nПервый указатель после свапа: " << *test.get() << "\nВторой указатель после свапа: " << *test2.get();

	cout << "\nИспытание перегрузки оператора * на первом классе: " << * test;

	cout << "\nИспытание перегрузки оператора -> на первом классе: " << *test.operator->();

	user_shared_ptr<int> test3{ test2 };

	cout << "\nИнициализация третьего указателя вторым с помощью конструктора копирования: " << *test3.get();

	cout << "\n\n\nnРАБОТА С UNIQUE PTR: ";

	int ff1 = 5;
	int zz1 = 6;
	user_unique_ptr<int> test1{ ff1 };

	cout << "\n\nПервый указатель до изменений: " << *test1.get() << ' ';

	test1.reset(&zz1);

	cout << "\nПервый указатель после изменений: " << *test1.get() << ' ';

	cout << "\nТип первого указателя: " << test1.get_typename();

	user_unique_ptr<int> test12{ ff1 };

	cout << "\nВторой указатель до изменений: " << *test12.get();

	test1.swapp(test12);

	cout << "\nПервый указатель после свапа: " << *test1.get() << "\nВторой указатель после свапа: " << *test12.get();

	cout << "\nИспытание перегрузки оператора * на первом классе: " << *test1;

	cout << "\nИспытание перегрузки оператора -> на первом классе: " << *test1.operator->();
	 
	//user_shared_ptr<int> test13{ test12 }; 

	//cout << "\nИнициализация третьего указателя первым с помощью конструктора копирования: " << *test3.get();

	return 0;
}
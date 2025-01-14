#include <iostream>
#include "user_shared_ptr.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int ff = 5;
	int zz = 6;
	user_shared_ptr<int> test{ ff };

	cout << "������ ��������� �� ���������: " << *test.get() << ' ';

	test.reset(&zz);

	cout << "\n������ ��������� ����� ���������: " << *test.get() << ' '; 

	cout << "\n��� ������� ���������: " << test.get_typename();

	user_shared_ptr<int> test2{ ff };

	cout << "\n������ ��������� �� ���������: " << *test2.get();

	test.swapp(test2);

	cout << "\n������ ��������� ����� �����: " << *test.get() << "\n������ ��������� ����� �����: " << *test2.get();

	cout << "\n��������� ���������� ��������� * �� ������ ������: " << * test;

	cout << "\n��������� ���������� ��������� -> �� ������ ������: " << *test.operator->();

	return 0;
}
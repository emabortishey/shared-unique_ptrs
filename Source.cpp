#include "user_shared_ptr.h"
#include "user_unique_ptr.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "������ � SHARED PTR: ";

	int ff = 5;
	int zz = 6;
	user_shared_ptr<int> test{ ff };

	cout << "\n\n������ ��������� �� ���������: " << *test.get() << ' ';

	test.reset(&zz);

	cout << "\n������ ��������� ����� ���������: " << *test.get() << ' '; 

	cout << "\n��� ������� ���������: " << test.get_typename();

	user_shared_ptr<int> test2{ ff };

	cout << "\n������ ��������� �� ���������: " << *test2.get();

	test.swapp(test2);

	cout << "\n������ ��������� ����� �����: " << *test.get() << "\n������ ��������� ����� �����: " << *test2.get();

	cout << "\n��������� ���������� ��������� * �� ������ ������: " << * test;

	cout << "\n��������� ���������� ��������� -> �� ������ ������: " << *test.operator->();

	user_shared_ptr<int> test3{ test2 };

	cout << "\n������������� �������� ��������� ������ � ������� ������������ �����������: " << *test3.get();

	cout << "\n\n\nn������ � UNIQUE PTR: ";

	int ff1 = 5;
	int zz1 = 6;
	user_unique_ptr<int> test1{ ff1 };

	cout << "\n\n������ ��������� �� ���������: " << *test1.get() << ' ';

	test1.reset(&zz1);

	cout << "\n������ ��������� ����� ���������: " << *test1.get() << ' ';

	cout << "\n��� ������� ���������: " << test1.get_typename();

	user_unique_ptr<int> test12{ ff1 };

	cout << "\n������ ��������� �� ���������: " << *test12.get();

	test1.swapp(test12);

	cout << "\n������ ��������� ����� �����: " << *test1.get() << "\n������ ��������� ����� �����: " << *test12.get();

	cout << "\n��������� ���������� ��������� * �� ������ ������: " << *test1;

	cout << "\n��������� ���������� ��������� -> �� ������ ������: " << *test1.operator->();
	 
	//user_shared_ptr<int> test13{ test12 }; 

	//cout << "\n������������� �������� ��������� ������ � ������� ������������ �����������: " << *test3.get();

	return 0;
}
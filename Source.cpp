#include <iostream>
#include "user_shared_ptr.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int ff = 5;
	int zz = 6;
	user_shared_ptr<int> test{ ff };

	for (auto buff : test.ptrlist)
	{
		cout << buff.first << ' ' << *buff.first << ' ' << buff.second << '\n';
	}

	test.reset(&zz);

	for (auto buff : test.ptrlist)
	{
		cout << buff.first << ' ' << *buff.first << ' ' << buff.second << '\n';
	}

	cout << test.get_typename();

	return 0;
}
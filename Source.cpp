#include <iostream>
#include "user_shared_ptr.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int ff = 5;
	user_shared_ptr<int> test{ ff };

	return 0;
}
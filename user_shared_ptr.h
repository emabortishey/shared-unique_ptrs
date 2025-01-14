#pragma once
#include <iostream>
#include <vector>
#include <list>

using namespace std;


template<class T>
class user_shared_ptr
{
	T* ptr;
public:
	static list<pair<T*&, int>> ptrlist;
	user_shared_ptr() : ptr{ nullptr } { };
	explicit user_shared_ptr(T obj_P) : ptr{ &obj_P }
	{
		ptrlist.push_back(pair<T*&, int>(ptr, 1)); 
	};
	explicit user_shared_ptr(T* ptr_P) : ptr{ ptr_P }
	{
		for (auto buff : ptrlist)
		{
			if (ptr_P == buff.first)
			{
				buff.second++;
			}
		}
		if(ptrlist.empty())
		{
			ptrlist.push_back(pair<T*&, int>(ptr_P, 1)); 
		}
	};

	~user_shared_ptr()
	{
		for (auto buff : ptrlist) 
		{
			if (ptr == buff.first)
			{
				if (buff.second > 1)
				{
					buff.second--;

					break;
				}
				else
				{
					ptrlist.remove(pair<T*&, int>(ptr, 1));

					ptr = nullptr;
					delete ptr;

					break;
				}
			}
		}
	}

};

template<class T>
list<pair<T*&, int>> user_shared_ptr<T>::ptrlist;
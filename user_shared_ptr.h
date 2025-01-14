#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<class T>
class user_shared_ptr
{
	T* ptr;
	static list<pair<T*&, int>> ptrlist;
public:
	user_shared_ptr() : ptr{ nullptr } { };
	explicit user_shared_ptr(T& obj_P) : ptr{ &obj_P }
	{
		ptrlist.push_back(pair<T*&, int>(ptr, 1)); 
	};
	explicit user_shared_ptr(T* ptr_P) : ptr{ ptr_P }
	{
		bool count = false;

		for (auto buff : ptrlist)
		{
			if (ptr == buff.first)
			{
				buff.second++;

				count = true;
			}
		}
		if(count == false)
		{
			ptrlist.push_back(pair<T*&, int>(ptr, 1)); 
		}
	};
	explicit user_shared_ptr(user_shared_ptr& ptr_P) : ptr{ ptr_P.ptr }
	{
		bool count = false;

		for (auto buff : ptrlist)
		{
			if (ptr == buff.first)
			{
				buff.second++;

				count = true;
			}
		}
		if (count == false)
		{
			ptrlist.push_back(pair<T*&, int>(ptr, 1));
		}
	}

	T* get() { return ptr; }

	void reset(T* new_ptr = nullptr)
	{
		T*& old_ptr_buff = ptr;
		ptr = new_ptr;

		for (auto buff : ptrlist)
		{
			if (old_ptr_buff == buff.first)
			{
				if (buff.second > 1)
				{
					buff.second--;
					break;
				}
				else
				{
					ptrlist.remove(pair<T*&, int>(buff.first, 1));
					break;
				}
			}
		}
		for (auto buff : ptrlist)
		{
			if (ptr == buff.first)
			{
				buff.second++;

				return;
			}
		}
		ptrlist.push_back(pair<T*&, int>(ptr, 1));
	}

	string get_typename() { return typeid(*ptr).name(); }

	void swapp(user_shared_ptr& obj) {  swap(ptr, obj.ptr); }

	T& operator*() { return *ptr; }

	T* operator->() { return ptr; }

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
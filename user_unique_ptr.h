#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

using namespace std;

template<class T>
class user_unique_ptr
{
	T* ptr;
public:
	user_unique_ptr() : ptr{ nullptr } { };
	explicit user_unique_ptr(T& obj_P) : ptr{ &obj_P } { };
	// запрет на конструктор копирования
	explicit user_unique_ptr(user_unique_ptr& ptr_P) = delete;

	// в остальном методы почти те же 
	// самые как и в unique ptr только без
	// наворотов в виде списка указателей
	T* get() { return ptr; }

	void reset(T* new_ptr = nullptr) { ptr = new_ptr; }

	string get_typename() { return typeid(*ptr).name(); }

	void swapp(user_unique_ptr& obj) { swap(ptr, obj.ptr); } 

	T& operator*() { return *ptr; }

	T* operator->() { return ptr; }

	~user_unique_ptr()
	{ 
		ptr = nullptr;
		delete ptr;
	}

};
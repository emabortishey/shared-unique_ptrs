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
	explicit user_shared_ptr(T& ptr_P) : ptr{ &ptr_P }
	{
		// переменная для будущего определения есть ли элемент в списке
		bool count = false;

		// пробегаемся по списку
		for (auto buff : ptrlist)
		{
			// в случае совпадения прибавляем к значению
			// в списке под этим указателем 1 еденицу
			if (ptr == buff.first)
			{
				buff.second++;
				// и переопределяем каунт как тру (эл уже есть)
				count = true;
				// прерываем цикл за ненадобностью
				break;
			}
		}
		// если каунт фолс и элемента пок
		// а ещё не существует в списке
		if (count == false)
		{
			// он пушбекается в него с деф. значением 1
			ptrlist.push_back(pair<T*&, int>(ptr, 1));
		}
	};
	explicit user_shared_ptr(T* ptr_P) : ptr{ ptr_P }
	{
		// переменная для будущего определения есть ли элемент в списке
		bool count = false;

		// пробегаемся по списку
		for (auto buff : ptrlist)
		{
			// в случае совпадения прибавляем к значению
			// в списке под этим указателем 1 еденицу
			if (ptr == buff.first)
			{
				buff.second++;
				// и переопределяем каунт как тру (эл уже есть)
				count = true;
				// прерываем цикл за ненадобностью
				break;
			}
		}
		// если каунт фолс и элемента пок
		// а ещё не существует в списке
		if(count == false)
		{
			// он пушбекается в него с деф. значением 1
			ptrlist.push_back(pair<T*&, int>(ptr, 1)); 
		}
	};
	explicit user_shared_ptr(user_shared_ptr& ptr_P) : ptr{ ptr_P.ptr }
	{
		// переменная для будущего определения есть ли элемент в списке
		bool count = false;

		// пробегаемся по списку
		for (auto buff : ptrlist)
		{
			// в случае совпадения прибавляем к значению
			// в списке под этим указателем 1 еденицу
			if (ptr == buff.first)
			{
				buff.second++;
				// и переопределяем каунт как тру (эл уже есть)
				count = true;
				// прерываем цикл за ненадобностью
				break;
			}
		}
		// если каунт фолс и элемента пок
		// а ещё не существует в списке
		if (count == false)
		{
			// он пушбекается в него с деф. значением 1
			ptrlist.push_back(pair<T*&, int>(ptr, 1));
		}
	}

	T* get() { return ptr; }

	// метод для удаления или переприсваивания атрибута указателя
	void reset(T* new_ptr = nullptr)
	{
		// переменная для будущего определения 
		// текущего наличия элемента в списке
		bool count = false;

		// поиск этого указателя в списке
		for (auto buff : ptrlist)
		{
			// если указатель найден
			if (ptr == buff.first)
			{
				// если кол-во указателей на элемент
				// больше одного
				if (buff.second > 1)
				{
					// просто убавляем кол-во и завершаем цикл
					buff.second--;
					break;
				}
				else
				{
					// удаляем указатель из списка с помощью ремува
					ptrlist.remove(pair<T*&, int>(buff.first, 1));
					break;
				}
			}
		}

		// присваиваем указателю новое значение
		ptr = new_ptr;

		// ищем есть ли уже такое значение в списке
		for (auto buff : ptrlist)
		{
			// если оно уже есть, прибавляем к его счётчику 1
			if (ptr == buff.first)
			{
				buff.second++;

				// т.к. мы определили что элемент уже существует в списке
				// и прибавили его в счётчик, то каунт становится тру
				count = true;

				return;
			}
		}

		// если все-таки элемента ещё нет, мы пушбекаем 
		// его в список с дефолтным значением счётчика 1
		if (count == false)
		{
			ptrlist.push_back(pair<T*&, int>(ptr, 1));
		}
	}

	// метод для получения типа указателя в классе
	string get_typename() { return typeid(*ptr).name(); }

	// метод для перемещения двух указателей между собой
	void swapp(user_shared_ptr& obj) {  swap(ptr, obj.ptr); }

	T& operator*() { return *ptr; }

	T* operator->() { return ptr; }

	~user_shared_ptr()
	{
		// пробег по всем элементам списка 
		for (auto buff : ptrlist)
		{
			// если найден элемент именно из данного обьекта класса
			if (ptr == buff.first)
			{
				// если указателей осталось больше чем 1
				if (buff.second > 1)
				{
					// их кол-во под ключом с таким указателем 
					// в спискепросто убавляется на 1 и цикл прерывается
					buff.second--;

					break;
				}
				// в случае если остался 1 указатель на обьект
				else
				{
					// мы удаляем его из списка где происходит
					// очистка выделенной под него памяти
					ptrlist.remove(pair<T*&, int>(ptr, 1));

					// и удаляем его самого, предварительно обнулив
					// т.к. он уже ведёт к несущетсвующему куску памяти
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
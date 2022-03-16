#pragma once
#include <assert.h>
#include <iostream>

namespace allen
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
			
		//构造函数
			vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}


		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

			
		//析构


		size_t capacity()
		{
			return _endofstorage - _start;
		}

		size_t size()
		{
			return _finish - _start;
		}

		T&  operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();//这个很重要
				T* tmp = new T[n];
				if (_start)//一开始是空的
				{
					memcpy(tmp,_start,size());
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}


		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = (capacity() == 0) ? 4 : capacity() * 2;
				reserve(newcapacity);
			}

			*_finish = x;
			++_finish;
		}

		void insert(iterator pos, const T& x);
		iterator erase(iterator pos);

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};


	void TestVector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}


}

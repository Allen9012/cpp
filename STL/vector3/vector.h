#pragma once
#include <assert.h>
#include<iostream>

namespace bit
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		//vector(size_t n, T val);
		// 类模板的成员函数，还可以再是函数模板
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//vector(const vector& v)

		// v2(v1)
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{

			/*reserve(v.capacity());
			for (auto e : v)
			{
			push_back(e);
			}*/

			_start = new T[v.capacity()];
			//memcpy(_start, v._start, sizeof(T)*v.size());
			for (size_t i = 0; i < v.size(); ++i)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
		}

		// v1 = v3
		/*vector<T>& operator=(const vector<T>& v)
		{
		if (this != &v)
		{
		delete[] _start;
		_start = new T[v.capacity()];
		memcpy(_start, v._start, sizeof(T)*v.size());
		_finish = _start + v.size();
		_endofstorage = _start + v.capacity();
		}

		return *this;
		}*/

		// v1 = v3
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
			}

			_start = _finish = _endofstorage = nullptr;
		}

		// v1.swap(v2)
		void swap(vector<T>& v)
		{
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		bool empty() const
		{
			return _start == _finish;
		}

		T& operator[](size_t i)
		{
			assert(i < size());

			return _start[i];
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());

			return _start[i];
		}

		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}

				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sz*sizeof(T));
					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i];
					}

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
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}

			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		void insert(iterator pos, const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;

				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);

				// 更新pos，解决增容后pos失效的问题
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}

		iterator erase(iterator pos)
		{
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}

			--_finish;

			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	template<class Con>
	void PrintVector(const Con& v)
	{
		//Con::const_iterator it = v.begin();
		auto it = v.begin();
		while (it != v.end())
		{
			// *it += 1;  只能读，不能写
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			*it += 1;
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

		PrintVector(v);
	}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		PrintVector(v);

		v.push_back(5);
		PrintVector(v);

		v.resize(3);
		PrintVector(v);

		v.resize(6, 1);
		PrintVector(v);

		v.resize(10, 2);
		PrintVector(v);
	}

	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(8);
		PrintVector(v);

		vector<int>::iterator pos = find(v.begin(), v.end(), 3);
		// 在pos -- 3的之前插入
		v.insert(pos, 30);
		// insert以后，pos就是失效了
		// 1、pos指向位置的意义变了，pos不是指向3
		// 2、pos成了野指针
		PrintVector(v);
	}

	void test_vector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		// 删除掉所有的偶数
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}

		PrintVector(v);
	}

	void test_vector5()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);

		vector<int> v2(v1);

		PrintVector(v1);
		PrintVector(v2);

		vector<int> v3;
		v3.push_back(10);
		v3.push_back(20);

		v1 = v3;

		PrintVector(v1);
		PrintVector(v3);
	}


	void test_vector6()
	{
		vector<string> v;
		v.push_back("1111111111111111111111111111111111");
		v.push_back("22222");
		v.push_back("333333333333333333333333333333333");
		v.push_back("44444");
		v.push_back("55555");
		//string时加一个引用，减少拷贝构造
		for (const auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<string> copy(v);
		for (const auto& e : copy)
		{
			cout << e << " ";
		}
		cout << endl;

		//string s1("1111");
		//string s2("11111111111111111111111111111111");
	}
}
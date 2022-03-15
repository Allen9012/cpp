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
		typedef const T* const_iterator;
		//构造函数
			vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

			vector(size_t n, T val)
				: _start(nullptr)
				, _finish(nullptr)
				, _endOfStorage(nullptr)
			{
				reserve(n);
				while (n--)
				{
					push_back(value);
				}
			}

			// 类模板的成员函数，还可以再是函数模板
			// 若使用iterator做迭代器，会导致初始化的迭代器区间[first,last)只能是vector的迭代器
			// 重新声明迭代器，迭代器区间[first,last)可以是任意容器的迭代器
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


		//拷贝构造,深拷贝
		// v2(v1)
			vector(const vector<T>& v)
				: _start(nullptr)
				, _finish(nullptr)
				, _endofstorage(nullptr)
			{//开一样大的空间
				reserve(v.capacity());
				for (auto e : v)
				{
					push_back(e);
				}
				//_start=new T[v.capacity()];
				//memcpy(_start,v._start,sizeof(T)*v.size());
				// _endofstorage=_start+v.capacity();
				//_finish=_start+=v.size();
			}


			void swap(vector<T>& v)
			{
				::swap(_start, v._start);
				::swap(_finish, v._finish);
				::swap(_endofstorage, v._endofstorage);
			}
			//v1=v2
			vector<T>& operator=( vector<T> v)//加一个const防止传过来的对象是const的
			{
					swap(v);
					return *this;
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
			
		//析构
		~vector()
		{
			if (_start)
				delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		size_t capacity()	const
		{
			return _endofstorage - _start;
		}

		size_t size()   const
		{
			return _finish - _start;
		}
		
		bool empty() const
		{
			return _start == _finish;
		}

		T&  operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		
		const T& operator[](size_t i) const
		{
			assert(i < size());

			return _start[i];
		}
		
		void resize(size_t n , T val= T() )//默认初始化成构造函数
		{//新的小
			if (n < size())
			{
				_finish = _start + n;
			}
			else 
			{//在中间
				if (n < capacity())
				{
					while (_finish < _start + n)
					{
						*_finish = val;
						++_finish;
					}
				}
				else
				{//超过capacity
					reserve(n);//开新空间，拷贝
					while (_finish < _start + n)
					{
						*_finish = val;
						++_finish;
					}
				}
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();//这个很重要
				T* tmp = new T[n];
				if (_start)//一开始是空的
				{
					//memcpy(tmp,_start,sz*sizeof(int));
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
				size_t newcapacity = (capacity() == 0) ? 4 : capacity() * 2;
				reserve(newcapacity);
			}

			*_finish = x;
			++_finish;
		}



		void pop_back()
		{//空的时候不可以pop
			assert(!empty());
			--_finish;
		}

		void insert(iterator& pos, const T& x)
		{
			if (_finish == _endofstorage)
			{//增容
				size_t len = pos - _start;
				size_t newcapacity = (capacity() == 0) ? 4 : capacity() * 2;
				reserve(newcapacity);
				//更新pos，解决pos增容后失效
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) =* end;
				--end;
			}
			*pos = x;
			++_finish;
			pos += 1;
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
	//针对const对象的输出vector
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

	void TestVector3()
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

		auto pos = find(v.begin(), v.end(), 3);
		// 在pos -- 3的之前插入
		v.insert(pos, 30);
		// insert以后，pos就是失效了
		// 1、pos指向位置的意义变了，pos不是指向3
		// 2、pos成了野指针
		PrintVector(v);
	}


	void TestVector4()
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
void TestVector5()
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

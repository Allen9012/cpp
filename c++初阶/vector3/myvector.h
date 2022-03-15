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
		//���캯��
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

			// ��ģ��ĳ�Ա���������������Ǻ���ģ��
			// ��ʹ��iterator�����������ᵼ�³�ʼ���ĵ���������[first,last)ֻ����vector�ĵ�����
			// ��������������������������[first,last)���������������ĵ�����
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


		//��������,���
		// v2(v1)
			vector(const vector<T>& v)
				: _start(nullptr)
				, _finish(nullptr)
				, _endofstorage(nullptr)
			{//��һ����Ŀռ�
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
			vector<T>& operator=( vector<T> v)//��һ��const��ֹ�������Ķ�����const��
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
			
		//����
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
		
		void resize(size_t n , T val= T() )//Ĭ�ϳ�ʼ���ɹ��캯��
		{//�µ�С
			if (n < size())
			{
				_finish = _start + n;
			}
			else 
			{//���м�
				if (n < capacity())
				{
					while (_finish < _start + n)
					{
						*_finish = val;
						++_finish;
					}
				}
				else
				{//����capacity
					reserve(n);//���¿ռ䣬����
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
				size_t sz = size();//�������Ҫ
				T* tmp = new T[n];
				if (_start)//һ��ʼ�ǿյ�
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
		{//�յ�ʱ�򲻿���pop
			assert(!empty());
			--_finish;
		}

		void insert(iterator& pos, const T& x)
		{
			if (_finish == _endofstorage)
			{//����
				size_t len = pos - _start;
				size_t newcapacity = (capacity() == 0) ? 4 : capacity() * 2;
				reserve(newcapacity);
				//����pos�����pos���ݺ�ʧЧ
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
	//���const��������vector
	void PrintVector(const Con& v)
	{
		//Con::const_iterator it = v.begin();
		auto it = v.begin();
		while (it != v.end())
		{
			// *it += 1;  ֻ�ܶ�������д
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
		// ��pos -- 3��֮ǰ����
		v.insert(pos, 30);
		// insert�Ժ�pos����ʧЧ��
		// 1��posָ��λ�õ�������ˣ�pos����ָ��3
		// 2��pos����Ұָ��
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

		// ɾ�������е�ż��
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

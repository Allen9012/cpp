
#pragma once
#include <assert.h>
//简洁版


//namespace allen
//{
//	//本质就像是管理字符串的顺序表数组，注意
//	//该数组结尾时'\0'，所以说strlen要+1
//
//	class string
//	{
//	public:
//		//构造函数	
//string(const char* str = "")
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		}
//
//
//		//析构函数
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		//拷贝构造函数   // s2(s1)
//		//1.传统写法
//		//string(const string& s)
//		//	: _str(new char[strlen(s._str) + 1])
//		//{
//		//	strcpy(_str, s._str);
//		//}
//
//		//2.现代写法
//		string(const string& s)
//			:_str(nullptr)
//			//不用strlen可以赋值nullptr,但是一定要有这句，因为_str是随机值的话交还给tmp
//			//之后调用析构，不能析构随机值
//		{
//			string tmp(s._str);
//			swap(_str, tmp._str);
//		}
//
//		//赋值运算符重载   s1 = s3
//		// 
//		////1.传统，可能内存不够的时候，导致报异常，这将把原来的_str销毁
//		//string& operator=(const string& s)
//		//{//防止自己给自己赋值
//		//	if (this != &s)
//		//	{
//		//		delete[]_str;//不能先赋值，要先delete销毁
//		//		_str = new char[strlen(s._str) + 1];
//		//		strcpy(_str, s._str);
//		//	}
//		// return *this;
//		//}
//
//		//2.现代,交换赋值法
//		string& operator=(string s)
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//
//		////现代写法二，可以dan没必要
//		/*string& operator=(const string& s)
//		{
//			if (this!=&s)
//			{
//				string tmp(s);
//				swap(_str, tmp._str);
//				return *this;
//			}
//		}*/
//
//		const char* c_str()
//		{
//			return _str;
//		}
//
//	private:
//		char* _str;
//
//	};
//
//	void Test_string1()
//	{
//		string s1("hello world");
//		string s2(s1);
//
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//
//		string s3("hello bit");
//		s1 = s3;
//		cout << s1.c_str() << endl;
//		cout << s3.c_str() << endl;
//
//		printf("%p\n", s1.c_str());
//		s1 = s1;
//		printf("%p\n", s1.c_str());
//	}
//}


//增删查改版

namespace allen
{

	class string
	{
	public:
		//迭代器
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + size();
		}


		//构造函数	
		string(const char* str = " ")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}


		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		
		//交换函数有点重复，自己写一个
	
		void swap(string& s)
		{//域作用限定符，为了区分，左边没有域名，指全局
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		//拷贝构造函数   // s2(s1)
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			,_capacity(0)
			//不用strlen可以赋值nullptr,但是一定要有这句，因为_str是随机值的话交还给tmp
			//之后调用析构，不能析构随机值
		{
			string tmp(s._str);
			swap(tmp);
		}

		//赋值运算符重载   s1 = s3
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}

		//返回
		const char* c_str()  const
		{
			return _str;
		}
		 size_t size() const
		{
			return _size;
		}

		
		//只读
		const char& operator[](size_t i) const
		{
			assert(i < _size);

			return _str[i];
		}
		// 可读，可写
		char& operator[](size_t i)
		{
			assert(i < _size);

			return _str[i];
		}

		//开空间，扩展capacity
		void reserve(size_t n)
		{// 如果新容量大于旧容量，则开辟空间
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				
				// 释放原来旧空间,然后使用新空间
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		//开空间+初始化，扩展capacity,并且初始化空间，size也要动
		void resize(size_t n,char val='\0')
		{
			if (n > _size)
			{
				// 如果n大于底层空间大小，则需要重新开辟空间
				if (n > _capacity)
				{
					reserve(n);
				}
				memset(_str + _size, val, n - _size);//在原来之后，直到n之前，换为val
			}
			_size = n;
			_str[n] = '\0';
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size] = ch;//原\0
			_str[_size+1] = '\0';
			_size++;	
		}

		void append(const char* str)
		{
			//增2倍可能不够用
			size_t len = _size + strlen(str); 
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str + _size, str);//用的很巧_str+size，指针直接指向\0
			_size = len;
		}
		


		bool operator<(const string& s)
		{}
		bool operator>(const string& s)
		{}
		bool operator<=(const string& s)
		{}
		bool operator>=(const string& s)
		{}
		bool operator==(const string& s)
		{}
		bool operator!=(const string& s)
		{}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	};




	void Test_string1()
	{
		string s1("hello world");
		string s2(s1);

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string s3("hello bit");
		s1 = s3;
		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;

		printf("%p\n", s1.c_str());
		s1 = s1;
		printf("%p\n", s1.c_str());
	}

	void Test_string2()
	{
		//倘若使用模板的话，用了三次深拷贝，效率低下，不选择 
		string s1("hello world");
		string s2(s1);
		string s3("hello bit");
		swap(s1, s3);
		s1.swap(s3);//效率高，推荐这个
	}
	void f(const string& s)
	{
		// ....
		for (size_t i = 0; i < s.size(); ++i)
		{
			//s[i] += 1;
			cout << s[i] << " ";
		}
		cout << endl;
	}

	//
	void Test_string3()
	{
		string s1("hello world");
		s1[0] = 'x';
		cout << s1[1] << endl;
		//cout << s1[100] << endl;
		cout << s1.c_str() << endl;

		f(s1);

		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
	}

	//测试迭代器
	void Test_string4()
	{
		//迭代器不一定是指针
		string s1("hello world");
		string::iterator it = s1.begin();
		while (it !=s1.end())
		{
			cout << *it << " ";
			++it;
		}
		//本质上就是替换成迭代器
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void Test_string5()
	{
		string s1("hello world");
		s1 += '#';
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;

		s1 += "xyz";
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;

		s1 += "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1";
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}
	void Test_string6()
	{
		string s1 = "Hello";
		s1 += "!";
		s1.resize(11);
	}
}
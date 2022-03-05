#pragma once
#include <assert.h>
#include<iostream>
#include <time.h>
#include <string>
//增删查改版

namespace allen
{

	class string
	{
	public:
		//迭代器
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		const_iterator begin() const
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator end() const
		{
			return _str + _size;
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
				//strcpy(tmp, _str);//问题在于把'\0'吃了
				strncpy(tmp, _str, _size + 1);//这里+1就是把\0拷进去
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
			/*if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			++_size;*/

			insert(_size, ch);
		}

		void append(const char* str)
		{
			/////增2倍可能不够用
			//size_t len = _size + strlen(str); 
			//if (len > _capacity)
			//{
			//	reserve(len);
			//}
			//strcpy(_str + _size, str);//用的很巧_str+size，指针直接指向\0
			//_size = len;
				insert(_size, str);
			
		}
		
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			// 不推荐
			/*int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}*/

			// 或者还可以指针
			/*size_t end = _size+1;
			while (end > pos)
			{
				_str[end] = _str[end]-1;
				--end;
			}*/

			//这个最好，指针倒是不存在什么
			char* end = _str + _size;
			while (end >= _str + pos)
			{
				*(end + 1) = *end;
				--end;
			}

			_str[pos] = ch;
			_size++;

			return *this;
		}

		//pos之前
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			// 挪动数据
			char* end = _str + _size;	
			while (end >= _str + pos)//到指定位置  
			{
				*(end + len) = *end;
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		//删
		//可以返回void
		string& erase(size_t pos=0, size_t len=npos)
		{
			assert(pos < _size);
			size_t leftLen = _size - pos;//剩下的长度，不是左边的长度
			if (len >= leftLen)//pos后删除光
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else //删除中间部分
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}		
			return *this;
		}

		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}

		size_t find(char ch, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		                      //从哪里开始去找
		size_t find(const char *str, size_t pos = 0)  const
		{
			assert(pos <_size);
			const char* ret = strstr(_str+pos, str);
			if (ret)
			{
				return ret - _str;
			}
			else
			{
				return npos;
			}
		}

		

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
		static const size_t npos;
	};

	const size_t string::npos = -1;//对const的定义

	//运算符的重载
	inline bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	inline bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	inline bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	inline bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	inline bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}

	inline bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}

		return in;
	}

	istream& getline(istream& in, string& s)
	{
		s.clear();

		char ch;
		ch = in.get();
		while (ch != '\n')
		{
			s += ch;
			ch = in.get();
		}

		return in;
	}


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
		string s1("hello");
		s1 += '!';

		s1.resize(8, 'x');
		cout << s1.c_str() << endl;

		s1.resize(15, 'y');
		cout << s1.c_str() << endl;

		s1.resize(3);
		cout << s1.c_str() << endl;
	}
	void Test_string7()
	{
		string s1("hello");
		s1.insert(2, 'x');
		cout << s1.c_str() << endl;

		s1.insert(0, 'y');
		cout << s1.c_str() << endl;

		s1.insert(0, "!!!!");
		cout << s1.c_str() << endl;

		s1 += '!';
		cout << s1.c_str() << endl;

		s1 += "world";
		cout << s1.c_str() << endl;

		s1.erase(2, 5);
		cout << s1.c_str() << endl;

		s1.erase(2);
		cout << s1.c_str() << endl;
	}
	void Test_string8()
	{
		string s1("hello world");
		cout << s1.find('x') << endl;
		cout << s1.find('o') << endl;

		cout << s1.find("wor") << endl;
		cout << s1.find("worx") << endl;

		string s2("hello world");
		s2.resize(20);
		s2 += "!!!";//发现bug

		//cin >> s2 >> s1;
		cout << s2 << endl;
		/*cout << s1 << endl;

		string line;
		getline(cin, line);
		cout << line << endl;*/
	}

}
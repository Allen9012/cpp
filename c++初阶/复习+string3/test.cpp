#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//namespace bit
//{
//	class string
//	{
//	public:
//		string(const char* str)
//		{
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//
//		size_t size()
//		{
//			return strlen(_str);
//		}
//
//	private:
//		char* _str;
//	};
//}

//int main()
//{
//	bit::string s("hello world");
//	cout << s[2] << endl;
//	cout << s.operator[](2) << endl;
//	//s[2] += 1;
//
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		cout << s[i] << " ";
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		s[i] += 1;
//	}
//
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		cout << s[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

class B
{
public:
	/*B()
		:_b(0)
		{}
		*/
	B(int b = 0)
		:_b(b)
	{}

	B(const B& bb)
		:_b(bb._b)
	{
		cout << "B(const B& bb)" << endl;
	}

	B& operator=(const B& bb)
	{
		cout << "B& operator=(const B& bb)" << endl;

		if (this != &bb)
		{
			_b = bb._b;
		}

		return *this;
	}
private:
	int _b;
};

class C
{
public:
	C(int c1 = 0, int c2 = 0)
		:_c1(c1)
		, _c2(c2)
	{}
private:
	int _c1;
	int _c2;
};

class A
{

private:
	// 默认生成构造函数对基本类型成员变量是不处理的。
	// (有些比较新的编译器也有可能会初始化成0，但是大多数编译器都不会处理，我们要当成不初始化)

	// 基本类型不处理，是C++语法设计的一个小缺陷
	// 所以C++11，给出了补充语法：声明缺省值，来补足这里的缺陷
	int _a1 = 1; // 这里不是初始化，这里是给缺省值
	int _a2 = 2;

	// 默认生成构造函数对自动类型的成员回去调用它的默认构造函数初始化
	//B _b = B(1);
	B _b = 1;

	//C _c = C(1, 1);
	C _c = { 1, 1 };
};

class D
{
public:
	// D的构造函数中，在哪里调用的B的默认构造函数呢？
	// 对象定义的时候自动调用构造函数，
	// 构造函数的初始化列表可以认为是成员变量定义初始化的地方
	// 初始化列表，你显示的写或者不写，都在走一遍
	D()
	{}

private:
	int _d = 0;    // 成员声明
	B	_b;
};

// 有三种成员变量必须在初始化列表初始化
// 1、const  2、引用   3、没有默认构造函数的成员对象

//int main()
//{
//	//A aa;
//
//	//D d;   // 对象定义的时候，成员也作为对象的一部分定义出来了
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////
// 析构函数
class Date
{
public:
	//~Date()
	//{
	//	 // ... 这个类没有什么资源需要清理，
	//	 // 所以其实它不写析构函数，编译器自动生成就可以
	//}
private:
	int _year = 0;
	int _month = 1;
	int _day = 1;

	B _b = 10;
};

namespace bit
{
	class string
	{
	public:
		string(const char* str = "")//不能缺省nullptr
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		// s2(s1)
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		// s1 = s3
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}

			return *this;
		}

		char& operator[](size_t i)
		{
			return _str[i];
		}

		size_t size()
		{
			return strlen(_str);
		}

		~string()
		{
			cout << "~string()" << endl;
			delete[] _str;
			_str = nullptr;
		}
	private:
		char* _str;
	};
} 

class F
{
private:
	// 默认生成的析构函数并不是什么事情都不做
	// 基本类型不处理，自定义类型，会去调用他的析构函数
	int _a;
	bit::string _s;
};

//int main()
//{
//	Date d;  // 析构函数不是完成对象的销毁
//			 // 这个对象是存在函数栈帧里面的，函数结束，栈帧销毁，对象就销毁了
//
//	bit::string s1("hello  world"); 
//	// 针对s1有两块空间要销毁
//	// 第一：s1对象本身，他是函数结束，栈帧销毁，他就销毁
//	// 第二：s1里面的_str指向的堆上的空间，他是析构函数清理的
//
//	//bit::string s2;
//	//F ff;
//}

int main()
{
	// 浅拷贝(值拷贝)的类
	Date d1;
	Date d2(d1);
	Date d3 = d1;
	Date d4;

	d4 = d1;

	bit::string s1("hello world");
	bit::string s2(s1);
	bit::string s3("hello bit");

	s1 = s3;

	return 0;
}
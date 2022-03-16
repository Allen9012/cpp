#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include "string.h"
#include "stringT.h"


// 四个默认成员函数
// 1、他们的作用和用法
// 2、常见的一些特性及用法
// 3、我们不写，编译器默认生成的做了些什么事情

class A
{
public:
	A(int a = 0)
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}

	A& operator=(const A& a)
	{
		cout << "A& operator=(const A& a)" << endl;

		return *this;
	}

	void print()
	{
		cout << "print A" << endl;
	}
};

A f2()
{
	static A aa;
	return aa;
}
void f11(A aa)

{}

void f1(const A& aa)
{}

//A aa;

// 《深度探索C++对象模型》


//int main()
//{
//	/*A a1;
//	f1(a1);*/
//
//	//A(); // 匿名对象
//	//A().print();
//
//	// 编译器优化行为，在同一个的表达式中，产生一个临时对象
//	// 再用临时对象去拷贝构造一个对象，那么编译器可能会优化
//	// 两个对象合二为一，直接构造出一个对象
//	// (C++标准并没有规定要优化，看编译器，一般新一点编译器都会优化)
//	//f1(A());
//
//	// A a2(2);
//	// A a3 = 3; // 隐式类型的转换，A tmp(3)， 再用tmp拷贝构造a3， 但是编译器优化了，直接构造
//
//	f2();
//	//跟前面一样，在一个表达式中，连续多个构造函数，可能会被编译器优化，优化成一次
//	A a4 = f2();
//	A a4;
//	a4 = f2();
//
//	return 0;
//}

//A f(A aa)
//{
//	A copy1(aa);
//	A copy2 = copy1;
//
//	return copy2;
//}
//
//int main()
//{
//	A a;
//	A ret = f(f(a));
//
//	return 0;
//}

//int main()
//{
//	//bit::test_string1();
//	//bit::test_string2();
//	//bit::test_string3();
//	bit::test_string4();
//
//
//	return 0;
//}


int main()
{
	allen::Test_string6();
	return 0;
}

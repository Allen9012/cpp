#include <iostream>
#include "assert.h"
#include <string>
#include<vector>
using namespace  std;
#include"BloomFilter.h"


//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B
//{
//public:
//	B()
//	{
//		cout << "B()" << endl;
//	}
//
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//};
//class Widget
//{
//public:
//	Widget()
//	{
//		cout << "构造" << endl;
//	}
//
//	Widget(const Widget& w)
//	{
//		cout << "拷贝构造" << endl;
//	}
//	~Widget()
//	{
//		cout << "析构" << endl;
//	}
//	Widget& operator=(Widget& w)
//	{
//		cout << "赋值运算符重载" << endl;
//		return *this;
//	}
//};
//
//Widget f(Widget u)
//
//{
//
//	Widget v(u);
//
//	Widget w = v;
//
//	return w;
//
//}
//class A
//{
//public:
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//class  B
//{
//public:
//
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//};
//class C {
//public:
//	~C()
//	{
//		cout << "~C()" << endl;
//	}
//};
//class D {
//public:
//	~D()
//	{
//		cout << "~D()" << endl;
//	}
//};
//C c;

int main()
{
	//A a;
	//B b;

	//Widget x;
	//Widget y = f(f(x));
	//A a;
	//B b;
	//static D d;
	TestBloomFilter();
	return 0;
}
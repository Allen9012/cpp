#define _CRT_SECURE_NO_WARNINGS 1;

#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <functional>
using namespace std;

#include "SmartPtr.h"

//int div() throw (invalid_argument)
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//
//	return a / b;
//}
//
//void f1()
//{
//	int* p = new int;
//	try
//	{
//		cout << div() << endl;
//	}
//	catch (...)
//	{
//		delete p;
//		throw;
//	}
//
//	delete p;
//}
//
//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


int div() throw (...)
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");

	return a / b;
}

void f1()
{
	SmartPtr<int> sp1(new int);
	*sp1 = 10;

	SmartPtr<pair<string, int>> sp2(new pair<string, int>("sort", 1));
	sp2->first;
	sp2->second;

	cout << div() << endl;

	//delete p;
}

//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	//bit::test_auto_ptr();
//	//bit::test_shared_ptr();
//	//bit::test_multithread_shared_ptr();
//	//bit::test_shared_ptr_cycle_ref();
//	allen::test_shared_ptr_deletor();
//
//	return 0;
//}

//
//void main()
//{
//	int i = 1;
//	// 隐式类型转换 -- 相近类似，类型的意义类似
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	// 显示的强制类型转换 -- 不相近类似，类型意义不一样
//	int address = (int)p;
//
//	printf("%x, %d\n", p, address);
//}

// 1、static_cast 相近类型
//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	//int* p = &a;
//	//// 显示的强制类型转换 -- 不相近类似，类型意义不一样
//	//int address = static_cast<int>(p);
//
//	return 0;
//}

// 2、reinterpret_cast -- 无关类型的转换

typedef void(*FUNC)();
int DoSomething(int i)
{
	cout << "DoSomething:" << i << endl;
	return 0;
}

void Test()
{
	//
	// reinterpret_cast可以编译器以FUNC的定义方式去看待DoSomething函数
	// 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用
	// C++不保证所有的函数指针都被一样的使用，所以这样用有时会产生不确定的结果
	//
	FUNC f = reinterpret_cast<FUNC>(DoSomething);
	f();
}

//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	int* p = &a;
//	// 显示的强制类型转换 -- 不相近类似，类型意义不一样
//	int address = reinterpret_cast<int>(p);
//
//	Test();
//
//	return 0;
//}

// const_cast 转换时去掉const属性
//void main ()
//{
//	volatile const int a = 2; 
//	//int* p = (int*)&a; // const int*
//	int* p = const_cast<int*>(&a); // const int*
//	*p = 3;
//
//	cout << a << endl;
//	cout << *p << endl;
//}

class A
{
public:
	virtual void f() {}

	int _a;
};

class B : public A
{
public:
	int _b;
};

// 父类A指针，我想把A转成子类B的指针 -- 向下转
void fun(A* pa)
{
	// 不安全的
	B* pb1 = (B*)pa;
	//pb1->_b = 10;

	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回nullptr
	B* pb2 = dynamic_cast<B*>(pa); // 安全的
	if (pb2)
	{
		pb1->_b = 10;
	}

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}

//int main()
//{
//	A a;
//	B b;
//	fun(&a);
//	fun(&b);
//
//	return 0;
//}
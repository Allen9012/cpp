#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//int Add(int left, int right)
//{
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2);
//
//	return 0;
//}

//int main()
//{
//	// 一个变量可以有多个别名
//	int a = 0;
//	int& b = a;
//	int& c = a;
//	int& d = b;
//
//	// 引用必须初始化
//	int& r = a;
//	int x = 10;
//
//	// 不是让r变成x的别名，而是把x赋值给r
//	r = x;
//
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	// int& ra = a;      //->ra引用a属于权限放大，所以不行 
//	const int& ra = a;
//
//	int b = 10;
//	int& rb = b;
//	const int& crb = b;  // -》crb引用b属于权限缩小，所以可以
//
//	int c = 10;
//	double d = 1.11;
//	d = c; // 隐式类型转换
//
//	//double& rc = c;
//	const double& rc = c;
//
//	return 0;
//}

//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	const int& ret = Add(1, 2);
//	return 0;
//}

// 实际中，如果出了函数作用域，返回变量就不存在了，不能用引用返回
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(5, 7);
//	cout << ret << endl;
//	printf("hello world\n");
//	cout << ret << endl;
//
//
//	return 0;
//}

//int& Add(int a, int b)
//{
//	static int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(5, 7);
//	printf("hello world\n");
//	cout << ret << endl;
//	return 0;
//}

//int main()
//{
//	// 越界是不一定报错的
//	int a[10] = { 1, 2, 3 };
//	// 越界读基本不报错，因为编译检查不出来
//	cout << a[10] << endl;
//	cout << a[11] << endl;
//	cout << a[12] << endl;
//	cout << a[13] << endl;
//
//	// 越界写，可能会报错
//	// 系统查越界使用的抽查，就像现实中查酒驾一样
//	//a[10] = 0;  // 检查了
//	//a[11] = 0;  // 检查了
//	a[12] = 0;    // 没检查
//	//a[13] = 0;
//	a[14] = 0;
//
//
//
//	return 0;
//}

#include <time.h>
struct A{ int a[10000]; };

void TestFunc1(A a){}

void TestFunc2(A& a){}

void TestRefAndValue()
{
	A aa;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(aa);
	size_t end1 = clock();

	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(aa);
	size_t end2 = clock();

	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

#include <time.h>
struct A { int a[10000]; };
A a;
// 值返回
A TestFunc1() { return a; }
// 引用返回
A& TestFunc2() { return a; }
void TestReturnByRefOrValue()
{
	// 以值作为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();
	// 以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();
	// 计算两个函数运算完成之后的时间
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}
int main()
{
	TestReturnByRefOrValue();
}
int main()
{
	TestRefAndValue();
 }
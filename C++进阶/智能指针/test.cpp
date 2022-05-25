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
//		throw invalid_argument("��0����");
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
		throw invalid_argument("��0����");

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
//	// ��ʽ����ת�� -- ������ƣ����͵���������
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	// ��ʾ��ǿ������ת�� -- ��������ƣ��������岻һ��
//	int address = (int)p;
//
//	printf("%x, %d\n", p, address);
//}

// 1��static_cast �������
//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	//int* p = &a;
//	//// ��ʾ��ǿ������ת�� -- ��������ƣ��������岻һ��
//	//int address = static_cast<int>(p);
//
//	return 0;
//}

// 2��reinterpret_cast -- �޹����͵�ת��

typedef void(*FUNC)();
int DoSomething(int i)
{
	cout << "DoSomething:" << i << endl;
	return 0;
}

void Test()
{
	//
	// reinterpret_cast���Ա�������FUNC�Ķ��巽ʽȥ����DoSomething����
	// ���Էǳ���BUG������ת������ָ��Ĵ����ǲ�����ֲ�ģ����Բ�����������
	// C++����֤���еĺ���ָ�붼��һ����ʹ�ã�������������ʱ�������ȷ���Ľ��
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
//	// ��ʾ��ǿ������ת�� -- ��������ƣ��������岻һ��
//	int address = reinterpret_cast<int>(p);
//
//	Test();
//
//	return 0;
//}

// const_cast ת��ʱȥ��const����
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

// ����Aָ�룬�����Aת������B��ָ�� -- ����ת
void fun(A* pa)
{
	// ����ȫ��
	B* pb1 = (B*)pa;
	//pb1->_b = 10;

	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�nullptr
	B* pb2 = dynamic_cast<B*>(pa); // ��ȫ��
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
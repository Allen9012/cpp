#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include "string.h"
#include "stringT.h"


// �ĸ�Ĭ�ϳ�Ա����
// 1�����ǵ����ú��÷�
// 2��������һЩ���Լ��÷�
// 3�����ǲ�д��������Ĭ�����ɵ�����Щʲô����

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

// �����̽��C++����ģ�͡�


//int main()
//{
//	/*A a1;
//	f1(a1);*/
//
//	//A(); // ��������
//	//A().print();
//
//	// �������Ż���Ϊ����ͬһ���ı��ʽ�У�����һ����ʱ����
//	// ������ʱ����ȥ��������һ��������ô���������ܻ��Ż�
//	// ��������϶�Ϊһ��ֱ�ӹ����һ������
//	// (C++��׼��û�й涨Ҫ�Ż�������������һ����һ������������Ż�)
//	//f1(A());
//
//	// A a2(2);
//	// A a3 = 3; // ��ʽ���͵�ת����A tmp(3)�� ����tmp��������a3�� ���Ǳ������Ż��ˣ�ֱ�ӹ���
//
//	f2();
//	//��ǰ��һ������һ�����ʽ�У�����������캯�������ܻᱻ�������Ż����Ż���һ��
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

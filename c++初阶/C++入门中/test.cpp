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
//	// һ�����������ж������
//	int a = 0;
//	int& b = a;
//	int& c = a;
//	int& d = b;
//
//	// ���ñ����ʼ��
//	int& r = a;
//	int x = 10;
//
//	// ������r���x�ı��������ǰ�x��ֵ��r
//	r = x;
//
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	// int& ra = a;      //->ra����a����Ȩ�޷Ŵ����Բ��� 
//	const int& ra = a;
//
//	int b = 10;
//	int& rb = b;
//	const int& crb = b;  // -��crb����b����Ȩ����С�����Կ���
//
//	int c = 10;
//	double d = 1.11;
//	d = c; // ��ʽ����ת��
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

// ʵ���У�������˺��������򣬷��ر����Ͳ������ˣ����������÷���
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
//	// Խ���ǲ�һ�������
//	int a[10] = { 1, 2, 3 };
//	// Խ���������������Ϊ�����鲻����
//	cout << a[10] << endl;
//	cout << a[11] << endl;
//	cout << a[12] << endl;
//	cout << a[13] << endl;
//
//	// Խ��д�����ܻᱨ��
//	// ϵͳ��Խ��ʹ�õĳ�飬������ʵ�в�Ƽ�һ��
//	//a[10] = 0;  // �����
//	//a[11] = 0;  // �����
//	a[12] = 0;    // û���
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
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(aa);
	size_t end1 = clock();

	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(aa);
	size_t end2 = clock();

	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

#include <time.h>
struct A { int a[10000]; };
A a;
// ֵ����
A TestFunc1() { return a; }
// ���÷���
A& TestFunc2() { return a; }
void TestReturnByRefOrValue()
{
	// ��ֵ��Ϊ�����ķ���ֵ����
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();
	// ��������Ϊ�����ķ���ֵ����
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();
	// �������������������֮���ʱ��
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
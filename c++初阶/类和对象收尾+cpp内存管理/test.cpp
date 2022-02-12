#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <iostream>
using namespace std;

class B
{
public:
	B(int x = 0)
		:_x(x)
	{
		cout << "B()" << endl;
	}

	int _x;
};
//
//// C++11
class A
{
public:
	// B�ͽ���A���ڲ���
	class C // C��������A����Ԫ��
	{
	public:
		void foo(const A& a)
		{
			cout << a._a << endl;
			cout << a._p << endl;
			cout << _n << endl;
		}

		int _c;
	};

	A(int a = 1, int* p = nullptr)
		:_a(a)
		, _p(p)
	{}

private:
	// ���� ��= ȱʡֵ
	int _a = 0;
	int* _p = nullptr;
	int* arr = (int*)malloc(sizeof(int) * 10);
	B _b = 6;

	static int _n;
};
//
//int A::_n = 0;
//
//int main()
//{
//	A aa;  // Ĭ�Ϲ��캯��
//	A::C cc;
//	cc.foo(aa);
//
//	return 0;
//}

// ��C���Զ���һ��ջ
// ��C++����һ��ջ�Աȸ���һ��



//struct StackC
//{
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//void StackInit(struct StackC* ps, int n)
//{}
//void StackDestory(struct StackC* ps)
//{}
//
//void StackPush(struct StackC* ps, int x)
//{}
//
//void TestStackC()
//{
//	struct StackC st;
//	StackInit(&st, 4);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//
//	st._a[st._top++] = 5; // ���Ϸ��Ĳ��룬��Ϊ����Խ����
//
//	StackDestory(&st);
//}
//
//class StackCPP
//{
//public:
//	StackCPP(int n = 4)
//	{
//		// ...
//	}
//
//	~StackCPP()
//	{
//		// ...
//	}
//
//	void Push(int x)
//	{
//		// ...
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//void TestStackCPP()
//{
//	StackCPP st;
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//	//st._a;	
//}
//
//int main()
//{
//	return 0;
//}

//void f2()
//{
//	int b = 0;
//	cout << "b:" << &b << endl;
//}
//
//void f1()
//{
//	int a = 0;
//	cout <<"a:" <<&a << endl;
//
//	f2();
//}
//
//int main()
//{
//	f1();
//	for (int i = 0; i < 3; ++i)
//	{
//		int* p1 = (int*)malloc(4);
//		int* p2 = (int*)malloc(4);
//		cout << "p1:" << p1 << endl;
//		cout << "p2:" << p2 << endl;
//
//		free(p1);
//	}
//
//
//
//	return 0;
//}

//int main()
//{
//	void* p1 = malloc(10);
//	void* p2 = realloc(p1, 200);
//
//	cout << p1 << endl;
//	cout << p2 << endl;
//
//
//	return 0;
//}

//int main()
//{
//	// new/delete��malloc/free �����������û���κβ��ֻ���÷���һ��
//	// ����һ��10��int������
//
//	// new/delete new[]/delete[]һ��Ҫƥ�䣬������ܻ����
//	int* p1 = (int*)malloc(sizeof(int) * 10);
//	int* p2 = new int[10];
//
//	free(p1);
//	delete[] p2;
//
//	// ���뵥��int����
//	int* p3 = (int*)malloc(sizeof(int));
//	int* p4 = new int;
//
//	free(p3);
//	delete p4;
//
//	return 0;
//}

struct ListNode
{
	//struct ListNode* _next; //C
	ListNode* _next;
	ListNode* _prev;
	int _val;

	ListNode(int val = 0)
		:_next(nullptr)
		, _prev(nullptr)
		, _val(val)
	{
		cout << "ListNode(int val = 0)" << endl;
	}

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

int main()
{
	// c mallocֻ�ǿ��ռ� free�ͷſռ�
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	free(n1);

	// cpp new ����Զ������ͣ����ռ�+���캯����ʼ��
	//     delete ����Զ������ͣ������������� + �ͷſռ�
	ListNode* n2 = new ListNode(5);   // -> �൱��c������BuyListNode(5) 
	delete n2;

	struct ListNode* arr3 = (struct ListNode*)malloc(sizeof(struct ListNode)*4);
	free(arr3);

	ListNode* arr4 = new ListNode[4]{1,2,3,4};
	delete[] arr4;
	// delete arr4; ��ƥ������

	int* p1 = new int(0);
	int* p2 = new int[4]{ 1, 2, 3, 4 };

	return 0;
}

//// malloc/new�����������Ŀռ䣿
//// ���malloc��4G�Ŀռ䣿
//int main()
//{
//	// 1byte == 8bit
//	// 1KB = 1024byte
//	// 1MB = 1024KB
//	// 1GB = 1024MB
//	// 1TB = 1024GB
//	void* p1 = malloc(0xffffffff);
//
//	cout << p1 << endl;
//
//	return 0;
//}
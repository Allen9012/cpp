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
	// B就叫做A的内部类
	class C // C天生就是A的友元类
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
	// 声明 《= 缺省值
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
//	A aa;  // 默认构造函数
//	A::C cc;
//	cc.foo(aa);
//
//	return 0;
//}

// 用C语言定义一个栈
// 用C++定义一个栈对比感受一下



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
//	st._a[st._top++] = 5; // 不合法的插入，因为可能越界了
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
//	// new/delete和malloc/free 针对内置类型没有任何差别，只是用法不一样
//	// 申请一个10个int的数组
//
//	// new/delete new[]/delete[]一定要匹配，否则可能会出错
//	int* p1 = (int*)malloc(sizeof(int) * 10);
//	int* p2 = new int[10];
//
//	free(p1);
//	delete[] p2;
//
//	// 申请单个int对象
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
	// c malloc只是开空间 free释放空间
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	free(n1);

	// cpp new 针对自定义类型，开空间+构造函数初始化
	//     delete 针对自定义类型，析构函数清理 + 释放空间
	ListNode* n2 = new ListNode(5);   // -> 相当于c语言中BuyListNode(5) 
	delete n2;

	struct ListNode* arr3 = (struct ListNode*)malloc(sizeof(struct ListNode)*4);
	free(arr3);

	ListNode* arr4 = new ListNode[4]{1,2,3,4};
	delete[] arr4;
	// delete arr4; 不匹配会崩溃

	int* p1 = new int(0);
	int* p2 = new int[4]{ 1, 2, 3, 4 };

	return 0;
}

//// malloc/new最大能申请多大的空间？
//// 如何malloc出4G的空间？
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
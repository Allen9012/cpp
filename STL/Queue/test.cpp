#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <queue>
#include <functional>

using std::cout;
using std::endl;
using namespace std;

#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"

void test_stack()
{
	//allen::stack<int> st;
	allen::stack<int, std::vector<int>> st;
	//allen::stack<int, std::list<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void test_queue()
{
	//std::queue<int> q;
	//allen::queue<int, list<int>> q;
	//allen::queue<int, vector<int>> q; // 报错
	allen::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void test_priority_queue()
{
	// 默认是一个大堆，默认大的优先级高 less
	allen::priority_queue<int> pq;

	// 变成小堆，小的优先级高怎么处理 greater
	//std::priority_queue<int, vector<int>, std::greater<int>> pq;



	// 默认是一个大堆，默认大的优先级高 less
	//allen::priority_queue<int> pq;

	//// 变成小堆，小的优先级高怎么处理 greater
	////allen::priority_queue<int, vector<int>, bit::greater<int>> pq;
	pq.push(3);
	pq.push(5);
	pq.push(6);
	pq.push(1);
	pq.push(4);
	pq.push(3);
	pq.push(6);
    pq.push(10);
	pq.push(3);

	//int k = 5;
	while (!pq.empty() /*&& k-- */ )
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

// 仿函数 -- 函数对象   这个类的对象可以像函数一样去使用
struct LessInt
{
	bool operator()(int l, int r)
	{
		return l < r;
	}
};

template<class T>
struct Less
{
	bool operator()(const T& l, const T& r)
	{
		return l < r;
	}
};

bool LessFunc1(int l, int r)
{
	return l < r;
}

int main()
{
	//test_stack();
	//test_queue();
	test_priority_queue();

	//cout << LessFunc1(1, 2) << endl;;

	//LessInt LessFunc2;
	//cout << LessFunc2(3, 4) << endl;
	 //转换成下面的调用
	//cout << LessFunc2.operator()(3, 4) << endl;

	//Less<double> less;
	//less(3.3, 4.4);


	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <queue>

using std::cout;
using std::endl;

#include "Stack.h"

void test_stack()
{
	//bit::stack<int> st;
	allen::stack<int, std::vector<int>> st;
	//bit::stack<int, std::list<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	// get data
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void test_queue()
{
	std::queue<int> q;
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

int main()
{
	test_stack();
	test_queue();

	return 0;
}
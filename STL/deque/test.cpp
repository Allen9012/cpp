#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <queue>
#include <functional>
#include <deque>

using std::cout;
using std::endl;
using std::deque;

void test_deque()
{
	deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);
	dq.push_front(1);
	dq.push_front(2);
	dq.push_front(3);
	dq.push_front(4);

	for (size_t i = 0; i < dq.size(); ++i)
	{
		cout << dq[i] << " ";
	}
	cout << endl;

	deque<int>::iterator it = dq.begin();
	while (it != dq.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : dq)
	{
		cout << e << " ";
	}
	cout << endl;
}


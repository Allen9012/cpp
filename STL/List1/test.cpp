#define _CRT_SECURE_NO_WARNINGS 1
#include <list>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//#include "List.h"
#include "myList.h"
void test_list1()
{
	list<int> lt;
	lt.push_back(10);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	// 遍历方式1
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 遍历方式2
	// g++ test_list1.cpp -std=C++11
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	int a[] = { 16, 2, 77, 29 };
	list<int> lt1(a, a + 4); //list (InputIterator first, InputIterator last)
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	// < 升序 默认
	// > 降序
	vector<int> v(a, a + 4); // { 16, 2, 77, 29 };
	sort(v.begin(), --v.end());
	sort(v.begin(), v.end(), greater<int>()); // 原理后面再讲，先会用

	sort(a, a + 4);

	// sort的底层使用的是快速排序，快速排序要求容器迭代器必须得是随机迭代器
	// 比如：快排要三数取中优化，不支持随机访问，效率就不够了
	//sort(lt.begin(), lt.end());  不支持

	//lt.sort(); // 不建议用
}

template<class Con>
void PrintContainer(const Con& c)
{
	//Con:: const_iterator  it = c.begin();
	Con::template const_iterator  it = c.begin();

	while (it != c.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_list2()
{
	list<int> lt;
	lt.push_back(10);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	//cout << lt.max_size() << endl;
	//lt.assign(10, 5);
	PrintContainer(lt);

	list<int>::iterator pos = find(lt.begin(), lt.end(), 3);
	lt.insert(pos, 30);
	PrintContainer(lt);
	// vector insert会导致pos失效，list会不会呢？  不会
	cout << *pos << endl;

	// vector erase会导致pos失效，list会不会呢？  会
	lt.erase(pos);
	PrintContainer(lt);

	cout << *pos << endl;
}

void test_list3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(4);
	lt.push_back(2);
	lt.push_back(2);

	//lt.remove(3);
	//lt.remove(30);
	PrintContainer(lt);

	// 一般情况，不太建议用list的排序，效率不是很高
	//lt.sort();
	lt.unique();
	//PrintContainer(lt);

	//lt.reverse();
	PrintContainer(lt);
}

int main()
{
	test_list3();

	//bit::test_list1();

	return 0;
}
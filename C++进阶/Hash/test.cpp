#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <set>
#include <time.h>
using namespace std;
#include "HashTable.h"

	void test_unordered_set1()
	{
		unordered_set<int> us;
		us.insert(2);
		us.insert(1);
		us.insert(2);
		us.insert(3);
		us.insert(5);
		us.insert(6);
		us.insert(2);
		us.insert(6);

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		for (auto e : us)
		{
			cout << e << " ";
		}
		cout << endl;

		// unordered_set专用查找算法。优点：使用哈希特性去查找，效率高 -- O(1)  
		// 类似如果是set的，效率是O(logN)
		auto pos = us.find(2);

		// 通用算法，优点：每个容器都可以使用，泛型算法。 缺点：暴力查找  -- O(N)
		// 复用
		//auto pos = find(us.begin(), us.end(), 2);
		// 这两个find有没有什么区别？
		if (pos != us.end())
		{
			cout << "找到了" << endl;
		}
		else
		{
			cout << "找不到" << endl;
		}
	}

	void test_unordered_map1()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "排序"));
		dict["left"] = "左边";
		dict["left"] = "剩余";

		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}

	// 1000
	// 900
	void test_op()
	{
		int N = 100000;
		vector<int> v;
		v.reserve(N);
		srand(time(0));
		for (int i = 0; i < N; ++i)
		{
			v.push_back(rand());
		}

		unordered_set<int> us;
		set<int> s;

		size_t begin1 = clock();
		for (auto e : v)
		{
			s.insert(e);
		}
		size_t end1 = clock();

		size_t begin2 = clock();
		for (auto e : v)
		{
			us.insert(e);
		}
		size_t end2 = clock();

		cout << "set insert:" << end1 - begin1 << endl;
		cout << "unordered_set insert:" << end2 - begin2 << endl;

		size_t begin3 = clock();
		for (auto e : v)
		{
			s.find(e);
		}
		size_t end3 = clock();

		size_t begin4 = clock();
		for (auto e : v)
		{
			us.find(e);
		}
		size_t end4 = clock();

		cout << "set find:" << end3 - begin3 << endl;
		cout << "unordered_set find:" << end4 - begin4 << endl;

		size_t begin5 = clock();
		for (auto e : v)
		{
			s.erase(e);
		}
		size_t end5 = clock();

		size_t begin6 = clock();
		for (auto e : v)
		{
			us.erase(e);
		}
		size_t end6 = clock();

		cout << "set erase:" << end5 - begin5 << endl;
		cout << "unordered_set erase:" << end6 - begin6 << endl;
	}

int main()
{
	//std::test_unordered_set1();
	//std::test_unordered_map1();
	//test_op();
	Close_Hash::TestHashTable2();

	return 0;
}
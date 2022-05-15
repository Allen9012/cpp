#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <set>
#include <time.h>
using namespace  std;

#include "unordered_map.h"
#include "unordered_set.h"

void test_op2()
{
	int N = 10000000;
	vector<int> v;
	v.reserve(N);
	srand((unsigned int)time(0));
	for (int i = 0; i < N; ++i)
	{
		//v.push_back(rand());
		v.push_back(i);
	}

	unordered_set<int> us1;
	unordered_set<int> us2;

	us1.reserve(N);
	//us1.rehash(N);

	size_t begin1 = clock();
	for (auto e : v)
	{
		us1.insert(e);
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (auto e : v)
	{
		us2.insert(e);
	}
	size_t end2 = clock();

	cout << "unordered_set1 insert:" << end1 - begin1 << endl;
	cout << "unordered_set2 insert:" << end2 - begin2 << endl;

	cout << us1.bucket_count() << endl;
	cout << us2.bucket_count() << endl;
}
int main()
{
	allen::test_unordered_map1();
	return 0;
}
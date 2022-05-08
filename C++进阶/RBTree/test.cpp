#include "RBTree.h"
#include"allen.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
//#include "Map.h"
//#include "Set.h"

void TestRBTree()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	allen::RBTree<int, int> t;
	int n = 100000;
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		int e = rand();
		t.Insert(make_pair(e, e));
	}

	//t.InOrder();
	cout << t.CheckBalance() << endl;
}

int main()
{
	TestRBTree();

	return 0;
}

//int main()
//{
//	bit::map<int, int> m;
//	m.insert(make_pair(1, 1));
//	m.insert(make_pair(3, 3));
//	m.insert(make_pair(0, 0));
//	m.insert(make_pair(9, 9));
//
//
//	bit::set<int> s;
//	s.insert(1);
//	s.insert(5);
//	s.insert(2);
//	s.insert(1);
//	s.insert(13);
//	s.insert(0);
//	s.insert(15);
//	s.insert(18);
//
//
//	bit::set<int>::iterator sit = s.begin();
//	while (sit != s.end())
//	{
//		cout << *sit << " ";
//		++sit;
//	}
//	cout << endl;
//
//
//	return 0;
//}
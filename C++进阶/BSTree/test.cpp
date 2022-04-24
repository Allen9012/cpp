#define _CRT_SECURE_NO_WARNINGS 1
#include"allen.h"

int  main()
{
	allen::BSTree<int> tree;
	int a[]= { 5,3,4,1,7,8,2,6,0,9 };
	for (auto e: a)
	{
		tree.Insert(e);
	}
	tree.InOder();

	tree.Erase(7);
	tree.InOder();
	tree.Erase(5);
	tree.InOder();
	return 0;
}
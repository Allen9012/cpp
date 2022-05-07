#include "RBTree.h"
#include "allen.h"
int main()
{
	allen::RBTree<int, int> t;
	t.Insert(make_pair(1, 1));

	return 0;
}
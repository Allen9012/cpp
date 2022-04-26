#define _CRT_SECURE_NO_WARNINGS 1
#include"allen.h"
#include "BinarySearchTree.h"
#include<iostream>
#include<string>
using namespace std;
void TestBSTree1()
{
	allenK::BSTree<int> t;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : a)
	{
		t.InsertR(e);
	}
	t.InOrder();

	t.EraseR(5);
	t.InOrder();

	t.EraseR(8); 
	t.InOrder();

	t.EraseR(7);
	t.InOrder();

	t.EraseR(5);
	t.InOrder();

	// 测试时，把树中的节点删除干净，确保没问题 
	for (auto e : a)
	{
		t.EraseR(e);
		t.InOrder();
	}
	t.InOrder();
}

void TestBSTree2()
{
	allenK::BSTree<int> t;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : a)
	{
		t.InsertR(e);
	}
	t.InOrder();

	allenK::BSTree<int> copy1 = t;
	allenK::BSTree<int> copy2(t);

	copy1.InOrder();
	copy2.InOrder();
}

void TestBSTree3()
{
	allenK_V::BSTree<string, string> dict;
	dict.InsertR("string", "字符串");
	dict.InsertR("tree", "树");
	dict.InsertR("left", "左边、剩余");
	dict.InsertR("right", "右边");
	dict.InsertR("sort", "排序");
	dict.InsertR("皮卡丘", "pikachu");
	// ...插入词库中所有单词
	string str;
	while (cin >> str)
	{
		allenK_V::BSTreeNode<string, string>* ret = dict.FindR(str);
		if (ret == nullptr)
		{
			cout << "单词拼写错误，词库中没有这个单词:" << str << endl;
		}
		else
		{
			cout << str << "中文翻译:" << ret->_value << endl;
		}
	}
}

void TestBSTree4()
{
	// 统计水果出现的次数
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	allenK_V::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// 先查找水果在不在搜索树中
		// 1、不在，说明水果第一次出现，则插入<水果, 1>
		//allenK_V::BSTreeNode<string, int>* ret = countTree.FindR(str);
		auto ret = countTree.FindR(str);
		if (ret == nullptr)
		{
			countTree.InsertR(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}

	countTree.InOrder();
}


int main()
{
	TestBSTree4();

	return 0;
}
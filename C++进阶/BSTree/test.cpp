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

	// ����ʱ�������еĽڵ�ɾ���ɾ���ȷ��û���� 
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
	dict.InsertR("string", "�ַ���");
	dict.InsertR("tree", "��");
	dict.InsertR("left", "��ߡ�ʣ��");
	dict.InsertR("right", "�ұ�");
	dict.InsertR("sort", "����");
	dict.InsertR("Ƥ����", "pikachu");
	// ...����ʿ������е���
	string str;
	while (cin >> str)
	{
		allenK_V::BSTreeNode<string, string>* ret = dict.FindR(str);
		if (ret == nullptr)
		{
			cout << "����ƴд���󣬴ʿ���û���������:" << str << endl;
		}
		else
		{
			cout << str << "���ķ���:" << ret->_value << endl;
		}
	}
}

void TestBSTree4()
{
	// ͳ��ˮ�����ֵĴ���
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
	allenK_V::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// �Ȳ���ˮ���ڲ�����������
		// 1�����ڣ�˵��ˮ����һ�γ��֣������<ˮ��, 1>
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
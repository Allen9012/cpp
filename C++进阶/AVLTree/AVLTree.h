#pragma once
#include <iostream>
#include "assert.h"
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf; // ƽ������  balance factor

	pair<K, V> _kv;

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	// ��������͸�ֵ��Ҫʵ�����

	~AVLTree()
	{
		// ...
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		// �ҵ��洢λ�ã������ݲ����ȥ
		Node* parent = _root, * cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// ����ƽ��
		// 1������ƽ������
		// 2��������ֲ�ƽ�⣬����Ҫ��ת
		//while (parent)
		while (cur != _root)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// parent���ڵ������߶ȱ��ˣ���Ӱ��parent->parent
				// �������ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//parent���������Ѿ���ƽ�⣬��Ҫ��ת����һ��
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						// �ҵ���
						RotateR(parent);
					}
					else // cur->_bf == 1
					{
						RotateLR(parent);
					}
				}
				else // parent->_bf  == 2
				{
					if (cur->_bf == 1)
					{
						// ����
						RotateL(parent);
					}
					else // cur->_bf == -1
					{
						RotateRL(parent);
					}
				}

				break;
			}
			else
			{
				// ����ڵ�֮ǰ�����Ѿ���ƽ���ˣ�����bf������Ҫ��������߼�
				assert(false);
			}
		}

		return true;
	}
	void RotateLR(Node* parent)
	{
		RotateL(parent->_left);
		RotateR(parent);

		// ...ƽ�����ӵ��ڻ���Ҫ�������
	}

	void RotateRL(Node* parent);
	void RotateL(Node* parent);
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				parentParent->_right = subL;

			subL->_parent = parentParent;
		}

		subL->_bf = parent->_bf = 0;
	}

	Node* Find(const K& key)
	{
		return nullptr;
	}

	bool Erase(const K& key)
	{
		return false;
	}

private:
	Node* _root;
};
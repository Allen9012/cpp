#pragma once
#include <iostream>
using namespace std;

enum Colour
{
	RED,
	BLACK,
};

//red-black
template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template<class K, class V>
struct __TreeIterator
{
	typedef RBTreeNode<K, V> Node;
	Node* _node;
	__TreeIterator(Node* node)
		:_node(node)
	{}

	//operator*();

	// �ѵ�
	//operator++();
	//operator--();
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
	{}

	// ���������operator=����Լ�ȥʵ��һ��

	void Destory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		Destory(root->_left);
		Destory(root->right);
		delete root;
	}

	~RBTree()
	{
		Destory(_root);
		_root = nullptr;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}

	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return make_pair(_root, true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(cur, false);
			}
		}

		Node* newnode = new Node(kv);
		newnode->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}
		else
		{
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		cur = newnode;

		// ������״��ڣ�����ɫΪ��ɫ����Ҫ����
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			// �ؼ��ǿ�����
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				// ���1��uncle������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else // ���2+3��uncle������ uncle������Ϊ��
				{
					// ���2������
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else // ���3��˫��
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
			else // parent == grandfather->_right
			{
				//...
			}
		}

		_root->_col = BLACK;
		return make_pair(newnode, true);
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
	}

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
	}

private:
	Node* _root;
};
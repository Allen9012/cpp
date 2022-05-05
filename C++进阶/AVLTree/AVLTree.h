#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	// �������ĸ߶�-�������ĸ߶�
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

	void _Destory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_Destory(root->_left);
		_Destory(root->_right);
		delete root;
	}

	~AVLTree()
	{
		_Destory(_root);
		_root = nullptr;
	}

	V& operator[](const K& key)
	{
		pair<Node*, bool> ret = Insert(make_pair(key, V()));
		return ret.first->_kv.second;
	}

	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
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
				return make_pair(cur, true);
			}
		}

		cur = new Node(kv);
		Node* newnode = cur;
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

		return make_pair(newnode, true);
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		// ...ƽ�����ӵ��ڻ���Ҫ�������
		if (bf == -1)
		{
			subL->_bf = 0;
			parent->_bf = 1;
			subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		// ƽ�����Ӹ���
		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
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

		parent->_bf = subR->_bf = 0;
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

		subL->_bf = parent->_bf = 0;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}

	// 1�������л��õģ�AVL�������Լ�д������ͨ�������������һ���������ʾ͹��ˣ�
	// 2��У�лῼ�ģ�����������ɾ����ϸ�ڣ�
	// ����Ȥ�Ŀ�����ȥʵ��һ�¡�
	bool Erase(const K& key)
	{
		return false;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return rightHeight > leftHeight ? rightHeight + 1 : leftHeight + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		// ���һ��ƽ�������Ƿ���ȷ
		if (rightHeight - leftHeight != root->_bf)
		{
			cout << "ƽ�������쳣:" << root->_kv.first << endl;
			return false;
		}

		return abs(rightHeight - leftHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	bool IsAVLTree()
	{
		return _IsBalance(_root);
	}
private:
	Node* _root;
};
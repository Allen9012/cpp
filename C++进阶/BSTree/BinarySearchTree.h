#pragma once
#include <iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	//�ֶ�
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	//����
	BSTreeNode(const K& key)
		: _left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{}

	// �漰��ǳ��������Ҫʵ�ֿ������� operator=��

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return NULL;
	}

	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//�ҵ��ˣ�׼����ʼɾ��
				// 1����Ϊ�ջ�����Ϊ�գ�����һ�����ӽ������׹���ɾ���Լ�
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}

					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
				}
				else ///2�����Ҷ���Ϊ�գ��滻��ɾ��
				{
					// �ҵ���������С�ڵ�ȥ�滻
					//Node* minParent = cur;
					//Node* minRight = cur->_right;
					//while (minRight->_left)
					//{
					//	minParent = minRight;
					//	minRight = minRight->_left;
					//}

					//// �����滻�ڵ��ֵ
					//cur->_key = minRight->_key;

					//// ɾ���滻�ڵ�
					//if (minParent->_left == minRight)
					//{
					//	minParent->_left = minRight->_right;
					//}
					//else
					//{
					//	minParent->_right = minRight->_right;
					//}
					//delete minRight;

					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					K min = minRight->_key;

					// �ݹ�����Լ�ȥɾ���滻�ڵ㣬һ�����ߵ���Ϊ�յ��������
					this->Erase(min);

					cur->_key = min;
				}


				return true;
			}
		}

		return false;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	Node* _root;
};

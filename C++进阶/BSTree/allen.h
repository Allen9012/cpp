#pragma once
#include<iostream>
using namespace  std;

namespace allen
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

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

		//�漰��ǳ��������Ҧʵ�ֿ�������
		/*~BSTree()
		{
		}*/

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}
			else
			{
				//�ǵݹ�
				Node* cur = _root;
				Node* parent = nullptr;
				//1. ��������
				while (cur)
				{//����һ��ֵ֮��Ҫ�����ӽڵ㣬���Ӹ���
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
					else//���  ->  return false
						return false;
				}
				//2. ����cur�ڵ�
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
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
		//��ֹ����Ҫ�����ڵ㣬���ǿ��Է�װһ��
		void InOder()
		{
			_InOrder(_root);
			cout << endl;
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
					cur = cur->_right;
				else if (cur->_key>key)
					cur = cur->_left;
				else
					return cur;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			//1. ��ʼ��
			while (cur)
			{
				if (cur->_key< key)
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
				{//2. �ҵ���,׼����ʼɾ��
					//��Ϊ�գ���Ϊ�գ������ԣ��Ѻ��ӽ������׹���
					if (cur->_left==nullptr)
					{
						//���curû�и���
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							//����ָ��cur����
							if (parent->_left == cur)
							{//���Ǹ��׵���
								parent->_left = cur->_right;
							}
							else
							{//���Ǹ��׵���
								parent->_right = cur->_right;
							}
						}
						delete cur;//�ÿսڵ�
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
							{//���Ǹ��׵���
								parent->_left = cur->_left;
							}
							else
							{//���Ǹ��׵���
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else
						//�������ӣ��滻��ɾ��
					{
						//Node* min_parent = cur;
						//Node* minRight = cur->_right;
						////�ҵ�����������ڵ�
						//while (minRight->_left)
						//{
						//	min_parent = minRight;
						//	minRight = minRight->_left;
						//}
						////�����滻�Ľڵ�
						//cur->_key = minRight->_key;
						//ɾ���滻�ڵ�
					/*	if (min_parent->_left == minRight)
							min_parent->_left = minRight->_right;
						else
							min_parent->_right = minRight->_right;
						delete minRight;*/
						//�ҵ�����������ڵ�
						Node* minRight = cur->_right;
						while (minRight->_left)
						{
							minRight = minRight->_left;
						}
						K min = minRight->_key;
						//�ݹ�ȥɾ���滻�ڵ㣬һ�����ߵ���Ϊ�յ��������
						this->Erase(min);
						cur->_key = min;//��ɾ�����滻
					}
					return true;
				}
			}
			return false;
		}

	private:
		Node* _root;
	};
}
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

		//涉及深浅拷贝，余姚实现拷贝构造
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
				//非递归
				Node* cur = _root;
				Node* parent = nullptr;
				//1. 遍历到底
				while (cur)
				{//插入一个值之后还要来链接节点，链接父亲
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
					else//相等  ->  return false
						return false;
				}
				//2. 链接cur节点
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
		//防止传参要传根节点，我们可以封装一下
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
			//1. 开始找
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
				{//2. 找到了,准备开始删除
					//左为空，右为空，都可以，把孩子交给父亲管理
					if (cur->_left==nullptr)
					{
						//如果cur没有父亲
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							//父亲指向cur的右
							if (parent->_left == cur)
							{//我是父亲的左
								parent->_left = cur->_right;
							}
							else
							{//我是父亲的右
								parent->_right = cur->_right;
							}
						}
						delete cur;//置空节点
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
							{//我是父亲的左
								parent->_left = cur->_left;
							}
							else
							{//我是父亲的右
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else
						//两个孩子，替换法删除
					{
						//Node* min_parent = cur;
						//Node* minRight = cur->_right;
						////找到右树的最左节点
						//while (minRight->_left)
						//{
						//	min_parent = minRight;
						//	minRight = minRight->_left;
						//}
						////保存替换的节点
						//cur->_key = minRight->_key;
						//删除替换节点
					/*	if (min_parent->_left == minRight)
							min_parent->_left = minRight->_right;
						else
							min_parent->_right = minRight->_right;
						delete minRight;*/
						//找到右树的最左节点
						Node* minRight = cur->_right;
						while (minRight->_left)
						{
							minRight = minRight->_left;
						}
						K min = minRight->_key;
						//递归去删除替换节点，一定会走到作为空的情况处理
						this->Erase(min);
						cur->_key = min;//先删除再替换
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
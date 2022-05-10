#pragma once
#include <iostream>
#include "Reverse_Iterator.h"
using namespace std;
namespace allen
{
	enum Color
	{
		RED,
		BLACK,
	};

	template<class T>
	struct RBTreeNode
	{
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;
		T _data;

		Color _col;

		RBTreeNode(const T& x)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _data(x)
			, _col(RED)
		{}
	};

	template<class T,class Ref,class Ptr>
	struct __TreeIterator  
	{
		typedef Ref reference;
		typedef Ptr pointer;

		typedef RBTreeNode<T> Node;
		typedef __TreeIterator<T,  Ref, Ptr> Self;

		Node* _node;

		__TreeIterator(Node* node)
			:_node(node)
		{ }

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator !=(const Self& s) const 
		{
			return _node != s._node;
		}

		bool operator == (const Self& s) const
		{
			return _node == s._node;
		}

		//难点
		Self& operator++()
		{
			if (_node->_right)
			{
				//右树中中序的第一个节点
				Node* left = _node->_right;
				while (left->_left)
				{
					left = left->_left;
				}
				_node = left;
			}
			else
			{//右树为空，祖先中父亲右的哪一个
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && cur==parent->_right)
				{
					cur = cur->_parent;
					parent = parent->_parent;
				}
				_node = parent;
			}
			return *this;
		}

		Self& operator--()
		{
			if (_node->_left)
			{
				Node* right = _node->_left;
				while (right->_right)
				{
					right = right->_right;
				}
				_node = right;
			}
			else
			{
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && cur==parent->_left)
				{
					cur = parent;
					parent = parent->_parent;
				}
				_node = parent;
			}
			return *this;
		}
	};


	template<class K, class T, class KeyOfT>
	class RBTree
	{
	public:
		typedef RBTreeNode<T> Node;
		typedef __TreeIterator<T, T&, T*>  iterator;
		typedef __TreeIterator<T, const T&, const T*>  const_iterator;
		typedef Reverse_Iterator<iterator> reverse_iterator;

		reverse_iterator rbegin()
		{
			Node* right = _root;
			while (right && right->_right)
			{
				right = right->_right;
			}
			return reverse_iterator(iterator(right));
		}

		reverse_iterator rend()
		{
			return reverse_iterator(iterator(nullptr));
		}


		iterator begin()
		{
			Node* left = _root;
			while (left && left->_left)
			{
				left = left->_left;
			}
			return iterator(left);
		}

		iterator end()
		{
			return iterator(nullptr);
		}

		//构造
		RBTree()
			:_root(nullptr)
		{}
		//析构
		~RBTree()
		{
			_Destroy(_root);
			_root = nullptr;
		}

		//下面的需要递归去拷贝

		//拷贝构造

		//赋值重载
		
	private:
		void _Rotate_R(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			//1.旋转
			parent->_left = subLR;
			if (subLR)
			{
				subLR->_parent=parent;
			}
			subL->_right = parent;
			Node* grandparent = parent->_parent;//记录爷爷
			parent->_parent = subL;

			//2. 修改父子关系
			if (parent == _root)
			{//原来的父亲做了根节点
				_root = subL;
				_root->_parent = nullptr;
			}
			else
			{//修改爷爷和父亲链接
				if (grandparent->_left==parent)
					grandparent->_left = subL;
				else
					grandparent->_right = subL;
				subL->_parent = grandparent;
			}
		}

		void _Rotate_L(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			//1. 旋转
			parent->_right = subRL;
			if (subRL)
			{
				subRL->_parent = parent;
			}
			subR->_left = parent;
			Node* grandparent = parent->_parent;
			parent->_parent = subR;

			//2. 修改父子关系
			if (_root==parent)
			{
				_root = subR;
				_root->_parent = nullptr;
			} 
			else
			{
				if (grandparent->_left == parent)
					grandparent->_left = subR;
				else
					grandparent->_right = subR;
				subR->_parent = grandparent;
			}
		}

		void _Destroy(Node* root)
		{
			if (root==nullptr)
				return;
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
		}

		bool _CheckBalance(Node*root,int black_num,int count)
		{
			if (root ==nullptr)
			{
				if (count != black_num)
				{		//3.路径黑节点数相等
					cout << "路径上黑色节点的数量不相等" << endl;
					return false;
				}
				return true;
			}

			//2.遍历红节点，查父亲是不是红的，不要查孩子因为孩子可能没有
			if (root->_col==RED && root->_parent->_col==RED)
			{
				cout << "存在连续的红色节点" << endl;
				return false;
			}

			if (root->_col==BLACK)
			{
				count++;
			}
			return _CheckBalance(root->_left,black_num,count)
						&& _CheckBalance(root->_right,black_num,count);
		}


	public:
		//插入
		pair<iterator, bool> Insert(const T& data)
		{
			if (_root == nullptr)
			{
				_root = new Node(data);
				_root->_col = BLACK;
				return make_pair(iterator(_root), true);
			}

			KeyOfT kot;

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (kot(cur->_data) < kot(data))
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kot(cur->_data) > kot(data))
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return make_pair(iterator(cur), false);
				}
			}

			Node* newnode = new Node(data);
			newnode->_col = RED;
			if (kot(parent->_data) < kot(data))
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

			// 如果父亲存在，且颜色为红色就需要处理
			while (parent && parent->_col == RED)
			{
				Node* grandfather = parent->_parent;
				// 关键是看叔叔
				if (parent == grandfather->_left)
				{
					Node* uncle = grandfather->_right;
					// 情况1：uncle存在且为红
					if (uncle && uncle->_col == RED)
					{
						parent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;

						// 继续往上处理
						cur = grandfather;
						parent = cur->_parent;
					}
					else // 情况2+3：uncle不存在 uncle存在且为黑
					{
						// 情况2：单旋
						if (cur == parent->_left)
						{
							_Rotate_R(grandfather);
							grandfather->_col = RED;
							parent->_col = BLACK;
						}
						else // 情况3：双旋
						{
							_Rotate_L(parent);
							_Rotate_R(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
						}

						break;
					}
				}
				else // parent == grandfather->_right
				{
					Node* uncle = grandfather->_left;
					// 情况1：
					if (uncle && uncle->_col == RED)
					{
						uncle->_col = parent->_col = BLACK;
						grandfather->_col = RED;

						cur = grandfather;
						parent = cur->_parent;
					}
					else // 情况2：+ 情况3：
					{
						if (cur == parent->_right)
						{
							_Rotate_L(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;
						}
						else // cur == parent->_left
						{
							_Rotate_R(parent);
							_Rotate_L(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
						}
						// 插入结束
						break;
					}
				}
			}

			_root->_col = BLACK;
			return make_pair(iterator(newnode), true);
		}
		
		Node* Find(const K& key)
		{
			KeyOfT kot;
			Node* cur = _root;
			while (cur)
			{
				if (kot(cur->_data) > key)
				{
					cur = cur->_left;
				}
				else if (kot(cur->_data) < key)
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

		bool  CheckBalance()
		{
			if (_root==nullptr)
			{
				return true;
			}
			//1.黑根
			if (_root->_col==false)
			{
				cout << "root是红色"<<endl;
				return false;
			}
			//2. 每条路径走到NIL节点，遇到黑++，找最左路径做黑色节点的参考值
			int black_num = 0;
			Node* left = _root;
			while (left)
			{
				if (left->_col==BLACK)
				{
					black_num++;
				}
				left = left->_left;
			}
			int count = 0;//count计算该条路的值
			//3. 用子函数来递归遍历
			return _CheckBalance(_root,black_num,count);
		}

		//void _InOrder(Node* root)
		//{
		//	if (root == nullptr)
		//	{
		//		return;
		//	}

		//	_InOrder(root->_left);
		//	cout << root->_kv.first << ":" << root->_kv.second << endl;
		//	_InOrder(root->_right);
		//}

		//void InOrder()
		//{
		//	_InOrder(_root);
		//	cout << endl;
		//}

	private:
		Node* _root;
	};
}
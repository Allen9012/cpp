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

		//�ѵ�
		Self& operator++()
		{
			if (_node->_right)
			{
				//����������ĵ�һ���ڵ�
				Node* left = _node->_right;
				while (left->_left)
				{
					left = left->_left;
				}
				_node = left;
			}
			else
			{//����Ϊ�գ������и����ҵ���һ��
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

		//����
		RBTree()
			:_root(nullptr)
		{}
		//����
		~RBTree()
		{
			_Destroy(_root);
			_root = nullptr;
		}

		//�������Ҫ�ݹ�ȥ����

		//��������

		//��ֵ����
		
	private:
		void _Rotate_R(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			//1.��ת
			parent->_left = subLR;
			if (subLR)
			{
				subLR->_parent=parent;
			}
			subL->_right = parent;
			Node* grandparent = parent->_parent;//��¼үү
			parent->_parent = subL;

			//2. �޸ĸ��ӹ�ϵ
			if (parent == _root)
			{//ԭ���ĸ������˸��ڵ�
				_root = subL;
				_root->_parent = nullptr;
			}
			else
			{//�޸�үү�͸�������
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
			//1. ��ת
			parent->_right = subRL;
			if (subRL)
			{
				subRL->_parent = parent;
			}
			subR->_left = parent;
			Node* grandparent = parent->_parent;
			parent->_parent = subR;

			//2. �޸ĸ��ӹ�ϵ
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
				{		//3.·���ڽڵ������
					cout << "·���Ϻ�ɫ�ڵ�����������" << endl;
					return false;
				}
				return true;
			}

			//2.������ڵ㣬�鸸���ǲ��Ǻ�ģ���Ҫ�麢����Ϊ���ӿ���û��
			if (root->_col==RED && root->_parent->_col==RED)
			{
				cout << "���������ĺ�ɫ�ڵ�" << endl;
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
		//����
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
							_Rotate_R(grandfather);
							grandfather->_col = RED;
							parent->_col = BLACK;
						}
						else // ���3��˫��
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
					// ���1��
					if (uncle && uncle->_col == RED)
					{
						uncle->_col = parent->_col = BLACK;
						grandfather->_col = RED;

						cur = grandfather;
						parent = cur->_parent;
					}
					else // ���2��+ ���3��
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
						// �������
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
			//1.�ڸ�
			if (_root->_col==false)
			{
				cout << "root�Ǻ�ɫ"<<endl;
				return false;
			}
			//2. ÿ��·���ߵ�NIL�ڵ㣬������++��������·������ɫ�ڵ�Ĳο�ֵ
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
			int count = 0;//count�������·��ֵ
			//3. ���Ӻ������ݹ����
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
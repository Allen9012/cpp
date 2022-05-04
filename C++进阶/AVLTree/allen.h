#pragma once
#include <assert.h>
#include <iostream>

namespace allen
{
	template<class K, class V>
	struct AVLTreeNode
	{
		AVLTreeNode<K, V>*  _left;
		AVLTreeNode<K, V>*  _right;
		AVLTreeNode<K, V>*  _parent;

		int _bf; // 平衡因子  balance factor

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
	private:


		void _Rotate_R(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			//1. 旋转
			parent->_left = subLR;
			//subLR有可能是空的
			if (subLR)
			{
				subLR->_parent = parent;
			}
			subL->_right = parent;
			Node* grandparent = parent->_parent;//先记录parent->_parent
			parent->_parent = subL;
			//2. 修改平衡因子
			subL->_bf = parent->_bf = 0;
			//3. 修改新父子关系
			if (parent == _root)
			{//独立子树
				_root = subL;
				_root->_parent = nullptr;
			}
			else
			{//还有父亲，那要修改父亲，就要记录父亲的父亲
				if (grandparent->_left == parent)
				{
					grandparent->_left = subL;
					subL->_parent = grandparent;
				}
				else
				{
					grandparent->_right = subL;
					subL->_parent = grandparent;
				}
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

			//2. 修改bf
			subR->_bf = parent->_bf = 0;

			//3. 修改新的父子关系
			//空树
			if (parent == _root)
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else
			{//还有父亲，那要修改父亲，就要记录父亲的父亲
				if (grandparent->_left == parent)
				{
					grandparent->_left = subR;
					subR->_parent = grandparent;
				}                                                                                                       
				else
				{//grandparent->_left == parent
					grandparent->_right = subR;
					subR->_parent = grandparent;
				}
			}
		}

		void _Rotate_LR(Node* parent)
		{
			//先旋转左
			_Rotate_L(parent->left);
			//再旋转右
			_Rotate_R(parent->_right);
			//平衡因子调节

		}
		void _Rotate_RL(Node* parent)
		{

		}


	public:
		typedef AVLTreeNode<K, V> Node;
		//构造
		AVLTree()
			:_root(nullptr)
		{}

		//析构
		~AVLTree()
		{
			//
		}

		//拷贝构造深拷贝

		//赋值重载深拷贝

		//插入
		bool Insert(const pair<K, V>& kv)
		{
			//1. 空树
			if (_root==nullptr)
			{
				_root = new Node(kv);
				return true;
			} 
			Node* parent = _root, * cur = _root;
			//2. 找到节点
			while (cur)
			{//普通版本不允许冗余
				if (cur->_kv.first>kv.first)
				{
					parent = cur;
					cur = cur->_left;
				} 
				else if(cur->_kv.first < kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else//数据重复直接false
					return false;
			}

			cur = new Node(kv);
			//3. 连接节点，注意是三叉链结构
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

			//4. 更新平衡因子
			while (cur != _root)
			{
				if (parent->_left == cur)
					cur->_parent->_bf--;//新节点是在parent左
				else 
					cur->_parent->_bf++;//新节点是在parent右
				
				//bf==0 停止
				if (parent->_bf == 0)
					break;
				//bf==1 || bf==-1 继续往上走
				else if (parent->_bf==1 || parent->_bf == -1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				//_bf == 2 ||_bf == -2  parent所在的子树不平衡，需要旋转处理一下
				else if(parent->_bf == 2 || parent->_bf == -2)
				{
					if (parent->_bf == -2)
					{
						//1. right rotation
						if (cur->_bf == -1)
						{
							_Rotate_R(parent);
						}
						else //cur->_bf == 1
						{
							_Rotate_LR(parent)
						}
					}
					else   //parent->_bf == 2
					{
						if (cur->_bf ==1 )
						{
							//2. left rotation 
							_Rotate_L(parent);
						} 
						else //cur->_bf == -1
						{
							_Rotate_RL(parent);
						}
					}
					
			
					//3. Left-Right Rotation
				}
				else//之前的出错了，暴力assert
					assert(false);
			}

			return true;
		}

		//查找
		Node* Find(const K& key)
		{
			return nullptr;
		}

		//删除
		bool Erase(const K& key)
		{
			return false;
		}

	private:
		Node* _root;
	};

}
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
				//旋转
				else if(parent->_bf == 2 || parent->_bf == -2)
				{
					//parent所在的子树不平衡，需要旋转处理一下

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
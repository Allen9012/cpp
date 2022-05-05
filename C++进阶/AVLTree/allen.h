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
		typedef AVLTreeNode<K, V>  Node;

	private:
		void _Destroy(Node* root)
		{
			if (root==nullptr)
			{
				return;
			}
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
		}

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
	
			//2. 修改新父子关系
			if (parent == _root)
			{//独立子树
				_root = subL;
				_root->_parent = nullptr;
			}
			else
			{//还有父亲，那要修改父亲，就要记录父亲的父亲
				if (grandparent->_left == parent)
					grandparent->_left = subL;
				else
					grandparent->_right = subL;

				subL->_parent = grandparent;
			}

			//3. 修改平衡因子
			subL->_bf = parent->_bf = 0;
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

			//2. 修改新的父子关系
			//空树
			if (parent == _root)
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else
			{//还有父亲，那要修改父亲，就要记录父亲的父亲
				if (grandparent->_left == parent)
					grandparent->_left = subR;
				else//grandparent->_right == parent
					grandparent->_right = subR;

				subR->_parent = grandparent;
			}

			//3. 修改bf
			subR->_bf = parent->_bf = 0;
		}

		void _Rotate_LR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int bf = subLR->_bf;

			//先旋转左
			_Rotate_L(parent->_left);
			//再旋转右
			_Rotate_R(parent);
			
			//平衡因子调节
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

		void _Rotate_RL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int bf = subRL->_bf;

			//先右旋
			_Rotate_R(parent->_right);
			//再左旋
			_Rotate_L(parent);

			// 平衡因子更新
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
				assert(false);
		}

		int _Height(Node* root)
		{
			if (root==nullptr)
			{
				return 0;
			}
			int left_height = _Height(root->_left);
			int right_height = _Height(root->_right);
			return left_height > right_height ? left_height + 1 : right_height + 1;
		}

		bool _IsBalance(Node* root)
		{
			if (root==nullptr)
			{
				return true;
			}
			int left_height = _Height(root->_left);
			int right_height = _Height(root->_right);
			
			//检查平衡
			if (right_height - left_height != root->_bf)
			{
				cout << "平衡因子异常：" << root->_kv.first << endl;
				return false;
			}
			return abs(right_height - left_height) < 2 
				&& _IsBalance(root->_left) 
				&& _IsBalance(root->_right);
		}


	public:
		//构造
		AVLTree()
			:_root(nullptr)
		{}

		//析构
		~AVLTree()
		{
			_Destroy(_root);
			_root = nullptr;
		}

		//拷贝构造深拷贝

		//赋值重载深拷贝

		//插入
		pair<Node*,bool> Insert(const pair<K, V>& kv)
		{
			//1. 空树
			if (_root==nullptr)
			{
				_root = new Node(kv);
				return make_pair(_root, true);
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
					return make_pair(cur,false);//插入失败返回和这个节点相等的节点
			}

			cur = new Node(kv);
			Node* newnode = cur;

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

				//1. bf==0 停止
				if (parent->_bf == 0)
				{
					break;
				}
				//2. bf==1 || bf==-1 继续往上走
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				//3. _bf == 2 ||_bf == -2  parent所在的子树不平衡，需要旋转处理一下
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					if (parent->_bf == -2)
					{
						if (cur->_bf == -1)
						{//右单旋
							_Rotate_R(parent);
						}
						else //cur->_bf == 1
						{//左右双旋
							_Rotate_LR(parent);
						}
					}
					else   //parent->_bf == 2
					{
						if (cur->_bf == 1)
						{
							//左单旋
							_Rotate_L(parent);
						}
						else //cur->_bf == -1
						{//右单旋
							_Rotate_RL(parent);
						}
					}

					break;
				}
				else//之前的出错了，暴力assert
				{
					assert(false);
				}
			}
			return  make_pair(newnode,true);
		}

		V& operator[](const K& key)
		{
			pair<Node*, bool> ret = Insert(make_pair(key, V()));
			return ret.first->_kv.second;
		}

		//查找
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

		//删除
		bool Erase(const K& key)
		{
			return false;
		}

		void _InOrder(Node *root)
		{
			if (root==nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_kv.first << ":" << root->_kv.second << endl;
			_InOrder(root->_right);
			
		}

		void InOrder()
		{
			_InOrder(_root);
		}

		bool IsAVLTree()
		{
			return _IsBalance(_root);
		}
	private:
		Node* _root;
	};

}
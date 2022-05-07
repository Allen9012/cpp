#pragma once

namespace allen
{
	enum Color
	{
		RED,
		BLACK,
	};

	template<class K,class V>
	struct RBTreeNode
	{
		RBTreeNode<K, V>* _left;
		RBTreeNode<K, V>* _right;
		RBTreeNode<K, V>* _parent;
		pair<K, V> _kv;
		Color _col;

		RBTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_col(RED)
		{}
	};
	template<class K, class V>
	struct __TreeIterator  
	{
		typedef RBTreeNode<K, V> Node;
		Node* _node;

		__TreeIterator(Node* node)
			:_node(node)
		{ }

		/*	operator*();
			 //难点
			operator++();
			operator--();*/
	};

	template<class K,class V>
	class RBTree
	{
		typedef RBTreeNode<K, V> Node;
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

	public:
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

		//插入
		pair<Node*, bool> Insert(const pair<K, V>& kv)
		{
			//空树
			if (_root==nullptr)
			{
				_root = new Node(kv);
				_root->_col = BLACK;//根必须是黑的
				return make_pair(_root, true);
			} 

			Node* parent = nullptr;
			Node* cur = _root;
			
			//1. 找适当的空位置
			while (cur)
			{
				if (cur->_kv.first<kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_kv.first<kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{//重复
					return make_pair(cur, false);
				}
			}

			//2. cur走到空 可以链接
			Node* newnode = new Node(kv);
			newnode->_col = RED;

			if (parent->_kv.first <kv.first)
			{
				parent->_right = cur;
				cur->_parent = parent;
			}
			else
			{
				parent->_left = cur;
				cur->_parent = parent;
			}
			cur = newnode;

			//如果父亲存在，且颜色为红色就需要处理
			while (parent && parent->_col == RED)
			{	
				//抓住叔叔是关键
				Node* grandfather = parent->_parent;
			//a. 首先父亲在祖父左边的情况
				if (parent==grandfather->_left)
				{
					Node* uncle = grandfather->_right;
					//情况1：uncle 存在且为红
					if (uncle && uncle->_col ==RED)
					{
						parent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;
						//继续往上处理
						cur = grandfather;
						parent = cur->_parent;
					}

					//情况2+3 uncle不存在或者uncle存在且为黑
					else//此时变色无法处理
					{
						//情况2：单旋
						if (cur==parent->_left)
						{   //1. 右单旋
							_Rotate_R(parent);
							//2. 变色
							grandfather->_col = RED;
							parent->_col = BLACK;
						} 
						else//情况3：双旋
						{
							_Rotate_L(parent);
							_Rotate_R(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
						}
						break;//根是黑的了，不会往上影响直接break
					}
				} 
				
				//b. 首先父亲在祖父左边的情况
				else//parent == grandfather->_right
				{
					Node* uncle = parent->_left;
					//情况1：uncle 存在且为红 
					if (uncle && uncle->_col==RED)
					{
						uncle->_col=parent->_col = BLACK;
						grandfather->_col = RED;
						//继续往上递归
						cur = grandfather;
						parent = cur->_parent;//这个肯定有父亲
					} 
					//情况 2+3： uncle不存在或为黑
					else
					{
						if (parent->_right==cur)
						{
							_Rotate_L(parent);
							parent->_col = BLACK;
							grandfather->_col = RED;
						} 
						else
						{
							_Rotate_R(parent);
							_Rotate_L(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
						}
						break;
					}
				}
			}
			//默认修改根节点为黑色
			parent->_col = BLACK;
			return make_pair(newnode, true);
		}
		
		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first>key)
				{
					cur = cur->_left;
				}
				else if (cur->_kv.first<key)
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

	private:
		Node* _root;
	};
}
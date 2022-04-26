#pragma once
#include<iostream>
using namespace  std;

namespace allenK
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
		//下面的有些封装的函数可以放在私有的， 别人最好无法调用
	private:

		//封装析构
		void _Destroy(Node* root)
		{//后序遍历析构
			if (root==nullptr)
				return;
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
		}

		//封装拷贝构造
		Node* _Copy(Node* root)
		{
			if (root==nullptr)
				return nullptr;

			Node* copyNode = new Node(root->_key);
			copyNode->_left = _Copy(root->_left);
			copyNode->_right = _Copy(root->_right);
			return copyNode;
		}

		Node* _FindR(Node* root, const K& key)
		{
			//如果为空
			if (root==nullptr)
				return nullptr;

			//如果不为空
			if (root->_key>key)
				return _FindR(root->_left,key);
			else if(root->_key<key)
				return _FindR(root->_right,key);
			else
				return _root;
		}

		//不许相同节点
		bool _InsertR(Node*& root, const K& key)
		{
			if (root== nullptr)   //插入
			{
				root = new Node(key);
				return true;
			}

			if (root->_key>key)
				return _InsertR(root->_left,key);
			else if (root->_key<key)
				return _InsertR(root->_right,key);
			else
				return false;
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root==nullptr)
				return  false;
			
			//寻找该节点
			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else
			{//找到了,要删除root
				if (root->_left==nullptr)
				{//左树空，右树存在
					Node* del = root;//当下要删除的保存一下过会删除
					root = root->_right;//找到删掉节点的右孩子
					delete del;//删除节点
				} 
				else if(root->_right==nullptr)
				{//右树空，左树存在
					Node* del = root;
					root = root->_left;
					delete del;
				}
				else
				{//两孩子都存在,找右树的最左子代
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					K  min = minRight->_key;

					// 转换成在root的右子树删除min
					_EraseR(root->_right, min);
					root->_key = min;
				}
				return true;
			}
		}

	public:
		BSTree()
			:_root(nullptr)
		{}

		//析构
		~BSTree()
		{
			_Destroy(_root);
			_root = nullptr;
		}

		//拷贝构造
		BSTree(const BSTree<K>& tree)
		{
			//递归拷贝
			_root=_Copy(tree._root);
		}
			
		//赋值运算符
		//t1=t2
		BSTree<K>& operator=(BSTree<K> tree)
		{
			swap(_root, tree._root);
			return *this;
		}


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
		void InOrder()
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


		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}



		Node* FindR(const K& key)
		{//为了递归保证参数
			return _FindR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:
		Node* _root;
	};
}

namespace allenK_V
{
	template<class K,class V>
	struct BSTreeNode
	{
		BSTreeNode<K,V>* _left;
		BSTreeNode<K,V>* _right;
		
		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value)
			: _left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	template<class K,class V>
	class BSTree
	{
		typedef BSTreeNode<K,V> Node;
		//下面的有些封装的函数可以放在私有的， 别人最好无法调用
	private:

		//封装析构
		void _Destroy(Node* root )
		{//后序遍历析构
			if (root == nullptr)
				return;
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
		}

		//封装拷贝构造
		Node* _Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* copyNode = new Node(root->_key);
			copyNode->_left = _Copy(root->_left);
			copyNode->_right = _Copy(root->_right);
			
			return copyNode;
		}

		Node* _FindR(Node* root, const K& key)
		{
			//如果为空
			if (root == nullptr)
				return nullptr;

			//如果不为空
			if (root->_key > key)
				return _FindR(root->_left, key);
			else if (root->_key < key)
				return _FindR(root->_right, key);
			else
				return _root;
		}

		//不许相同节点
		bool _InsertR(Node*& root, const K& key, const V& value)
		{
			if (root == nullptr)   //插入
			{
				root = new Node(key,value);
				return true;
			}

			if (root->_key > key)
				return _InsertR(root->_left, key,value);
			else if (root->_key < key)
				return _InsertR(root->_right, key,value);
			else
				return false;
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return  false;

			//寻找该节点
			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else
			{//找到了,要删除root
				if (root->_left == nullptr)
				{//左树空，右树存在
					Node* del = root;//当下要删除的保存一下过会删除
					root = root->_right;//找到删掉节点的右孩子
					delete del;//删除节点
				}
				else if (root->_right == nullptr)
				{//右树空，左树存在
					Node* del = root;
					root = root->_left;
					delete del;
				}
				else
				{//两孩子都存在,找右树的最左子代
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					K  k_min = minRight->_key;
					V v_min = minRight->_value;

					// 转换成在root的右子树删除min
					_EraseR(root->_right, k_min);
					root->_key = k_min;
					root->_value = v_min;
				}
				return true;
			}
		}

	public:
		BSTree()
			:_root(nullptr)
		{}

		//析构
		~BSTree()
		{
			_Destroy(_root);
			_root = nullptr;
		}

		//拷贝构造
		BSTree(const BSTree<K,V>& tree)
		{
			//递归拷贝
			_root = _Copy(tree._root);
		}

		//赋值运算符
		//t1=t2
		BSTree<K,V>& operator=(BSTree<K,V> tree)
		{
			swap(_root, tree._root);
			return *this;
		}

		bool InsertR(const K& key,const V& value)
		{
			return _InsertR(_root, key,value);
		}

		Node* FindR(const K& key)
		{//为了递归保证参数
			return _FindR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << " : " << root->_value << endl;
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
}
#include <iostream>
using namespace std;

namespace K
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
	private:
		// ��������Ѿ�����key������false
		bool _InsertR(Node*& root, const K& key)
		{
			if (root == NULL)  // ����
			{
				root = new Node(key);
				return true;
			}

			if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else
			{
				return false;
			}
		}

		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return root;
			}
		}

		// ������в�����key������false
		// ���ڣ�ɾ���󣬷���true
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == NULL)
			{
				return false;
			}

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				// �ҵ��ˣ�root����Ҫɾ���Ľڵ�
				if (root->_left == nullptr)
				{
					Node* del = root;
					root = root->_right;
					delete del;
				}
				else if (root->_right == nullptr)
				{
					Node* del = root;
					root = root->_left;
					delete del;
				}
				else
				{
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					K min = minRight->_key;

					// ת������root��������ɾ��min
					_EraseR(root->_right, min);
					root->_key = min;
				}

				return true;
			}
		}

		void _Destory(Node* root)
		{
			if (root == NULL)
			{
				return;
			}

			_Destory(root->_left);
			_Destory(root->_right);
			delete root;
		}

		Node* _Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* copyNode = new Node(root->_key);
			copyNode->_left = _Copy(root->_left);
			copyNode->_right = _Copy(root->_right);

			return copyNode;
		}

	public:
		BSTree()
			:_root(nullptr)
		{}

		BSTree(const BSTree<K>& t)
		{
			_root = _Copy(t._root);
		}

		// t1 = t2
		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree()
		{
			_Destory(_root);
			_root = nullptr;
		}

		// �漰��ǳ��������Ҫʵ�ֿ������� operator=��

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		Node* FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

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
}


namespace KV
{
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;

		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value)
			: _left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	private:
		// ��������Ѿ�����key������false
		bool _InsertR(Node*& root, const K& key, const V& value)
		{
			if (root == NULL)  // ����
			{
				root = new Node(key, value);
				return true;
			}

			if (root->_key < key)
			{
				return _InsertR(root->_right, key, value);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key, value);
			}
			else
			{
				return false;
			}
		}

		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return root;
			}
		}

		// ������в�����key������false
		// ���ڣ�ɾ���󣬷���true
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == NULL)
			{
				return false;
			}

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				// �ҵ��ˣ�root����Ҫɾ���Ľڵ�
				if (root->_left == nullptr)
				{
					Node* del = root;
					root = root->_right;
					delete del;
				}
				else if (root->_right == nullptr)
				{
					Node* del = root;
					root = root->_left;
					delete del;
				}
				else
				{
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					K kmin = minRight->_key;
					V vMin = minRight->_value;

					// ת������root��������ɾ��min
					_EraseR(root->_right, kmin);
					root->_key = kmin;
					root->_value = vMin;
				}

				return true;
			}
		}

		void _Destory(Node* root)
		{
			if (root == NULL)
			{
				return;
			}

			_Destory(root->_left);
			_Destory(root->_right);
			delete root;
		}

		Node* _Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* copyNode = new Node(root->_key, root->_value);
			copyNode->_left = _Copy(root->_left);
			copyNode->_right = _Copy(root->_right);

			return copyNode;
		}

	public:
		BSTree()
			:_root(nullptr)
		{}

		BSTree(const BSTree<K, V>& t)
		{
			_root = _Copy(t._root);
		}

		// t1 = t2
		BSTree<K, V>& operator=(BSTree<K, V> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree()
		{
			_Destory(_root);
			_root = nullptr;
		}

		// �漰��ǳ��������Ҫʵ�ֿ������� operator=��

		bool InsertR(const K& key, const V& value)
		{
			return _InsertR(_root, key, value);
		}

		Node* FindR(const K& key)
		{
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
			cout << root->_key << ":" << root->_value << endl;
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
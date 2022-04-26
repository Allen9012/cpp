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
		//�������Щ��װ�ĺ������Է���˽�еģ� ��������޷�����
	private:

		//��װ����
		void _Destroy(Node* root)
		{//�����������
			if (root==nullptr)
				return;
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
		}

		//��װ��������
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
			//���Ϊ��
			if (root==nullptr)
				return nullptr;

			//�����Ϊ��
			if (root->_key>key)
				return _FindR(root->_left,key);
			else if(root->_key<key)
				return _FindR(root->_right,key);
			else
				return _root;
		}

		//������ͬ�ڵ�
		bool _InsertR(Node*& root, const K& key)
		{
			if (root== nullptr)   //����
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
			
			//Ѱ�Ҹýڵ�
			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else
			{//�ҵ���,Ҫɾ��root
				if (root->_left==nullptr)
				{//�����գ���������
					Node* del = root;//����Ҫɾ���ı���һ�¹���ɾ��
					root = root->_right;//�ҵ�ɾ���ڵ���Һ���
					delete del;//ɾ���ڵ�
				} 
				else if(root->_right==nullptr)
				{//�����գ���������
					Node* del = root;
					root = root->_left;
					delete del;
				}
				else
				{//�����Ӷ�����,�������������Ӵ�
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					K  min = minRight->_key;

					// ת������root��������ɾ��min
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

		//����
		~BSTree()
		{
			_Destroy(_root);
			_root = nullptr;
		}

		//��������
		BSTree(const BSTree<K>& tree)
		{
			//�ݹ鿽��
			_root=_Copy(tree._root);
		}
			
		//��ֵ�����
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


		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}



		Node* FindR(const K& key)
		{//Ϊ�˵ݹ鱣֤����
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
		//�������Щ��װ�ĺ������Է���˽�еģ� ��������޷�����
	private:

		//��װ����
		void _Destroy(Node* root )
		{//�����������
			if (root == nullptr)
				return;
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
		}

		//��װ��������
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
			//���Ϊ��
			if (root == nullptr)
				return nullptr;

			//�����Ϊ��
			if (root->_key > key)
				return _FindR(root->_left, key);
			else if (root->_key < key)
				return _FindR(root->_right, key);
			else
				return _root;
		}

		//������ͬ�ڵ�
		bool _InsertR(Node*& root, const K& key, const V& value)
		{
			if (root == nullptr)   //����
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

			//Ѱ�Ҹýڵ�
			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else
			{//�ҵ���,Ҫɾ��root
				if (root->_left == nullptr)
				{//�����գ���������
					Node* del = root;//����Ҫɾ���ı���һ�¹���ɾ��
					root = root->_right;//�ҵ�ɾ���ڵ���Һ���
					delete del;//ɾ���ڵ�
				}
				else if (root->_right == nullptr)
				{//�����գ���������
					Node* del = root;
					root = root->_left;
					delete del;
				}
				else
				{//�����Ӷ�����,�������������Ӵ�
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					K  k_min = minRight->_key;
					V v_min = minRight->_value;

					// ת������root��������ɾ��min
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

		//����
		~BSTree()
		{
			_Destroy(_root);
			_root = nullptr;
		}

		//��������
		BSTree(const BSTree<K,V>& tree)
		{
			//�ݹ鿽��
			_root = _Copy(tree._root);
		}

		//��ֵ�����
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
		{//Ϊ�˵ݹ鱣֤����
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
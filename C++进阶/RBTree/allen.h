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
			 //�ѵ�
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

		//����
		pair<Node*, bool> Insert(const pair<K, V>& data)
		{
			//����
			if (_root==nullptr)
			{
				_root = new Node(data);
				_root->_col = BLACK;//�������Ǻڵ�
				return make_pair(_root, true);
			} 

			Node* parent = nullptr;
			Node* cur = _root;
			
			//1. ���ʵ��Ŀ�λ��
			while (cur)
			{
				if (cur->_kv.first<data.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_kv.first<data.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{//�ظ�
					return make_pair(cur, false);
				}
			}

			//2. cur�ߵ��� ��������
			Node* newnode = new Node(data);
			newnode->_col = RED;

			if (parent->_kv.first <data.first)
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

			//3.�жϴ�������
			//������״��ڣ�����ɫΪ��ɫ����Ҫ����
			while (parent && parent->_col == RED)
			{	
				//ץס�����ǹؼ�
				Node* grandfather = parent->_parent;
			//a. ���ȸ������游��ߵ����
				if (parent==grandfather->_left)
				{
					Node* uncle = grandfather->_right;
					//���1��uncle ������Ϊ��
					if (uncle && uncle->_col ==RED)
					{
						parent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;
						//�������ϴ���
						cur = grandfather;
						parent = cur->_parent;
					}

					//���2+3 uncle�����ڻ���uncle������Ϊ��
					else//��ʱ��ɫ�޷�����
					{
						//���2������
						if (cur==parent->_left)
						{   //1. �ҵ���
							_Rotate_R(parent);
							//2. ��ɫ
							grandfather->_col = RED;
							parent->_col = BLACK;
						} 
						else//���3��˫��
						{
							_Rotate_L(parent);
							_Rotate_R(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
						}
						break;//���Ǻڵ��ˣ���������Ӱ��ֱ��break
					}
				} 
				
				//b. ���ȸ������游��ߵ����
				else//parent == grandfather->_right
				{
					Node* uncle = grandfather->_left;
					//���1��uncle ������Ϊ�� 
					if (uncle && uncle->_col==RED)
					{
						uncle->_col=parent->_col = BLACK;
						grandfather->_col = RED;
						//�������ϵݹ�
						cur = grandfather;
						parent = cur->_parent;//����϶��и���
					} 
					//��� 2+3�� uncle�����ڻ�Ϊ��
					else
					{
						if (parent->_right==cur)
						{
							_Rotate_L(grandfather);
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
			//Ĭ���޸ĸ��ڵ�Ϊ��ɫ
			_root->_col = BLACK;
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
	private:
		Node* _root;
	};
}
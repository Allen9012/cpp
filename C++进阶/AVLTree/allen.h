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

		int _bf; // ƽ������  balance factor

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
			//1. ��ת
			parent->_left = subLR;
			//subLR�п����ǿյ�
			if (subLR)
			{
				subLR->_parent = parent;
			}
			subL->_right = parent;
			Node* grandparent = parent->_parent;//�ȼ�¼parent->_parent
			parent->_parent = subL;
	
			//2. �޸��¸��ӹ�ϵ
			if (parent == _root)
			{//��������
				_root = subL;
				_root->_parent = nullptr;
			}
			else
			{//���и��ף���Ҫ�޸ĸ��ף���Ҫ��¼���׵ĸ���
				if (grandparent->_left == parent)
					grandparent->_left = subL;
				else
					grandparent->_right = subL;

				subL->_parent = grandparent;
			}

			//3. �޸�ƽ������
			subL->_bf = parent->_bf = 0;
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

			//2. �޸��µĸ��ӹ�ϵ
			//����
			if (parent == _root)
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else
			{//���и��ף���Ҫ�޸ĸ��ף���Ҫ��¼���׵ĸ���
				if (grandparent->_left == parent)
					grandparent->_left = subR;
				else//grandparent->_right == parent
					grandparent->_right = subR;

				subR->_parent = grandparent;
			}

			//3. �޸�bf
			subR->_bf = parent->_bf = 0;
		}

		void _Rotate_LR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int bf = subLR->_bf;

			//����ת��
			_Rotate_L(parent->_left);
			//����ת��
			_Rotate_R(parent);
			
			//ƽ�����ӵ���
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

			//������
			_Rotate_R(parent->_right);
			//������
			_Rotate_L(parent);

			// ƽ�����Ӹ���
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
			
			//���ƽ��
			if (right_height - left_height != root->_bf)
			{
				cout << "ƽ�������쳣��" << root->_kv.first << endl;
				return false;
			}
			return abs(right_height - left_height) < 2 
				&& _IsBalance(root->_left) 
				&& _IsBalance(root->_right);
		}


	public:
		//����
		AVLTree()
			:_root(nullptr)
		{}

		//����
		~AVLTree()
		{
			_Destroy(_root);
			_root = nullptr;
		}

		//�����������

		//��ֵ�������

		//����
		pair<Node*,bool> Insert(const pair<K, V>& kv)
		{
			//1. ����
			if (_root==nullptr)
			{
				_root = new Node(kv);
				return make_pair(_root, true);
			} 
			Node* parent = _root, * cur = _root;
			//2. �ҵ��ڵ�
			while (cur)
			{//��ͨ�汾����������
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
				else//�����ظ�ֱ��false
					return make_pair(cur,false);//����ʧ�ܷ��غ�����ڵ���ȵĽڵ�
			}

			cur = new Node(kv);
			Node* newnode = cur;

			//3. ���ӽڵ㣬ע�����������ṹ
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

			//4. ����ƽ������
			while (cur != _root)
			{
				if (parent->_left == cur)
					cur->_parent->_bf--;//�½ڵ�����parent��
				else
					cur->_parent->_bf++;//�½ڵ�����parent��

				//1. bf==0 ֹͣ
				if (parent->_bf == 0)
				{
					break;
				}
				//2. bf==1 || bf==-1 ����������
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				//3. _bf == 2 ||_bf == -2  parent���ڵ�������ƽ�⣬��Ҫ��ת����һ��
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					if (parent->_bf == -2)
					{
						if (cur->_bf == -1)
						{//�ҵ���
							_Rotate_R(parent);
						}
						else //cur->_bf == 1
						{//����˫��
							_Rotate_LR(parent);
						}
					}
					else   //parent->_bf == 2
					{
						if (cur->_bf == 1)
						{
							//����
							_Rotate_L(parent);
						}
						else //cur->_bf == -1
						{//�ҵ���
							_Rotate_RL(parent);
						}
					}

					break;
				}
				else//֮ǰ�ĳ����ˣ�����assert
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

		//����
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

		//ɾ��
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
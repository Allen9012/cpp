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
	private:


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
			//2. �޸�ƽ������
			subL->_bf = parent->_bf = 0;
			//3. �޸��¸��ӹ�ϵ
			if (parent == _root)
			{//��������
				_root = subL;
				_root->_parent = nullptr;
			}
			else
			{//���и��ף���Ҫ�޸ĸ��ף���Ҫ��¼���׵ĸ���
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

			//1. ��ת
			parent->_right = subRL;
			if (subRL)
			{
				subRL->_parent = parent;
			}
			subR->_left = parent;
			Node* grandparent = parent->_parent;
			parent->_parent = subR;

			//2. �޸�bf
			subR->_bf = parent->_bf = 0;

			//3. �޸��µĸ��ӹ�ϵ
			//����
			if (parent == _root)
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else
			{//���и��ף���Ҫ�޸ĸ��ף���Ҫ��¼���׵ĸ���
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
			//����ת��
			_Rotate_L(parent->left);
			//����ת��
			_Rotate_R(parent->_right);
			//ƽ�����ӵ���

		}
		void _Rotate_RL(Node* parent)
		{

		}


	public:
		typedef AVLTreeNode<K, V> Node;
		//����
		AVLTree()
			:_root(nullptr)
		{}

		//����
		~AVLTree()
		{
			//
		}

		//�����������

		//��ֵ�������

		//����
		bool Insert(const pair<K, V>& kv)
		{
			//1. ����
			if (_root==nullptr)
			{
				_root = new Node(kv);
				return true;
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
					return false;
			}

			cur = new Node(kv);
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
				
				//bf==0 ֹͣ
				if (parent->_bf == 0)
					break;
				//bf==1 || bf==-1 ����������
				else if (parent->_bf==1 || parent->_bf == -1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				//_bf == 2 ||_bf == -2  parent���ڵ�������ƽ�⣬��Ҫ��ת����һ��
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
				else//֮ǰ�ĳ����ˣ�����assert
					assert(false);
			}

			return true;
		}

		//����
		Node* Find(const K& key)
		{
			return nullptr;
		}

		//ɾ��
		bool Erase(const K& key)
		{
			return false;
		}

	private:
		Node* _root;
	};

}
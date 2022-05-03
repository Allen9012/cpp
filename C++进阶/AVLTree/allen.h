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
				//��ת
				else if(parent->_bf == 2 || parent->_bf == -2)
				{
					//parent���ڵ�������ƽ�⣬��Ҫ��ת����һ��

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
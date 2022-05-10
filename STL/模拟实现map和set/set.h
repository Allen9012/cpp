#pragma once
#include "RB-tree.h"
namespace allen
{
	template<class K>
	class set
	{
		//�ڲ����װһ���º�������������key
		struct set_KeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		//������Ҫ��һ��typename��Ϊ����ĺ������û��ʵ������û��ʵ��������ȥ�������������ͣ�����˵Ҫ��
		typedef typename RBTree<K,K,set_KeyOfT>::iterator  iterator;
		typedef typename RBTree<K, K, set_KeyOfT>::reverse_iterator reverse_iterator;

		reverse_iterator rbegin()
		{
			return _t.rbegin();
		}

		reverse_iterator rend()
		{
			return _t.rend();
		}

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const K& k)
		{
			return _t.Insert(k);
		}
	private:
		RBTree<K, K,set_KeyOfT> _t;
	};
}
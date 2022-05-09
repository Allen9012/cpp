#pragma once
#include "RB-tree.h"
namespace allen
{
	template<class K, class V>
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
		typedef typename RBTree<K,K,set_KeyOfT>::iterator  iterator;
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		bool insert(const K& k)
		{
			_t.Insert(k);
			return true;
		}
	private:
		RBTree<K, K,set_KeyOfT> _t;
	};
}
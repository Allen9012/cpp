#pragma once
#include "RB-tree.h"
namespace allen
{
	template<class K, class V>
	class map
	{
		//内部类封装一个仿函数，用来返回key
		struct map_KeyOfT
		{
			const K& operator()(const pair<const K,V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef  typename RBTree<K, pair<const K, V>, map_KeyOfT>::iterator  iterator;
		typedef typename RBTree<K, pair<const K, V>, map_KeyOfT>::reverse_iterator reverse_iterator;

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

		pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		RBTree<K, pair<const K, V>, map_KeyOfT> _t;
	};
}
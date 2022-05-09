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
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		bool insert(const pair<const K, V>& kv)
		{
			_t.Insert(kv);
			return true;
		}
	private:
		RBTree<K, pair<const K, V>, map_KeyOfT> _t;
	};
}
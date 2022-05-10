#pragma once
#include "RB-tree.h"
namespace allen
{
	template<class K>
	class set
	{
		//内部类封装一个仿函数，用来返回key
		struct set_KeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		//这里需要加一个typename因为这里的红黑树还没有实例化，没有实例化不能去类内找内置类型，所以说要加
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
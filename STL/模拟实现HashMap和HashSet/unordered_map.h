#pragma once
#include"HashTable.h"

namespace allen
{
	template<class K,class V>
	class unordered_map
	{
		struct Map_Key_Of_T
		{
			const K& operator()(const pair<K,V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename Open_Hash::HashTable<K, pair<K,V>, Map_Key_Of_T>::iterator iterator;
		
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		pair<iterator,bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		Open_Hash::HashTable<K, pair<K, V>, Map_Key_Of_T> _ht;
	};


	void test_unordered_map1()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "排序"));
		dict["left"] = "左边";
		dict["left"] = "剩余";
		dict["map"] = "映射";
		dict["string"] = "字符串";
		dict["set"] = "集合";

		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}
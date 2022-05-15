#pragma once
#include"HashTable.h"
namespace allen
{
	template<class K>
	class unordered_set
	{
		struct Set_Key_Of_T
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename Open_Hash::HashTable<K, K, Set_Key_Of_T>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool insert(const K& key)
		{
			_ht.Insert(key);
			return true;
		}
	private:
		Open_Hash::HashTable<K,  K, Set_Key_Of_T> _ht;
	};


	void test_unordered_set1()
	{
		unordered_set<int> us;
		us.insert(200);
		us.insert(1);
		us.insert(2);
		us.insert(33);
		us.insert(50);
		us.insert(60);
		us.insert(243);
		us.insert(6);

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			cout << *it << " ";
			++it;
		}
	}
}
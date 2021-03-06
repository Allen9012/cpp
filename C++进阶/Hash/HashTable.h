#pragma once
#include <vector>
using std::vector;
using std::make_pair;
namespace Close_Hash
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE,
	};

	template <class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;//默认给空
	};

	template<class K>
	struct Hash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	// 特化
	template<>
	struct Hash<string>
	{
		// "int"  "insert" 
		// 字符串转成对应一个整形值，因为整形才能取模算映射位置
		// 期望->字符串不同，转出的整形值尽量不同
		// "abcd" "bcad"
		// "abbb" "abca"
		size_t operator()(const string& s)
		{
			// BKDR Hash
			size_t value = 0;
			for (auto ch : s)
			{
				value += ch;
				value *= 131;
			}

			return value;
		}
	};


	template <class K, class V,class HashFunc=Hash<K>>
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			//防止重复
			auto ret = Find(kv.first);
			if (ret)
			{
				return false;
			}

			//空表
			if (_table.size() == 0)
			{
				_table.resize(10);
			}
			//负载0.7
			else if ((double)_n / (double)_table.size() >= 0.7)
			{
				//增容
					//vector<HashData> newtable;
					// newtable.resize(_table.size*2);
					//for (auto& e:_table)
					//{
					//	if (e._state==EXIST)
					//	{
					//		//重新计算放到newtable
					//		//逻辑类似插入
					//	}
					//}
					//_table.swap(newtable);
				HashTable<K, V,HashFunc> newHT;
				newHT._table.resize(_table.size() * 2);
				for (auto& e : _table)
				{
					if (e._state == EXIST)
					{
						newHT.Insert(e._kv);
					}
				}
				_table.swap(newHT._table);
			}
			
			HashFunc hf;
			size_t start = hf(kv.first) % _table.size();
			size_t index = start;

			// 探测后面的位置 -- 线性探测 or 二次探测
			size_t i = 1;
			while (_table[index]._state == EXIST)
			{
				index = start + i;
				index %= _table.size();
				++i;
			}

			_table[index]._kv = kv;
			_table[index]._state = EXIST;
			++_n;

			return true;
		}

		HashData<K,V>* Find(const K& key)
		{
			if (_table.size() == 0)
			{
				return nullptr;
			}

			HashFunc hf;
			size_t start = hf(key) % _table.size();
			size_t index = start;
			size_t i = 1;
			while (_table[index]._state != EMPTY)
			{
				if (_table[index]._state == EXIST
					&& _table[index]._kv.first == key)
				{
					return &_table[index];
				}

				index = start + i;
				index %= _table.size();
				++i;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				ret->_state = DELETE;
				return true;
			}
		}

	private:
		vector<HashData<K,V>> _table;
		size_t _n=0;  //存储的有效数据个数
	};



	void TestHashTable()
	{
		vector<int> v= {1, 5, 10, 100000, 100, 18, 15, 7, 40};
		HashTable<int, int,Hash<int>> ht;
		for (auto e: v)
		{
			ht.Insert(make_pair(e, e));
		}
	}

	void TestHashTable2()
	{
		string a[] = { "皮卡丘", "喷火龙", "皮卡丘", "喷火龙", "皮卡丘", "路卡利欧", "皮卡丘" };
		HashTable<string, int,Hash<string>> ht;
		for (auto str : a)
		{
			auto ret = ht.Find(str);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(str, 1));
			}
		}
	}

	struct pokemon
	{
		// ...
	};

	struct PokemonHashFunc
	{
		size_t operator()(const pokemon& kv)
		{
			// 如果是结构体
			// 1、比如说结构体中有一个整形，基本是唯一值 - pokemon序号
			// 2、比如说结构体中有一个字符串，基本是唯一值 - pokemon name
			// 3、如果没有一项是唯一值，可以考虑多项组合
			size_t value = 0;
			// ...
			return value;
		}
	};

	void TestHashTable3()
	{
		string a[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "橘子", "苹果" };
		// 任意类型都可以做key，跟上一个把这个类型对象转换成整形的仿函数即可
		HashTable<pokemon, int, PokemonHashFunc> ht;
	}


}


namespace Open_Hash
{
	const int PRIMECOUNT = 28;
	const size_t primeList[PRIMECOUNT] =
	{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
	};
	size_t GetNextPrime(size_t prime)
	{
		size_t i = 0;
		for (; i < PRIMECOUNT; ++i)
		{
			if (primeList[i] > primeList[i])
				return primeList[i];
		}
		return primeList[i];
	}

	template<class K,class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;

		HashNode(const pair<K,V>& kv)
			:_next(nullptr)
			,_kv(kv)
		{}
	};
	
	template<class K>
	struct Hash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};
	// 特化
	template<>
	struct Hash<string>
	{
		size_t operator()(const string& s)
		{
			// BKDR Hash
			size_t value = 0;
			for (auto ch : s)
			{
				value += ch;
				value *= 131;
			}

			return value;
		}
	};

	template<class K, class V,class HashFunc=Hash<K>>
	class HashTable 
	{
		typedef HashNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			//有相同数据直接false
			if (Find(kv.first))
				return false;
			HashFunc hf;
			//负载因子，到一的时候，进行增容
			if (_n == _table.size())
			{
				vector<Node*> newtable;
				/*size_t new_size = _table.size() == 0 ? 10 : _table.size() * 2;
				newtable.resize(new_size);*/
				newtable.resize(GetNextPrime(_table.size()));
				//旧表节点重新算位置搞到新表
				for (size_t i=0;i<_table.size();++i)
				{
					if (_table[i])
					{
						Node* cur = _table[i];
						while (cur)
						{
							Node* next = cur->_next;
							size_t index = hf(cur->_kv.first) % newtable.size();
							//头插
							cur->_next = newtable[index];
							newtable[index] = cur;
							//原表迭代
							cur = next;
						}
						_table[i] = nullptr;
					}
				}
				_table.swap(newtable);
			}

			//没有到1，直接链接
			size_t index = hf(kv.first) % _table.size();
			Node* newnode = new Node(kv);
			//头插,而且也不用排空
			newnode->_next = _table[index];
			_table[index] = newnode;
			++_n;
			return true;
		}

		Node* Find(const K& key)
		{
			if (_table.size() == 0)
			{
				return nullptr;
			}
			HashFunc hf;
			size_t index = hf(key) % _table.size();
			Node* cur = _table[index];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashFunc hf;
			size_t index =hf(key) % _table.size();
			Node* cur = _table[index];
			Node* prev=nullptr;
			while (cur)
			{
				if (cur->_kv.first==key)
				{
					if (_table[index]==cur)
					{
						_table[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					cur = nullptr;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

	private:
		vector<Node*> _table;//存的是指针
		size_t _n = 0;  //有效数据个数
	};


	void TestHashTable()
	{
		vector<int> v = { 1, 5, 10, 100000, 100, 18, 15, 7, 40 ,44};
		HashTable<int, int> ht;
		for (auto e : v)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Insert(make_pair(25, 25));
	}

	void TestHashTable2()
	{
		string a[] = { "皮卡丘", "喷火龙", "皮卡丘", "喷火龙", "皮卡丘", "路卡利欧", "皮卡丘" };
		HashTable<string, int, Hash<string>> ht;
		for (auto str : a)
		{
			auto ret = ht.Find(str);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(str, 1));
			}
		}
	}

	struct pokemon
	{
		// ...
	};

	struct PokemonHashFunc
	{
		size_t operator()(const pokemon& kv)
		{
			// 如果是结构体
			// 1、比如说结构体中有一个整形，基本是唯一值 - pokemon序号
			// 2、比如说结构体中有一个字符串，基本是唯一值 - pokemon name
			// 3、如果没有一项是唯一值，可以考虑多项组合
			size_t value = 0;
			// ...
			return value;
		}
	};

	void TestHashTable3()
	{
		string a[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "橘子", "苹果" };
		// 任意类型都可以做key，跟上一个把这个类型对象转换成整形的仿函数即可
		HashTable<pokemon, int, PokemonHashFunc> ht;
	}
}
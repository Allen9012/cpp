#pragma once
#include <vector>
using std::vector;
using std::make_pair;

//namespace Close_Hash
//{
//	enum State
//	{
//		EMPTY,
//		EXIST,
//		DELETE,
//	};
//
//	template <class K, class V>
//	struct HashData
//	{
//		pair<K, V> _kv;
//		State _state = EMPTY;//Ĭ�ϸ���
//	};
//
//	template<class K>
//	struct Hash
//	{
//		size_t operator()(const K& key)
//		{
//			return key;
//		}
//	};
//
//	// �ػ�
//	template<>
//	struct Hash<string>
//	{
//		// "int"  "insert" 
//		// �ַ���ת�ɶ�Ӧһ������ֵ����Ϊ���β���ȡģ��ӳ��λ��
//		// ����->�ַ�����ͬ��ת��������ֵ������ͬ
//		// "abcd" "bcad"
//		// "abbb" "abca"
//		size_t operator()(const string& s)
//		{
//			// BKDR Hash
//			size_t value = 0;
//			for (auto ch : s)
//			{
//				value += ch;
//				value *= 131;
//			}
//
//			return value;
//		}
//	};
//
//
//	template <class K, class V,class HashFunc=Hash<K>>
//	class HashTable
//	{
//	public:
//		bool Insert(const pair<K, V>& kv)
//		{
//			//��ֹ�ظ�
//			auto ret = Find(kv.first);
//			if (ret)
//			{
//				return false;
//			}
//
//			//�ձ�
//			if (_table.size() == 0)
//			{
//				_table.resize(10);
//			}
//			//����0.7
//			else if ((double)_n / (double)_table.size() >= 0.7)
//			{
//				HashTable<K, V,HashFunc> newHT;
//				newHT._table.resize(_table.size() * 2);
//				for (auto& e : _table)
//				{
//					if (e._state == EXIST)
//					{
//						newHT.Insert(e._kv);
//					}
//				}
//				_table.swap(newHT._table);
//			}
//			
//			HashFunc hf;
//			size_t start = hf(kv.first) % _table.size();
//			size_t index = start;
//
//			// ̽������λ�� -- ����̽�� or ����̽��
//			size_t i = 1;
//			while (_table[index]._state == EXIST)
//			{
//				index = start + i;
//				index %= _table.size();
//				++i;
//			}
//
//			_table[index]._kv = kv;
//			_table[index]._state = EXIST;
//			++_n;
//
//			return true;
//		}
//
//		HashData<K,V>* Find(const K& key)
//		{
//			if (_table.size() == 0)
//			{
//				return nullptr;
//			}
//
//			HashFunc hf;
//			size_t start = hf(key) % _table.size();
//			size_t index = start;
//			size_t i = 1;
//			while (_table[index]._state != EMPTY)
//			{
//				if (_table[index]._state == EXIST
//					&& _table[index]._kv.first == key)
//				{
//					return &_table[index];
//				}
//
//				index = start + i;
//				index %= _table.size();
//				++i;
//			}
//
//			return nullptr;
//		}
//
//		bool Erase(const K& key)
//		{
//			HashData<K, V>* ret = Find(key);
//			if (ret == nullptr)
//			{
//				return false;
//			}
//			else
//			{
//				ret->_state = DELETE;
//				return true;
//			}
//		}
//
//	private:
//		vector<HashData<K,V>> _table;
//		size_t _n=0;  //�洢����Ч���ݸ���
//	};
//
//}


namespace Open_Hash
{
	template<class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data)
			:_next(nullptr)
			, _data(data)
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
	// �ػ�
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

	//ǰ������
	template<class K, class T, class Key_Of_T, class HashFunc>
	class HashTable;

	template<class K, class T, class Key_Of_T, class HashFunc = Hash<K>>
	struct __HTIterator
	{
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, Key_Of_T, HashFunc> Self;
		typedef HashTable<K, T, Key_Of_T, HashFunc>   HT;
		Node* _node;
		HT* _pht;
		__HTIterator(Node* node, HT* pht)
			:_node(node)
			, _pht(pht)
		{}

		Self& operator++()
		{
			//1.��ǰͰ�л�������,ֱ��������
			if (_node->_next)
			{
				_node = _node->_next;
			}
			//2.��ǰ������
			else
			{
				//�ߵ���һ��Ͱ��
				Key_Of_T kot;
				HashFunc hf;
				size_t index = hf(kot(_node->_data)) % _pht->_table.size();
				
				++index;
				//Ҫ�ҵ������ݵ�Ͱ
				while (index < _pht->_table.size())
				{
					if (_pht->_table[index])
					{
						_node = _pht->_table[index];
						return *this;
					}
					else
					{
						++index;
					}
				}
				_node = nullptr;
			}
			return *this;
		}

		Self& operator--()
		{

		}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator != (const Self& s) const
		{
			return _node != s._node;
		}

		bool operator == (const Self& s) const
		{
			return _node == s.node;
		}

	};

	template<class K, class T, class Key_Of_T,class HashFunc =Hash<K>>
	class HashTable 
	{
	public:
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, Key_Of_T, HashFunc> iterator;

		template<class K, class T, class Key_Of_T, class HashFunc>
		friend struct __HTIterator;
		
		iterator begin()
		{
			size_t i = 0;
			while (i<_table.size())
			{
				if(_table[i])
				{
					return iterator(_table[i], this);
				}
				++i;
			}
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}
		//����
		HashTable() = default;//��ʾָ��

		//��������
		HashTable(const HashTable& ht)	//����Ϳ������Բ�дģ��
		{
			_n = ht._n;
			_table.resize(ht._table.size());
			for (size_t i = 0; i < ht._table.size(); i++)
			{
				Node* cur = ht._table[i];
				while (cur)
				{
					Node* copy = new Node(cur->_data);
					// ͷ�嵽�±�
					copy->_next = _table[i];
					_table[i] = copy;

					cur = cur->_next;
				}
			}
		}

		//��ֵ����
		HashTable& operator=(HashTable ht)
		{
			_table.swap(ht._table);
			swap(_n, ht._n);

			return *this;
		}

		//����
		~HashTable()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}

		//����
		size_t GetNextPrime(size_t prime)
		{
			const int PRIMECOUNT = 28;
			static size_t primeList[PRIMECOUNT] =
			{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
			};
			size_t i = 0;
			for (; i < PRIMECOUNT; ++i)
			{
				if (primeList[i] > prime)
					return primeList[i];
			}
			return primeList[i];
		}

	
		pair<iterator,bool> Insert(const T& data)
		{
			Key_Of_T kot;
			//����ͬ����ֱ��false
			auto ret = Find(kot(data));
			if (ret != end())
			{
				return make_pair(ret, false);
			}

			HashFunc hf;
			//�������ӣ���һ��ʱ�򣬽�������
			if (_n == _table.size())
			{
				vector<Node*> newtable;
				/*size_t new_size = _table.size() == 0 ? 10 : _table.size() * 2;
				newtable.resize(new_size);*/
				newtable.resize(GetNextPrime(_table.size()));
				//�ɱ�ڵ�������λ�ø㵽�±�
				for (size_t i=0;i<_table.size();++i)
				{
					if (_table[i])
					{
						Node* cur = _table[i];
						while (cur)
						{
							Node* next = cur->_next;
							size_t index = hf(kot(cur->_data)) % newtable.size();
							//ͷ��
							cur->_next = newtable[index];
							newtable[index] = cur;
							//ԭ�����
							cur = next;
						}
						_table[i] = nullptr;
					}
				}
				_table.swap(newtable);
			}

			//û�е�1��ֱ������
			size_t index = hf(kot(data)) % _table.size(); 
			Node* newnode = new Node(data);
			//ͷ��,����Ҳ�����ſ�
			newnode->_next = _table[index];
			_table[index] = newnode;
			++_n;
			return make_pair(iterator(newnode,this), true);
		}

		iterator Find(const K& key)
		{
			if (_table.size() ==0)
			{
				return end();
			}

			Key_Of_T kot;
			if (_table.size() == 0)
			{
				return end();
			}
			HashFunc hf;
			size_t index = hf(key) % _table.size();
			Node* cur = _table[index];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur,this);
				}
				else
				{
					cur = cur->_next;
				}
			}
			return end();
		}

		bool Erase(const K& key)
		{
			Key_Of_T kot;

			HashFunc hf;
			size_t index =hf(key) % _table.size();
			Node* cur = _table[index];
			Node* prev=nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
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
		vector<Node*> _table;//�����ָ��
		size_t _n = 0;  //��Ч���ݸ���
	};

}
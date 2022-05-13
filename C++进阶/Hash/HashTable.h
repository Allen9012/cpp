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
		State _state = EMPTY;//Ĭ�ϸ���
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
		// "int"  "insert" 
		// �ַ���ת�ɶ�Ӧһ������ֵ����Ϊ���β���ȡģ��ӳ��λ��
		// ����->�ַ�����ͬ��ת��������ֵ������ͬ
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


	template <class K, class V,class HashFunc>
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			//��ֹ�ظ�
			auto ret = Find(kv.first);
			if (ret)
			{
				return false;
			}

			//�ձ�
			if (_table.size() == 0)
			{
				_table.resize(10);
			}
			//����0.7
			else if ((double)_n / (double)_table.size() >= 0.7)
			{
				//����
					//vector<HashData> newtable;
					// newtable.resize(_table.size*2);
					//for (auto& e:_table)
					//{
					//	if (e._state==EXIST)
					//	{
					//		//���¼���ŵ�newtable
					//		//�߼����Ʋ���
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

			// ̽������λ�� -- ����̽�� or ����̽��
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
		size_t _n=0;  //�洢����Ч���ݸ���
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
		string a[] = { "Ƥ����", "�����", "Ƥ����", "�����", "Ƥ����", "·����ŷ", "Ƥ����" };
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
			// ����ǽṹ��
			// 1������˵�ṹ������һ�����Σ�������Ψһֵ - pokemon���
			// 2������˵�ṹ������һ���ַ�����������Ψһֵ - pokemon name
			// 3�����û��һ����Ψһֵ�����Կ��Ƕ������
			size_t value = 0;
			// ...
			return value;
		}
	};

	void TestHashTable3()
	{
		string a[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "����", "ƻ��" };
		// �������Ͷ�������key������һ����������Ͷ���ת�������εķº�������
		HashTable<pokemon, int, PokemonHashFunc> ht;
	}


}


namespace Open_Hash
{
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
	
	template<class K, class V>
	class HashTable 
	{
		typedef HashNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}
			size_t index = kv.first % _table.size();
			Node* newnode = new Node(kv);
			//ͷ��,����Ҳ�����ſ�
			newnode->_next = _table[index];
			_table[index] = newnode;
			return true;
		}

		Node* Find(const K& key)
		{
			size_t index = kv.first % _table.size();
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
			size_t index = kv.first % _table.size();
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
		vector<Node*> _table;//�����ָ��
		size_t _n = 0;  //��Ч���ݸ���
	};
}
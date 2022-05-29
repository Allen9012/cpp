#pragma once


template<class K,class V,size_t M>
struct BTreeNode
{
	/*pair<K, V>						     _kvs[M - 1];
	BTreeNode<K, V, M>*		 _subs[M];*/

	//���һ���ռ䷽����ѣ������Ļ����Բ���֮���ٷ��ѣ���Ȼ�Ļ��͵��ȷ����ٸ����
	pair<K, V>						     _kvs[M];
	BTreeNode<K, V, M>*		_subs[M+1];
	BTreeNode<K, V, M>*		 _parent;

	size_t _kvSize;

	BTreeNode()
		: _kvSize(0)
		,_parent(nullptr)
	{
			for (int i=0;i<M+1;++i)
			{
				_subs[i] = nullptr;
			}
	}
};

template<class K, class V, size_t M>
class BTree
{
	typedef BTreeNode<K, V, M> Node;

private:
	// ��cur�������һ��kv��sub
	void InsertKV(Node* cur, const pair<K, V>& kv, Node* sub)
	{
		// ��kv�ҵ����ʵ�λ�ò����ȥ
		int i = static_cast<int> (cur->_kvSize - 1);
		for (; i >= 0; )
		{
			if (cur->_kvs[i].first < kv.first)
			{
				break;
			}
			else
			{
				//kv[i]����Ų����kv[i]���Һ���ҲŲ��
				cur->_kvs[i + 1] = cur->_kvs[i];
				cur->_subs[i + 2] = cur->_subs[i + 1];
				--i;
			}
		}

		cur->_kvs[i + 1] = kv;
		cur->_subs[i + 2] = sub;
		cur->_kvSize++;
		if (sub)
		{
			sub->_parent = cur;
		}
	}

	void _InOrder(Node* cur)
	{
		if (cur == nullptr)
		{
			return;
		}

		size_t i = 0;
		while (i < cur->_kvSize)
		{
			// �ȷ������������ٷ��ʵ�ǰֵ
			_InOrder(cur->_subs[i]);
			cout << cur->_kvs[i].first << " ";
			++i;
		}

		// �ٷ������һ��������
		_InOrder(cur->_subs[i]);
	}
public:

	pair <Node*,int> Find(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			size_t i = 0;
			while (i < cur->_kvSize) //���M�Ƚϴ󣬾͸ĳɶ��ֲ���
			{
				if (cur->_kvs[i].first < key) //key���ڵ�ǰλ��key��������
					++i;
				else if (cur->_kvs[i].first > key)//keyС�ڵ�ǰλ�õ�key����������ȥ��
					break;
				else
					return make_pair(cur, i);
			}
			parent = cur;
			cur = cur->_subs[i];
		}
		return make_pair(parent, -1);
	}

	bool Insert(const pair<K, V> kv)
	{
		//1. root==nullptr
		if (_root==nullptr)
		{
			_root = new Node;
			_root->_kvs[0] = kv;
			_root->_kvSize=1;
			return true;
		}

		//2. �ҵ�����λ��
		pair<Node*, int > ret = Find(kv.first);
		//�Ѿ����˾Ͳ��ܲ���(��ǰ�������������multi�汾)
		if (ret.second >= 0)//û�еĻ�second��-1
		{
			return false;
		}

		// ��cur�ڵ��в���һ��newkv��sub
		// 1�����curû���ͽ���
		// 2��������˾ͷ��ѣ����ѳ��ֵ��Ժ������ײ���һ���ؼ��ֺͺ��ӣ�������Ҫ��������
		// 3�����������Ƿ��ѵ�����ԭ�������ѣ�������һ���µĸ����ͽ�����
		// Ҳ����˵�����������Ѹ߶ȴ�
		Node* cur = ret.first;
		pair<K, V> newkv = kv;
		Node* sub = nullptr;

		while (1)
		{
			//�����µ�KV��kvs[]
			InsertKV(cur, newkv, sub); 

			// 1�����curû���ͽ���
			if (cur->_kvSize < M)
			{
				return true;
			}
			else // 2�����ˣ���Ҫ����
			{
				// ���ѳ�һ���ֵܽڵ㣬�����ڸýڵ����mid�ڵ��ұߵ�ֵ
				Node* newnode = new Node;

				// 1�������Ұ���������ѵ��ֵܽڵ�
				int mid = M / 2;
				int j = 0;
				int i = mid + 1;

				//�ȱ���mid�ڵ㣬���ԭλ��
				newkv = cur->_kvs[mid];
				cur->_kvs[mid] = pair<K, V>();
				//new�ڵ�ĺ������ϸ���
				for (; i < M; ++i)
				{//�������Ϻ��ӣ���һ���ÿ�һ��
					newnode->_kvs[j] = cur->_kvs[i];
					cur->_kvs[i] = pair<K, V>();
					newnode->_subs[j] = cur->_subs[i];
					cur->_subs[i] = nullptr;

					//�������Ӹ��ף����Ӻܿ����ǿյ�
					if (newnode->_subs[j])
					{
						newnode->_subs[j]->_parent = newnode;
					}
					//����j
					j++;
					newnode->_kvSize++;
				}

				// ��ʣ���һ���Һ���
				newnode->_subs[j] = cur->_subs[i];
				if (newnode->_subs[j])
				{
					newnode->_subs[j]->_parent = newnode;
				}

				cur->_kvSize = cur->_kvSize - newnode->_kvSize - 1;

				// 1�����curû�и��ף���ôcur���Ǹ��������µĸ�
				if (cur->_parent == nullptr)
				{
					_root = new Node;
					_root->_kvs[0] = newkv;
					_root->_subs[0] = cur;
					_root->_subs[1] = newnode;
					//�������Ӹ���
					cur->_parent = _root;
					newnode->_parent = _root;
					_root->_kvSize = 1;

					return true;
				}
				// 2�����cur�и��ף���ô��Ҫת������cur�ĸ����в���һ��key��һ������newnode
				else
				{
					// ������ȥ����newkv��newnode��ת���ɵ����߼�
					sub = newnode;
					cur = cur->_parent;
				}
			}
		}

		return true;
	}



	void InOrder()
	{
		_InOrder(_root);
	}

	

private:
	Node* _root=nullptr;
};


void TestBTree()
{
	BTree<int, int, 3> t;
	//BTree<int, int, 5> t;
	int a[] = { 53, 139, 75, 49, 145, 36, 101 };
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}

	t.InOrder();
}
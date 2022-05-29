#pragma once


template<class K,class V,size_t M>
struct BTreeNode
{
	/*pair<K, V>						     _kvs[M - 1];
	BTreeNode<K, V, M>*		 _subs[M];*/

	//多给一个空间方便分裂，这样的话可以插入之后再分裂，不然的话就得先分裂再搞插入
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
	// 往cur里面插入一个kv和sub
	void InsertKV(Node* cur, const pair<K, V>& kv, Node* sub)
	{
		// 将kv找到合适的位置插入进去
		int i = static_cast<int> (cur->_kvSize - 1);
		for (; i >= 0; )
		{
			if (cur->_kvs[i].first < kv.first)
			{
				break;
			}
			else
			{
				//kv[i]往后挪动，kv[i]的右孩子也挪动
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
			// 先访问左子树，再访问当前值
			_InOrder(cur->_subs[i]);
			cout << cur->_kvs[i].first << " ";
			++i;
		}

		// 再访问最后一个右子树
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
			while (i < cur->_kvSize) //如果M比较大，就改成二分查找
			{
				if (cur->_kvs[i].first < key) //key大于当前位置key，往右找
					++i;
				else if (cur->_kvs[i].first > key)//key小于当前位置的key，就往左孩子去找
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

		//2. 找到插入位置
		pair<Node*, int > ret = Find(kv.first);
		//已经有了就不能插入(当前如果允许插入就是multi版本)
		if (ret.second >= 0)//没有的话second是-1
		{
			return false;
		}

		// 往cur节点中插入一个newkv和sub
		// 1、如果cur没满就结束
		// 2、如果满了就分裂，分裂出兄弟以后，往父亲插入一个关键字和孩子，再满还要继续分裂
		// 3、最坏的情况就是分裂到根，原来根分裂，产生出一个新的根，就结束了
		// 也就是说，我们最多分裂高度次
		Node* cur = ret.first;
		pair<K, V> newkv = kv;
		Node* sub = nullptr;

		while (1)
		{
			//插入新的KV到kvs[]
			InsertKV(cur, newkv, sub); 

			// 1、如果cur没满就结束
			if (cur->_kvSize < M)
			{
				return true;
			}
			else // 2、满了，需要分裂
			{
				// 分裂出一个兄弟节点，后序在该节点插入mid节点右边的值
				Node* newnode = new Node;

				// 1、拷贝右半区间给分裂的兄弟节点
				int mid = M / 2;
				int j = 0;
				int i = mid + 1;

				//先保存mid节点，清空原位置
				newkv = cur->_kvs[mid];
				cur->_kvs[mid] = pair<K, V>();
				//new节点的孩子连上父亲
				for (; i < M; ++i)
				{//父亲连上孩子，连一个置空一个
					newnode->_kvs[j] = cur->_kvs[i];
					cur->_kvs[i] = pair<K, V>();
					newnode->_subs[j] = cur->_subs[i];
					cur->_subs[i] = nullptr;

					//孩子连接父亲，孩子很可能是空的
					if (newnode->_subs[j])
					{
						newnode->_subs[j]->_parent = newnode;
					}
					//迭代j
					j++;
					newnode->_kvSize++;
				}

				// 还剩最后一个右孩子
				newnode->_subs[j] = cur->_subs[i];
				if (newnode->_subs[j])
				{
					newnode->_subs[j]->_parent = newnode;
				}

				cur->_kvSize = cur->_kvSize - newnode->_kvSize - 1;

				// 1、如果cur没有父亲，那么cur就是根，产生新的根
				if (cur->_parent == nullptr)
				{
					_root = new Node;
					_root->_kvs[0] = newkv;
					_root->_subs[0] = cur;
					_root->_subs[1] = newnode;
					//孩子连接父亲
					cur->_parent = _root;
					newnode->_parent = _root;
					_root->_kvSize = 1;

					return true;
				}
				// 2、如果cur有父亲，那么就要转换成往cur的父亲中插入一个key和一个孩子newnode
				else
				{
					// 往父亲去插入newkv和newnode，转换成迭代逻辑
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
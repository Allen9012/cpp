#pragma once
#include<iostream>
namespace allen
{
	template<class T>
	struct _list_node
	{
		T _val;
		_list_node<T>* _next;
		_list_node<T>* _prev;
		_list_node(const T& val = T())
			:_val(val)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};

	template<class T, class Ref,  class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T,Ref,Ptr>  self;//自己类型,为了简洁一点，不然后面每一个都要写成带三个模板参数的
		node* _pnode;//封装一个节点的指针
		_list_iterator(node* pnode)
			: _pnode(pnode)
		{}

		T operator*()
		{
			return _pnode->_val;
		}

		bool operator!=(const self& s) const
		{
			return _pnode != s._pnode;
		}

		bool operator==(const self& s) const
		{
			return _pnode == s._pnode;
		}

		// ++it -> it.operator++(&it)
		self& operator++()
		{
			_pnode = _pnode->_next;
			return *this;
		}

		// it++ -> it.operator++(&it, 0)
		self operator++(int)
		{
			self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;
		}

		self& operator--()
		{
			_pnode = _pnode->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}
	};

	template<class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		typedef _list_iterator<T,  T&,T*> iterator;
		//传统想法是拷贝一下iterate，改成const的，但是代码重复是大量的
		//优化就是增加模板参数表
		typedef _list_iterator<T,  const T&, const T*> const_iterator;
		
		list()
		{
			_head = new node(T());//传一个匿名对象
			_head->_next = _head;
			_head->_prev = _head;
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

			const_iterator begin() const
			{
				return const_iterator(_head->_next);
			}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void push_back(const T& x)
		{
			node* newnode = new node(x);
			node* tail = _head->_prev;
			//head -----tail         newnode
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
	private:
		node* _head;
	};

	//void PrintList(const list<int>& lt)
	//{
	//	list<int>::const_iterator it = lt.begin();
	//	while (it != lt.end())
	//	{
	//		// *it += 1; // ?
	//		cout << *it << " ";
	//		++it;
	//	}
	//	cout << endl;
	//}

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//(*it) += 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		//PrintList(lt);
	}
}

#pragma once
#include<iostream>
using namespace std;
namespace bit
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

	// typedef _list_iterartor<T, T&, T*> iterator;
	// typedef _list_iterartor<T, const T&, const T*> const_iterator;
	template<class T, class Ref, class Ptr>
	struct _list_iterartor
	{
		typedef _list_node<T> node;
		typedef _list_iterartor<T, Ref, Ptr> self;

		node* _pnode;

		_list_iterartor(node* pnode)
			:_pnode(pnode)
		{}

		// 拷贝构造、operator=、析构我们不写，编译器默认生成就可以用

		Ref operator*()
		{
			return _pnode->_val;
		}

		//Ptr operator->

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

	// 这样写虽然可以，但是普通迭代器和const迭代器有大量重复冗余代码
	// 如何优化呢？
	//template<class T>
	//struct _list_const_iterartor
	//{
	//	typedef _list_node<T> node;
	//	typedef _list_const_iterartor<T> self;

	//	node* _pnode;

	//	_list_const_iterartor(node* pnode)
	//		:_pnode(pnode)
	//	{}

	//	// 拷贝构造、operator=、析构我们不写，编译器默认生成就可以用

	//	const T& operator*()
	//	{
	//		return _pnode->_val;
	//	}

	//	//operator->

	//	bool operator!=(const self& s) const
	//	{
	//		return _pnode != s._pnode;
	//	}

	//	bool operator==(const self& s) const
	//	{
	//		return _pnode == s._pnode;
	//	}

	//	// ++it -> it.operator++(&it)
	//	self& operator++()
	//	{
	//		_pnode = _pnode->_next;
	//		return *this;
	//	}

	//	// it++ -> it.operator++(&it, 0)
	//	self operator++(int)
	//	{
	//		self tmp(*this);
	//		_pnode = _pnode->_next;
	//		return tmp;
	//	}

	//	self& operator--()
	//	{
	//		_pnode = _pnode->_prev;
	//		return *this;
	//	}

	//	self operator--(int)
	//	{
	//		self tmp(*this);
	//		_pnode = _pnode->_prev;
	//		return tmp;
	//	}
	//};

	template<class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		typedef _list_iterartor<T, T&, T*> iterator;
		typedef _list_iterartor<T, const T&, const T*> const_iterator;


		// 只能读不能写，如何_list_iterartor中如何控制写呢？->
		//typedef _list_const_iterartor<T> const_iterator;


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

		list()
		{
			//_head = new node(T());
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			node* newnode = new node(x);
			node* tail = _head->_prev;
			// head         tail   newnode
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

	private:
		node* _head;
	};

	void PrintList(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			// *it += 1; // ?
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

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
			*it += 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		PrintList(lt);
	}
}
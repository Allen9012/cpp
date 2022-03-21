#pragma once
#include <cassert>
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

	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr>  self;//自己类型,为了简洁一点，不然后面每一个都要写成带三个模板参数的
		node* _pnode;//封装一个节点的指针

					 //构造
		_list_iterator(node* pnode)
			: _pnode(pnode)
		{}

		//T&
		Ref operator*()
		{
			return _pnode->_val;
		}
		//T*
		Ptr operator->()
		{
			return &_pnode->_val;
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
		typedef _list_iterator<T, T&, T* >  iterator;
		//传统想法是拷贝一下iterate，改成const的，但是代码重复是大量的
		//优化就是增加模板参数表
		typedef _list_iterator<T, const T&, const T*> const_iterator;
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
			_head = new node(T());//传一个匿名对象
			_head->_next = _head;
			_head->_prev = _head;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		list(const list<T>& lt)
		{
			_head = new node;//传一个匿名对象
			_head->_next = _head;
			_head->_prev = _head;
			for (const auto& e : lt)
			{
				//this.push_back
				push_back(e);
			}
		}

		list<T>& operator=(list<T> lt)
		{
			swap(_head, lt._head);

			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it!=end())
			{
				//erase(it++);//这个方式只适合这里
				it = erase(it);
			}
		}

		//void push_back(const T& x)
		//{
		//	node* newnode = new node(x);
		//	node* tail = _head->_prev;
		//	//head -----tail         newnode
		//	tail->_next = newnode;
		//	newnode->_prev = tail;
		//	newnode->_next = _head;
		//	_head->_prev = newnode;
		//}

		void insert(iterator pos, const T& x)
		{
			assert(pos._pnode);

			node* cur = pos._pnode;
			node* prev = cur->_prev;
			node* newnode = new node(x);
			//prev newnode cur
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			prev->_next = newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos._pnode);
			assert(pos != end());

			node* prev = pos._pnode->_prev;
			node* next = pos._pnode->_next;

			delete pos._pnode;

			prev->_next = next;
			next->_prev = prev;

			return iterator(next);
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		bool empty()
		{
			return begin() == end();
		}

		size_t size()		const
		{
			size_t sz = 0;
			iterator it = begin();
			while (it != end())
			{
				++sz;
				++it;
			}
			return sz;
		}

	private:
		node* _head;
	};

	class Date
	{
	public:
		int _year = 0;
		int _month = 1;
		int _day = 1;
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
	void test_list2()
	{
		list<Date> lt;
		lt.push_back(Date());
		lt.push_back(Date());
		lt.push_back(Date());

		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._year << " " << (*it)._month <<" " <<(*it)._day<<endl;
			cout << it->_year << " " << it->_month << " " << it->_day << endl;
			++it;
		}
		cout << endl;

		Date d;
		Date* p = &d;

		(*p)._year = 100;
		p->_year = 100;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		PrintList(lt);

		list<int> copy(lt);
		PrintList(copy);

		list<int> lt1;
		lt1.push_back(10);
		lt1.push_back(20);
		copy = lt1;
		PrintList(copy);
		PrintList(lt1);



		//	lt.clear();
		PrintList(lt);
	}
}

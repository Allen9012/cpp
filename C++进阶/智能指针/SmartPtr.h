#pragma once
template<class T>
class SmartPtr
{
public:
	// RAII
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete _ptr;
	}

	// 可以像指针一样使用
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};


namespace allen
{
	// C++98 -- 管理权转移,保证只有一个对象在管理资源
	// 很多公司都明确的规定了，不能使用auto_ptr
	template<class T>
	class auto_ptr
	{
	public:
		// RAII
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		// 管理权转移
		// sp2(sp1);
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		// ap1 = ap3
		// ap1 = ap1
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				delete _ptr;
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}

			return *this;
		}

		// 可以像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	void test_auto_ptr()
	{
		//bit::auto_ptr<int> sp1(new int);
		//// 拷贝
		//bit::auto_ptr<int> sp2(sp1);

		//*sp2 = 10;
		//*sp1 = 20;

		std::auto_ptr<int> sp1(new int);
		// 拷贝
		std::auto_ptr<int> sp2(sp1);

		*sp2 = 10;
		*sp1 = 20;
	}

	// C++98标准出来以后，在C++11出来之前，boost库增加几个智能指针，然后boost中智能指针被吸收到C++11中
	// C++11

	// 简单粗暴的解决拷贝问题：禁止拷贝
	template<class T>
	class unique_ptr
	{
	public:
		// RAII
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
		}

		// 可以像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>operator=(const unique_ptr<T>&) = delete;
	private:
		T* _ptr;
	};

	void test_unique_ptr()
	{
		//std::unique_ptr<int> sp1(new int);
		// 拷贝
		//std::unique_ptr<int> sp2(sp1);

		allen::unique_ptr<int> sp1(new int);
		// 拷贝
		//bit::unique_ptr<int> sp2(sp1);
	}

	template<class T>
	struct Delete
	{
		void operator()(const T* ptr)
		{
			delete ptr;
		}
	};

	template<class T, class D = Delete<T>>
	class shared_ptr
	{
	private:
		void AddRef()
		{
			_pmutex->lock();
			++(*_pcount);
			_pmutex->unlock();
		}

		void ReleaseRef()
		{
			_pmutex->lock();
			bool flag = false;
			if (--(*_pcount) == 0)
			{
				if (_ptr)
				{
					cout << "delete:" << _ptr << endl;
					//delete _ptr;
					_del(_ptr);
				}

				delete _pcount;
				flag = true;
			}
			_pmutex->unlock();

			if (flag == true)
			{
				delete _pmutex;
			}
		}
	public:
		// RAII
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmutex(new mutex)
		{}

		shared_ptr(T* ptr, D del)
			: _ptr(ptr)
			, _pcount(new int(1))
			, _pmutex(new mutex)
			, _del(del)
		{}

		~shared_ptr()
		{
			ReleaseRef();
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmutex(sp._pmutex)
		{
			AddRef();
		}

		// sp1 = sp1
		// sp1 = sp2
		// sp3 = sp1;
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				ReleaseRef();

				_pcount = sp._pcount;
				_ptr = sp._ptr;
				_pmutex = sp._pmutex;

				AddRef();
			}

			return *this;
		}


		// 可以像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pcount;
		}

		T* get() const
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pcount;
		mutex* _pmutex;
		D _del;
	};

	void test_shared_ptr()
	{
		allen::shared_ptr<int> sp1(new int);
		// 拷贝
		allen::shared_ptr<int> sp2(sp1);
		/*
				*sp1 = 10;
				*sp2 = 20;
				cout<<sp1.use_count()<<endl;*/


		allen::shared_ptr<int> sp3(new int);
		// 拷贝
		allen::shared_ptr<int> sp4(sp3);
		allen::shared_ptr<int> sp5(sp3);


		sp1 = sp1;
		sp1 = sp2;

		sp3 = sp1;
	}

	struct Date
	{
		int _year;
		int _month;
		int _day;
	};

	void SharePtrFunc(allen::shared_ptr<Date>& sp, size_t n)
	{
		for (size_t i = 0; i < n; ++i)
		{
			// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
			allen::shared_ptr<Date> copy(sp);

			// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最终看到的结果，并一定是加了2n
			/*copy->_year++;
			copy->_month++;
			copy->_day++;*/
		}
	}

	void test_multithread_shared_ptr()
	{
		allen::shared_ptr<Date> p(new Date);

		const size_t n = 10000;
			thread t1(SharePtrFunc,ref(p),n);
			thread t2(SharePtrFunc,ref(p),n);

			t1.join();
			t2.join();

		//cout << p->_year << endl;
		//cout << p->_month << endl;
		//cout << p->_day << endl;

		cout << p.use_count() << endl;
	}



	// 不参与资源管理，不增加shared_ptr管理资源的引用计数，可以像指针一样使用
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{  
			_ptr = sp.get();
			return *this;
		}

		// 可以像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	struct ListNode
	{
		//ListNode* _next;
		//ListNode* _prev;
		//std::shared_ptr<ListNode> _next;
		//std::shared_ptr<ListNode> _prev;

		allen::weak_ptr<ListNode> _next;
		allen::weak_ptr<ListNode> _prev;

		int _val;

		~ListNode()
		{
			cout << "~ListNode()" << endl;																
		}
	};

	// 循环引用
	//void test_shared_ptr_cycle_ref()
	//{
	//	ListNode* node1 = new ListNode;
	//	ListNode* node2 = new ListNode;
	//	node1->_next = node2;
	//	node2->_prev = node1;
	//	// ...

	//	delete node1;
	//	delete node2;
	//}

	// 假设我们想用智能指针来进行管理节点
	void test_shared_ptr_cycle_ref()
	{
		allen::shared_ptr<ListNode> node1(new ListNode);
		allen::shared_ptr<ListNode> node2(new ListNode);

		cout << node1.use_count() << endl;
		cout << node2.use_count() << endl;

		// 循环引用
		node1->_next = node2;
		node2->_prev = node1;
		// ...

		cout << node1.use_count() << endl;
		cout << node2.use_count() << endl;

		//delete node1;
		//delete node2;
	}

	template<class T>
	struct DelArr
	{
		void operator()(const T* ptr)
		{
			cout << "delete[]:" << ptr << endl;
			delete[] ptr;
		}
	};

	// 定制删除器 -- 删除器控制释放资源的方式
	void test_shared_ptr_deletor()
	{
		std::shared_ptr<ListNode> spArr(new ListNode[10], DelArr<ListNode>());
		std::shared_ptr<FILE> spfl(fopen("test.txt", "w"), [](FILE* ptr) {
			cout << "fclose:" << ptr << endl;
			fclose(ptr);
			});

		allen::shared_ptr<ListNode, DelArr<ListNode>> spArr(new ListNode[10], DelArr<ListNode>());

		allen::shared_ptr<FILE, std::function<void(FILE*)>> spfl(fopen("test.txt", "w"), [](FILE* ptr) {
			cout << "fclose:" << ptr << endl;
			fclose(ptr);
			});

		auto f = [](FILE* ptr) {
			cout << "fclose:" << ptr << endl;
			fclose(ptr);
		};
		allen::shared_ptr<FILE, decltype(f)> spf2(fopen("test.txt", "w"), f);
	}
}
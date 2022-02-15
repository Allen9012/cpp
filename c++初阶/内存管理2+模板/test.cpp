#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <assert.h>

//#include<stdlib.h>
using namespace std;

// 直接在类里面定义实现的成员函数，默认就是内联函数
//class A
//{
//public:
//	void func()
//	{
//		cout << "A" << endl;
//	}
//private:
//};
//
//int main()
//{
//	A aa;
//	aa.func();
//
//	return 0;
//}

//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//
//	ListNode(int val)
//		:_next(nullptr)
//		, _prev(nullptr)
//		, _val(val)
//	{}
//};

//void f()
//{
//	// 他的用法跟malloc和free是完全一样的，功能都是在堆上申请释放空间
//	// 失败了处理方式不一样，malloc失败返回NULL，operator new失败以后抛异常
//	ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
//	free(p1);
//
//	ListNode* p2 = (ListNode*)operator new(sizeof(ListNode));
//	operator delete(p2);
//
//
//	void* p3 = malloc(0xefffffff);
//	if (p3 == NULL)
//	{
//		cout << "malloc fail" << endl;
//	}
//	try
//	{
//		void* p4 = operator new(0xefffffff);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	
//
//	void* p4 = operator new(11);
//	char* p5 = new char[0x7fffffff];
//
//	ListNode* p6 = new ListNode(2);
//
//	cout << "继续" << endl;
//}
//
//
//int main()
//{
//	try
//	{
//		f();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//
//	// 类中重载专属operator new
//	// 
//	/*void* operator new(size_t n)
//	{
//	void* p = nullptr;
//	p = allocator<ListNode>().allocate(1);
//	cout << "memory pool allocate" << endl;
//	return p;
//	}*/
//
//	/*void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//
//	}*/
//
//	ListNode(int val)
//		:_next(nullptr)
//		, _prev(nullptr)
//		, _val(val)
//	{}
//};
//
//int main()
//{
//	ListNode* p = new ListNode(1);
//	delete p;
//	
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	// A* p = (A*)malloc(sizeof(A));
//
//	// 等价于直接用A* p = new A
//	A* p = (A*)operator new(sizeof(A));
//	new(p)A; // new(p)A(3);  // 定位new，placement-new，显示调用构造函数初始化这块对象空间
//
//	// 等于 delete p
//	p->~A(); // 析构函数可以显示调用
//	operator delete(p);
//
//	return 0;
//}

//int main()
//{
//	void* p = malloc(1024 * 1024 * 1024);
//
//	return 0;
//}

//void Swapi(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//void Swapd(double* p1, double* p2)
//{
//	double tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	Swapi(&a, &b);
//
//	double c = 1.1, d = 2.2;
//	Swapd(&c, &d);
//
//
//	return 0;
//}


// 泛型编程 -- 模板

// 函数模板
//template<class T>  // Type
//template<typename T>  // 定义模板参数T可以用typename，也可以用class，都一样
//void Swap(T& x1, T& x2)
//{
//	T tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	// 下面两个调用Swap函数的地方是一个函数还是两个？
//	int a = 1, b = 2;
//	Swap(a, b);
//
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//
//	//Swap(a, c);
//
//	// 编译器会通过实参推形参的类型T分别为int和double
//	// 这种方式是隐式实例化
//	cout << Add(a, b) << endl;
//	cout << Add(c, d) << endl;
//	cout << Add(a, (int)c) << endl;
//
//	// 不让编译器推演类型，显示指定类型
//	// 这种方式叫做显示实例化
//	cout << Add<int>(a, c) << endl;
//	cout << Add<double>(a, c) << endl;
//
//	return 0;
//}

// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//
//void main()
//{
//	Add(1, 2);       // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2);  // 调用编译器特化的Add版本
//}

//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//// 模板调用，有现成匹配函数，绝对不去实例化模板
//// 有更匹配的，优先匹配类型最合适的
//void main()
//{
//	Add(1, 2);     // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0);   // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}

// 类模板
//typedef double VDataType;
//class vector
//{
//public:
//	//
//private:
//	VDataType* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	vector v1; // int
//
//	vector v2; // double
//
//
//	return 0;
//}

// 类模板
//namespace zj
//{
	//template<class T>
	//class vector
	//{
	//public:
	//	vector()
	//		:_a(nullptr)
	//		, _size(0)
	//		, _capacity(0)
	//	{}

	//	// 拷贝构造和operator= 这里涉及深浅拷贝问题，还挺复杂，后面具体再讲

	//	~vector()
	//	{
	//		delete[] _a;
	//		_a = nullptr;
	//		_size = _capacity = 0;
	//	}

	//	void push_back(const T& x)
	//	{
	//		if (_size == _capacity)
	//		{
	//			int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
	//			T* tmp = new T[newcapacity];
	//			if (_a)
	//			{
	//				memcpy(tmp, _a, sizeof(T) * _size);
	//				delete[] _a;
	//			}
	//			_a = tmp;
	//			_capacity = newcapacity;
	//		}

	//		_a[_size] = x;
	//		++_size;
	//	}

	//	// 读+写
	//	T& operator[](size_t pos);
	//	size_t size();
	//private:
	//	T* _a;
	//	size_t _size;
	//	size_t _capacity;
	//};
//
//	// 模板不支持分离编译，也就是声明在.h ,定义在.cpp，原因后面再讲
//	// 建议就是定义在一个文件 xxx.h  xxx.hpp
//	// 在类外面定义
//	template<class T>
//	T& vector<T>::operator[](size_t pos)
//	{
//		assert(pos < _size);
//
//		return _a[pos];
//	}
//
//	template<class T>
//	size_t vector<T>::size()
//	{
//		return _size;
//	}
//}
//
//int main()
//{
//	zj::vector<int> v1;		// int
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//
//	// v1.operator[](3);
//	//cout << v1[3] << endl;
//	//cout << v1[5] << endl;
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		v1[i] *= 2;
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//
//	zj::vector<double> v2;   // double
//	v2.push_back(1.1);
//	v2.push_back(2.2);
//	v2.push_back(3.3);
//	v2.push_back(4.4);
//
//	for (size_t i = 0; i < v2.size(); ++i)
//	{
//		cout << v2[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


namespace allen
{
	template<class T>
	class vector
	{
	public:
		vector()
			:_a(nullptr)
			, _size(0)
			, _capacity(0)
		{}
		~vector()
		{
			delete[] _a;
			_a = nullptr;
			_size = _capacity = 0;
		}

		//拷贝构造和operator= 涉及深拷贝
		void push_back(const T& x)
		{
			if (_size == _capacity)
			{
				int newcapacity = (_capacity == 0) ? 4 : _capacity * 2;
				T* tmp = new T[newcapacity];
				if (_a)
				{
					memcpy(tmp, _a, sizeof(T)* _size);
					delete[] _a;
				}
				_a = tmp;
				_capacity = newcapacity;
			}
			_a[_size++] = x;
		}

		//引用返回完成读+写
	T&	operator[] (size_t pos)
		{
			assert(pos < _size);
			return _a[pos];
		}

	size_t size() 
	{
		return _size;
	}
	private: 
		T* _a;
		size_t _size;
		size_t _capacity;
	};

}


int main()
{
	allen::vector<int> v1;
	v1.push_back(3);
	v1.push_back(4);
	for (int i=0;i<v1.size();i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	allen::vector<double> v2;
	v2.push_back(3.1);
	v2.push_back(4.2);
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	return 0;
}
# define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <thread>
#include <atomic>
#include <initializer_list>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <assert.h>
using namespace std;

//namespace allen
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		iterator begin()
//		{
//			return _str;
//		}
//
//		iterator end()
//		{
//			return _str + _size;
//		}
//
//		string(const char* str = "")
//			:_size(strlen(str))
//			, _capacity(_size)
//		{
//			//cout << "string(char* str)" << endl;
//
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//
//		// s1.swap(s2)
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//
//		// 拷贝构造
//		string(const string& s)
//			:_str(nullptr)
//		{
//			cout << "string(const string& s) -- 深拷贝" << endl;
//
//			string tmp(s._str);
//			swap(tmp);
//		}
//
//		// 移动构造
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- 移动构造" << endl;
//			this->swap(s);
//		}
//
//		// 移动赋值 
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
//			this->swap(s);
//
//			return *this;
//		}
//
//		// 赋值重载
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(string s) -- 深拷贝" << endl;
//			string tmp(s);
//			swap(tmp);
//
//			return *this;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		char& operator[](size_t pos)
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//
//				_capacity = n;
//			}
//		}
//
//		void push_back(char ch)
//		{
//			if (_size >= _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(newcapacity);
//			}
//
//			_str[_size] = ch;
//			++_size;
//			_str[_size] = '\0';
//		}
//
//		//string operator+=(char ch)
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//
//		const char* c_str() const
//		{
//			return _str;
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity; // 不包含最后做标识的\0
//	};
//
//	allen::string to_string(int value)
//	{
//		bool flag = true;
//		if (value < 0)
//		{
//			flag = false;
//			value = 0 - value;
//		}
//
//		allen ::string str;
//		while (value > 0)
//		{
//			int x = value % 10;
//			value /= 10;
//
//			str += ('0' + x);
//		}
//
//		if (flag == false)
//		{
//			str += '-';
//		}
//
//		std::reverse(str.begin(), str.end());
//		return str;
//	}
//}

// 左值引用的使用场景
// 1、做参数 
// 2、做返回值
//void func1(allen::string s)
//{}
//
//void func2(const allen::string& s)
//{}

//int main()
//{
//	bit::string s1("hello world");
//	// func1和func2的调用我们可以看到左值引用做参数减少了拷贝，提高效率的使用场景和价值
//	//func1(s1);
//	func2(s1);
//
//	// operator+=可以使用传左值引用返回
//	s1 += 'A';
//
//	// to_string 不能用左值引用返回，这个就是左值引用短板
//	// 如果函数返回对象除了函数作用域就不在了，就不能使用做引用返回，就会存在拷贝
//	//bit::string ret1 = bit::to_string(1234);
//	//bit::to_string(1234);
//
//	return 0;
//}

//int main()
//{
//	//bit::to_string(1234);
//	bit::string ret1 = bit::to_string(1234);
//	//bit::string ret1;
//	//ret1 = bit::to_string(1234);
//
//	return 0;
//}
//
//int main()
//{
//	bit::string s1("hello");
//
//	bit::string s2 = s1;
//	bit::string s3 = bit::to_string(1234);
//
//	bit::string s4 = std::move(s1);
//
//	return 0;
//}

//int main()
//{
//	list<allen::string> lt;
//
//	allen::string s1("1111");
//	 这里调用的是拷贝构造
//	lt.push_back(s1);
//
//	 下面调用都是移动构造
//	lt.push_back("2222");
//	lt.push_back(allen::string("2222"));
//	lt.push_back(std::move(s1));
//
//	return 0;
//}

void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }

void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }

 //模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
 //模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
 //但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
 //我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要用我们下面学习的完美转发
template<typename T>
void PerfectForward(T&& t)
{
	Fun(std::forward<T>(t));
	//Fun(t);
}

//int main()
//{
//	PerfectForward(10);           // 右值
//
//	int a;
//	PerfectForward(a);            // 左值
//	PerfectForward(std::move(a)); // 右值
//
//	const int b = 8;
//	PerfectForward(b);		      // const 左值
//	PerfectForward(std::move(b)); // const 右值
//
//	return 0;
//}

template<class T>
struct ListNode
{
	ListNode* _next = nullptr;
	ListNode* _prev = nullptr;
	T _data;
};

template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()
	{
		//_head = new Node;
		_head = (Node*)malloc(sizeof(Node));
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(const T& x)
	{
		//Insert(_head, x);
		Insert(_head, x);
	}

	void PushBack(T&& x)
	{
		//cout << &x << endl;
		// 这里x属性退化为左值，其他对象再来引用x，x会识别为左值

		//Insert(_head, x);
		// 这里就要用完美转发，让x保持他的右值引属性
		Insert(_head, std::forward<T>(x));
	}

	void PushFront(T&& x)
	{
		//Insert(_head->_next, x);
		Insert(_head->_next, std::forward<T>(x));
	}

	void Insert(Node* pos, T&& x)
	{
		Node* prev = pos->_prev;
		//Node* newnode = new Node;
		//newnode->_data = std::forward<T>(x); // 关键位置
		Node* newnode = (Node*)malloc(sizeof(Node));
		new(&newnode->_data)T(std::forward<T>(x));

		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}

	void Insert(Node* pos, const T& x)
	{
		Node* prev = pos->_prev;
		//Node* newnode = new Node;
		//newnode->_data = x; // 关键位置
		Node* newnode = (Node*)malloc(sizeof(Node));
		new(&newnode->_data)T(x);

		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
private:
	Node* _head;
};

//int main()
//{
//	/*List<bit::string> lt;
//	bit::string s1("1111");
//	lt.PushBack(s1);
//
//	lt.PushBack("1111");
//	lt.PushFront("2222");*/
//
//
//	list<std::string> lt;
//	
//	std::string s1("1111");
//	// 这里调用的是拷贝构造
//	lt.push_back(s1);
//	
//	// 下面调用都是移动构造
//	lt.push_back("2222");
//	lt.push_back(std::string("2222"));
//	lt.push_back(std::move(s1));
//
//	return 0;
//}

//// 以下代码在vs2013中不能体现，在vs2019下才能演示体现上面的特性。
//class Person
//{
//public:
//	/*Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//		{}*/
//
//	//Person() = default;
//
//	//Person(Person&& p) = default;
//
//	Person(const Person& p)
//		:_name(p._name)
//		, _age(p._age)
//	{}
//
//	/*Person& operator=(const Person& p)
//	{
//	if(this != &p)
//	{
//	_name = p._name;
//	_age = p._age;
//	}
//	return *this;
//	}*/
//
//	~Person()
//	{}
//
//private:
//	allen::string _name;
//	int _age = 0;
//};

// C++对于自定义类型成员变量非常的友好，默认成员函数都会恰当处理自定义类型成员
//class MyQueue
//{
//private:
//	std::stack<int> _pushST;
//	std::stack<int> _popST;
//};

//int main()
//{
//	Person s1;
//	//Person s2 = s1;
//	Person s3 = std::move(s1);
//	//Person s4;
//	//s4 = std::move(s2);
//
//	return 0;
//}

// decltype的一些使用使用场景
//template<class T1, class T2>
//auto F(T1 t1, T2 t2) -> decltype(t1 * t2)
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//	
//	return ret;
//}
//
//int main()
//{
//	F(1, 2.2);
//
//	return 0;
//}

//template <class ...Args>
//void ShowList(Args... args)
//{
//	//cout << sizeof...(args) << endl;
//	for (int i = 0; i < sizeof...(args); ++i)
//	{
//		cout<<args[i]<<" "; // 不支持
//	}
//}
//
//int main()
//{
//	ShowList();
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//
//	return 0;
//}

//一定要补一个空参数包，这样才能停下来
void ShowList()
{
	cout << endl;
}

//template <class T>
//void ShowList(const T& t)
//{
//	cout << t << endl;
//}

template <class T, class ...Args>
void ShowList(T value, Args... args)
{
	cout << value << " ";
	if (sizeof...(args) == 0)
	{
		return;
	}
	ShowList(args...);
}

//int main()
//{
//	ShowList();
//	//ShowList(1);
//	//ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//
//	return 0;
//}

struct Goods
{
	string _name;
	double _price;
	int _num;

	// ...
};

struct ComparePriceLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

struct CompareNumLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._num < gr._num;
	}
};

struct CompareNumGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._num > gr._num;
	}
};

// 可调用对象类型
// 仿函数
// 函数指针
// lamber

//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 300 }, { "香蕉", 3.3,  100}, { "橙子", 2.2 , 1000}, { "菠萝", 1.5, 1} };
//	// 要求分别按名字、价格、数量进行排序，升序或降序
//
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	sort(v.begin(), v.end(), CompareNumLess());
//	sort(v.begin(), v.end(), CompareNumGreater());
//
//	return 0;
//}

//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 300 }, { "香蕉", 3.3, 100 }, { "橙子", 2.2, 1000 }, { "菠萝", 1.5, 1 } };
//	// 要求分别按名字、价格、数量进行排序，升序或降序
//
//	// 如果仿函数都名字是按比较规则命名的，还方便理解，如果命名不规范，
//	// 比如是compare1，compare2... 那么这里可苦了看代码人
//	/*sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	sort(v.begin(), v.end(), CompareNumLess());
//	sort(v.begin(), v.end(), CompareNumGreater());*/
//
//	/*auto f1 = [](const Goods& g1, const Goods& g2)
//	{
//	return g1._price > g2._price;
//	};
//	sort(v.begin(), v.end(), f1);
//	*/
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price > g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._num > g2._num; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._num < g2._num; });
//
//	return 0;
//}

//int main()
//{
//	[]{};
//
//	int a = 1, b = 2;
//	// 实现add的lambda
//	auto add1 = [](int x, int y)->int{return x + y; };
//	cout << add1(a, b) << endl;
//
//	// 在捕捉列表，捕捉a、b, 没有参数可以省略参数列表，返回值可以通过推演，也可以省略
//	//auto add2 = [a, b]{}->int{return a + b + 10; };
//	auto add2 = [a, b]{return a + b + 10; };
//	cout << add2() << endl;
//
//	return 0;
//}



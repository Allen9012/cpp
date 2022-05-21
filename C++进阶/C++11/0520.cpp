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
#include <functional>
#include <thread>
using namespace std;

namespace allen
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// 移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			this->swap(s);
		}

		// 移动赋值 
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			this->swap(s);

			return *this;
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的\0
	};

	allen::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		allen::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}
}
//void ShowListArg()
//{
//	cout << endl;
//}
//
//// 展开函数
//template <class T, class ...Args>
//void ShowListArg(T value, Args... args)
//{
//	cout << value << " ";
//	ShowListArg(args...);
//}
//
//template <class ...Args>
//void ShowList(Args... args)
//{
//	ShowListArg(args...);
//}

//展开函数
// ShowList(1, 2, 3);
// ShowList(1, 2, 3, 4, 5);
//template <class ...Args>
//void ShowList(Args... args)
//{
//	// 列表初始化
//	int arr[] = { args... };
//	cout << endl;
//}

//template <class T>
//void PrintArg(T t)
//{
//	cout << t << " ";
//}

//void ShowList()
//{
//	cout << endl;
//}

//template <class ...Args>
//void ShowList(Args... args)
//{
//	// 列表初始化
//	// {(printarg(args), 0)...}将会展开成((printarg(arg1),0), (printarg(arg2),0), (printarg(arg3),0), etc... )
//	int arr[] = { (PrintArg(args), 0)... };
//	cout << endl;
//}
//
//template <class T>
//int PrintArg(T t)
//{
//	cout << t << " ";
//	return 0;
//}
//
////template <class ...Args>
////void ShowList(Args... args)
////{
////	// 列表初始化
////	int arr[] = { args... };
////	cout << endl;
////}
//
//// 这里得&&是万能引用，实参是左值，参数包的这个形参就是左值引用
////                   实参是右值，参数包的这个形参就是右值引用
//template <class ...Args>
//void ShowList(Args&&... args)
//{
//	// 列表初始化
//	int arr[] = { PrintArg(args)... };
//	cout << endl;
//}

//int main()
//{
//	ShowList();
//	std::string s("111");
//	ShowList(1,2,'A',"ssss", s);
//	ShowList(23, 11.11, "121313");
//
//	ShowList(1, 2, 3);
//	ShowList(1, 2, 3, 4, 5);
//
////	 列表初始化
//	int a[] = { 1, 2, 3, 4 };
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};

//int main()
//{
//	std::list< std::pair<int, char> > mylist;
//
//	// emplace_back支持可变参数，拿到构建pair对象的参数后自己去创建对象
//	// 那么在这里我们可以看到除了用法上，和push_back没什么太大的区别
//	mylist.emplace_back(10, 'a');
//	mylist.emplace_back(20, 'b');
//
//	mylist.emplace_back(make_pair(30, 'c'));
//	mylist.push_back(make_pair(40, 'd'));
//	mylist.push_back({ 50, 'e' });
//
//	for (auto e : mylist)
//		cout << e.first << ":" << e.second << endl;
//
//	std::list<Date> lt;
//	Date d1 = { 2022, 5, 18 };
//	lt.push_back(d1);
//	lt.push_back(Date(2022,5,19));
//	lt.push_back({2022,5,19});
//
//	lt.emplace_back(d1);
//	lt.emplace_back(Date(2022, 5, 19));
//	lt.emplace_back(2022, 5, 19);//err
//
//
//	return 0;
//}

//int main()
//{
//	// 下面我们试一下带有拷贝构造和移动构造的bit::string，再试试呢
//	// 我们会发现其实差别也不到，emplace_back是直接构造了，push_back
//	// 是先构造，再移动构造，其实也还好。
//	std::list< std::pair<int, allen::string> > mylist;
//	std::pair<int, allen::string> kv(20, "sort");
//	mylist.emplace_back(kv);					// 左值
//	mylist.emplace_back(std::pair<int, allen::string>(20, "sort")); // 右值
//	mylist.emplace_back(10, "sort");			// 参数包
//
//
//
//	//cout << endl;
//	//mylist.push_back(kv);					// 左值
//	//mylist.push_back(std::pair<int, allen::string>(20, "sort")); // 右值
//
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


//int main()
//{
//	int a = 0, b = 1;
//	//标准写法
//	auto my_swap1 = [](int& x,int& y) 
//	{
//		int tmp = x;
//		x = y; 
//		y = tmp;
//	};
//	my_swap1(a, b);
//	//利用捕捉列表，捕捉当前局部与的变量，或者减少传参
//	auto my_swap2 = [a, b]()mutable
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//	my_swap2();
//
//	auto my_swap3 = [&a, &b]
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//	my_swap3();
//
//	auto my_swap4 = [&]
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//	my_swap4();
//	return 0;
//}




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
//
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
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._price < g2._price;});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._price > g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._num > g2._num;});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){return g1._num < g2._num;});
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

//int main()
//{
//	int a = 0, b = 1;
//	// 标准写法1
//	auto swap1 = [](int& x, int& y)->void
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	swap1(a, b);
//
//	// 尝试利用捕捉列表，捕捉当前局部域的变量，
//	// 这样就不用传参或者减少传参，省略参数和返回值
//	// 这里传值方式捕捉，拷贝外面的a和b给lambda里面的a、b
//	// lambda里面的a、b的改变不会影响外面
//	auto swap2 = [a, b]()mutable
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//
//	swap2();
//
//	auto swap3 = [&a, &b]
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//
//	swap3();
//
//	auto swap4 = [&]
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//
//	swap4();
//
//
//	return 0;
//}

class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}

	double operator()(double money, int year)
	{
		return money * _rate * year;
	}

private:
	double _rate;
};

//int main()
//{
//	// 函数对象
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//
//	// lambda
//	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };
//	r2(10000, 2);
//
//	return 0;
//}

// ret = func(x);
// 上面func可能是什么呢？那么func可能是函数名？函数指针？函数对象(仿函数对象)？也有可能是lamber表达式对象？所以这些都是可调用的类型！如此丰富的类型，可能会导致模板的效率低下！为什么呢？我们继续往下看

// 函数模板会被实例化多次
template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;

	return f(x);
}

double func(double i)
{
	return i / 2;
}

struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};

//int main()
//{
//	// 函数名
//	cout << useF(func, 11.11) << endl;
//
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//
//	// lamber表达式
//	cout << useF([](double d)->double{ return d / 4; }, 11.11) << endl;
//
//	return 0;
//}

// 使用包装器以后，useF看到的都是包装器，只会实例化一份
//template<class F, class T>
//T useF(F f, T x)

//int main()
//{
//	// 函数名
//	std::function<double(double)> f1 = func;
//	cout << useF(f1, 11.11) << endl;
//
//	// 函数对象
//	std::function<double(double)> f2 = Functor();
//	cout << useF(f2, 11.11) << endl;
//
//	// lamber表达式
//	std::function<double(double)> f3 = [](double d)->double{ return d / 4; };
//	cout << useF(f3, 11.11) << endl;
//
//	return 0;
//}

int f1(int a, int b)
{
	return a + b;
}

struct Functor1
{
public:
	int operator() (int a, int b)
	{
		return a + b;
	}
};

class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}

	double plusd(double a, double b)
	{
		return a + b;
	}
};

int main()
{
	// 包装函数指针
	std::function<int(int, int)> ff1 = f1;
	cout << ff1(1, 2) << endl;

	// 包装仿函数
	std::function<int(int, int)> ff2 = Functor1();
	cout << ff2(1, 2) << endl;

	// 包装成员函数
	std::function<int(int, int)> ff3 = Plus::plusi;
	cout << ff3(1, 2) << endl;

	//std::function<double(Plus, double, double)> ff4 = &Plus::plusd;
	//cout << ff4(Plus(),1.1, 2.2) << endl;

	// 包装lambda表达式
	auto f5 = [](int a, int b){return a + b; };
	std::function<int(int, int)> ff5 = f5;
	cout << ff5(1, 2) << endl;
}


// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/submissions/
//class Solution {
//public:
//	//void getnum(stack<int>& st, int& x1, int& x2);
//	int evalRPN(vector<string>& tokens) {
//		stack<int> st;
//		map<string, std::function<int(int, int)>> opMap =
//		{
//			{ "+", [](int x, int y){return x + y; } },
//			{ "-", [](int x, int y){return x - y; } },
//			{ "*", [](int x, int y){return x*y; } },
//			{ "/", [](int x, int y){return x / y; } }
//		};
//
//		for (const auto& str : tokens)
//		{
//			int left, right;
//			if (str == "+" || str == "-" || str == "*" || str == "/")
//			{
//				right = st.top();
//				st.pop();
//				left = st.top();
//				st.pop();
//
//				st.push(opMap[str](left, right));
//			}
//			else // 操作数
//			{
//				st.push(stoi(str));
//			}
//		}
//
//		return st.top();;
//	}
//};


int Plus(int a, int b)
{
	return a + b;
}

class Sub
{
public:
	int sub(int a, int b)
	{
		return a - b;
	}
};


//int main()
//{
//	std::function<int(int, int)> f1 =  bind(Plus, placeholders::_1, placeholders::_2);
//	cout << f1(1, 2) << endl;
//
//	// 想把plus绑定成一个值+10
//	std::function<int(int)> f2 = bind(Plus, 10, placeholders::_1);
//	cout << f2(5) << endl;
//
//	// 绑定固定的可调用对象
//	std::function<int(int, int)> f3 = bind(&Sub::sub, Sub(), placeholders::_1, placeholders::_2);
//	cout << f3(1, 2) << endl;
//
//	std::function<int(int, int)> f4 = bind(&Sub::sub, Sub(), placeholders::_2, placeholders::_1);
//	cout << f4(1, 2) << endl;
//
//	return 0;
//}

//int main()
//{
//	size_t n = 100;
//	thread t1([n]
//		{
//			for (size_t i = 0; i < n; i += 2)
//			{
//				cout << i << endl;
//			}
//		});
//
//	thread t2([n]
//		{
//			for (size_t i = 1; i < n; i += 2)
//			{
//				cout << i << endl;
//			}
//		});
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}
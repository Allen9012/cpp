#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

#include <deque>

using std::cout;
using std::endl;



//#define N 1000

// 模板参数
// 类型模板参数
// 非类型模板参数 -- 整形常量
template<class T = int, size_t N = 8>
class Array
{
public:
	void f()
	{
		N = 1000;  // 不行 会报错
	}
private:
	T _a[N];
};

//template<double D>
//class B
//{
//public:
//};
//
//template<string s>
//class C
//{
//public:
//};

//int main()
//{
//	Array<int, 100> aa1;   // 100
//	Array<int, 1000> aa2;  // 1000
//	Array<int> aa3;  // 1000
//	Array<> aa4;
//
//	//aa1.f();
//
//	return 0;
//}

template<class T>
bool IsEqual(const T& left, const T& right)
{
	return left == right;
}

// 针对字符串类型要特殊化处理 -- 写一份函数模板的特殊出来
template<>
bool IsEqual <const char*>(const char* const& left, const char* const& right)
{
	return strcmp(left, right) == 0;
}

//bool IsEqual(const char* const& left, const char* const& right)
//{
//	return strcmp(left, right) == 0;
//}

//int main()
//{
//	//cout << IsEqual(1, 2) << endl;
//	//cout << IsEqual(1.1, 1.1) << endl;
//
//	char p1[] = "hello";
//	char p2[] = "hello";
//	cout << IsEqual(p1, p2) << endl;
//
//	const char* p3 = "hello";
//	const char* p4 = "hello";
//	cout << IsEqual(p3, p4) << endl;
//
//	return 0;
//}

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 假设针对T1 T2是 int int想做一些特殊化那么怎么办 ？ -- 类模板特化
// -- 全特化
template<>
class Data < int, int >
{
public:
	Data() { cout << "Data<int, int>" << endl; }
};

// 将第二个参数特化为int --偏特化
template <class T1>
class Data < T1, int >
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
};

// 偏特化 指定如何模板参数是指针
template <class T1, class T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
};

template <class T1, class T2>
class Data < T1&, T2& >
{
public:
	Data() { cout << "Data<T1&, T2&>" << endl; }
};

template <class T1, class T2>
class Data < T1&, T2* >
{
public:
	Data() { cout << "Data<T1&, T2*>" << endl; }
};

// 函数模板也一样，也有全特化和偏特化

int main()
{
	Data<int, int> d1;
	Data<int, double> d2;
	Data<double, int> d3;
	Data<double*, int*> d4;
	Data<int*, int*> d5;
	Data<int&, int&> d6;
	Data<int&, int*> d7;

	return 0;
}
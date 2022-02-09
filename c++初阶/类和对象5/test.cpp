#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Date
//{
//	// 友元函数
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	// d1 << cout; -> d1.operator<<(&d1, cout);
//	/*ostream& operator<<(ostream& _cout)
//	{
//	_cout << _year << "-" << _month << "-" << _day << endl;
//	return _cout;
//	}*/
//
//	int GetYear()
//	{
//		return _year;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//int main()
//{
//	Date d1(2021, 5, 31);
//	Date d2(2021, 5, 31);
//	//d1._year = 10;
//	//d1.GetYear() = 10;
//
//	cin >> d1>>d2;
//	cout << d1 << d2;
//
//	return 0;
//}

//class Date;
//
//class Time
//{
//	friend class Date;   // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//	void f(Date& d)
//	{
//		d._year = 1;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//	friend class Time;
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		_t._hour = 1;
//	}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}

//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	return 0;
//}

//class A
//{
//public:
//	A(int x)
//	{
//		cout << "A(int x)" << endl;
//		_x = x;
//	}
//private:
//	int _x;
//};
//
//class Date
//{
//	friend class Time;
//public:
//	// 可以理解成，一个对象的单个成员变量在初始化列表是
//	// 这个其实算是初始化列表初始化和函数体内初始化不同的地方，也是他的价值体现
//	Date(int year = 0, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _n(10)
//		, _ref(year)
//		, _a(1)  // 显示去调用
//	{
//		_day = day;
//		//	_n = 10; // 不能在函数体内初始化，必须使用初始化列表初始化
//		// _ref = year;
//		
//	}
//
//private:
//	// 成员变量声明
//	int _year;
//	int _month;
//	int _day;
//	
//	// 他们必须在定义的时候初始化
//	const int _n;
//	int& _ref;
//	A _a;
//};



//int main()
//{
//	Date d1;
//	//Date d2;
//
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	// 自定义类型，使用初始化列表 -》 构造函数
//	/*Date(int day, int hour)
//		:_t(hour)
//	{}*/
//
//	// 自定义类型，不使用初始化列表 -》 构造函数 + operator=
//	Date(int day, int hour)
//	{
//		// 函数体内初始化
//		Time t(hour);
//		_t = t;
//	}
//
//private:
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d(12, 12);
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//
//int main() {
//	A aa(1);
//	A aa2(aa);
//	aa.Print();
//
//	return 0;
//}

//class A
//{
//public:
//	//explicit A(int a)
//	explicit A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A&)" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//	void f()
//	{
//		// ...
//		cout << "f()" << endl;
//	}
//
//private:
//	int _a;
//};

//int main()
//{
//	A aa1(1);
//
//	// 单参数的构造函数，支持隐式类型转换
//	A aa2 = 2; 
//	const A& aa3 = 2;
//	// 语法意义上是先构造，在拷贝构造，
//	// 早期的编译器：A tmp(2) + A aa2(tmp) -> 现在的编译器，做了优化，直接调用构造函数A aa2(2)
//
//	int i = 0;
//	double d = i; // 隐式类型转换
//
//	string s11("hello");
//	string s22 = "hello"; // string(const char* str){}
//
//	vector<string> v;  // -> push_back(const string& s) {}
//	string s1("周杰");
//	v.push_back(s1);
//	string s2("梁松");
//	v.push_back(s2);
//
//	// string支持单参数的隐式类型转换，我们就可以这样传参，写起来更便捷
//	// 这块具体细节，我们后面会再讲
//	v.push_back("杭哥");
//
//	return 0;
//}

//int main()
//{
//	//A aa1(1);  // 标准的构造函数调用，定义有名对象
//	////A aa2 = 2; // 隐式类型转换，编译器优化后，也是直接调的构造
//	//A(3);      // 构造匿名对象，生命周期还在这一行
//	//A aa3(2);
//
//	// 什么场景使用：定义一个对象要用，但是这里这一行用，其他地方不用。
//	// 先定义有名对象，反而麻烦，直接定义匿名对象，方便快捷
//	A aa4;
//	aa4.f();
//	
//	A().f();
//
//	vector<A> v;
//	A aa1(1);
//	v.push_back(aa1);
//	A aa2(2);
//	v.push_back(aa2);
//
//	// 方便快捷
//	v.push_back(A(3));
//	v.push_back(A(4));
//	v.push_back(A(5));
//
//	return 0;
//}

// //计算一个程序中A定义多少个对象出来
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		++_n;
//	}
//
//
//	A(const A& a)
//	{
//		++_n;
//	}
//
//	void f()
//	{
//		GetN();
//	}
//
//	// 跟普通成员函数区别：没有this指针，不能访问非静态成员
//	static int GetN() 
//	{
//		// 没有this指针
//		//_a = 1; // this->_a
//		// f(); // this->f()
//
//		return _n;
//	}
//private:
//	// 这里只是声明，不在构造函数初始化，在类外面全局位置初始化
//	static int _n;  // n是存在静态区，属于整个类，也属于类的所有对象
//	int _a;
//};
//
//// 静态成员变量的定义初始化，特例，不受访问限定符限制，否则就没办法定义初始化了
//int A::_n = 0;
//
//// 类似这里，const不能修改，但是定义的时候可以，否则没办法初始化
////const int n = 10;
////n = 20;
//
//void f(A a)
//{
//
//}
//
//int main()
//{
//	A a1;
//	A a2;
//	A();
//	f(a1);
//
//	//cout << sizeof(A) << endl;
//
//	// 静态成员，不属于某个对象，突破类域就能访问
//	//cout << A::_n << endl; // public
//	//cout << a1._n << endl; // public
//	//cout << a2._n << endl; // public
//	//cout << A()._n << endl; // public
//
//	cout << a1.GetN() << endl;
//	cout << A().GetN() << endl;
//	cout << A::GetN() << endl;
//
//	A aa[10];
//
//	return 0;
//}

class Add
{
public:
	Add()
	{
		_ret += _i;
		_i++;
	}

	static int GetRet()
	{
		return _ret;
	}

private:
	static int _i;
	static int _ret;
};

int Add::_i = 1;
int Add::_ret = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		//Add arr[n]; // 新一点的编译器时支持的，变长数组c99
		Add* p = new Add[n];

		return Add::GetRet();
	}
};

//int main()
//{
//	cout << Solution().Sum_Solution(10) << endl;
//	cout << Solution().Sum_Solution(10) << endl;
//
//
//	return 0;
//}
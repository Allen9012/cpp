#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

// 都是类，默认访问限定符不一样
// 一般情况，成员变量都是私有的，成员函数想给调用是共有，其他是私有
//class Stack // private
//{};
//
////struct Stack // public  兼容c语言对结构体的用法
////{};
//
//struct ListNode
//{};
//
//class List
//{};
//
//
//int main()
//{
//	cout << "hello" << endl;
//
//	return 0;
//}

//class Date
//{
//public:
//	// 编译会增加一个隐含的参数-> void Init(Date* this, int year, int month, int day)
//	// 1、this指针是隐含的，是编译器编译时加的，我们不能显示的在调用和函数定义中加
//	// 2、可以在成员函数中使用this指针
//	// 3、this一般是存在栈上的，不同的编译器不同，vs是使用ecx寄存器存储，传参
//	void Init(int year, int month, int day)
//	{
//		// 检查日期的合法性
//		// ...
//		// 成员函数中，成员前面编译器会自动加this->，你显示加也可以
//		_year = year;
//		_month = month;
//		_day = day;
//
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//
//		cout << "this:" << this << endl;
//	}
//
//private:
//	// 凡是成员变量，建议命名风格区分一下
//	int _year;
//	int _month;
//	int _day;
//
//	// 其他风格
//	//int year_;
//	//int m_year;
//	//int mYear;
//};
//
//int main()
//{
//	Date d1;
//	cout << "d1:" << &d1 << endl;
//	d1.Init(2021, 5, 24); // d1.Init(&d1, 2021, 5, 24);
//
//	Date d2;
//	cout << "d2:" << &d2 << endl;
//	d2.Init(2021, 5, 25); // d2.Init(&d2, 2021, 5, 25)
//
//	return 0;
//}


// 1.下面程序能编译通过吗？
// 2.下面程序会崩溃吗？在哪里崩溃
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->PrintA(); // 空指针
//	p->Show();     // 正常运行
//}







// 类里面成员函数我们什么都不写的时候，编译器会自动生成6个函数，这6个函数就叫默认(缺省)成员函数

// 1、构造函数 --> 对象的初始化
//class Date
//{
//public:
//	// 可能我们会忘记调用它
//	// C++为了解决这个问题，引入构造函数，来初始化
//	//void Init(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;		
//	//}
//
//	// 构造函数 -> 对象实例化的时候自动调用，这样就保证对象一定初始化
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//	// 一般情况，对象初始化惯例都分两种，默认值初始化，给定值初始化
//	// 合二为一，给一个全缺省的，这样定义的构造函数写一个就ok，好用
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Stack
//{
//public:
//	//void Init()
//	//{
//	//	_a = nullptr;
//	//	_size = _capacity = 0;
//	//}
//
//	Stack()
//	{
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//
//	Stack(int capacity)
//	{
//		_a = (int*)malloc(sizeof(int)*capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int x)
//	{}
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Date d1(2021, 5, 24);
//	d1.Print();
//
//	Date d2;
//	d2.Print();
//
//	Date d3(2021);
//	d3.Print();
//
//	Stack st1;
//	st1.Push(1);
//
//	Stack st2(10);
//	st2.Push(1);
//
//
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//	{
//		cout << "A(int a = 0)构造函数" << endl;
//		_a = a;
//	}
//
//	void Print()
//	{
//		cout << _a << endl;
//	}
//
//private:
//	int _a;
//};
//
//
//class Date
//{
//public:
//	// 我们不写，编译器会生成一个构造函数，我们写了编译器就不会生成了。所以说构造函数叫默认成员函数
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		_aa.Print();
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	mksamc
//};
//
//int main()
//{
//	Date d2;
//	d2.Print();
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//	{
//		cout << "A(int a = 0)构造函数" << endl;
//		_a = a;
//	}
//
//	void Print()
//	{
//		cout << _a << endl;
//	}
//
//private:
//	int _a;
//};


//class Date
//{
//public:
//	//Date()
//	//{
//	//	_year = 0;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		//_aa.Print();
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	//A _aa;
//};
//
//// 默认构造函数 很多同学都会以为是我们不写，编译默认生成的那一个，这个理解是不全面的
//// 1、我们不写，编译器默认生成的
//// 2、我们自己写的无参的
//// 3、我们写的全缺省
//// 总结一下：不用参数就可以调用的构造函数
//
//int main()
//{
//	Date d2;
//	d2.Print();
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 有同学就会想，Date的析构函数好像没啥意义？ -》 是的
//	~Date()
//	{
//		// 资源的清理
//		cout << "~Date()" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = (int*)malloc(sizeof(int) * capacity);
		_size = 0;
		_capacity = capacity;
	}

	void Push(int x)
	{}

	// 像Stack这样的类，析构函数具有重大意义
	~Stack()
	{
		cout << "~Stack()析构函数" << endl;
		// 清理资源
		free(_a);
		_a = nullptr;
		_size = _capacity = 0;
	}

private:
	int* _a;
	int _size;
	int _capacity;
};
//
//int main()
//{
//	Date d1;
//
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//
//	Stack st2;
//	st2.Push(10);
//	st2.Push(11);
//	st2.Push(12);
//
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 不写，编译器会生成默认的析构函数
//	// 编译器默认的生成的是什么事情都不做吗？ 不是的
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Stack _st; 
//};
//
//int main()
//{
//	Date d;
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// d1.Equel(d2)
//	bool operator==(Date d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
////private:
//	int _year;
//	int _month;
//	int _day;
//};

//bool operator==(Date x1, Date x2)
//{
//	return x1._year == x2._year
//		&& x1._month == x2._month
//		&& x1._day == x2._day;
//}
//
//int main()
//{
//	Date d1(2021, 1, 1);
//	Date d2(2021, 1, 1);
//
//	 ////内置类型，语言层面就支持运算符
//	 ////自定义类型，默认不支持。C++可以用运算符重载来让类对象支持用某个运算符
//	//operator==(d1, d2);
//	d1 == d2; // operator==(d1, d2);
//	//d1 < d2;
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// d1.Equel(d2)
	bool Equel(Date d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator==(Date x)
	{
		return _year == x._year
			&& _month == x._month
			&& _day == x._day;
	}

	// 当运算符是两个操作数时，第一个参数时左操作数，第二个参数时右操作数
	// d1 < d2
	bool operator<(Date x)
	{
		if (_year < x._year)
		{
			return true;
		}
		else if (_year == x._year)
		{
			if (_month < x._month)
			{
				return true;
			}
			else if (_month == x._month)
			{
				if (_day < x._day)
				{
					return true;
				}
			}
		}
		return false;
	}

	// d1 - 100
	Date operator-(int day)
	{

	}

	// d1 + 100
	Date operator+(int day)
	{

	}

	// d1 - d2
	int operator-(Date d)
	{

	}
private:
	int _year;
	int _month;
	int _day;
};

class Array
{
public:
	Array()
	{
		for (int i = 0; i < 10; ++i)
		{
			_a[i] = i * 10;
		}
	}

	int& operator[](size_t pos)
	{
		return _a[pos];
	}     
private:
	int _a[10];
};

int main()
{
	Date d1(2021, 1, 1);
	Date d2(2021, 1, 2);

	// 内置类型，语言层面就支持运算符
	// 自定义类型，默认不支持。C++可以用运算符重载来让类对象支持用某个运算符
	//d1.operator==(d2); // d1.operator==(&d1, d2);
	cout << (d1 == d2) << endl; // d1.operator==(&d1, d2);
	cout << (d1 < d2) << endl;

	//cout << d1 + 100 << endl;
	//cout << d1 - 100 << endl;
	//cout << d1 - d2 << endl;

	Array ay;
	cout << ay[0] << endl; // ay.operator[](&ay, 0);
	cout << ay[1] << endl;
	cout << ay[2] << endl;
	cout << ay[3] << endl;

	// 修改 -- 赋值给了返回对象的引用（别名）
	ay[0] = 100;
	ay[1] = 200;
	ay[2] = 300;
	ay[3] = 400;

	cout << ay[0] << endl; // ay.operator[](&ay, 0);
	cout << ay[1] << endl;
	cout << ay[2] << endl;
	cout << ay[3] << endl;

	return 0;
}
#include <iostream>
using namespace std;

// 1、功能
// 2、特性及用法
// 3、编译器我们不写默认生成的做了啥

 //6个默认成员函数 
 //-- 我们不写编译器会自动生成，虽然会自动生成，但是好多时候还是需要我们自己写,因为生成的那个不一定好用
 //a、构造函数  --  初始化，大部分情况下，都需要我们自己写构造函数
 //b、析构函数  --  清理内对象中资源
 //c、拷贝构造函数 -- 拷贝初始化，特殊构造函数   深浅拷贝问题
 //d、赋值运算符重载 -- 也是拷贝行为，但是不一样的是，拷贝构造是创建一个对象时，拿同类对象初始化的拷贝
 //赋值拷贝时两个对象已经都存在了，都被初始化过了，现在想把一个对象，赋值拷贝给另一个对象

 //针对我们不写编译默认生成的总结一下：
 //构造和析构的特性是类似，我们不写编译器内置类型不处理，自定义类型调用它的构造和析构处理
 //拷贝构造和赋值重载特性是类似的，内置类型会完成浅拷贝，自定义类型会调用他们的拷贝构造和赋值重载

// 大家要下去总结，关于四个函数和运算符重载的特性和一些使用特点

class A
{
public:
	A(int a = 1)
	{
		_a = a;
	}

	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
		_a = a._a;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

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
//	// Date d4(d1);
//	Date(const Date& d)
//	{
//		/*d._year = _year;
//		d._month = _month;
//		d._day = _day;*/
//
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	// 默认成员函数，我们不写编译器会自动生成拷贝构造
//	// 这个拷贝构造对内置类型会完成浅拷贝，或者值拷贝
//	// d1 < d2 -> d1.operator<(&d1, d2)
//	// bool operator<(const Date& d2); -> bool operator<(Date* this, const Date& d2);
//
//	// d1 = d2;  d1.operator=(&d1, d2)
//	// d1 = d1;
//	// 赋值运算符的也是一个默认成员函数，也就是说我们不写编译器会自动生成一个
//	// 编译器默认生成赋值运算符跟拷贝构造的特性是一致的
//	// a、针对内置类型，会完浅拷贝，也就是说像Date这样的类不需要我们自己写赋值运算符重载，Stack就得自己写
//	// b、针对自定义类型，也一样，它会调用他的赋值运算符重载完成拷贝
//	Date& operator=(const Date& d) // void operator=(Date* this, const Date& d)
//	{
//		if (this != &d) // 检查如果不是自己给自己赋值，才需要拷贝
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//	
//		return *this;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month <<"-" << _day << endl;
//	}
//
//	// 析构函数，我们不需要写，编译默认生成就够用，对象内没有资源清理
//	// 默认生成的析构函函数也是基本不做什么事情，release下优化，就没了
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	//A _aa;
//};

// d1 < d2
// bool operator<(const Date& d1, const Date& d2);


//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		if (capacity <= 0)
//		{
//			_a = nullptr;
//			_size = _capacity = 0;
//		}
//		else
//		{
//			_a = (int*)malloc(sizeof(int)*capacity);
//			_capacity = capacity;
//			_size = 0;
//		}
//	}
//
//	~Stack()
//	{
//		free(_a);
//		_size = _capacity = 0;
//		_a = nullptr;
//	}
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//void f1(Date d)
//{
//
//}
//
//void f2(const Date& d)
//{
//
//}

//int main()
//{
//	//Stack st;
//	//Stack copy(st);
//
//	//Date d1(2020, 5, 26);
//	//Date d2;
//	////Date d3(); // 没有调到构造函数，对象没有被构造出来
//	////Date f1();
//	//d1.Print();
//	//d2.Print();
//	////d3.Print();
//
//	//Date d4(d1); // 拷贝构造函数
//	//d4.Print();
//	//d1.Print();
//
//	/*Date d1(2020, 5, 26);
//	f1(d1);
//	f2(d1);*/
//
//	Date d1(2020, 5, 26);
//	Date d2;
//	Date d3(2020, 1, 1);
//	d1.Print();
//	d2.Print();
//
//	// 也是拷贝行为，但是不一样的是，拷贝构造是创建一个对象时，拿同类对象初始化的拷贝
//	// 赋值拷贝时两个对象已经都存在了，都被初始化过了，现在想把一个对象，赋值拷贝给另一个对象
//	d1 = d2;
//	d1.Print();
//	d2.Print();
//
//	// 连续赋值
//	d1 = d2 = d3;
//	// i = j = k;
//	d1 = d1;
//
//	Date d5(d1); // 拷贝构造  拿一个已经存在的对象去构造初始化另一个要创建的对象
//	d1 = d2;     // 赋值重载  两个已经存在的对象-》拷贝
//	Date d6 = d1; // 拷贝构造? 赋值重载?
//
//
//	return 0;
//}

#include "Date.h"

void Test1()
{
	Date d1(2021, 5, 25);
	d1.Print();

	Date d2(2021, 0, 0);
	//d2.Print();

	Date d3(2021, 2, 29);
	d3.Print();
}

void Test2()
{
	Date d1(2021, 5, 25);
	d1.Print();

	d1 += 3;
	d1.Print();

	d1 += 17;
	d1.Print();

	Date d2 = d1 + 100;
	d2.Print();

	Date d3 = d1 - 800;
	d3.Print();
	//d1++;
	//++d1;
}

int main()
{
	Test2();

	return 0;
}
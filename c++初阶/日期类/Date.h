#pragma once
#include <iostream>
#include <assert.h>

using std::cout;
using std::cin;
using std::endl;

class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1);
	void Print();
	// 析构、拷贝构造、赋值重载，可以不写，默认生成就够用; 
	// 像Stack才需要自己写这三个

	// d + 100
	Date& operator+=(int day);
	Date operator+(int day);

	Date& operator-=(int day);
	Date operator-(int day);

	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	bool operator== (const Date& d);
	bool operator!= (const Date& d);


	int operator-(const Date& d);

	// ++d -> d.operator++(&d)
	Date& operator++();

	// d++ -> d.operator++(&d, 0)
	// int参数不需要给实参，因为没用，他的作用是为了跟前置++构成函数重载
	Date operator++(int);//后置++先使用后++所以要tmp，不能引用
	Date& operator--();
	Date operator--(int);

private:
	int _year;
	int _month;
	int _day;
};

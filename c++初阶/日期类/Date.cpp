#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"


inline int GetMonthDay(int year, int month)
{
	// 数组存储平年每个月的天数
	static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = dayArray[month];

	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day = 29;
	}

	return day;
}

Date::Date(int year, int month, int day)
{
	// 检查日期的合法性
	if (year >= 0
		&& month > 0 && month < 13
		&& day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		// 严格来说抛异常更好
		cout << "非法日期" << endl;
		cout << year << "年" << month << "月" << day << "日" << endl;
		//assert(false);
		//exit(-1);
	}
}

void Date::Print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

// d += 100 返回到自己的地方 生命周期在外面
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
	}
	else {
		_day += day;
		// 天数不合法，不断进位，让他合法
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				++_year;
				_month = 1;
			}
		}
	}
	return *this;
}

// d1 + 100
// 复用
Date Date::operator+(int day)//不能返回引用，临时值除了临时空间就会销毁
{
	Date ret(*this);
	// 复用operator+=
	ret += day;

	return ret;
}

Date& Date::operator-=(int day)
{
	//传入负数则复用
	if (day < 0)
	{
		*this += -day;
	}
	else {
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
	}
	return (*this);
}

Date Date::operator-(int day)
{
	Date ret(*this);
	// 复用operator+=
	ret -= day;
	return ret;
}
//涉及进位
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)//可以接收参数也可以不接收
{
	Date tmp(*this);
	*this += 1;
	return tmp;//return 临时不可以传引用
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;//return 临时不可以传引用
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year==d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month=d._month)
		{
			if (_day>d._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator<(const Date& d)
{
	//不用拷贝，可以复用
	return !(*this >= d);
}

bool Date::operator>=(const Date& d)
{//复用
	return *this > d || *this == d;
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

bool Date::operator== (const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator!= (const Date& d)
{
	return !(*this == d);
} 

int Date::operator-(const Date& d)
{//巧妙的复用，效率差别不大的话，那么还是最好可读性越高越好
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{//复用了++
		++min;
		++n;
	}
	return flag * n;
}

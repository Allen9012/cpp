#include <iostream>
using namespace std;
//
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
//	// d1 == d2
//	// bool operator==(const Date& d) // bool operator==(Date* this, const Date& d)
//	// 加const，修饰的是*this，好处：函数中不小心改变的成员变量，编译时就会被检查出来
//	// 建议：成员函数中，不需要改变成员变量，建议都加上const
//	bool operator==(const Date& d) const // bool operator==(const Date* this, const Date& d)
//	{
//		/*return (_year == d._year) 
//			&& (_month = d._month)
//			&& (_day == d._day);*/
//
//		return (_year == d._year)
//			&& (_month == d._month)
//			&& (_day == d._day);
//	}
//
//	// 成员函数中，编译器处理以后在成员(成员变量/成员函数)前面都会加this->
//	void Func1()
//	{
//		// ...
//	}
//
//	void Print() const // void Print(Date* this)
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//		Func1();
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2021, 5, 27);
//	Date d2(2021, 4, 27);
//
//	cout << (d1 == d2) << endl;
//
//	d1.Print();
//	d2.Print();
//
//	const Date d3(2021, 5, 27);
//	d3.Print();
//
//
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

	// 了解一下
	// 他们基本没有被自己实现的价值
	// 除非你不想让别人获取Date类对象的地址，才有必要自己实现
	Date* operator&()
	{
	//return this;
		return nullptr;
	}

	const Date* operator&() const
	{
	//return this;
		return nullptr;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2021, 5, 27);
	const Date d2(2021, 4, 27);

	cout << &d1 << endl;
	cout << &d2 << endl;

	return 0;
}


class Date
{
	// 友元函数的声明
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// d1 << cout;
	// 第一个参数是左操作数，第二个参数是右操作数
	// 
	//void operator<<(ostream& out) // void operator<<(Date* this, ostream& out)
	//{
	//	out << _year << "-" << _month << "-" << _day << endl;
	//}

	//void operator>>(istream& in)
	//{
	//}

private:
	int _year;
	int _month;
	int _day;
};

// cout << d1;
ostream& operator<<(ostream& out, const Date& d) // void operator<<(Date* this, ostream& out)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;

	return in;
}

// ostream cout;
// istream cin;

//int main()
//{
//	Date d1, d2(2020, 1, 1);
//	cin >> d1 >> d2;
//	cout << d1 << d2;
//
//	//d1 << cout;
//
//	//int i;
//	//double d;
//	//cin >> i;
//	//cin >> d;
//
//	//cout << i;
//	//cout << d;
//
//	return 0;
//}
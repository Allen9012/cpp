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
//	// ��const�����ε���*this���ô��������в�С�ĸı�ĳ�Ա����������ʱ�ͻᱻ������
//	// ���飺��Ա�����У�����Ҫ�ı��Ա���������鶼����const
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
//	// ��Ա�����У������������Ժ��ڳ�Ա(��Ա����/��Ա����)ǰ�涼���this->
//	void Func1()
//	{
//		// ...
//	}
//
//	void Print() const // void Print(Date* this)
//	{
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
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

	// �˽�һ��
	// ���ǻ���û�б��Լ�ʵ�ֵļ�ֵ
	// �����㲻���ñ��˻�ȡDate�����ĵ�ַ�����б�Ҫ�Լ�ʵ��
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
	// ��Ԫ����������
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
	// ��һ������������������ڶ����������Ҳ�����
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
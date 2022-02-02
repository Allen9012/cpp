#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"


inline int GetMonthDay(int year, int month)
{
	// ����洢ƽ��ÿ���µ�����
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
	// ������ڵĺϷ���
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
		// �ϸ���˵���쳣����
		cout << "�Ƿ�����" << endl;
		cout << year << "��" << month << "��" << day << "��" << endl;
		//assert(false);
		//exit(-1);
	}
}

void Date::Print()
{
	cout << _year << "��" << _month << "��" << _day << "��" << endl;
}

// d += 100 ���ص��Լ��ĵط� ��������������
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
	}
	else {
		_day += day;
		// �������Ϸ������Ͻ�λ�������Ϸ�
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
// ����
Date Date::operator+(int day)//���ܷ������ã���ʱֵ������ʱ�ռ�ͻ�����
{
	Date ret(*this);
	// ����operator+=
	ret += day;

	return ret;
}

Date& Date::operator-=(int day)
{
	//���븺������
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
	// ����operator+=
	ret -= day;
	return ret;
}
//�漰��λ
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)//���Խ��ղ���Ҳ���Բ�����
{
	Date tmp(*this);
	*this += 1;
	return tmp;//return ��ʱ�����Դ�����
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
	return tmp;//return ��ʱ�����Դ�����
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
	//���ÿ��������Ը���
	return !(*this >= d);
}

bool Date::operator>=(const Date& d)
{//����
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
{//����ĸ��ã�Ч�ʲ�𲻴�Ļ�����ô������ÿɶ���Խ��Խ��
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
	{//������++
		++min;
		++n;
	}
	return flag * n;
}

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
	// �������������졢��ֵ���أ����Բ�д��Ĭ�����ɾ͹���; 
	// ��Stack����Ҫ�Լ�д������

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
	// int��������Ҫ��ʵ�Σ���Ϊû�ã�����������Ϊ�˸�ǰ��++���ɺ�������
	Date operator++(int);//����++��ʹ�ú�++����Ҫtmp����������
	Date& operator--();
	Date operator--(int);

private:
	int _year;
	int _month;
	int _day;
};

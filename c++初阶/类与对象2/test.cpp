#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

// �����࣬Ĭ�Ϸ����޶�����һ��
// һ���������Ա��������˽�еģ���Ա������������ǹ��У�������˽��
//class Stack // private
//{};
//
////struct Stack // public  ����c���ԶԽṹ����÷�
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
//	// ���������һ�������Ĳ���-> void Init(Date* this, int year, int month, int day)
//	// 1��thisָ���������ģ��Ǳ���������ʱ�ӵģ����ǲ�����ʾ���ڵ��úͺ��������м�
//	// 2�������ڳ�Ա������ʹ��thisָ��
//	// 3��thisһ���Ǵ���ջ�ϵģ���ͬ�ı�������ͬ��vs��ʹ��ecx�Ĵ����洢������
//	void Init(int year, int month, int day)
//	{
//		// ������ڵĺϷ���
//		// ...
//		// ��Ա�����У���Աǰ����������Զ���this->������ʾ��Ҳ����
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
//	// ���ǳ�Ա���������������������һ��
//	int _year;
//	int _month;
//	int _day;
//
//	// �������
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


// 1.��������ܱ���ͨ����
// 2.����������������������
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
//	p->PrintA(); // ��ָ��
//	p->Show();     // ��������
//}







// �������Ա��������ʲô����д��ʱ�򣬱��������Զ�����6����������6�������ͽ�Ĭ��(ȱʡ)��Ա����

// 1�����캯�� --> ����ĳ�ʼ��
//class Date
//{
//public:
//	// �������ǻ����ǵ�����
//	// C++Ϊ�˽��������⣬���빹�캯��������ʼ��
//	//void Init(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;		
//	//}
//
//	// ���캯�� -> ����ʵ������ʱ���Զ����ã������ͱ�֤����һ����ʼ��
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
//	// һ������������ʼ�������������֣�Ĭ��ֵ��ʼ��������ֵ��ʼ��
//	// �϶�Ϊһ����һ��ȫȱʡ�ģ���������Ĺ��캯��дһ����ok������
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
//		cout << "A(int a = 0)���캯��" << endl;
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
//	// ���ǲ�д��������������һ�����캯��������д�˱������Ͳ��������ˡ�����˵���캯����Ĭ�ϳ�Ա����
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
//		cout << "A(int a = 0)���캯��" << endl;
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
//// Ĭ�Ϲ��캯�� �ܶ�ͬѧ������Ϊ�����ǲ�д������Ĭ�����ɵ���һ�����������ǲ�ȫ���
//// 1�����ǲ�д��������Ĭ�����ɵ�
//// 2�������Լ�д���޲ε�
//// 3������д��ȫȱʡ
//// �ܽ�һ�£����ò����Ϳ��Ե��õĹ��캯��
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
//	// ��ͬѧ�ͻ��룬Date��������������ûɶ���壿 -�� �ǵ�
//	~Date()
//	{
//		// ��Դ������
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

	// ��Stack�������࣬�������������ش�����
	~Stack()
	{
		cout << "~Stack()��������" << endl;
		// ������Դ
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
//	// ��д��������������Ĭ�ϵ���������
//	// ������Ĭ�ϵ����ɵ���ʲô���鶼������ ���ǵ�
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
//	 ////�������ͣ����Բ����֧�������
//	 ////�Զ������ͣ�Ĭ�ϲ�֧�֡�C++������������������������֧����ĳ�������
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

	// �������������������ʱ����һ������ʱ����������ڶ�������ʱ�Ҳ�����
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

	// �������ͣ����Բ����֧�������
	// �Զ������ͣ�Ĭ�ϲ�֧�֡�C++������������������������֧����ĳ�������
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

	// �޸� -- ��ֵ���˷��ض�������ã�������
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
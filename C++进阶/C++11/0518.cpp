# define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <initializer_list>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <assert.h>
using namespace std;

//struct Point
//{
//	int _x;
//	int _y;
//};
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////
////int main()
////{
////	Point p1 = { 1, 2 };
////	Point p2 { 1, 2 };
////	int x1 = 1;
////	int x2{ 2 };
////	// !!!
////	int* p3 = new int[4]{0};
////	int* p4 = new int[4]{1,2,3,4};
////
////	Date d1;
////	Date d2(2022, 1, 17);
////	// ������Ȼ������ô�ã��������ǽ������ã������÷���Ϊ�����ط�׼����
////	Date d3{2022, 1, 18};
////	Date d4 = { 2022, 1, 18 };
////
////
////	return 0;
////}
//
//
//int main()
//{
//	auto il1 = { 10, 20, 30 };
//	std::initializer_list<int> il2 = { 1, 2, 3, 4 };
//	cout << typeid(il1).name() << endl;
//
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	list<int> lt{ 10, 20, 30 };
//	vector<Date> vd = { { 2022, 5, 17 }, Date{ 2022, 5, 17 }, { 2022, 5, 17 } };
//	map<string, int> dict = { make_pair("��������", 1), { "�����", 2 } };
//
//	allen::vector<int> bv = { 1, 2, 3, 4, 5 };
//	bv = { 10, 20, 30 };
//
//	return 0;
//}

//// decltype��һЩʹ��ʹ�ó���
//template<class T1, class T2>
//void F(T1 t1, T2 t2)
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//
//	//return ret;
//}
//
//void f(int)
//{
//	cout << "void f(int)" << endl;
//}
//
//void f(int*)
//{
//	cout << "void f(int*)" << endl;
//}
//
//int main()
//{
//	//int i = 10;
//	//auto p = &i;
//	//auto pf = strcpy;
//
//	//cout << typeid(p).name() << endl;
//	//cout << typeid(pf).name() << endl;
//
//	//decltype(pf) px;
//	//cout << typeid(px).name() << endl;
//
//	const int x = 1;
//	double y = 2.2;
//
//	decltype(x * y) ret; // ret��������double
//	//auto ret = x*y;
//
//	decltype(&x) p;      // p��������int*
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//
//	f(NULL);
//	f(nullptr);
//
//	F(x, y);
//
//	return 0;
//}
//
//#include <array>

//int main()
//{
//	// Խ�������׼�ϸ�
//	array<int, 10> a1;
//	array<int, 20> a2;
//	//a1[11];
//	//a1.at(11);
//
//	int a3[10];
//	a3[11];
//
//	vector<int> v;
//	v.resize(10);
//
//	return 0;
//}

//int main()
//{
//	double x = 1.1, y = 2.2;
//
//	// ���¼������ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);
//
//	// ���¼������Ƕ���ֵ����ֵ����
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	cout << &rr1 << endl;
//
//	rr1 = 20;
//	cout << &rr1 << endl;
//
//	/* �������ᱨ��error C2106: ��=��: �����������Ϊ��ֵ
//	10 = 1;
//	x + y = 1;
//	fmin(x, y) = 1;*/
//
//	return 0;
//}

// 1����ֵ����  -�� ��ֵ
// 2����ֵ����  -�� ��ֵ


// 3��const ��ֵ����  -����ֵ �� ��ֵ
// 4����ֵ����  -�� std::move(��ֵ) 


//int main()
//{
//	// ��ֵ����ֻ����ֵ������������ֵ��
//	int&& r1 = 10;
//
//	// error C2440: ����ʼ����: �޷��ӡ�int��ת��Ϊ��int &&��
//	// message : �޷�����ֵ�󶨵���ֵ����
//	int a = 10;
//	//int&& r2 = a;
//
//	// ��ֵ���ÿ�������move�Ժ����ֵ
//	int&& r3 = std::move(a);
//
//	return 0;
//}


namespace allen
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// �ƶ�����
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			this->swap(s);
		}

		// �ƶ���ֵ 
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
			this->swap(s);

			return *this;
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};

	allen::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		allen::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}
}

// ��ֵ���õ�ʹ�ó���
// 1�������� 
// 2��������ֵ
void func1(allen::string s)
{}

void func2(const allen::string& s)
{}

int main()
{
	allen::string s1("hello world");
	// func1��func2�ĵ������ǿ��Կ�����ֵ���������������˿��������Ч�ʵ�ʹ�ó����ͼ�ֵ
	//func1(s1);
	func2(s1);

	// operator+=����ʹ�ô���ֵ���÷���
	s1 += 'A';

	// to_string ��������ֵ���÷��أ����������ֵ���ö̰�
	// ����������ض�����˺���������Ͳ����ˣ��Ͳ���ʹ�������÷��أ��ͻ���ڿ���
	allen::string ret1 = allen::to_string(1234);
	allen::to_string(1234);

	return 0;
}

//int main()
//{
//	bit::string ret1;
//	// ....
//
//	ret1 = bit::to_string(1234);
//
//	return 0;
//}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Date
//{
//	// ��Ԫ����
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	// d1 << cout; -> d1.operator<<(&d1, cout);
//	/*ostream& operator<<(ostream& _cout)
//	{
//	_cout << _year << "-" << _month << "-" << _day << endl;
//	return _cout;
//	}*/
//
//	int GetYear()
//	{
//		return _year;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//int main()
//{
//	Date d1(2021, 5, 31);
//	Date d2(2021, 5, 31);
//	//d1._year = 10;
//	//d1.GetYear() = 10;
//
//	cin >> d1>>d2;
//	cout << d1 << d2;
//
//	return 0;
//}

//class Date;
//
//class Time
//{
//	friend class Date;   // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//	void f(Date& d)
//	{
//		d._year = 1;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//	friend class Time;
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		_t._hour = 1;
//	}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}

//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	return 0;
//}

//class A
//{
//public:
//	A(int x)
//	{
//		cout << "A(int x)" << endl;
//		_x = x;
//	}
//private:
//	int _x;
//};
//
//class Date
//{
//	friend class Time;
//public:
//	// �������ɣ�һ������ĵ�����Ա�����ڳ�ʼ���б���
//	// �����ʵ���ǳ�ʼ���б��ʼ���ͺ������ڳ�ʼ����ͬ�ĵط���Ҳ�����ļ�ֵ����
//	Date(int year = 0, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _n(10)
//		, _ref(year)
//		, _a(1)  // ��ʾȥ����
//	{
//		_day = day;
//		//	_n = 10; // �����ں������ڳ�ʼ��������ʹ�ó�ʼ���б��ʼ��
//		// _ref = year;
//		
//	}
//
//private:
//	// ��Ա��������
//	int _year;
//	int _month;
//	int _day;
//	
//	// ���Ǳ����ڶ����ʱ���ʼ��
//	const int _n;
//	int& _ref;
//	A _a;
//};



//int main()
//{
//	Date d1;
//	//Date d2;
//
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	// �Զ������ͣ�ʹ�ó�ʼ���б� -�� ���캯��
//	/*Date(int day, int hour)
//		:_t(hour)
//	{}*/
//
//	// �Զ������ͣ���ʹ�ó�ʼ���б� -�� ���캯�� + operator=
//	Date(int day, int hour)
//	{
//		// �������ڳ�ʼ��
//		Time t(hour);
//		_t = t;
//	}
//
//private:
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d(12, 12);
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//
//int main() {
//	A aa(1);
//	A aa2(aa);
//	aa.Print();
//
//	return 0;
//}

//class A
//{
//public:
//	//explicit A(int a)
//	explicit A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A&)" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//	void f()
//	{
//		// ...
//		cout << "f()" << endl;
//	}
//
//private:
//	int _a;
//};

//int main()
//{
//	A aa1(1);
//
//	// �������Ĺ��캯����֧����ʽ����ת��
//	A aa2 = 2; 
//	const A& aa3 = 2;
//	// �﷨���������ȹ��죬�ڿ������죬
//	// ���ڵı�������A tmp(2) + A aa2(tmp) -> ���ڵı������������Ż���ֱ�ӵ��ù��캯��A aa2(2)
//
//	int i = 0;
//	double d = i; // ��ʽ����ת��
//
//	string s11("hello");
//	string s22 = "hello"; // string(const char* str){}
//
//	vector<string> v;  // -> push_back(const string& s) {}
//	string s1("�ܽ�");
//	v.push_back(s1);
//	string s2("����");
//	v.push_back(s2);
//
//	// string֧�ֵ���������ʽ����ת�������ǾͿ����������Σ�д���������
//	// ������ϸ�ڣ����Ǻ�����ٽ�
//	v.push_back("����");
//
//	return 0;
//}

//int main()
//{
//	//A aa1(1);  // ��׼�Ĺ��캯�����ã�������������
//	////A aa2 = 2; // ��ʽ����ת�����������Ż���Ҳ��ֱ�ӵ��Ĺ���
//	//A(3);      // �������������������ڻ�����һ��
//	//A aa3(2);
//
//	// ʲô����ʹ�ã�����һ������Ҫ�ã�����������һ���ã������ط����á�
//	// �ȶ����������󣬷����鷳��ֱ�Ӷ����������󣬷�����
//	A aa4;
//	aa4.f();
//	
//	A().f();
//
//	vector<A> v;
//	A aa1(1);
//	v.push_back(aa1);
//	A aa2(2);
//	v.push_back(aa2);
//
//	// ������
//	v.push_back(A(3));
//	v.push_back(A(4));
//	v.push_back(A(5));
//
//	return 0;
//}

// //����һ��������A������ٸ��������
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		++_n;
//	}
//
//
//	A(const A& a)
//	{
//		++_n;
//	}
//
//	void f()
//	{
//		GetN();
//	}
//
//	// ����ͨ��Ա��������û��thisָ�룬���ܷ��ʷǾ�̬��Ա
//	static int GetN() 
//	{
//		// û��thisָ��
//		//_a = 1; // this->_a
//		// f(); // this->f()
//
//		return _n;
//	}
//private:
//	// ����ֻ�����������ڹ��캯����ʼ������������ȫ��λ�ó�ʼ��
//	static int _n;  // n�Ǵ��ھ�̬�������������࣬Ҳ����������ж���
//	int _a;
//};
//
//// ��̬��Ա�����Ķ����ʼ�������������ܷ����޶������ƣ������û�취�����ʼ����
//int A::_n = 0;
//
//// �������const�����޸ģ����Ƕ����ʱ����ԣ�����û�취��ʼ��
////const int n = 10;
////n = 20;
//
//void f(A a)
//{
//
//}
//
//int main()
//{
//	A a1;
//	A a2;
//	A();
//	f(a1);
//
//	//cout << sizeof(A) << endl;
//
//	// ��̬��Ա��������ĳ������ͻ��������ܷ���
//	//cout << A::_n << endl; // public
//	//cout << a1._n << endl; // public
//	//cout << a2._n << endl; // public
//	//cout << A()._n << endl; // public
//
//	cout << a1.GetN() << endl;
//	cout << A().GetN() << endl;
//	cout << A::GetN() << endl;
//
//	A aa[10];
//
//	return 0;
//}

class Add
{
public:
	Add()
	{
		_ret += _i;
		_i++;
	}

	static int GetRet()
	{
		return _ret;
	}

private:
	static int _i;
	static int _ret;
};

int Add::_i = 1;
int Add::_ret = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		//Add arr[n]; // ��һ��ı�����ʱ֧�ֵģ��䳤����c99
		Add* p = new Add[n];

		return Add::GetRet();
	}
};

//int main()
//{
//	cout << Solution().Sum_Solution(10) << endl;
//	cout << Solution().Sum_Solution(10) << endl;
//
//
//	return 0;
//}
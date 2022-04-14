#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

#include <deque>

using std::cout;
using std::endl;



//#define N 1000

// ģ�����
// ����ģ�����
// ������ģ����� -- ���γ���
template<class T = int, size_t N = 8>
class Array
{
public:
	void f()
	{
		N = 1000;  // ���� �ᱨ��
	}
private:
	T _a[N];
};

//template<double D>
//class B
//{
//public:
//};
//
//template<string s>
//class C
//{
//public:
//};

//int main()
//{
//	Array<int, 100> aa1;   // 100
//	Array<int, 1000> aa2;  // 1000
//	Array<int> aa3;  // 1000
//	Array<> aa4;
//
//	//aa1.f();
//
//	return 0;
//}

template<class T>
bool IsEqual(const T& left, const T& right)
{
	return left == right;
}

// ����ַ�������Ҫ���⻯���� -- дһ�ݺ���ģ����������
template<>
bool IsEqual <const char*>(const char* const& left, const char* const& right)
{
	return strcmp(left, right) == 0;
}

//bool IsEqual(const char* const& left, const char* const& right)
//{
//	return strcmp(left, right) == 0;
//}

//int main()
//{
//	//cout << IsEqual(1, 2) << endl;
//	//cout << IsEqual(1.1, 1.1) << endl;
//
//	char p1[] = "hello";
//	char p2[] = "hello";
//	cout << IsEqual(p1, p2) << endl;
//
//	const char* p3 = "hello";
//	const char* p4 = "hello";
//	cout << IsEqual(p3, p4) << endl;
//
//	return 0;
//}

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// �������T1 T2�� int int����һЩ���⻯��ô��ô�� �� -- ��ģ���ػ�
// -- ȫ�ػ�
template<>
class Data < int, int >
{
public:
	Data() { cout << "Data<int, int>" << endl; }
};

// ���ڶ��������ػ�Ϊint --ƫ�ػ�
template <class T1>
class Data < T1, int >
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
};

// ƫ�ػ� ָ�����ģ�������ָ��
template <class T1, class T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
};

template <class T1, class T2>
class Data < T1&, T2& >
{
public:
	Data() { cout << "Data<T1&, T2&>" << endl; }
};

template <class T1, class T2>
class Data < T1&, T2* >
{
public:
	Data() { cout << "Data<T1&, T2*>" << endl; }
};

// ����ģ��Ҳһ����Ҳ��ȫ�ػ���ƫ�ػ�

int main()
{
	Data<int, int> d1;
	Data<int, double> d2;
	Data<double, int> d3;
	Data<double*, int*> d4;
	Data<int*, int*> d5;
	Data<int&, int&> d6;
	Data<int&, int*> d7;

	return 0;
}
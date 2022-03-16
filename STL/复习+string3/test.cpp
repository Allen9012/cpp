#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//namespace bit
//{
//	class string
//	{
//	public:
//		string(const char* str)
//		{
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//
//		size_t size()
//		{
//			return strlen(_str);
//		}
//
//	private:
//		char* _str;
//	};
//}

//int main()
//{
//	bit::string s("hello world");
//	cout << s[2] << endl;
//	cout << s.operator[](2) << endl;
//	//s[2] += 1;
//
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		cout << s[i] << " ";
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		s[i] += 1;
//	}
//
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		cout << s[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

class B
{
public:
	/*B()
		:_b(0)
		{}
		*/
	B(int b = 0)
		:_b(b)
	{}

	B(const B& bb)
		:_b(bb._b)
	{
		cout << "B(const B& bb)" << endl;
	}

	B& operator=(const B& bb)
	{
		cout << "B& operator=(const B& bb)" << endl;

		if (this != &bb)
		{
			_b = bb._b;
		}

		return *this;
	}
private:
	int _b;
};

class C
{
public:
	C(int c1 = 0, int c2 = 0)
		:_c1(c1)
		, _c2(c2)
	{}
private:
	int _c1;
	int _c2;
};

class A
{

private:
	// Ĭ�����ɹ��캯���Ի������ͳ�Ա�����ǲ�����ġ�
	// (��Щ�Ƚ��µı�����Ҳ�п��ܻ��ʼ����0�����Ǵ���������������ᴦ������Ҫ���ɲ���ʼ��)

	// �������Ͳ�������C++�﷨��Ƶ�һ��Сȱ��
	// ����C++11�������˲����﷨������ȱʡֵ�������������ȱ��
	int _a1 = 1; // ���ﲻ�ǳ�ʼ���������Ǹ�ȱʡֵ
	int _a2 = 2;

	// Ĭ�����ɹ��캯�����Զ����͵ĳ�Ա��ȥ��������Ĭ�Ϲ��캯����ʼ��
	//B _b = B(1);
	B _b = 1;

	//C _c = C(1, 1);
	C _c = { 1, 1 };
};

class D
{
public:
	// D�Ĺ��캯���У���������õ�B��Ĭ�Ϲ��캯���أ�
	// �������ʱ���Զ����ù��캯����
	// ���캯���ĳ�ʼ���б������Ϊ�ǳ�Ա���������ʼ���ĵط�
	// ��ʼ���б�����ʾ��д���߲�д��������һ��
	D()
	{}

private:
	int _d = 0;    // ��Ա����
	B	_b;
};

// �����ֳ�Ա���������ڳ�ʼ���б��ʼ��
// 1��const  2������   3��û��Ĭ�Ϲ��캯���ĳ�Ա����

//int main()
//{
//	//A aa;
//
//	//D d;   // �������ʱ�򣬳�ԱҲ��Ϊ�����һ���ֶ��������
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////
// ��������
class Date
{
public:
	//~Date()
	//{
	//	 // ... �����û��ʲô��Դ��Ҫ����
	//	 // ������ʵ����д�����������������Զ����ɾͿ���
	//}
private:
	int _year = 0;
	int _month = 1;
	int _day = 1;

	B _b = 10;
};

namespace bit
{
	class string
	{
	public:
		string(const char* str = "")//����ȱʡnullptr
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		// s2(s1)
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		// s1 = s3
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}

			return *this;
		}

		char& operator[](size_t i)
		{
			return _str[i];
		}

		size_t size()
		{
			return strlen(_str);
		}

		~string()
		{
			cout << "~string()" << endl;
			delete[] _str;
			_str = nullptr;
		}
	private:
		char* _str;
	};
} 

class F
{
private:
	// Ĭ�����ɵ���������������ʲô���鶼����
	// �������Ͳ������Զ������ͣ���ȥ����������������
	int _a;
	bit::string _s;
};

//int main()
//{
//	Date d;  // ��������������ɶ��������
//			 // ��������Ǵ��ں���ջ֡����ģ�����������ջ֡���٣������������
//
//	bit::string s1("hello  world"); 
//	// ���s1������ռ�Ҫ����
//	// ��һ��s1���������Ǻ���������ջ֡���٣���������
//	// �ڶ���s1�����_strָ��Ķ��ϵĿռ䣬�����������������
//
//	//bit::string s2;
//	//F ff;
//}

int main()
{
	// ǳ����(ֵ����)����
	Date d1;
	Date d2(d1);
	Date d3 = d1;
	Date d4;

	d4 = d1;

	bit::string s1("hello world");
	bit::string s2(s1);
	bit::string s3("hello bit");

	s1 = s3;

	return 0;
}
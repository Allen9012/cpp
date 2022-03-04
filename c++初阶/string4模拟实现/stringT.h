#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <assert.h>

//�շ巨
//PushBack  ���� ���� ��������ĸ��д
//valueOver ����      ��һ������Сд������ĵ�������ĸ��д

// stl,linuxԴ���
// ȫСд�����ʺ͵���֮����_�ָ�

//namespace bit1
//{
//	// �����ַ��������飬������ɾ���
//	// �ַ�������Ľ�β��\0
//	class string
//	{
//	public:
//		string(const char* str = "")
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		}
//
//		// ��ͳд��
//		// s2(s1)
//		//string(const string& s)
//		//	:_str(new char[strlen(s._str)+1])
//		//{
//		//	strcpy(_str, s._str);
//		//}
//
//		//// s1 = s3
//		//// s1 = s1
//		//string& operator=(const string& s)
//		//{
//		//	if (this != &s) // s1 = s1
//		//	{
//		//		delete[] _str;
//		//		_str = new char[strlen(s._str) + 1];
//		//		strcpy(_str, s._str);
//		//	}
//
//		//	return *this;
//		//}
//
//		// �ִ�д��
//		// s2(s1)
//		string(const string& s)
//			:_str(nullptr)
//		{
//			string tmp(s._str);
//			swap(_str, tmp._str);
//		}
//
//		// s1 = s3
//		string& operator=(string s)
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//
//		// s1 = s3
//		//string& operator=(const string& s)
//		//{
//		//	if (this != &s)
//		//	{
//		//		string tmp(s);
//		//		swap(_str, tmp._str);
//		//		return *this;
//		//	}
//		//}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		const char* c_str()
//		{
//			return _str;
//		}
//
//	private:
//		char* _str;
//	};
//
//	void test_string1()
//	{
//		string s1("hello world");
//		string s2(s1);
//
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//
//		string s3("hello bit");
//		s1 = s3;
//		cout << s1.c_str() << endl;
//		cout << s3.c_str() << endl;
//
//		printf("%p\n", s1.c_str());
//		s1 = s1;
//		printf("%p\n", s1.c_str());
//	}
//}


namespace bit
{
	// �����ַ��������飬������ɾ���
	// �ַ�������Ľ�β��\0
	// ֧����ɾ���
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
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		// s1.swap(s2);
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// s2(s1)
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			/*	swap(_str, tmp._str);
				swap(_size, tmp._size);
				swap(_capacity, tmp._capacity);*/

				//this->swap(tmp);
			swap(tmp);
		}

		// s1 = s3
		string& operator=(string s)
		{
			/*swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);*/
			swap(s);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		// ����
		// at ���ú�operator[]���ƣ�Խ�����쳣

		// ��
		const char& operator[](size_t i) const
		{
			assert(i < _size);

			return _str[i];
		}

		// �ɶ�����д
		char& operator[](size_t i)
		{
			assert(i < _size);

			return _str[i];
		}

		// ���ռ䣬��չcapacity
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;

				_str = tmp;
			}
		}

		// ���ռ�+��ʼ������չcapacity ���ҳ�ʼ���ռ䡣sizeҲҪ��
		void resize(size_t n, char val = '\0')
		{}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			++_size;
		}

		void append(const char* str)
		{
			size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}

			strcpy(_str + _size, str);
			_size = len;
		}

		// s1 += 'x'
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		// s1 += "xxxxx"
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		bool operator<(const string& s);
		bool operator>(const string& s);
		bool operator<=(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);


		size_t size() const
		{
			return _size;
		}

		const char* c_str() const
		{
			return _str;
		}

	private:
		char* _str;

		size_t _size;
		size_t _capacity;
	};

	void test_string1()
	{
		string s1("hello world");
		string s2(s1);

		string s3("hello bit");

		// C++98��C++11��������ֵ���õ��ƶ����壬�Ż���swap����ģ��
		swap(s1, s3); // Ч�ʵ�
		s1.swap(s3); // Ч�ʸߣ��Ƽ����
	}

	void f(const string& s)
	{
		// ....
		for (size_t i = 0; i < s.size(); ++i)
		{
			//s[i] += 1;
			cout << s[i] << " ";
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		s1[0] = 'x';
		cout << s1[1] << endl;
		//cout << s1[100] << endl;
		cout << s1.c_str() << endl;

		f(s1);

		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		// �����������棬����ԭ��ܼ򵥣������Χfor�ᱻ�������滻�ɵ�������ʽ
		// Ҳ����˵��Χfor���е�����֧�ֵ�
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void test_string4()
	{
		string s1("hello world");
		s1 += '#';
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;

		s1 += "xyz";
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;

		s1 += "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1";
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}
}





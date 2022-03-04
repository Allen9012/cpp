
#pragma once
#include <assert.h>
//����


//namespace allen
//{
//	//���ʾ����ǹ����ַ�����˳������飬ע��
//	//�������βʱ'\0'������˵strlenҪ+1
//
//	class string
//	{
//	public:
//		//���캯��	
//string(const char* str = "")
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		}
//
//
//		//��������
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		//�������캯��   // s2(s1)
//		//1.��ͳд��
//		//string(const string& s)
//		//	: _str(new char[strlen(s._str) + 1])
//		//{
//		//	strcpy(_str, s._str);
//		//}
//
//		//2.�ִ�д��
//		string(const string& s)
//			:_str(nullptr)
//			//����strlen���Ը�ֵnullptr,����һ��Ҫ����䣬��Ϊ_str�����ֵ�Ļ�������tmp
//			//֮����������������������ֵ
//		{
//			string tmp(s._str);
//			swap(_str, tmp._str);
//		}
//
//		//��ֵ���������   s1 = s3
//		// 
//		////1.��ͳ�������ڴ治����ʱ�򣬵��±��쳣���⽫��ԭ����_str����
//		//string& operator=(const string& s)
//		//{//��ֹ�Լ����Լ���ֵ
//		//	if (this != &s)
//		//	{
//		//		delete[]_str;//�����ȸ�ֵ��Ҫ��delete����
//		//		_str = new char[strlen(s._str) + 1];
//		//		strcpy(_str, s._str);
//		//	}
//		// return *this;
//		//}
//
//		//2.�ִ�,������ֵ��
//		string& operator=(string s)
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//
//		////�ִ�д����������danû��Ҫ
//		/*string& operator=(const string& s)
//		{
//			if (this!=&s)
//			{
//				string tmp(s);
//				swap(_str, tmp._str);
//				return *this;
//			}
//		}*/
//
//		const char* c_str()
//		{
//			return _str;
//		}
//
//	private:
//		char* _str;
//
//	};
//
//	void Test_string1()
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


//��ɾ��İ�

namespace allen
{

	class string
	{
	public:
		//������
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + size();
		}


		//���캯��	
		string(const char* str = " ")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}


		//��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		
		//���������е��ظ����Լ�дһ��
	
		void swap(string& s)
		{//�������޶�����Ϊ�����֣����û��������ָȫ��
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		//�������캯��   // s2(s1)
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			,_capacity(0)
			//����strlen���Ը�ֵnullptr,����һ��Ҫ����䣬��Ϊ_str�����ֵ�Ļ�������tmp
			//֮����������������������ֵ
		{
			string tmp(s._str);
			swap(tmp);
		}

		//��ֵ���������   s1 = s3
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}

		//����
		const char* c_str()  const
		{
			return _str;
		}
		 size_t size() const
		{
			return _size;
		}

		
		//ֻ��
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

		//���ռ䣬��չcapacity
		void reserve(size_t n)
		{// ������������ھ��������򿪱ٿռ�
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				
				// �ͷ�ԭ���ɿռ�,Ȼ��ʹ���¿ռ�
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		//���ռ�+��ʼ������չcapacity,���ҳ�ʼ���ռ䣬sizeҲҪ��
		void resize(size_t n,char val='\0')
		{
			if (n > _size)
			{
				// ���n���ڵײ�ռ��С������Ҫ���¿��ٿռ�
				if (n > _capacity)
				{
					reserve(n);
				}
				memset(_str + _size, val, n - _size);//��ԭ��֮��ֱ��n֮ǰ����Ϊval
			}
			_size = n;
			_str[n] = '\0';
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size] = ch;//ԭ\0
			_str[_size+1] = '\0';
			_size++;	
		}

		void append(const char* str)
		{
			//��2�����ܲ�����
			size_t len = _size + strlen(str); 
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str + _size, str);//�õĺ���_str+size��ָ��ֱ��ָ��\0
			_size = len;
		}
		


		bool operator<(const string& s)
		{}
		bool operator>(const string& s)
		{}
		bool operator<=(const string& s)
		{}
		bool operator>=(const string& s)
		{}
		bool operator==(const string& s)
		{}
		bool operator!=(const string& s)
		{}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	};




	void Test_string1()
	{
		string s1("hello world");
		string s2(s1);

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string s3("hello bit");
		s1 = s3;
		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;

		printf("%p\n", s1.c_str());
		s1 = s1;
		printf("%p\n", s1.c_str());
	}

	void Test_string2()
	{
		//����ʹ��ģ��Ļ����������������Ч�ʵ��£���ѡ�� 
		string s1("hello world");
		string s2(s1);
		string s3("hello bit");
		swap(s1, s3);
		s1.swap(s3);//Ч�ʸߣ��Ƽ����
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

	//
	void Test_string3()
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

	//���Ե�����
	void Test_string4()
	{
		//��������һ����ָ��
		string s1("hello world");
		string::iterator it = s1.begin();
		while (it !=s1.end())
		{
			cout << *it << " ";
			++it;
		}
		//�����Ͼ����滻�ɵ�����
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void Test_string5()
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
	void Test_string6()
	{
		string s1 = "Hello";
		s1 += "!";
		s1.resize(11);
	}
}
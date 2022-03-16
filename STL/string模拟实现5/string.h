#pragma once
#include <assert.h>
#include<iostream>
#include <time.h>
#include <string>
//��ɾ��İ�

namespace allen
{

	class string
	{
	public:
		//������
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		const_iterator begin() const
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator end() const
		{
			return _str + _size;
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
				//strcpy(tmp, _str);//�������ڰ�'\0'����
				strncpy(tmp, _str, _size + 1);//����+1���ǰ�\0����ȥ
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
			/*if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			++_size;*/

			insert(_size, ch);
		}

		void append(const char* str)
		{
			/////��2�����ܲ�����
			//size_t len = _size + strlen(str); 
			//if (len > _capacity)
			//{
			//	reserve(len);
			//}
			//strcpy(_str + _size, str);//�õĺ���_str+size��ָ��ֱ��ָ��\0
			//_size = len;
				insert(_size, str);
			
		}
		
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			// ���Ƽ�
			/*int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}*/

			// ���߻�����ָ��
			/*size_t end = _size+1;
			while (end > pos)
			{
				_str[end] = _str[end]-1;
				--end;
			}*/

			//�����ã�ָ�뵹�ǲ�����ʲô
			char* end = _str + _size;
			while (end >= _str + pos)
			{
				*(end + 1) = *end;
				--end;
			}

			_str[pos] = ch;
			_size++;

			return *this;
		}

		//pos֮ǰ
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			// Ų������
			char* end = _str + _size;	
			while (end >= _str + pos)//��ָ��λ��  
			{
				*(end + len) = *end;
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		//ɾ
		//���Է���void
		string& erase(size_t pos=0, size_t len=npos)
		{
			assert(pos < _size);
			size_t leftLen = _size - pos;//ʣ�µĳ��ȣ�������ߵĳ���
			if (len >= leftLen)//pos��ɾ����
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else //ɾ���м䲿��
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}		
			return *this;
		}

		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}

		size_t find(char ch, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		                      //�����￪ʼȥ��
		size_t find(const char *str, size_t pos = 0)  const
		{
			assert(pos <_size);
			const char* ret = strstr(_str+pos, str);
			if (ret)
			{
				return ret - _str;
			}
			else
			{
				return npos;
			}
		}

		

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
		static const size_t npos;
	};

	const size_t string::npos = -1;//��const�Ķ���

	//�����������
	inline bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	inline bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	inline bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	inline bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	inline bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}

	inline bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}

		return in;
	}

	istream& getline(istream& in, string& s)
	{
		s.clear();

		char ch;
		ch = in.get();
		while (ch != '\n')
		{
			s += ch;
			ch = in.get();
		}

		return in;
	}


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
		string s1("hello");
		s1 += '!';

		s1.resize(8, 'x');
		cout << s1.c_str() << endl;

		s1.resize(15, 'y');
		cout << s1.c_str() << endl;

		s1.resize(3);
		cout << s1.c_str() << endl;
	}
	void Test_string7()
	{
		string s1("hello");
		s1.insert(2, 'x');
		cout << s1.c_str() << endl;

		s1.insert(0, 'y');
		cout << s1.c_str() << endl;

		s1.insert(0, "!!!!");
		cout << s1.c_str() << endl;

		s1 += '!';
		cout << s1.c_str() << endl;

		s1 += "world";
		cout << s1.c_str() << endl;

		s1.erase(2, 5);
		cout << s1.c_str() << endl;

		s1.erase(2);
		cout << s1.c_str() << endl;
	}
	void Test_string8()
	{
		string s1("hello world");
		cout << s1.find('x') << endl;
		cout << s1.find('o') << endl;

		cout << s1.find("wor") << endl;
		cout << s1.find("worx") << endl;

		string s2("hello world");
		s2.resize(20);
		s2 += "!!!";//����bug

		//cin >> s2 >> s1;
		cout << s2 << endl;
		/*cout << s1 << endl;

		string line;
		getline(cin, line);
		cout << line << endl;*/
	}

}
//#pragma once
//#include<iostream>
//namespace bit
//{
//	// �����ַ��������飬������ɾ���
//	// �ַ�������Ľ�β��\0
//	// ֧����ɾ���
//	class string
//	{
//	public:
//		typedef char* iterator;
//		typedef const char* const_iterator;
//
//		iterator begin()
//		{
//			return _str;
//		}
//
//		const_iterator begin() const
//		{
//			return _str;
//		}
//
//		iterator end()
//		{
//			return _str + _size;
//		}
//
//		const_iterator end() const
//		{
//			return _str + _size;
//		}
//
//		string(const char* str = "")
//		{
//			_size = strlen(str);
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//
//			strcpy(_str, str);
//		}
//
//		// s1.swap(s2);
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//
//		// s2(s1)
//		string(const string& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			string tmp(s._str);
//			/*	swap(_str, tmp._str);
//				swap(_size, tmp._size);
//				swap(_capacity, tmp._capacity);*/
//
//				//this->swap(tmp);
//			swap(tmp);
//		}
//
//		// s1 = s3
//		string& operator=(string s)
//		{
//			/*swap(_str, s._str);
//			swap(_size, s._size);
//			swap(_capacity, s._capacity);*/
//			swap(s);
//
//			return *this;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//			_size = 0;
//			_capacity = 0;
//		}
//
//		// ����
//		// at ���ú�operator[]���ƣ�Խ�����쳣
//
//		// ��
//		const char& operator[](size_t i) const
//		{
//			assert(i < _size);
//
//			return _str[i];
//		}
//
//		// �ɶ�����д
//		char& operator[](size_t i)
//		{
//			assert(i < _size);
//
//			return _str[i];
//		}
//
//		// ���ռ䣬��չcapacity
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strncpy(tmp, _str, _size + 1);
//				delete[] _str;
//
//				_str = tmp;
//				_capacity = n;
//			}
//		}
//
//		// ���ռ�+��ʼ������չcapacity ���ҳ�ʼ���ռ䡣sizeҲҪ��
//		void resize(size_t n, char val = '\0')
//		{
//			if (n < _size)
//			{
//				_size = n;
//				_str[_size] = '\0';
//			}
//			else
//			{
//				if (n > _capacity)
//				{
//					reserve(n);
//				}
//
//				for (size_t i = _size; i < n; ++i)
//				{
//					_str[i] = val;
//				}
//				_str[n] = '\0';
//				_size = n;
//			}
//		}
//
//		void push_back(char ch)
//		{
//			/*if (_size == _capacity)
//			{
//				reserve(_capacity == 0 ? 4 : _capacity * 2);
//			}
//			_str[_size] = ch;
//			_str[_size + 1] = '\0';
//			++_size;*/
//
//			insert(_size, ch);
//		}
//
//		void append(const char* str)
//		{
//			/*size_t len = _size + strlen(str);
//			if (len > _capacity)
//			{
//				reserve(len);
//			}
//
//			strcpy(_str + _size, str);
//			_size = len;*/
//
//			insert(_size, str);
//		}
//
//		// s1 += 'x'
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//
//		// s1 += "xxxxx"
//		string& operator+=(const char* str)
//		{
//			append(str);
//			return *this;
//		}
//
//		string& insert(size_t pos, char ch)
//		{
//			assert(pos <= _size);
//
//			if (_size == _capacity)
//			{
//				reserve(_capacity == 0 ? 4 : _capacity * 2);
//			}
//
//			// ���Ƽ�
//			/*int end = _size;
//			while (end >= (int)pos)
//			{
//				_str[end + 1] = _str[end];
//				--end;
//			}*/
//
//			// ���߻�����ָ��
//			/*size_t end = _size+1;
//			while (end > pos)
//			{
//				_str[end] = _str[end]-1;
//				--end;
//			}*/
//
//			char* end = _str + _size;
//			while (end >= _str + pos)
//			{
//				*(end + 1) = *end;
//				--end;
//			}
//
//			_str[pos] = ch;
//			_size++;
//
//			return *this;
//		}
//
//		// posλ��֮ǰ
//		string& insert(size_t pos, const char* str)
//		{
//			assert(pos <= _size);
//			size_t len = strlen(str);
//			if (_size + len > _capacity)
//			{
//				reserve(_size + len);
//			}
//
//			// Ų������
//			char* end = _str + _size;
//			while (end >= _str + pos)
//			{
//				*(end + len) = *end;
//				--end;
//			}
//
//			strncpy(_str + pos, str, len);
//			_size += len;
//
//			return *this;
//		}
//
//		string& erase(size_t pos, size_t len = npos)
//		{
//			assert(pos < _size);
//			size_t leftLen = _size - pos;
//			// 1��ʣ����ַ�����С��Ҫɾ�ĳ���  ������ȫ��ɾ�꣩
//			// 2��ʣ����ַ����ȴ���Ҫɾ�ĳ���
//			if (len >= leftLen)
//			{
//				_str[pos] = '\0';
//				_size = pos;
//			}
//			else
//			{
//				strcpy(_str + pos, _str + pos + len);
//				_size -= len;
//			}
//
//			return *this;
//		}
//
//		size_t find(char ch, size_t pos = 0)
//		{
//			assert(pos < _size);
//
//			for (size_t i = pos; i < _size; ++i)
//			{
//				if (_str[i] == ch)
//				{
//					return i;
//				}
//			}
//
//			return npos;
//		}
//
//		size_t find(const char* str, size_t pos = 0)
//		{
//			assert(pos < _size);
//
//			const char* ret = strstr(_str + pos, str);
//			if (ret)
//			{
//				return ret - _str;
//			}
//			else
//			{
//				return npos;
//			}
//		}
//
//		// rfind  ������ȥ����˼������ñȽϼ򵥵ķ�ʽ�����
//		size_t size() const
//		{
//			return _size;
//		}
//
//		const char* c_str() const
//		{
//			return _str;
//		}
//
//		void clear()
//		{
//			_size = 0;
//			_str[0] = '\0';
//		}
//
//	private:
//		char* _str;
//
//		size_t _size;
//		size_t _capacity;
//
//		static const size_t npos;
//	};
//
//	const size_t string::npos = -1;
//
//	// "abc"
//	// "cd"
//	inline bool operator<(const string& s1, const string& s2)
//	{
//		return strcmp(s1.c_str(), s2.c_str()) < 0;
//	}
//
//	inline bool operator==(const string& s1, const string& s2)
//	{
//		return strcmp(s1.c_str(), s2.c_str()) == 0;
//	}
//
//	inline bool operator<=(const string& s1, const string& s2)
//	{
//		return s1 < s2 || s1 == s2;
//	}
//
//	inline bool operator>(const string& s1, const string& s2)
//	{
//		return !(s1 <= s2);
//	}
//
//	inline bool operator>=(const string& s1, const string& s2)
//	{
//		return !(s1 < s2);
//	}
//
//	inline bool operator!=(const string& s1, const string& s2)
//	{
//		return !(s1 == s2);
//	}
//
//	ostream& operator<<(ostream& out, const string& s)
//	{
//		for (auto ch : s)
//		{
//			out << ch;
//		}
//
//		return out;
//	}
//
//	istream& operator>>(istream& in, string& s)
//	{
//		s.clear();
//
//		char ch;
//		ch = in.get();
//		while (ch != ' ' && ch != '\n')
//		{
//			s += ch;
//			ch = in.get();
//		}
//
//		return in;
//	}
//
//	istream& getline(istream& in, string& s)
//	{
//		s.clear();
//
//		char ch;
//		ch = in.get();
//		while (ch != '\n')
//		{
//			s += ch;
//			ch = in.get();
//		}
//
//		return in;
//	}
//
//	//void test_string1()
//	//{
//	//	string s1("hello world");
//	//	string s2(s1);
//
//	//	string s3("hello bit");
//
//	//	// C++98��C++11��������ֵ���õ��ƶ����壬�Ż���swap����ģ��
//	//	swap(s1, s3); // Ч�ʵ�
//	//	s1.swap(s3); // Ч�ʸߣ��Ƽ����
//	//}
//
//	//void f(const string& s)
//	//{
//	//	// ....
//	//	for (size_t i = 0; i < s.size(); ++i)
//	//	{
//	//		//s[i] += 1;
//	//		cout << s[i] << " ";
//	//	}
//	//	cout << endl;
//	//}
//
//	//void test_string2()
//	//{
//	//	string s1("hello world");
//	//	s1[0] = 'x';
//	//	cout << s1[1] << endl;
//	//	//cout << s1[100] << endl;
//	//	cout << s1.c_str() << endl;
//
//	//	f(s1);
//
//	//	for (size_t i = 0; i < s1.size(); ++i)
//	//	{
//	//		cout << s1[i] << " ";
//	//	}
//	//	cout << endl;
//	//}
//
//	//void func(const string& s)
//	//{
//	//	string::const_iterator it = s.begin();
//	//	while (it != s.end())
//	//	{
//	//		// *it = 'x';
//	//		cout << *it << " ";
//	//		++it;
//	//	}
//	//	cout << endl;
//	//}
//
//	//void test_string3()
//	//{
//	//	string s1("hello world");
//	//	string::iterator it = s1.begin();
//	//	while (it != s1.end())
//	//	{
//	//		*it += 1; // �޸�
//	//		cout << *it << " ";
//	//		++it;
//	//	}
//	//	cout << endl;
//
//	//	func(s1);
//
//	//	// �����������棬����ԭ��ܼ򵥣������Χfor�ᱻ�������滻�ɵ�������ʽ
//	//	// Ҳ����˵��Χfor���е�����֧�ֵ�
//	//	for (auto ch : s1)
//	//	{
//	//		cout << ch << " ";
//	//	}
//	//	cout << endl;
//	//}
//
//	//void test_string4()
//	//{
//	//	string s1("hello world");
//	//	s1 += '#';
//	//	for (auto ch : s1)
//	//	{
//	//		cout << ch << " ";
//	//	}
//	//	cout << endl;
//
//	//	s1 += "xyz";
//	//	for (auto ch : s1)
//	//	{
//	//		cout << ch << " ";
//	//	}
//	//	cout << endl;
//
//	//	s1 += "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1";
//	//	for (auto ch : s1)
//	//	{
//	//		cout << ch << " ";
//	//	}
//	//	cout << endl;
//	//}
//
//	//void test_string5()
//	//{
//	//	string s1("hello");
//	//	s1 += '!';
//
//	//	s1.resize(8, 'x');
//	//	cout << s1.c_str() << endl;
//
//	//	s1.resize(15, 'y');
//	//	cout << s1.c_str() << endl;
//
//	//	s1.resize(3);
//	//	cout << s1.c_str() << endl;
//	//}
//
//	void test_string6()
//	{
//		string s1("hello");
//		s1.insert(2, 'x');
//		cout << s1.c_str() << endl;
//
//		s1.insert(0, 'y');
//		cout << s1.c_str() << endl;
//
//		s1.insert(0, "!!!!");
//		cout << s1.c_str() << endl;
//
//		s1 += '!';
//		cout << s1.c_str() << endl;
//
//		s1 += "world";
//		cout << s1.c_str() << endl;
//
//		s1.erase(2, 5);
//		cout << s1.c_str() << endl;
//
//		s1.erase(2);
//		cout << s1.c_str() << endl;
//	}
//
//	//void test_string7()
//	//{
//	//	string s1("hello world");
//	//	cout << s1.find('x') << endl;
//	//	cout << s1.find('o') << endl;
//
//	//	cout << s1.find("wor") << endl;
//	//	cout << s1.find("worx") << endl;
//
//	//	string s2("hello world");
//	//	s2.resize(20, 'x');
//	//	s2 += "!!!";
//
//	//	cin >> s2 >> s1;
//	//	cout << s2 << endl;
//	//	cout << s1 << endl;
//
//	//	string line;
//	//	getline(cin, line);
//	//	cout << line << endl;
//	//}
//}
# define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <thread>
#include <atomic>
#include <initializer_list>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <assert.h>
using namespace std;

//namespace allen
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		iterator begin()
//		{
//			return _str;
//		}
//
//		iterator end()
//		{
//			return _str + _size;
//		}
//
//		string(const char* str = "")
//			:_size(strlen(str))
//			, _capacity(_size)
//		{
//			//cout << "string(char* str)" << endl;
//
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//
//		// s1.swap(s2)
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//
//		// ��������
//		string(const string& s)
//			:_str(nullptr)
//		{
//			cout << "string(const string& s) -- ���" << endl;
//
//			string tmp(s._str);
//			swap(tmp);
//		}
//
//		// �ƶ�����
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- �ƶ�����" << endl;
//			this->swap(s);
//		}
//
//		// �ƶ���ֵ 
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
//			this->swap(s);
//
//			return *this;
//		}
//
//		// ��ֵ����
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(string s) -- ���" << endl;
//			string tmp(s);
//			swap(tmp);
//
//			return *this;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		char& operator[](size_t pos)
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//
//				_capacity = n;
//			}
//		}
//
//		void push_back(char ch)
//		{
//			if (_size >= _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(newcapacity);
//			}
//
//			_str[_size] = ch;
//			++_size;
//			_str[_size] = '\0';
//		}
//
//		//string operator+=(char ch)
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//
//		const char* c_str() const
//		{
//			return _str;
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity; // �������������ʶ��\0
//	};
//
//	allen::string to_string(int value)
//	{
//		bool flag = true;
//		if (value < 0)
//		{
//			flag = false;
//			value = 0 - value;
//		}
//
//		allen ::string str;
//		while (value > 0)
//		{
//			int x = value % 10;
//			value /= 10;
//
//			str += ('0' + x);
//		}
//
//		if (flag == false)
//		{
//			str += '-';
//		}
//
//		std::reverse(str.begin(), str.end());
//		return str;
//	}
//}

// ��ֵ���õ�ʹ�ó���
// 1�������� 
// 2��������ֵ
//void func1(allen::string s)
//{}
//
//void func2(const allen::string& s)
//{}

//int main()
//{
//	bit::string s1("hello world");
//	// func1��func2�ĵ������ǿ��Կ�����ֵ���������������˿��������Ч�ʵ�ʹ�ó����ͼ�ֵ
//	//func1(s1);
//	func2(s1);
//
//	// operator+=����ʹ�ô���ֵ���÷���
//	s1 += 'A';
//
//	// to_string ��������ֵ���÷��أ����������ֵ���ö̰�
//	// ����������ض�����˺���������Ͳ����ˣ��Ͳ���ʹ�������÷��أ��ͻ���ڿ���
//	//bit::string ret1 = bit::to_string(1234);
//	//bit::to_string(1234);
//
//	return 0;
//}

//int main()
//{
//	//bit::to_string(1234);
//	bit::string ret1 = bit::to_string(1234);
//	//bit::string ret1;
//	//ret1 = bit::to_string(1234);
//
//	return 0;
//}
//
//int main()
//{
//	bit::string s1("hello");
//
//	bit::string s2 = s1;
//	bit::string s3 = bit::to_string(1234);
//
//	bit::string s4 = std::move(s1);
//
//	return 0;
//}

//int main()
//{
//	list<allen::string> lt;
//
//	allen::string s1("1111");
//	 ������õ��ǿ�������
//	lt.push_back(s1);
//
//	 ������ö����ƶ�����
//	lt.push_back("2222");
//	lt.push_back(allen::string("2222"));
//	lt.push_back(std::move(s1));
//
//	return 0;
//}

void Fun(int& x) { cout << "��ֵ����" << endl; }
void Fun(const int& x) { cout << "const ��ֵ����" << endl; }

void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }

 //ģ���е�&&��������ֵ���ã������������ã�����ܽ�����ֵ���ܽ�����ֵ��
 //ģ�����������ֻ���ṩ���ܹ�����ͬʱ������ֵ���ú���ֵ���õ�������
 //�����������͵�Ψһ���þ��������˽��յ����ͣ�����ʹ���ж��˻�������ֵ��
 //����ϣ���ܹ��ڴ��ݹ����б���������ֵ������ֵ������, ����Ҫ����������ѧϰ������ת��
template<typename T>
void PerfectForward(T&& t)
{
	Fun(std::forward<T>(t));
	//Fun(t);
}

//int main()
//{
//	PerfectForward(10);           // ��ֵ
//
//	int a;
//	PerfectForward(a);            // ��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//
//	const int b = 8;
//	PerfectForward(b);		      // const ��ֵ
//	PerfectForward(std::move(b)); // const ��ֵ
//
//	return 0;
//}

template<class T>
struct ListNode
{
	ListNode* _next = nullptr;
	ListNode* _prev = nullptr;
	T _data;
};

template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()
	{
		//_head = new Node;
		_head = (Node*)malloc(sizeof(Node));
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(const T& x)
	{
		//Insert(_head, x);
		Insert(_head, x);
	}

	void PushBack(T&& x)
	{
		//cout << &x << endl;
		// ����x�����˻�Ϊ��ֵ������������������x��x��ʶ��Ϊ��ֵ

		//Insert(_head, x);
		// �����Ҫ������ת������x����������ֵ������
		Insert(_head, std::forward<T>(x));
	}

	void PushFront(T&& x)
	{
		//Insert(_head->_next, x);
		Insert(_head->_next, std::forward<T>(x));
	}

	void Insert(Node* pos, T&& x)
	{
		Node* prev = pos->_prev;
		//Node* newnode = new Node;
		//newnode->_data = std::forward<T>(x); // �ؼ�λ��
		Node* newnode = (Node*)malloc(sizeof(Node));
		new(&newnode->_data)T(std::forward<T>(x));

		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}

	void Insert(Node* pos, const T& x)
	{
		Node* prev = pos->_prev;
		//Node* newnode = new Node;
		//newnode->_data = x; // �ؼ�λ��
		Node* newnode = (Node*)malloc(sizeof(Node));
		new(&newnode->_data)T(x);

		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
private:
	Node* _head;
};

//int main()
//{
//	/*List<bit::string> lt;
//	bit::string s1("1111");
//	lt.PushBack(s1);
//
//	lt.PushBack("1111");
//	lt.PushFront("2222");*/
//
//
//	list<std::string> lt;
//	
//	std::string s1("1111");
//	// ������õ��ǿ�������
//	lt.push_back(s1);
//	
//	// ������ö����ƶ�����
//	lt.push_back("2222");
//	lt.push_back(std::string("2222"));
//	lt.push_back(std::move(s1));
//
//	return 0;
//}

//// ���´�����vs2013�в������֣���vs2019�²�����ʾ������������ԡ�
//class Person
//{
//public:
//	/*Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//		{}*/
//
//	//Person() = default;
//
//	//Person(Person&& p) = default;
//
//	Person(const Person& p)
//		:_name(p._name)
//		, _age(p._age)
//	{}
//
//	/*Person& operator=(const Person& p)
//	{
//	if(this != &p)
//	{
//	_name = p._name;
//	_age = p._age;
//	}
//	return *this;
//	}*/
//
//	~Person()
//	{}
//
//private:
//	allen::string _name;
//	int _age = 0;
//};

// C++�����Զ������ͳ�Ա�����ǳ����Ѻã�Ĭ�ϳ�Ա��������ǡ�������Զ������ͳ�Ա
//class MyQueue
//{
//private:
//	std::stack<int> _pushST;
//	std::stack<int> _popST;
//};

//int main()
//{
//	Person s1;
//	//Person s2 = s1;
//	Person s3 = std::move(s1);
//	//Person s4;
//	//s4 = std::move(s2);
//
//	return 0;
//}

// decltype��һЩʹ��ʹ�ó���
//template<class T1, class T2>
//auto F(T1 t1, T2 t2) -> decltype(t1 * t2)
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//	
//	return ret;
//}
//
//int main()
//{
//	F(1, 2.2);
//
//	return 0;
//}

//template <class ...Args>
//void ShowList(Args... args)
//{
//	//cout << sizeof...(args) << endl;
//	for (int i = 0; i < sizeof...(args); ++i)
//	{
//		cout<<args[i]<<" "; // ��֧��
//	}
//}
//
//int main()
//{
//	ShowList();
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//
//	return 0;
//}

//һ��Ҫ��һ���ղ���������������ͣ����
void ShowList()
{
	cout << endl;
}

//template <class T>
//void ShowList(const T& t)
//{
//	cout << t << endl;
//}

template <class T, class ...Args>
void ShowList(T value, Args... args)
{
	cout << value << " ";
	if (sizeof...(args) == 0)
	{
		return;
	}
	ShowList(args...);
}

//int main()
//{
//	ShowList();
//	//ShowList(1);
//	//ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//
//	return 0;
//}

struct Goods
{
	string _name;
	double _price;
	int _num;

	// ...
};

struct ComparePriceLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

struct CompareNumLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._num < gr._num;
	}
};

struct CompareNumGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._num > gr._num;
	}
};

// �ɵ��ö�������
// �º���
// ����ָ��
// lamber

//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 300 }, { "�㽶", 3.3,  100}, { "����", 2.2 , 1000}, { "����", 1.5, 1} };
//	// Ҫ��ֱ����֡��۸��������������������
//
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	sort(v.begin(), v.end(), CompareNumLess());
//	sort(v.begin(), v.end(), CompareNumGreater());
//
//	return 0;
//}

//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 300 }, { "�㽶", 3.3, 100 }, { "����", 2.2, 1000 }, { "����", 1.5, 1 } };
//	// Ҫ��ֱ����֡��۸��������������������
//
//	// ����º����������ǰ��ȽϹ��������ģ���������⣬����������淶��
//	// ������compare1��compare2... ��ô����ɿ��˿�������
//	/*sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	sort(v.begin(), v.end(), CompareNumLess());
//	sort(v.begin(), v.end(), CompareNumGreater());*/
//
//	/*auto f1 = [](const Goods& g1, const Goods& g2)
//	{
//	return g1._price > g2._price;
//	};
//	sort(v.begin(), v.end(), f1);
//	*/
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price > g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._num > g2._num; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._num < g2._num; });
//
//	return 0;
//}

//int main()
//{
//	[]{};
//
//	int a = 1, b = 2;
//	// ʵ��add��lambda
//	auto add1 = [](int x, int y)->int{return x + y; };
//	cout << add1(a, b) << endl;
//
//	// �ڲ�׽�б���׽a��b, û�в�������ʡ�Բ����б�����ֵ����ͨ�����ݣ�Ҳ����ʡ��
//	//auto add2 = [a, b]{}->int{return a + b + 10; };
//	auto add2 = [a, b]{return a + b + 10; };
//	cout << add2() << endl;
//
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <assert.h>

//#include<stdlib.h>
using namespace std;

// ֱ���������涨��ʵ�ֵĳ�Ա������Ĭ�Ͼ�����������
//class A
//{
//public:
//	void func()
//	{
//		cout << "A" << endl;
//	}
//private:
//};
//
//int main()
//{
//	A aa;
//	aa.func();
//
//	return 0;
//}

//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//
//	ListNode(int val)
//		:_next(nullptr)
//		, _prev(nullptr)
//		, _val(val)
//	{}
//};

//void f()
//{
//	// �����÷���malloc��free����ȫһ���ģ����ܶ����ڶ��������ͷſռ�
//	// ʧ���˴���ʽ��һ����mallocʧ�ܷ���NULL��operator newʧ���Ժ����쳣
//	ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
//	free(p1);
//
//	ListNode* p2 = (ListNode*)operator new(sizeof(ListNode));
//	operator delete(p2);
//
//
//	void* p3 = malloc(0xefffffff);
//	if (p3 == NULL)
//	{
//		cout << "malloc fail" << endl;
//	}
//	try
//	{
//		void* p4 = operator new(0xefffffff);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	
//
//	void* p4 = operator new(11);
//	char* p5 = new char[0x7fffffff];
//
//	ListNode* p6 = new ListNode(2);
//
//	cout << "����" << endl;
//}
//
//
//int main()
//{
//	try
//	{
//		f();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//
//	// ��������ר��operator new
//	// 
//	/*void* operator new(size_t n)
//	{
//	void* p = nullptr;
//	p = allocator<ListNode>().allocate(1);
//	cout << "memory pool allocate" << endl;
//	return p;
//	}*/
//
//	/*void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//
//	}*/
//
//	ListNode(int val)
//		:_next(nullptr)
//		, _prev(nullptr)
//		, _val(val)
//	{}
//};
//
//int main()
//{
//	ListNode* p = new ListNode(1);
//	delete p;
//	
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	// A* p = (A*)malloc(sizeof(A));
//
//	// �ȼ���ֱ����A* p = new A
//	A* p = (A*)operator new(sizeof(A));
//	new(p)A; // new(p)A(3);  // ��λnew��placement-new����ʾ���ù��캯����ʼ��������ռ�
//
//	// ���� delete p
//	p->~A(); // ��������������ʾ����
//	operator delete(p);
//
//	return 0;
//}

//int main()
//{
//	void* p = malloc(1024 * 1024 * 1024);
//
//	return 0;
//}

//void Swapi(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//void Swapd(double* p1, double* p2)
//{
//	double tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	Swapi(&a, &b);
//
//	double c = 1.1, d = 2.2;
//	Swapd(&c, &d);
//
//
//	return 0;
//}


// ���ͱ�� -- ģ��

// ����ģ��
//template<class T>  // Type
//template<typename T>  // ����ģ�����T������typename��Ҳ������class����һ��
//void Swap(T& x1, T& x2)
//{
//	T tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	// ������������Swap�����ĵط���һ����������������
//	int a = 1, b = 2;
//	Swap(a, b);
//
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//
//	//Swap(a, c);
//
//	// ��������ͨ��ʵ�����βε�����T�ֱ�Ϊint��double
//	// ���ַ�ʽ����ʽʵ����
//	cout << Add(a, b) << endl;
//	cout << Add(c, d) << endl;
//	cout << Add(a, (int)c) << endl;
//
//	// ���ñ������������ͣ���ʾָ������
//	// ���ַ�ʽ������ʾʵ����
//	cout << Add<int>(a, c) << endl;
//	cout << Add<double>(a, c) << endl;
//
//	return 0;
//}

// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//
//void main()
//{
//	Add(1, 2);       // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2);  // ���ñ������ػ���Add�汾
//}

//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//// ģ����ã����ֳ�ƥ�亯�������Բ�ȥʵ����ģ��
//// �и�ƥ��ģ�����ƥ����������ʵ�
//void main()
//{
//	Add(1, 2);     // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0);   // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//}

// ��ģ��
//typedef double VDataType;
//class vector
//{
//public:
//	//
//private:
//	VDataType* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	vector v1; // int
//
//	vector v2; // double
//
//
//	return 0;
//}

// ��ģ��
//namespace zj
//{
	//template<class T>
	//class vector
	//{
	//public:
	//	vector()
	//		:_a(nullptr)
	//		, _size(0)
	//		, _capacity(0)
	//	{}

	//	// ���������operator= �����漰��ǳ�������⣬��ͦ���ӣ���������ٽ�

	//	~vector()
	//	{
	//		delete[] _a;
	//		_a = nullptr;
	//		_size = _capacity = 0;
	//	}

	//	void push_back(const T& x)
	//	{
	//		if (_size == _capacity)
	//		{
	//			int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
	//			T* tmp = new T[newcapacity];
	//			if (_a)
	//			{
	//				memcpy(tmp, _a, sizeof(T) * _size);
	//				delete[] _a;
	//			}
	//			_a = tmp;
	//			_capacity = newcapacity;
	//		}

	//		_a[_size] = x;
	//		++_size;
	//	}

	//	// ��+д
	//	T& operator[](size_t pos);
	//	size_t size();
	//private:
	//	T* _a;
	//	size_t _size;
	//	size_t _capacity;
	//};
//
//	// ģ�岻֧�ַ�����룬Ҳ����������.h ,������.cpp��ԭ������ٽ�
//	// ������Ƕ�����һ���ļ� xxx.h  xxx.hpp
//	// �������涨��
//	template<class T>
//	T& vector<T>::operator[](size_t pos)
//	{
//		assert(pos < _size);
//
//		return _a[pos];
//	}
//
//	template<class T>
//	size_t vector<T>::size()
//	{
//		return _size;
//	}
//}
//
//int main()
//{
//	zj::vector<int> v1;		// int
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//
//	// v1.operator[](3);
//	//cout << v1[3] << endl;
//	//cout << v1[5] << endl;
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		v1[i] *= 2;
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//
//	zj::vector<double> v2;   // double
//	v2.push_back(1.1);
//	v2.push_back(2.2);
//	v2.push_back(3.3);
//	v2.push_back(4.4);
//
//	for (size_t i = 0; i < v2.size(); ++i)
//	{
//		cout << v2[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


namespace allen
{
	template<class T>
	class vector
	{
	public:
		vector()
			:_a(nullptr)
			, _size(0)
			, _capacity(0)
		{}
		~vector()
		{
			delete[] _a;
			_a = nullptr;
			_size = _capacity = 0;
		}

		//���������operator= �漰���
		void push_back(const T& x)
		{
			if (_size == _capacity)
			{
				int newcapacity = (_capacity == 0) ? 4 : _capacity * 2;
				T* tmp = new T[newcapacity];
				if (_a)
				{
					memcpy(tmp, _a, sizeof(T)* _size);
					delete[] _a;
				}
				_a = tmp;
				_capacity = newcapacity;
			}
			_a[_size++] = x;
		}

		//���÷�����ɶ�+д
	T&	operator[] (size_t pos)
		{
			assert(pos < _size);
			return _a[pos];
		}

	size_t size() 
	{
		return _size;
	}
	private: 
		T* _a;
		size_t _size;
		size_t _capacity;
	};

}


int main()
{
	allen::vector<int> v1;
	v1.push_back(3);
	v1.push_back(4);
	for (int i=0;i<v1.size();i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	allen::vector<double> v2;
	v2.push_back(3.1);
	v2.push_back(4.2);
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	return 0;
}
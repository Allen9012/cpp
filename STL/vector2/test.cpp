#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

#include "Vector.h"
#include "myvector.h"
//void PrintVector(const vector<int>& v)
//{
//	//v[0] = 20;
//	vector<int>::const_iterator it1 = v.begin();
//	while (it1 != v.end())
//	{
//		//*it1 += 1;
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//}
template<class T>
void PrintVector(const vector<T>& v)
{
	 vector <T>::template const_iterator  it1 = v.begin();
	 //vector <T>:: const_iterator  it1 = v.begin();

	 while (it1 != v.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}

void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1[0] = 10;

	// ����1
	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	// ����2
	vector<int>::iterator it1 = v1.begin();
	while (it1 != v1.end())
	{
		*it1 += 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	// ����3 (�Զ��жϽ������Զ�����++)->�����������ܣ�
	// ʵ�����أ���ʵ���Ǳ��滻���˵�����
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	PrintVector(v1);
}

void test_vector2()
{
	vector<int> v1;
	vector<int> v2(10, 0);
	vector<int> v3(v2.begin(), v2.end());

	string s("hello world");
	vector<char> v4(s.begin(), s.end());

	string s1("hello");
	string s2 = "hello";

	vector<string> v5;
	string s3("sort");
	v5.push_back(s3);
	v5.push_back(string("insert"));

	// �Ƽ�
	v5.push_back("erase");

	PrintVector(v1);
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);
	PrintVector(v5);

	vector<string> copy(v5);
	PrintVector(copy);

	//vector<string>::reverse_iterator rit = copy.rbegin();
	auto rit = copy.rbegin();
	while (rit != copy.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_vector3()
{
	// ��֤vector�����ݷ�ʽ
	size_t sz;
	std::vector<int> foo;
	foo.reserve(100);

	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	vector<int> v1;
	v1.reserve(10);

	vector<int> v2;
	v2.resize(10, 2);
}

void test_vector4()
{
	vector<vector<int>> vv;
	vv.resize(5);

	for (size_t i = 0; i < vv.size(); ++i)
	{
		vv[i].resize(i + 1);
	}

	for (size_t i = 0; i < vv.size(); ++i)
	{
		vv[i][0] = vv[i][vv[i].size() - 1] = 1;
	}
}

void test_vector5()
{
	//vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//v.push_back(5);
	//v.insert(v.begin(), 0);

	//for (auto e : v)
	//{
	//cout << e << " ";
	//}
	//cout << endl;

	//v.erase(v.begin());
	//for (auto e : v)
	//{
	//cout << e << " ";
	//}
	//cout << endl;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	// 3��ǰ�����һ��100
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
	{
		v.insert(pos, 100);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// ɾ��3
	// pos��insert�Ժ��ʧЧ�ˣ��������ǲ�Ҫ����
		pos = find(v.begin(), v.end(), 3);
		if (pos != v.end())
		{
			v.erase(pos);
		}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


// Ҫ��ɾ��v�����е�ż��
void test_vector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	//vector<int>::iterator it = v.begin();
	auto it = v.begin();

	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			// v.erase(it)�Ժ� itʧЧ������++��
			// erase �᷵��ɾ��λ��it����һ��λ��
			it = v.erase(it);
			//v.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

// Ҫ��ɾ��v�����е�ż��
void test_vector7()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);

	// C++98 �Ƽ��ڶ���
	swap(v1, v2);
	v1.swap(v2);

	// C++11 ��һ��������Ժ�����˵

}

int main()
{
	//test_vector6();
	//bit::test_vector1();
	allen::TestVector1();
	return 0;
}
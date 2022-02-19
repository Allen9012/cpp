#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

// char ascall���� -�� Ӣ��
// �����ʾ���ģ����ģ��������ҵ����ּ������δ洢�� unicode utf-8 utf-16 utf-32  gbk
//int main()
//{
//	char ch1 = 'a';
//	char ch2 = 97;
//	cout << ch1 << endl;
//	cout << ch2 << endl;
//
//	char str1[] = "�й�";
//	cout << strlen(str1) << endl;
//
//	str1[3] = -7;
//	cout << str1 << endl;
//
//	str1[3] = -8;
//	cout << str1 << endl;
//
//	str1[3] = -5;
//	cout << str1 << endl;
//
//	wchar_t wch;  // ���ֽڣ�2byte���ܸ��õı�ʾunicode�ȱ���
//	char ch;
//	cout << sizeof(ch) << endl;
//	cout << sizeof(wch) << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1;
//	string s2("hello bit");
//	string s3(s2);
//	string s4 = "hello bit";
//
//	string s5(s4, 3, string::npos);
//	cout << s5 << endl;
//
//	char* url = "http://www.cplusplus.com/reference/string/string/string/";
//	string s6(url, 4);
//	cout << s6 << endl;
//
//	string s7(10, 'x');
//	cout << s7 << endl;
//
//	s7 = s2;
//	cout << s7 << endl;
//
//
//	return 0;
//}

int firstUniqChar(const string& s) {
	int count[26] = { 0 };
	string::const_iterator it = s.cbegin();
	while (it != s.end())
	{
		//*it += 1;
		count[*it - 'a']++;
	}

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (count[s[i] - 'a'] == 1)
			return i;
	}

	return -1;
}

// size/clear/resize
void Teststring1()
{
	// ע�⣺string�����֧��ֱ����cin��cout������������
	string s("helloworld");
	cout << s.size() << endl;//10
	cout << s.length() << endl;//10
	cout << s.capacity() << endl;//15
	cout << s << endl;
	// ��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
	s.clear();
	cout << s.size() << endl;//0
	cout << s.capacity() << endl;//15
	// ��s����Ч�ַ��������ӵ�10�������λ����'a'�������
	// ��aaaaaaaaaa��
	s.resize(10, 'a');
	cout << s.size() << endl;//10
	cout << s.capacity() << endl;//15
	// ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
	// "aaaaaaaaaa\0\0\0\0\0"
	// ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
	s.resize(15);
	cout << s.size() << endl;//15
	cout << s.capacity() << endl;//15
	cout << s << endl;//aaaaaaaaaa
	// ��s����Ч�ַ�������С��5��
	s.resize(5);
	cout << s.size() << endl;//5
	cout << s.capacity() << endl;//15
	cout << s << endl;//aaaaa
}
//================================================================================

void Teststring2()
{
	string s;
	// ����reserve�Ƿ��ı�string����ЧԪ�ظ���
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	// ����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}



int main()
{
	string s1;
	string s2("hello bit");

	// ���ֱ���
	// 1���±�+[]
	for (size_t i = 0; i < s2.size(); ++i)
	{
		// s2.operator[](i)
		s2[i] = 'x';
	}
	cout << endl;

	for (size_t i = 0; i < s2.size(); ++i)
	{
		// s2.operator[](i)
		cout << s2[i] << " ";
		//cout << s2.at(i) << " ";
	}
	cout << endl;

	//s2[10]; // Խ����Ա���
	try 
	{
		s2.at(10);  // Խ�����쳣
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	// 2��������
	// [begin(), end() ) end()���صĲ������һ������λ�õĵ����������������һ��λ����һ��λ��
	// ҲҪע����ǣ�C++�з��Ǹ�������һ�㶼�Ǹ���[)����ҿ�������
	// ������������ָ��һ��������������ʲô���ǽ��˵ײ�ʵ�ֲ���֪��
	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ���������壺��string��vector֧��[]����������list��map�ȵ�������֧��[]
	// ���Ǿ�Ҫ�õ��������������Ե�������һ��ͳһʹ�õķ�ʽ
	vector<int> v = { 1, 2, 3, 4 };
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;

	list<int> lt = { 1, 2, 3, 4 };
	list<int>::iterator ltit = lt.begin();
	while (ltit != lt.end())
	{
		cout << *ltit << " ";
		++ltit;
	}
	cout << endl;

	// ���������
	string s3("123456");
	string::iterator it3 = s3.begin();
	while (it3 != s3.end())
	{
		*it3 += 5;

		++it3;
	}
	cout << endl;

	string::reverse_iterator rit = s3.rbegin();
	while (rit != s3.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	// 3��C++11 �ṩ ��Χfor�� �ص㣺д�������
	// ����ȡ�����е����ݣ���ֵ��e���Զ��жϽ���
	//for (auto& e : s3)
	for (char& e : s3)
	{
		e += 1;
	}
	cout << endl;

	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	for (auto x : lt)
	{
		cout << x << " ";
	}
	cout << endl;


	return 0;
}

int main()
{
	string s1;
	s1.push_back('h');
	s1.push_back('e');
	s1.push_back('l');
	s1.push_back('l');
	s1.push_back('o');

	s1.append("world");
	cout << s1 << endl;

	string s2("!!!!");
	//s1.append(s2);
	s1.append(s2.begin(), s2.end());
	cout << s1 << endl;

	// ʵ������ϲ�������+=
	s1 += ' ';
	s1 += "����";
	s1 += s2;
	cout << s1 << endl;

	// ��������insert����Ϊ�ײ�ʵ�������飬ͷ�������м������ҪŲ������
	s1.insert(0, "x");
	cout << s1 << endl;
	s1.insert(3, "yyyy");
	cout << s1 << endl;
	s1.insert(0, "yyyy");
	cout << s1 << endl;
	//s1.insert(300, "yyyy");
	cout << s1 << endl;

	s1.erase(0, 1);
	cout << s1 << endl;

	s1.erase(0, 3);
	cout << s1 << endl;

	s1.erase(3, 10);
	cout << s1 << endl;

	//s1.erase(3, 100);
	s1.erase(3);
	cout << s1 << endl;

	s1.erase();
	cout << s1 << endl;

	return 0;
}
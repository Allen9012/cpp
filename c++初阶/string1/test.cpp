#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

// char ascall编码 -》 英文
// 如何显示中文？日文？其他国家的文字计算机如何存储？ unicode utf-8 utf-16 utf-32  gbk
//int main()
//{
//	char ch1 = 'a';
//	char ch2 = 97;
//	cout << ch1 << endl;
//	cout << ch2 << endl;
//
//	char str1[] = "中国";
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
//	wchar_t wch;  // 宽字节，2byte，能更好的表示unicode等编码
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
	// 注意：string类对象支持直接用cin和cout进行输入和输出
	string s("helloworld");
	cout << s.size() << endl;//10
	cout << s.length() << endl;//10
	cout << s.capacity() << endl;//15
	cout << s << endl;
	// 将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小
	s.clear();
	cout << s.size() << endl;//0
	cout << s.capacity() << endl;//15
	// 将s中有效字符个数增加到10个，多出位置用'a'进行填充
	// “aaaaaaaaaa”
	s.resize(10, 'a');
	cout << s.size() << endl;//10
	cout << s.capacity() << endl;//15
	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
	// "aaaaaaaaaa\0\0\0\0\0"
	// 注意此时s中有效字符个数已经增加到15个
	s.resize(15);
	cout << s.size() << endl;//15
	cout << s.capacity() << endl;//15
	cout << s << endl;//aaaaaaaaaa
	// 将s中有效字符个数缩小到5个
	s.resize(5);
	cout << s.size() << endl;//5
	cout << s.capacity() << endl;//15
	cout << s << endl;//aaaaa
}
//================================================================================

void Teststring2()
{
	string s;
	// 测试reserve是否会改变string中有效元素个数
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}



int main()
{
	string s1;
	string s2("hello bit");

	// 三种遍历
	// 1、下标+[]
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

	//s2[10]; // 越界断言报错
	try 
	{
		s2.at(10);  // 越界抛异常
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	// 2、迭代器
	// [begin(), end() ) end()返回的不是最后一个数据位置的迭代器，返回是最后一个位置下一个位置
	// 也要注意的是，C++中凡是给迭代器一般都是给的[)左闭右开的区间
	// 迭代器是类似指针一样东西，具体是什么我们讲了底层实现才能知道
	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 迭代器意义：像string、vector支持[]遍历，但是list、map等等容器不支持[]
	// 我们就要用迭代器遍历，所以迭代器是一种统一使用的方式
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

	// 反向迭代器
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

	// 3、C++11 提供 范围for， 特点：写起来简洁
	// 依次取容器中的数据，赋值给e，自动判断结束
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

	// 实际中最喜欢用这个+=
	s1 += ' ';
	s1 += "比特";
	s1 += s2;
	cout << s1 << endl;

	// 尽量少用insert，因为底层实现是数组，头部或者中间插入需要挪动数据
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
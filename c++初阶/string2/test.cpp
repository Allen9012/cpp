#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;



//int main()
//{
//	string s1;
//	cout << "size:"<<s1.size() << endl;
//	cout << "capacity:" << s1.capacity() << endl;
//	cout << s1 << endl;
//
//	s1.resize(20, 'x');
//	cout << "size:" << s1.size() << endl;
//	cout << "capacity:" << s1.capacity() << endl;
//	cout << s1 << endl;
//
//	string s2("hello world");
//	s2.resize(20, 'x');
//	cout << s2 << endl;
//	cout << "size:" << s2.size() << endl;
//	cout << "capacity:" << s2.capacity() << endl;
//
//	s2.resize(5);
//	cout << s2 << endl;
//	cout << "size:" << s2.size() << endl;
//	cout << "capacity:" << s2.capacity() << endl << endl;
//
//	//vector<int> countV;
//	//countV.resize(100, 0);
//
//	string s3;
//	cout << "size:" << s3.size() << endl;
//	cout << "capacity:" << s3.capacity() << endl;
//
//	s3.reserve(40);
//	cout << "size:" << s3.size() << endl;
//	cout << "capacity:" << s3.capacity() << endl;
//
//
//	string s4;
//	//s4.reserve(127);
//	int oldCp = s4.capacity();
//	for (char ch = 0; ch < 127; ++ch)
//	{
//		s4 += ch;
//		if (oldCp != s4.capacity())
//		{
//			cout << "增容：" << oldCp << "->" << s4.capacity() << endl;
//			oldCp = s4.capacity();
//		}
//	}
//	cout << s4 << endl;
//
//
//
//	return 0;
//}

string GetDomain(const string& url)
{
	size_t pos = url.find("://");
	if (pos != string::npos)
	{
		size_t start = pos + 3;
		size_t end = url.find('/', start);
		if (end != string::npos)
		{
			return url.substr(start, end - start);
		}
		else
		{
			return string();
		}
	}
	else
	{
		return string();
	}
}

string GetProtocol(const string& url)
{
	size_t pos = url.find("://");
	if (pos != string::npos)
	{
		return url.substr(0, pos - 0);
	}
	else
	{//找不到返回空字符串
		return string();
	}
}

int main()
{
	string s1("hello world");
	cout << s1 << endl;   // 调用 operator<<(cout, s1)
	cout << s1.c_str() << endl; // 调用 operator<<(cout, const char*)

	s1.resize(20);
	s1 += "!!!";
	cout << s1 << endl;   // 调用 operator<<(cout, s1)
	cout << s1.c_str() << endl; // 调用 operator<<(cout, const char*)

	cout << strlen(s1.c_str()) << endl;
	cout << s1.size() << endl << endl;

	// 假设要求取出文件名的后缀
	string filename = "test.txt.zip";
	size_t pos = filename.find('.');
	if (pos != string::npos)
	{
		//string suff(filename, pos, filename.size() - pos);
		//string suff(filename, pos);
		//string suff = filename.substr(pos, filename.size() - pos);
		string suff = filename.substr(pos);

		cout << suff << endl;
	}

	// 要求写一个程序分别取出域名和协议名
	string url1 = "http://www.cplusplus.com/reference/string/string/rfind/";
	string url2 = "https://tower.im/users/sign_in";
	string url3 = "tower.im/users/sign_in";

	cout << GetDomain(url1) << endl;
	cout << GetProtocol(url1) << endl;

	cout << GetDomain(url2) << endl;
	cout << GetProtocol(url2) << endl;

	//cout << GetProtocol(url3) << endl;

	return 0;
}

//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	bool isLetterOrNumber(char ch)
//	{
//		if ((ch >= 'a' && ch <= 'z')
//			|| (ch >= 'A' && ch <= 'Z')
//			|| (ch >= '0' && ch <= '9'))
//			return true;
//		else
//			return false;
//	}
//
//	bool isPalindrome(string s) {
//		// 把字符串中的大写字母都转成小写
//		for (auto& ch : s)
//		{
//			if (ch >= 'A' && ch <= 'Z')
//			{
//				ch += 32;
//			}
//		}
//
//		int begin = 0, end = s.size() - 1;
//		while (begin < end)
//		{
//			while (begin < end && !isLetterOrNumber(s[begin]))
//			{
//				++begin;
//			}
//
//			while (begin < end && !isLetterOrNumber(s[end]))
//			{
//				--end;
//			}
//
//			if (s[begin] == s[end])
//			{
//				++begin;
//				--end;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		return true;
//	}
//};
//
//int main()
//{
//	cout << Solution().isPalindrome("a.") << endl;
//
//	return 0;
//}
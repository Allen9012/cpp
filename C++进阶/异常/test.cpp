#include <iostream>
#include <string>
using namespace std;

//void f1()
//{
//	int i, j;
//	cin >> i >> j;
//	if (j == 0)
//	{
//		throw 1;
//	}
//
//	cout << i / j << endl;
//}
//
//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (int errid)
//	{
//		cout <<"错误码："<<errid << endl;
//	}
//
//	return 0;
//}

//void f1()
//{
//	int i, j;
//	cin >> i >> j;
//	if (j == 0)
//	{
//		throw string("除零错误");
//	}
//
//	cout << i / j << endl;
//}
//
//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (int errid)
//	{
//		cout << "错误码：" << errid << endl;
//	}
//	catch (const string& s)
//	{
//		cout <<"错误描述："<<s << endl;
//	}
//
//	return 0;
//}

//void f1()
//{
//	int i, j;
//	cin >> i >> j;
//	if (j == 0)
//	{
//		throw string("除零错误");
//	}
//
//	cout << i / j << endl;
//}
//
//int* p2 = nullptr;
//FILE* p3 = nullptr;
//
//void f2()
//{
//	p2 = (int*)malloc(40);
//	if (p2 == nullptr)
//	{
//		throw string("malloc失败");
//	}
//}
//
//void f3()
//{
//	p3 = fopen("test.txt", "r");
//	if (p3 == nullptr)
//	{
//		throw string("fopen失败了");
//	}
//}
//
//int main()
//{
//	try
//	{
//		f1();
//		f2();
//		f3();
//
//		free(p2);
//		fclose(p3);
//	}
//	catch (int errid)
//	{
//		cout << "错误码：" << errid << endl;
//	}
//	catch (const string& s)
//	{
//		cout << "错误描述：" << s << endl;
//
//		if (s == "fopen失败")
//		{
//			free(p2);
//		}
//	}
//
//	return 0;
//}

//class MyExcetion
//{
//public:
//	MyExcetion(int errid, const char* errmsg)
//		:_errid(errid)
//		, _errmsg(errmsg)
//	{}
//
//	int GetErrId() const
//	{
//		return _errid;
//	}
//
//	const string& what() const
//	{
//		return _errmsg;
//	}
//
//private:
//	int _errid;
//	string _errmsg;
//	// ...
//};
//
//void f1()
//{
//	int i, j;
//	cin >> i >> j;
//	if (j == 0)
//	{
//		throw MyExcetion(1, "除零错误");
//	}
//
//	cout << i / j << endl;
//}
//
//int* p2 = nullptr;
//FILE* p3 = nullptr;
//
//void f2()
//{
//	p2 = (int*)malloc(40);
//	if (p2 == nullptr)
//	{
//		throw MyExcetion(2, "malloc失败");
//	}
//}
//
//void f3()
//{
//	p3 = fopen("test.txt", "r");
//	if (p3 == nullptr)
//	{
//		throw MyExcetion(3, "fopen失败");
//	}
//}
//
//int main()
//{
//	try
//	{
//		f1();
//		f2();
//		f3();
//
//		free(p2);
//		fclose(p3);
//	}
//	catch (int errid)
//	{
//		cout << "错误码：" << errid << endl;
//	}
//	catch (const string& s)
//	{
//		cout << "错误描述：" << s << endl;
//
//		if (s == "fopen失败")
//		{
//			free(p2);
//		}
//	}
//	catch (const MyExcetion& e)
//	{
//		cout << "错误描述：" << e.what() << endl;
//		if (e.GetErrId() == 3)
//		{
//			free(p2);
//		}
//	}
//
//	return 0;
//}


//class MyExcetion
//{
//public:
//	MyExcetion(int errid, const char* errmsg)
//		:_errid(errid)
//		, _errmsg(errmsg)
//	{}
//
//	int GetErrId() const
//	{
//		return _errid;
//	}
//
//	const string& what() const
//	{
//		return _errmsg;
//	}
//
//private:
//	int _errid;
//	string _errmsg;
//	// ...
//};
//
//void f1()
//{
//	int i, j;
//	cin >> i >> j;
//	if (j == 0)
//	{
//		//throw MyExcetion(1, "除零错误");
//		MyExcetion e(1, "除零错误");
//		throw e;
//	}
//
//	cout << i / j << endl;
//}
//
//void f2()
//{
//	try
//	{
//		f1();
//	}
//	catch (const MyExcetion& e)
//	{
//		cout << "错误描述：" << e.what() << endl;
//	}
//}
//
//int main()
//{
//	try
//	{
//		f2();
//		char* p = new char[0x7fffffff];
//	}
//	catch (const MyExcetion& e)
//	{
//		cout << "错误描述：" << e.what() << endl;
//	}
//	catch (...) // 任意类型的异常
//	{
//		cout << "未知异常" << endl;
//	}
//
//	return 0;
//}


// 基类
class MyExcetion
{
public:
	MyExcetion(int errid, const char* errmsg)
		:_errid(errid)
		, _errmsg(errmsg)
	{}

	int GetErrId() const
	{
		return _errid;
	}

	virtual string what() const
	{
		return _errmsg;
	}

protected:
	int _errid;
	string _errmsg;
	// ...
};

class CacheExcetion : public MyExcetion
{
public:
	CacheExcetion(int errid, const char* errmsg)
		:MyExcetion(errid, errmsg)
	{}

	virtual string what() const
	{
		string msg = "CacheExcetion：";
		msg += _errmsg;
		return msg;
	}

protected:
	// ...
};

class SqlExcetion : public MyExcetion
{
public:
	SqlExcetion(int errid, const char* errmsg, const char* sql)
		:MyExcetion(errid, errmsg)
		, _sql(sql)
	{}

	virtual string what() const
	{
		string msg = "SqlExcetion：";
		msg += _errmsg;
		msg += "sql 语句：";
		msg += _sql;
		return msg;
	}
protected:
	// ...
	string _sql;
};

class NetworkExcetion : MyExcetion
{
protected:
	// ...
};

void f1()
{
	// ....
	int i;
	cin >> i;
	if (i == 0)
	{
		throw CacheExcetion(1, "数据不存在");
	}
}

void f2()
{
	int i;
	cin >> i;
	if (i == 0)
	{
		throw SqlExcetion(1, "数据库查询失败", "select * from t_student");
	}
}

int main()
{
	try
	{
		f1();
		f2();
	}
	catch (const MyExcetion& e) // 只捕获基类
	{
		cout << "错误描述：" << e.what() << endl; // 多态
	}
	catch (...) // 任意类型的异常
	{
		cout << "未知异常" << endl;
	}

	return 0;
}
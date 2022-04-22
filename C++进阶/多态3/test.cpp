#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class A
//{
//public:
//	virtual void func()
//	{
//		cout << "A::func()" << endl;
//	}
//public:
//	int _a;
//};
//
//// class B : public A
//class B : virtual public A
//{
//public:
//	virtual void func()
//	{
//		cout << "B:func()" << endl;
//	}
//
//	//virtual void func1()
//	//{
//	//	cout << "B:func1()" << endl;
//	//}
//public:
//	int _b;
//};
//
//// class C : public A
//class C : virtual public A
//{
//public:
//	virtual void func()
//	{
//		cout << "C::func()" << endl;
//	}
//
//	//virtual void func1()
//	//{
//	//	cout << "C::func1()" << endl;
//	//}
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	virtual void func()
//	{
//		cout << "D::func()" << endl;
//	}
//
//	//virtual void func1()
//	//{
//	//	cout << "D::func1()" << endl;
//	//}
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A{
//public:
//	A(char *s) { cout << s << endl; }
//	~A(){}
//};
//
//class B :virtual public A
//{
//public:
//	B(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//
//class C :virtual public A
//{
//public:
//	C(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//
//class D :public B, public C
//{
//public:
//	// 初始列表执行顺序跟声明有关，继承成员声明顺序，是按继承顺序算的
//	D(char *s1, char *s2, char *s3, char *s4) 
//		:B(s1, s2)
//		, C(s1, s3)
//		, A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//
//// A：class A class B class C class D      B：class D class B class C class A
//
//// C：class D class C class B class A      D：class A class C class B class D
//
//int main() {
//	D *p = new D("class A", "class B", "class C", "class D");
//	delete p;
//
//	return 0;
//}

class A
{
public:
	A()
	{}

	virtual inline void func(int val = 1){ std::cout << "A->" << val << std::endl; }
	virtual void test(){ func(); }
};

class B : public A
{
public:
	// 严格来说，这里就不要给val缺省值了或者跟父类保持一致
	// 充分体现，"选择题险恶", 出题人是真坏
	void func(int val = 100){ std::cout << "B->" << val << std::endl; }
};

int main(int argc, char* argv[])
{
	//B* p = new B;
	//p->test();

	A aa;

	return 0;
}
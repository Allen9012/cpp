#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//
// //抽象类 -- 不能实例化出对象
// //1、可以更好的去表示现实世界中，没有实例对象对应的抽象类型  比如：植物、人、动物
// //2、体现接口继承，强制子类去重写虚函数(不重写，子类也是抽象类)  
// //要注意跟override区分，override检查子类虚函数是否完成重写。
//class Pokemon
//{
//public:
//	// 纯虚函数
//	virtual void Move1()=0;
//	virtual void Move2() = 0;
//	virtual void Move3() = 0;
//	virtual void Move4() = 0;
//protected:
//	string _Type1;
//	string _Type2;
//	string _Abilities;
//};
////妙蛙花
//class Venusaur :public Pokemon
//{
//public:
//	virtual void Move1()
//	{
//		cout << "Solar Beam" << endl;
//	}
//	virtual void Move2() 
//	{
//		cout << "Poison Powder" << endl;
//	}
//	virtual void Move3() 
//	{
//		cout << "Sleep Powder" << endl;
//	}
//	virtual void Move4() 
//	{
//		cout << "Venoshock" << endl;
//	}
//protected:
//	string _Abilities ="Overgrow";
//	string _Type1 ="Grass";
//	string _Type2="Poison";
//};
//
////喷火龙
//class Charizard :public Pokemon
//{
//public:
//	virtual void Move1()
//	{
//		cout << "Flamethrower" << endl;
//	}
//	virtual void Move2() 
//	{
//		cout << "Flare Blitz" << endl;
//	}
//	virtual void Move3() 
//	{
//		cout << "Air Slash" << endl;
//	}
//	virtual void Move4() 
//	{
//		cout << "Dragon Dance" << endl;
//	}
//protected:
//	string _Abilities = "Blaze";
//	string _Type1 = "Fire";
//	string _Type2 = "Flying";
//};
//
//int main()
//{
//	//Pokemon p;   //error
//	Venusaur venusaur;
//	Charizard charizard;
//	venusaur.Move1();
//	charizard.Move1();
//	return 0;
//}
//
//// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//	char _ch = '\0';
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base bs;
//	
//	
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//
//	int _p = 1;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//
//	int _s = 2;
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student Johnson;
//	Johnson._p = 10;
//	Func(Johnson);
//
//	return 0;
//}

// 针对上面的代码我们做出以下改造
// 1.我们增加一个派生类Derive去继承Base
// 2.Derive中重写Func1
// 3.Base再增加一个虚函数Func2和一个普通函数Func3
//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base()" << endl;
//	}
//
//	virtual void Func1()
//	{
//		cout << "virtual Base::Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "virtual Base::Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "virtual Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
////int main()
////{
////	Base b;
////	Derive d;
////
////	return 0;
////}
//
//int j = 0;
//int main()
//{
//	// 取虚表地址打印一下
//	Base b;
//	Base* p = &b;
//	printf("vftptr:%p\n", *((int*)p));
//
//	int i;
//	printf("栈上地址:%p\n", &i);
//	printf("数据段地址:%p\n", &j);
//
//	int* k = new int;
//	printf("堆地址:%p\n", k);
//	const char* cp = "hello world";
//	printf("代码段地址:%p\n", cp);
//
//	return 0;
//}

//// 单继承
//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//// 写一个程序打印一下虚表，确认虚表中调用的函数
//typedef void(*VFunc)();//定义一个函数指针
//
////void PrintVFT(VFunc ptr[])
//void PrintVFT(VFunc* ptr)   // 存函数指针的数组指针
//{
//	printf("虚表地址:%p\n", ptr);
//	for (int i = 0; ptr[i] != nullptr; ++i)
//	{
//		printf("VFT[%d]:%p->", i, ptr[i]);
//		ptr[i]();
//	}
//	printf("\n");
//}
//int main()
//{
//	Base b;
//	PrintVFT((VFunc*)(*(int*)&b));
//	Derive d;
//	PrintVFT((VFunc*)(*(int*)&d));
//	return 0;
//}
//


class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

typedef void(*VFunc)();
void PrintVFT(VFunc* ptr)   // 存函数指针的数组指针
{
	printf("虚表地址:%p\n", ptr);
	for (int i = 0; ptr[i] != nullptr; ++i)
	{
		printf("VFT[%d]:%p->", i, ptr[i]);
		ptr[i]();
	}
	printf("\n");
}

int main()
{
	Base1 b1;
	Base2 b2;

	//PrintVFT((VFunc*)(*(int*)&b1));
	//PrintVFT((VFunc*)(*(int*)&b2));
	Derive d;
	PrintVFT((VFunc*)(*(int*)&d));
	PrintVFT((VFunc*)(*(int*)((char*)&d + sizeof(Base1))));
	return 0;
}
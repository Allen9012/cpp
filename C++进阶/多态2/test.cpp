#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//
// //������ -- ����ʵ����������
// //1�����Ը��õ�ȥ��ʾ��ʵ�����У�û��ʵ�������Ӧ�ĳ�������  ���磺ֲ��ˡ�����
// //2�����ֽӿڼ̳У�ǿ������ȥ��д�麯��(����д������Ҳ�ǳ�����)  
// //Ҫע���override���֣�override��������麯���Ƿ������д��
//class Pokemon
//{
//public:
//	// ���麯��
//	virtual void Move1()=0;
//	virtual void Move2() = 0;
//	virtual void Move3() = 0;
//	virtual void Move4() = 0;
//protected:
//	string _Type1;
//	string _Type2;
//	string _Abilities;
//};
////���ܻ�
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
////�����
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
//// ���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�
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
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//
//	int _p = 1;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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

// �������Ĵ��������������¸���
// 1.��������һ��������Deriveȥ�̳�Base
// 2.Derive����дFunc1
// 3.Base������һ���麯��Func2��һ����ͨ����Func3
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
//	// ȡ����ַ��ӡһ��
//	Base b;
//	Base* p = &b;
//	printf("vftptr:%p\n", *((int*)p));
//
//	int i;
//	printf("ջ�ϵ�ַ:%p\n", &i);
//	printf("���ݶε�ַ:%p\n", &j);
//
//	int* k = new int;
//	printf("�ѵ�ַ:%p\n", k);
//	const char* cp = "hello world";
//	printf("����ε�ַ:%p\n", cp);
//
//	return 0;
//}

//// ���̳�
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
//// дһ�������ӡһ�����ȷ������е��õĺ���
//typedef void(*VFunc)();//����һ������ָ��
//
////void PrintVFT(VFunc ptr[])
//void PrintVFT(VFunc* ptr)   // �溯��ָ�������ָ��
//{
//	printf("����ַ:%p\n", ptr);
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
void PrintVFT(VFunc* ptr)   // �溯��ָ�������ָ��
{
	printf("����ַ:%p\n", ptr);
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
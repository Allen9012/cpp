#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class A
//{
//public:
//	//int _a[10000];
//	int _a;
//};
//
////class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
////class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
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
//	//cout << sizeof(d) << endl;
//
//	B b = d;
//
//	return 0;
//}


//class A
//{
//public:
//	void func()
//	{}
//protected:
//	int _a;
//};
//
//// B�̳���A�����Ը���A
//class B : public A
//{
//protected:
//	int _b;
//};
//
//// C���A��Ҳ���Ը���A
//class C
//{
//private:
//	int _c;
//	A _a;
//};
//
//int main()
//{
//
//
//	return 0;
//}

//int main()
//{
//	int i;
//	char ch;
//	cin >> i;
//	cin >> ch;
//
//	cout << i << endl;
//	cout << ch << endl;
//
//	int i = 0, j = 1;
//	double d = 1.1, e = 2.2;
//	swap(i, j);
//	swap(d, e);
//
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person
//{
//public:
//	// ������麯����д�˸�����麯��
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//class Soldier : public Person
//{
//public:
//	// ������麯����д�˸�����麯��
//	virtual void BuyTicket() { cout << "����-��Ʊ" << endl; }
//};
//
//void f(Person& p)
//{
//	// ����ͬ���͵Ķ��󣬵��õ��ǲ�ͬ�ĺ�����ʵ���˵��õĶ�����̬
//	p.BuyTicket();
//}
//
//void f(Person* p)
//{
//	// ����ͬ���͵Ķ��󣬵��õ��ǲ�ͬ�ĺ�����ʵ���˵��õĶ�����̬
//	p->BuyTicket();
//}
//
//int main()
//{
//	Person p; // ��ͨ��
//	Student st; // ѧ��
//	Soldier so; // ����
//
//	f(p);
//	f(st);
//	f(so);
//	//cout << endl;
//
//	//f(&p);
//	//f(&st);
//	//f(&so);
//
//	return 0;
//}

//class A {};
//class B : public A {};
//
//class Person {
//public:
//	virtual A* f() {
//		cout << " A* Person::f()" << endl;
//		return new A;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual B* f() {
//		cout << " B* Student::f()" << endl;
//		return new B;
//	}
//};
//
//int main()
//{
//	Person p;
//	Student s;
//
//	Person* ptr;
//	ptr = &p;
//	ptr->f();
//
//	ptr = &s;
//	ptr->f();
//
//	return 0;
//}

//class Person {
//public:
//	// ����Ѹ���������������Ϊ�麯��
//	// ����������麯��������д������麯��
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	// Student��Person���������ĺ�����������������ͬ���������ǹ����麯����д
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	// ����ͨ�����£�����������������Ƿ񹹳���д������Ҫ��ûʲôӰ��
//	//Person p;
//	//Student s;
//
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	// ��̬��Ϊ
//	delete p1; // p1->������������ + operator delete(p1);
//	delete p2; // p2->������������ + operator delete(p2);
//
//	return 0;
//}


//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person
//{
//public:
//	// ������麯����д�˸�����麯��
//	// �����麯������дvirtual��Ҳ��Ϊ�����麯�����������д
//	void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//void Func(Person& p){p.BuyTicket();}
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	return 0;
//}
//

//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};


//class Car{
//public:
//virtual void Drive(char ch){}
//};
//
//class Benz :public Car {
//public:
//virtual void Drive(int i) override { cout << "Benz-����" << endl; }
//};
//int main()
//{
//return 0;
//}
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
//// B继承了A，可以复用A
//class B : public A
//{
//protected:
//	int _b;
//};
//
//// C组合A，也可以复用A
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
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person
//{
//public:
//	// 子类的虚函数重写了父类的虚函数
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//class Soldier : public Person
//{
//public:
//	// 子类的虚函数重写了父类的虚函数
//	virtual void BuyTicket() { cout << "优先-买票" << endl; }
//};
//
//void f(Person& p)
//{
//	// 传不同类型的对象，调用的是不同的函数，实现了调用的多种形态
//	p.BuyTicket();
//}
//
//void f(Person* p)
//{
//	// 传不同类型的对象，调用的是不同的函数，实现了调用的多种形态
//	p->BuyTicket();
//}
//
//int main()
//{
//	Person p; // 普通人
//	Student st; // 学生
//	Soldier so; // 军人
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
//	// 建议把父类析构函数定义为虚函数
//	// 这样子类的虚函数方便重写父类的虚函数
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	// Student和Person析构函数的函数名，看起来不相同，但是他们构成虚函数重写
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	// 在普通场景下，父子类的析构函数是否构成重写，不重要，没什么影响
//	//Person p;
//	//Student s;
//
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	// 多态行为
//	delete p1; // p1->析构函数（） + operator delete(p1);
//	delete p2; // p2->析构函数（） + operator delete(p2);
//
//	return 0;
//}


//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person
//{
//public:
//	// 子类的虚函数重写了父类的虚函数
//	// 子类虚函数，不写virtual，也认为他是虚函数，完成了重写
//	void BuyTicket() { cout << "买票-半价" << endl; }
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
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};


//class Car{
//public:
//virtual void Drive(char ch){}
//};
//
//class Benz :public Car {
//public:
//virtual void Drive(int i) override { cout << "Benz-舒适" << endl; }
//};
//int main()
//{
//return 0;
//}
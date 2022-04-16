#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//
//private:
//	int _age = 18;  // 年龄
//};
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		// 父类的私有成员继承下来不可见的意思：
//		// 内存上，子类对象有这个成员，但是语法规定了我们不能去访问
//		//cout << _age << endl;
//	}
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	//Student s;
//	//Teacher t;
//
//	//s.Print();
//	//t.Print();
//	////s._name;
//
//	Student s;
//	//s._age;
//	s.func();
//	s.Print();
//
//
//	return 0;
//}

// 赋值兼容规则
//class Person
//{
////protected:
//public:
//	string _name; // 姓名
//	string _sex;  // 性别
//	int	_age;	 // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	s._name = "张三";
//	s._sex = "男";
//	s._age = 18;
//
//	p = s;    // 父<-子   可以的  切割/切片
//	// s = p; // 子x-父   不行的
//
//	Person* ptr = &s;
//
//	Person& ref = s;
//
//	return 0;
//}

// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	   // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//void Test()
//{
//	B b;
//	b.fun(10);
//	b.A::fun();
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//
//	Person p = s;
//
//	return 0;
//}

class Person
{
public:
	Person(const char* name)
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person() // -> 因为后面多态的一些原因，任何类析构函数名都会被统一处理成destructor()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};

class Student : public Person
{
public:
	Student(const char* name, int id)
		: Person(name)
		,_id(id)
	{
		// 调用父类构造函数初始化继承的父类部分
		// 再初始化自己的成员
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		:Person(s)  // ->s传递给Person& s 是一个切片行为
		, _id(s._id)
	{
		// 类似构造函数
		cout << "Student(const Student& s)" << endl;
	}

	// s1 = s3;
	Student& operator=(const Student& s)
	{
		// 同上
		if (this != &s)
		{
			// 小心这里是隐藏
			Person::operator=(s);
			_id = s._id;
		}

		cout << "Student& operator=(const Student& s)" << endl;


		return *this;
	}

	// -> 因为后面多态的一些原因，任何类析构函数名都会被统一处理成destructor()
	~Student() // 编译器认为子类的析构函数和父类的析构函数构成隐藏
	{
		Person::~Person(); // 所以这里想调用，需要指定父类的

		// 清理自己的
		// delete ptr;

		cout << "~Student()"<<endl;
		// 为了保证析构时，保持先子再父的后进先出的顺序析构
		// 子类析构函数完成后，会自动去调用父类的析构函数
	}

private:
	int _id;
};


int main()
{
	Student s1("张三", 1);
	//Student s2(s1);
	//Student s3("李四", 2);
	//s1 = s3;

	return 0;
}

// 设计出一个类A，让这个类不能被继承
//class A
//{
//private:
//	A()
//	{}
//};
//
//class B : public A
//{
//};
//
//int main()
//{
//	B b;
//
//	return 0;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

//class Person
//{
//public:
//	Person() { ++_count; }
//	Person(const Person& p) { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//
//void func(Student s)
//{}
//
//int main()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//
//	func(s1);
//
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//void main()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	// 虚继承可以解决数据冗余和二义性
//	Assistant a;
//	a.Student::_name = "小张";
//	a.Teacher::_name = "张老师";
//	a._name = "xxx";
//}

//class A
//{
//public:
//	int _a;
//};
//
//// class B : public A
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
//	return 0;
//}
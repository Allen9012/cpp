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
//	string _name = "peter"; // ����
//
//private:
//	int _age = 18;  // ����
//};
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		// �����˽�г�Ա�̳��������ɼ�����˼��
//		// �ڴ��ϣ���������������Ա�������﷨�涨�����ǲ���ȥ����
//		//cout << _age << endl;
//	}
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
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

// ��ֵ���ݹ���
//class Person
//{
////protected:
//public:
//	string _name; // ����
//	string _sex;  // �Ա�
//	int	_age;	 // ����
//};
//
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	s._name = "����";
//	s._sex = "��";
//	s._age = 18;
//
//	p = s;    // ��<-��   ���Ե�  �и�/��Ƭ
//	// s = p; // ��x-��   ���е�
//
//	Person* ptr = &s;
//
//	Person& ref = s;
//
//	return 0;
//}

// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; 	   // ���֤��
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ��ݺ�:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
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

	~Person() // -> ��Ϊ�����̬��һЩԭ���κ����������������ᱻͳһ�����destructor()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // ����
};

class Student : public Person
{
public:
	Student(const char* name, int id)
		: Person(name)
		,_id(id)
	{
		// ���ø��๹�캯����ʼ���̳еĸ��ಿ��
		// �ٳ�ʼ���Լ��ĳ�Ա
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		:Person(s)  // ->s���ݸ�Person& s ��һ����Ƭ��Ϊ
		, _id(s._id)
	{
		// ���ƹ��캯��
		cout << "Student(const Student& s)" << endl;
	}

	// s1 = s3;
	Student& operator=(const Student& s)
	{
		// ͬ��
		if (this != &s)
		{
			// С������������
			Person::operator=(s);
			_id = s._id;
		}

		cout << "Student& operator=(const Student& s)" << endl;


		return *this;
	}

	// -> ��Ϊ�����̬��һЩԭ���κ����������������ᱻͳһ�����destructor()
	~Student() // ��������Ϊ��������������͸��������������������
	{
		Person::~Person(); // ������������ã���Ҫָ�������

		// �����Լ���
		// delete ptr;

		cout << "~Student()"<<endl;
		// Ϊ�˱�֤����ʱ�����������ٸ��ĺ���ȳ���˳������
		// ��������������ɺ󣬻��Զ�ȥ���ø������������
	}

private:
	int _id;
};


int main()
{
	Student s1("����", 1);
	//Student s2(s1);
	//Student s3("����", 2);
	//s1 = s3;

	return 0;
}

// ��Ƴ�һ����A��������಻�ܱ��̳�
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
//	string _name; // ����
//};
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
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
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
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
//	string _name; // ����
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//void main()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	// ��̳п��Խ����������Ͷ�����
//	Assistant a;
//	a.Student::_name = "С��";
//	a.Teacher::_name = "����ʦ";
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
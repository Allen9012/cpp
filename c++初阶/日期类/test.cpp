#include "Date.h"
void Test1()
{
	Date d1(2021,5,25);
	d1 -= 120;
	d1.Print();
	d1 -= -100;//处理负数，但是又产生了正数逻辑，于是尝试复用
}
void Test2()
{
	Date d1(2021, 5, 25);
	//前置和后置++都完成了++，但是不同的地方在于返回值不同
	//运算符是一样的，所以函数名是一样的，为了区分，做了特殊处理（加参数到后置++），形成函数重载
	d1++;
	d1.Print();

	++d1;
	d1.Print();
}

void Test3()
{
	Date d1(2021, 5, 27);
	Date d2(2021, 12, 31);
	cout << d2 - d1 <<  endl;  
}

int main()
{
	Test3();
	return 0;
}
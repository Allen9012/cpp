#pragma once
#include <iostream>
using namespace std;

// 
template<class T>
T Add(const T& left, const T& right);

// 
void func(int a, int b);

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

void func(int a, int b)
{
	cout << a << endl;
	cout << b << endl;
}


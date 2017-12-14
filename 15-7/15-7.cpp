// 15-7.cpp : 定义控制台应用程序的入口点。
//处理异常的一种方式：调用abort()函数，其典型实现是向标准错误流（即cerr使用的错误刘）发送消息abnormal program termination
//（程序异常终止），然后终止程序。

#include "stdafx.h"
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*求两个数的调和平均数*/
double hmean(double a, double b);

int main()
{
	double x, y, z;
	cout << "Enter two number:";
	while (cin >> x >> y)
	{
		z = hmean(x, y);
		cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
		cout << "Enter next set of numbers <q to quit>:";
	}
	cout << "Bye\n";
	getchar();
    return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		cout << "untenable arguments to hmean()\n";
		std::abort();
	}
	return 2.0*a*b / (a + b);
}
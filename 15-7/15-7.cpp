// 15-7.cpp : �������̨Ӧ�ó������ڵ㡣
//�����쳣��һ�ַ�ʽ������abort()�����������ʵ�������׼����������cerrʹ�õĴ�������������Ϣabnormal program termination
//�������쳣��ֹ����Ȼ����ֹ����

#include "stdafx.h"
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*���������ĵ���ƽ����*/
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
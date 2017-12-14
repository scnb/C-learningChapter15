// 15-8.cpp : �������̨Ӧ�ó������ڵ㡣
//���ش����룺��ʹ��ָ����������ò�������ֵ���ظ����ó��򣬲�ʹ�ú����ķ���ֵ��ָ���ɹ�����ʧ�ܡ�

#include "stdafx.h"
#include <cfloat>//Ϊ��ʹ��DBL_MAX
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool hmean(double a, double b, double * ans);

int main()
{
	double x, y, z;
	cout << "Enter two numbers:";
	while (cin >> x >> y)
	{
		if (hmean(x, y, &z))
		{
			cout << "Harmonic mean os " << x << " and " << y << " is " << z << endl;
		}
		else
		{
			cout << "One value should not be the negative of the other - try again.\n";
		}
		cout << "Ente next set of numbers <q to quit>: ";
	}
	cout << "Bye!\n";
	getchar();
    return 0;
}

bool hmean(double a, double b, double * ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0*a*b / (a + b);
		return true;
	}
}
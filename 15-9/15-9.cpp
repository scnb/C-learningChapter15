// 15-9.cpp : �������̨Ӧ�ó������ڵ㡣
//ʹ���쳣����������������
//C++�쳣�ǶԳ������й����з������쳣�����һ����Ӧ��
//�쳣�ṩ�˽�����Ȩ�ӳ����һ�����ִ��ݵ���һ�����ֵ�;����
//���쳣�Ĵ�����3����ɲ��֣�
//�������쳣                throw�ؼ��ֱ�ʾ�����쳣����������ֵָ�����쳣��������(throw���ʵ��������ת�������������ת����һ�����)
//��ʹ�ô�����򲶻��쳣    catch�ؼ��ֱ�ʾ�����쳣������������������ָ����Ҫ��Ӧ���쳣���͡����쳣������ʱ����������������ִ�С�
//��ʹ��try��               try��ʶ�ض��Ŀ��������쳣�Ĵ���飬�����һ������catch�顣������Ҫע������Щ�����������쳣��

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double hmean(double a, double b);

int main()
{
	double x, y, z;
	cout << "Enter two numbers:";
	while (cin >> x >> y)
	{
		try                         //try��Ŀ�ʼ
		{
			z = hmean(x, y);
		}
		catch (const char * s)
		{
			cout << s << endl;
			cout << "Enter a new pair of numbers:";
			continue;
		}
		cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
		cout << "Enter next pair of numbers<q to quit>��";
	}
    return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		throw "bad hmean() arguments: a = -b not allowed";
		//ִ��throw���������ִ�з�����䣬��Ϊ��Ҳ����ֹ������ִ�У�
		//Ȼ�������ǽ�����Ȩ���ظ����ú������������ź����������к��ˣ�ֱ���ҵ�����try��ĺ�����
	}
	return 2.0*a*b / (a + b);
}

// 15-13.cpp : �������̨Ӧ�ó������ڵ㡣
//C++�쳣����ҪĿ����Ϊ����ݴ�����ṩ���Լ�֧�֣����쳣ʹ���ڳ�������а����������ܸ����ס�
//exception�ࣺexceptionͷ�ļ�������exception�࣬C++���԰������������쳣��Ļ��ࡣ
//��������һ��what()�����Ա��������������ʵ�ֶ��졣

#include "stdafx.h"
#include <iostream>
#include <new>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::bad_alloc;

struct Big
{
	double stuf[2000];
};


int main()
{
	Big * pb;
	try
	{
		cout << "Trying to get a big block of memory:\n";
		pb = new Big[100000];//1000*2000*8������һ������1000���ṹ������飬ÿһ��Ԫ��������һ������2000��doubleԪ�ص�����
		cout << "Got past the new request:\n";
	}
	catch (bad_alloc & ba)
	{
		cout << "Caught the exception!\n";
		cout << ba.what() << endl;//what()��exception���һ�������Ա������������һ���ַ��������ַ�����������ʵ�ֶ���
		getchar();
		exit(EXIT_FAILURE);
	}
	cout << "Memory successfully allocated\n";
	pb[0].stuf[0] = 4;
	cout << pb[0].stuf[0] << endl;
	delete[] pb;
	getchar();
    return 0;
}


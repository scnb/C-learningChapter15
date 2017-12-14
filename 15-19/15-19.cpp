// 15-19.cpp : �������̨Ӧ�ó������ڵ㡣
//����ת���������const_cast
/*
	const_cast���������ִ��ֻ��һ����;������ת�������ı�ֵΪconst��volatile�����﷨��dynamic_cast�������ͬ��
	const_cast<type-name>(expression)������type_name��expression�����ͱ�����ͬ��

	�ṩconst_cast�������ԭ���ǣ���ʱ�������Ҫ����һ��ֵ�����ڴ����ʱ���ǳ���������ʱ���ǿ����޸ĵġ�
								  �������԰�һ����������Ϊconst���ͣ�ֻ����Ҫ�޸�ʱ��Ҫconst_cast������
								  �������Ƚϰ�ȫ��
	ʹ��const_cast�������ע��㣺�������޸�ָ��һ��ֵ��ָ�룬�������޸�constֵ�Ľ����
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void change(const int * pt, int n);

int main()
{
	int pop1 = 38383;
	const int pop2 = 2000;
	cout << "pop1,pop2: " << pop1 << ", " << pop2 << endl;
	change(&pop1, 1);
	change(&pop2, 1);
	cout << "pop1,pop2: " << pop1 << ", " << pop2 << endl;
	getchar();
    return 0;
}

void change(const int * pt, int n)
{
	int * pc;//const_cast�����������ptָ���ɿ��޸ĵģ����Ƕ���const���͵ı�����˵���ñ�����ֵ���ܸ��ġ�
	pc = const_cast<int *>(pt);//ָ��pcɾ����const��������˿������޸�ָ���ֵ��������ָ���ֵ����constʱ�ſ��С�
	*pc += n;
}

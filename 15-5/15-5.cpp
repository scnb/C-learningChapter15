// 15-5.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "queuetp.h"
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	QueueTP<string> cs(5);//5�Ƕ������Ԫ����
	string temp;
	while (!cs.isfull())
	{
		cout << "Please enter your name. You will be served in the order of arrival.\nname:";
		getline(cin, temp);
		cs.enqueue(temp);
	}
	cout << "The queue is full. Processing begins!\n";
	while (!cs.isempty())
	{
		cs.dequeue(temp);
		cout << "Now processing " << temp << "...\n";//���ճ��ӵ�Ԫ����ʾ����
	}
	getchar();
    return 0;
}


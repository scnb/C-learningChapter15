// 15-5.cpp : 定义控制台应用程序的入口点。
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
	QueueTP<string> cs(5);//5是队列最大元素数
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
		cout << "Now processing " << temp << "...\n";//将刚出队的元素显示出来
	}
	getchar();
    return 0;
}


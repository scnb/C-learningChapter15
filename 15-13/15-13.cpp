// 15-13.cpp : 定义控制台应用程序的入口点。
//C++异常的主要目的是为设计容错程序提供语言及支持，即异常使得在程序设计中包含错误处理功能更容易。
//exception类：exception头文件定义了exception类，C++可以把它当作其他异常类的基类。
//该类中有一个what()虚拟成员函数，其特征随实现而异。

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
		pb = new Big[100000];//1000*2000*8，产生一个包含1000个结构体的数组，每一个元素里又有一个包含2000个double元素的数组
		cout << "Got past the new request:\n";
	}
	catch (bad_alloc & ba)
	{
		cout << "Caught the exception!\n";
		cout << ba.what() << endl;//what()是exception类的一个虚拟成员函数，它返回一个字符串，该字符串的特征随实现而异
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


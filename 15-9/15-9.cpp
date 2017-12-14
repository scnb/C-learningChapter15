// 15-9.cpp : 定义控制台应用程序的入口点。
//使用异常处理机制来处理错误。
//C++异常是对程序运行过程中发生的异常情况的一种响应。
//异常提供了将控制权从程序的一个部分传递到另一个部分的途径。
//对异常的处理有3个组成部分：
//①引发异常                throw关键字表示引发异常，紧随其后的值指出了异常的特征。(throw语句实际上是跳转，即命令程序跳转到另一条语句)
//②使用处理程序捕获异常    catch关键字表示捕获异常，其括号中类型声明指出了要响应的异常类型。当异常被引发时，程序跳到这里来执行。
//③使用try块               try标识特定的可能引起异常的代码块，后面跟一个或多个catch块。表明需要注意由这些代码引发的异常。

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
		try                         //try块的开始
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
		cout << "Enter next pair of numbers<q to quit>：";
	}
    return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		throw "bad hmean() arguments: a = -b not allowed";
		//执行throw语句类似于执行返回语句，因为它也将终止函数的执行，
		//然后它不是将控制权返回给调用函数，而是沿着函数调用序列后退，直到找到包含try块的函数。
	}
	return 2.0*a*b / (a + b);
}

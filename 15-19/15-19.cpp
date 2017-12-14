// 15-19.cpp : 定义控制台应用程序的入口点。
//类型转换运算符：const_cast
/*
	const_cast运算符用于执行只有一种用途的类型转换，即改变值为const或volatile，其语法与dynamic_cast运算符相同：
	const_cast<type-name>(expression)，并且type_name和expression的类型必须相同。

	提供const_cast运算符的原因是：有时候可能需要这样一个值，它在大多数时候是常量，而有时又是可以修改的。
								  这样可以把一个变量声明为const类型，只在需要修改时需要const_cast，并且
								  这样做比较安全。
	使用const_cast运算符的注意点：它可以修改指向一个值的指针，但不能修改const值的结果。
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
	int * pc;//const_cast运算符可以是pt指针变成可修改的，但是对于const类型的变量来说，该变量的值不能更改。
	pc = const_cast<int *>(pt);//指针pc删除了const特征，因此可用来修改指向的值，但仅当指向的值不是const时才可行。
	*pc += n;
}

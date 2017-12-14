// 15-12.cpp : 定义控制台应用程序的入口点。
//在本程序中，使用到了栈解退（unwinding the stack），比如在try块没有直接调用引发异常的函数，而是调用了（对引发异常的函数）进行调用的函数，
//则程序流程将从引发异常的函数跳到包含try块和处理程序的函数。
//栈解退：函数由于出现异常而终止，程序也将释放栈中的内存，但不会在释放栈的第一个返回地址后停止，而是继续释放栈，
//		  直到找到一个位于try块中的返回地址。随后，控制权将转到块尾的异常处理程序（即catch块），而不是函数调用后的第一条语句

/*return和throw的区别：
		①函数fun（）中的return语句将控制权返回给调用fun（）的函数
		②throw语句将控制权向上返回到第一个这样的函数：包含能够捕获相应异常的try-catch组合。
*/


#include "stdafx.h"
#include <iostream>
#include "exc_mean.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	double x, y, z;
	{
		demo d1("found in block in main()");
		cout << "Enter two numbers:";
		while (cin >> x >> y)
		{
			try
			{
				z = means(x, y);
				cout << "The mean of " << x << " and " << y << " is " << z << endl;
				cout << "Enter next pair: ";
			}
			catch (bad_hmean & bg)
			{
				bg.mesg();
				cout << "Try again.\n";
				continue;
			}
			catch (bad_gmean & bg)
			{
				cout << bg.mesg();
				cout << "Values used : " << bg.v1 << ", " << bg.v2 << endl;
				cout << "Sorry,you don't get to play any more.\n";
				break;
			}
		}
		d1.show();
	}
	getchar();
	getchar();
    return 0;
}


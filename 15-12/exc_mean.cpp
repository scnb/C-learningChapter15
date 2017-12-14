#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "exc_mean.h"
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


double hmean(double a, double b)
{
	if (a == -b)
	{
		throw bad_hmean(a, b);
	}
	return 2.0*a*b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
	{
		throw bad_gmean(a, b);
	}
	return sqrt(a* b);
}

double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0;
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch (bad_hmean & bg)
	{
		bg.mesg();
		cout << "Caught in means()\n";
		throw;
	}
	/*在means函数中没有为bad_gmean准备catch块，所以当引发bad_gmean异常时会结束means函数，
	  并退出到main函数中寻找bad_gmean的catch块*/
	d2.show();
	return (am + hm + gm) / 3.0;
}
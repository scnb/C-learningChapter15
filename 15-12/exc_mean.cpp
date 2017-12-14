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
	/*��means������û��Ϊbad_gmean׼��catch�飬���Ե�����bad_gmean�쳣ʱ�����means������
	  ���˳���main������Ѱ��bad_gmean��catch��*/
	d2.show();
	return (am + hm + gm) / 3.0;
}
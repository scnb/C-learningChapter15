#pragma once
#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_

#include <iostream>
#include <string>

using std::string;

using std::cin;
using std::cout;
using std::endl;

class bad_hmean
{
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0) :v1(a), v2(b) {}
	void mesg();
};

class bad_gmean
{
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
	const char * mesg();
};

class demo
{
private:
	string word;
public:
	demo(const string & str)
	{
		word = str;
		cout << "demo " << word << " created\n";
	}
	~demo()
	{
		cout << "demo " << word << " destroyed\n";
	}
	void show()const
	{
		cout << "demo " << word << " lives!\n";
	}
};

inline const char * bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0\n";
}

inline void bad_hmean::mesg()
{
	cout << "hmean(" << v1 << ", " << v2 << "):" << " invalid arguments: a = -b\n";
}


double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

#endif // !EXC_MEAN_H_


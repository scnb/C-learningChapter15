#pragma once
#ifndef SALES_H_
#define SALES_H_

#include <iostream>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Sales
{
public:
	enum { MONTHS = 12 };
	/*嵌套类声明*/
	class bad_index : public std::logic_error//从logic_error异常类公有派生而来
	{
	private:
		int bi;//bad index value
	public:
		explicit bad_index(int ix, const string & s = "Index error in Sales object\n");//bad_index的构造函数
		int bi_val()const { return bi; }
		virtual ~bad_index() throw () {}
	};
	explicit Sales(int yy = 0);
	Sales(int yy, const double * gr, int n);
	virtual ~Sales() {}
	int Year() const { return year; }
	virtual double operator[](int i)const;//返回副本
	virtual double & operator[](int i);//返回引用
private:
	double gross[MONTHS];
	int year;
};

class LabeledSales : public Sales
{
public:
	class nbad_index : public Sales::bad_index
	{
	private:
		string lbl;
	public:
		nbad_index(const string & lb, int ix, const string & s = "Index error in LabeledSales object\n");
		const string & label_val() const { return lbl; }
		virtual ~nbad_index() throw() {}
	};
	explicit LabeledSales(const string & lb = "none", int yy = 0);
	LabeledSales(const string & lb, int yy, const double * gr, int n);
	virtual ~LabeledSales() {}
	const string & Label() const { return label; }
	virtual double operator[](int i)const;
	virtual double & operator[](int i);
private:
	string label;
};

#endif // !SALES_H_

// 15-17.cpp : 定义控制台应用程序的入口点。
//RTTI：运行阶段类型识别（Runtime Type Identification），旨在为程序在运行阶段确定对象的类型提供一种标准方式。
/*C++中三个支持RTTI的元素：
						①dynamic_cast运算符——使用一个指向基类的指针来生成一个指向派生类的指针
						②typeid运算符——返回一个指出对象的类型的值（即返回一个type_info对象的引用）
										  typeid运算符的参数：1、类名	2、结果为对象的表达式
						③type_info结构——存储了有关特定类型的信息

RTTI只适用于包含虚函数的类
*/

#include "stdafx.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) : hold(h) {}
	virtual void Speak() const { cout << "I am a grand class!\n"; }
	virtual int Value() const { return hold; }
};

class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) {}
	void Speak() const { cout << "I am a superb class!\n"; }
	virtual void Say() const { cout << "I hold the superb value of " << Value() << "!\n"; }
};

class Magnificient : public Superb
{
private:
	char ch;
public:
	Magnificient(int h = 0, char c = 'A') : Superb(h), ch(c) {}
	void Speak()const { cout << "I am a Magnificient class!\n"; }
	void Say()const { cout << "I hold the character " << ch << " and the integer " << Value() << "!\n"; }
};

Grand * GetOne();

int main()
{
	std::srand(std::time(0));
	Grand * pg;
	Superb * ps;
	for (int i = 0;i < 5;i++)
	{
		pg = GetOne();
		pg->Speak();
		if (ps = dynamic_cast<Superb *> (pg))
		{
			ps->Say();
		}
	}
	getchar();
    return 0;
}


Grand * GetOne()//随机生成三种类中的一种
{
	Grand * p = new Grand;
	switch (std::rand() % 3)
	{
	case 0:p = new Grand(std::rand() % 100);break;
	case 1:p = new Superb(std::rand() % 100);break;
	case 2:p = new Magnificient(std::rand() % 100, 'A' + std::rand() % 26);break;
	}
	return p;
}

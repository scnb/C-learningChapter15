// 15-17.cpp : �������̨Ӧ�ó������ڵ㡣
//RTTI�����н׶�����ʶ��Runtime Type Identification����ּ��Ϊ���������н׶�ȷ������������ṩһ�ֱ�׼��ʽ��
/*C++������֧��RTTI��Ԫ�أ�
						��dynamic_cast���������ʹ��һ��ָ������ָ��������һ��ָ���������ָ��
						��typeid�������������һ��ָ����������͵�ֵ��������һ��type_info��������ã�
										  typeid������Ĳ�����1������	2�����Ϊ����ı��ʽ
						��type_info�ṹ�����洢���й��ض����͵���Ϣ

RTTIֻ�����ڰ����麯������
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


Grand * GetOne()//��������������е�һ��
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

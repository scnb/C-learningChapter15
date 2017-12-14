#include "stdafx.h"
#include "tv.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

bool Tv::volup()//�����ϵ�
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
	{
		return false;
	}
}

bool Tv::voldown()//�����µ�
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
	{
		return false;
	}
}

void Tv::chanup()//Ƶ���ϵ�
{
	if (channel < maxchannel)
	{
		channel++;
	}
	else
	{
		channel = 1;//����ѭ���ķ�ʽ���е�̨
	}
}

void Tv::chandown()//Ƶ���µ�
{
	if (channel > 1)
	{
		channel--;
	}
	else
	{
		channel = maxchannel;//����ѭ���ķ�ʽ���е�̨
	}
}

void Tv::settings() const//��ʾ���е�����
{
	cout << "TV is " << (state == Off ? "Off" : "On") << endl;
	if (state == On)
	{
		cout << "Volume setting = " << volume << endl;
		cout << "Channel setting = " << channel << endl;
		cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
		cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
	}
}

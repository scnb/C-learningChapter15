#include "stdafx.h"
#include "tv.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

bool Tv::volup()//音量上调
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

bool Tv::voldown()//音量下调
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

void Tv::chanup()//频道上调
{
	if (channel < maxchannel)
	{
		channel++;
	}
	else
	{
		channel = 1;//采用循环的方式进行调台
	}
}

void Tv::chandown()//频道下调
{
	if (channel > 1)
	{
		channel--;
	}
	else
	{
		channel = maxchannel;//采用循环的方式进行调台
	}
}

void Tv::settings() const//显示所有的设置
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

// 15-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "tv.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Tv s42;//初始默认为关机状态
	cout << "Initial settings for 42\"TV:\n";
	s42.settings();//显示s42的设置
	s42.onoff();//切换开关状态
	s42.chanup();
	cout << "\nAdjusted settings for 42\"TV:\n";
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote:\n";
	s42.settings();

	Tv s58(Tv::On);//显示初始化一个为打开状态的电视
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" settings:\n";
	s58.settings();
	getchar();
    return 0;
}


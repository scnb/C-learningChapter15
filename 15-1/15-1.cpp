// 15-1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "tv.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Tv s42;//��ʼĬ��Ϊ�ػ�״̬
	cout << "Initial settings for 42\"TV:\n";
	s42.settings();//��ʾs42������
	s42.onoff();//�л�����״̬
	s42.chanup();
	cout << "\nAdjusted settings for 42\"TV:\n";
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote:\n";
	s42.settings();

	Tv s58(Tv::On);//��ʾ��ʼ��һ��Ϊ��״̬�ĵ���
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" settings:\n";
	s58.settings();
	getchar();
    return 0;
}


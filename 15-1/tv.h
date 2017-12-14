#pragma once
#ifndef TV_H_
#define TV_H_

class Tv
{
public:
	friend class Remote;//友元类声明，并且Remote类型可以访问Tv的私有部分
	/*用枚举类型定义一些状态变量*/
	enum { Off, On };//开关状态
	enum { MinVal, MaxVal = 20 };//音量
	enum { Antenna, Cable };//天线调节模式或有线电视
	enum { TV, DVD };//输入选择

	Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {};
	void onoff() { state = (state == On) ? Off : On; }//判断电视的开关状态
	bool ison() const { return state == On; }//判断电视是否是打开状态
	bool volup();//音量上调
	bool voldown();//音量下调
	void chanup();//频道上调
	void chandown();//频道下调
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }//切换有线/天线模式
	void set_input() { input = (input == TV) ? DVD : TV; }//切换输入模式
	void settings() const;//显示所有的设置
private:
	int state;
	int volume;
	int maxchannel;//最大频道数
	int channel;//频道数
	int mode;//广播或有线
	int input;//输入模式
};

class Remote
{
private:
	int mode;
public:
	Remote(int m = Tv::TV) : mode(m) {}
	bool volup(Tv & t) { return t.volup(); }
	bool voldown(Tv & t) { return t.voldown(); }
	void onoff(Tv & t) { t.onoff(); }
	void chanup(Tv & t) { t.chanup(); }
	void chandown(Tv & t) { t.chandown(); }
	void set_chan(Tv & t, int c) { t.channel = c; }
	void set_mode(Tv & t) { t.set_mode(); }
	void set_input(Tv & t) { t.set_input(); }
};

#endif

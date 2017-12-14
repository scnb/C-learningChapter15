/*15-2中的.h文件与15-1中的.h文件不一样的地方是：
	①改变了Tv类和Remote类的声明顺序；
	②使Remote声明只包含方法声明，实际的定义放在类外面

	如此就导致友元的不同：在15-1版本中，所有的Remote方法都是Tv类的友元，
						  而在15-2版本中，只有一个Remote方法是Tv类的友元
麻烦1：
	原因：①在两个类中存在着循环依赖的关系：在Tv类中需要声明Remote类中的set_chan函数为友元函数
		  ②而在Remote类中的方法又需要使用Tv类的对象
	所以无论把谁放在前面声明都不太好
	避免这种循环依赖的方法是：使用前向声明（Forward Declaration），即仅仅把Class Tv这个语句放在最前面
		然后把Class Remote{……}
			  Class Tv{……}依次放在后面
	把Remote类声明放在Tv类声明前面的原因是：在编译器在Tv类的声明中看到Remote的一个放在被声明为
	友元类之前，应该先看到Remote类的声明和set_chan()方法的声明
麻烦2：	
	另外的一个麻烦是在Remote声明中包含的内联代码，例如：void onoff(Tv & t) {t.onoff();}
	由于这将调用Tv的一个方法，所以编译器此时必须已经看到了Tv类的声明，但是现在Tv类的声明在Remote类的声明之后。
	
	解决办法：使Remote声明中只包含方法声明，而将实际的定义放在Tv之后。*/

#pragma once
#ifndef TVFM_H_
#define TVFM_H_

class Tv;//前向声明

class Remote                      //在这里仅仅写出Remote类的声明，把方法的定义放在class Tv类的声明的后面
{
public:
	enum State { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
private:
	int mode;
public:
	Remote(int m = TV) :mode(m) {}
	bool volup(Tv & t);
	bool voldown(Tv & t);
	void onoff(Tv & t);
	void chanup(Tv & t);
	void chandown(Tv & t);
	void set_mode(Tv & t);
	void set_input(Tv & t);
	void set_chan(Tv & t, int c);
};

class Tv
{
public:
	friend void Remote::set_chan(Tv & t, int c);//使Remote类中的set_chan函数成为Tv类的友元函数
	enum State { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125) :state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison()const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }//切换有线/天线
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings()const;

private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
};

//Remote methods as inline functions
inline bool Remote::volup(Tv & t) { return t.volup(); }
inline bool Remote::voldown(Tv & t) { return t.voldown(); }
inline void Remote::onoff(Tv & t) { t.onoff(); }
inline void Remote::chanup(Tv & t) { t.chanup(); }
inline void Remote::chandown(Tv & t) { t.chandown(); }
inline void Remote::set_mode(Tv & t) { t.set_mode(); }
inline void Remote::set_input(Tv & t) { t.set_input(); }
inline void Remote::set_chan(Tv & t, int c) { t.channel = c; }
#endif // !TVFM_H_

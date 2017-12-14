/*15-2�е�.h�ļ���15-1�е�.h�ļ���һ���ĵط��ǣ�
	�ٸı���Tv���Remote�������˳��
	��ʹRemote����ֻ��������������ʵ�ʵĶ������������

	��˾͵�����Ԫ�Ĳ�ͬ����15-1�汾�У����е�Remote��������Tv�����Ԫ��
						  ����15-2�汾�У�ֻ��һ��Remote������Tv�����Ԫ
�鷳1��
	ԭ�򣺢����������д�����ѭ�������Ĺ�ϵ����Tv������Ҫ����Remote���е�set_chan����Ϊ��Ԫ����
		  �ڶ���Remote���еķ�������Ҫʹ��Tv��Ķ���
	�������۰�˭����ǰ����������̫��
	��������ѭ�������ķ����ǣ�ʹ��ǰ��������Forward Declaration������������Class Tv�����������ǰ��
		Ȼ���Class Remote{����}
			  Class Tv{����}���η��ں���
	��Remote����������Tv������ǰ���ԭ���ǣ��ڱ�������Tv��������п���Remote��һ�����ڱ�����Ϊ
	��Ԫ��֮ǰ��Ӧ���ȿ���Remote���������set_chan()����������
�鷳2��	
	�����һ���鷳����Remote�����а������������룬���磺void onoff(Tv & t) {t.onoff();}
	�����⽫����Tv��һ�����������Ա�������ʱ�����Ѿ�������Tv�����������������Tv���������Remote�������֮��
	
	����취��ʹRemote������ֻ������������������ʵ�ʵĶ������Tv֮��*/

#pragma once
#ifndef TVFM_H_
#define TVFM_H_

class Tv;//ǰ������

class Remote                      //���������д��Remote����������ѷ����Ķ������class Tv��������ĺ���
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
	friend void Remote::set_chan(Tv & t, int c);//ʹRemote���е�set_chan������ΪTv�����Ԫ����
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
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }//�л�����/����
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

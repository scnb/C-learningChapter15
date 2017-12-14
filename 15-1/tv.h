#pragma once
#ifndef TV_H_
#define TV_H_

class Tv
{
public:
	friend class Remote;//��Ԫ������������Remote���Ϳ��Է���Tv��˽�в���
	/*��ö�����Ͷ���һЩ״̬����*/
	enum { Off, On };//����״̬
	enum { MinVal, MaxVal = 20 };//����
	enum { Antenna, Cable };//���ߵ���ģʽ�����ߵ���
	enum { TV, DVD };//����ѡ��

	Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {};
	void onoff() { state = (state == On) ? Off : On; }//�жϵ��ӵĿ���״̬
	bool ison() const { return state == On; }//�жϵ����Ƿ��Ǵ�״̬
	bool volup();//�����ϵ�
	bool voldown();//�����µ�
	void chanup();//Ƶ���ϵ�
	void chandown();//Ƶ���µ�
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }//�л�����/����ģʽ
	void set_input() { input = (input == TV) ? DVD : TV; }//�л�����ģʽ
	void settings() const;//��ʾ���е�����
private:
	int state;
	int volume;
	int maxchannel;//���Ƶ����
	int channel;//Ƶ����
	int mode;//�㲥������
	int input;//����ģʽ
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

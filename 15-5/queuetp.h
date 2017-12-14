#pragma once
#ifndef QUEUETP_H_
#define QUEUETP_H_

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*ʹ��������ģ�壬������ʵ������ʱ��������int���滻Item���������Ķ�����Item����int�͵�*/

template <class Item>

class QueueTP
{
private:
	enum { Q_SIZE = 10 };
	/*Node��Ƕ���࣬��QueueTP��������*/
	class Node
	{
	public:
		Item item;
		Node * next;
		Node(const Item & i) :item(i), next(0) {}//Node��Ĺ��캯��
	};
	Node * front;//ͷָ��
	Node * rear;//βָ��
	int items;//������Ŀǰ��Ԫ������
	const int qsize;//�������Ԫ����
	QueueTP(const QueueTP & q) : qsize(0) {}
	QueueTP & operator=(const QueueTP & q) { return *this; }
public:
	QueueTP(int qs = Q_SIZE);//Ĭ�Ϲ��캯��
	~QueueTP();
	bool isempty()const
	{
		return items == 0;
	}
	bool isfull()const
	{
		return items == qsize;
	}
	int queuecount()const
	{
		return items;
	}
	bool enqueue(const Item & item);//�ڶ�β���Ԫ��
	bool dequeue(Item & item);//�Ӷ�ͷɾ��Ԫ��
};

//QueueTP�ķ���
template <class Item>
/*��ʾ���캯��*/
QueueTP<Item>::QueueTP(int qs) :qsize(qs)
{
	front = rear = 0;
	items = 0;
}

template <class Item>
/*��������*/
QueueTP<Item>::~QueueTP()
{
	Node * temp;
	while (front != 0)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

/*��Ӻ���*/
template <class Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
	if (isfull())
	{
		return false;
	}
	Node * add = new Node(item);
	if (add == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�\n";
		getchar();
		exit(-1);
	}
	items++;
	if (front == 0)
	{
		front = add;
	}
	else
	{
		rear->next = add;
	}
	rear = add;
	return true;
}

/*���Ӻ���*/
template <class Item>
bool QueueTP<Item>::dequeue(Item & item)
{
	if (front == 0)
	{
		return false;
	}
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
	{
		rear = 0;
	}
	return true;
}

#endif // !QUEUETP_H_

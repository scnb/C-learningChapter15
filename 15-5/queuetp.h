#pragma once
#ifndef QUEUETP_H_
#define QUEUETP_H_

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*使用了类型模板，所以在实际声明时，比如用int来替换Item，则声明的对象中Item都是int型的*/

template <class Item>

class QueueTP
{
private:
	enum { Q_SIZE = 10 };
	/*Node是嵌套类，在QueueTP类中声明*/
	class Node
	{
	public:
		Item item;
		Node * next;
		Node(const Item & i) :item(i), next(0) {}//Node类的构造函数
	};
	Node * front;//头指针
	Node * rear;//尾指针
	int items;//队列中目前的元素数量
	const int qsize;//队列最大元素数
	QueueTP(const QueueTP & q) : qsize(0) {}
	QueueTP & operator=(const QueueTP & q) { return *this; }
public:
	QueueTP(int qs = Q_SIZE);//默认构造函数
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
	bool enqueue(const Item & item);//在队尾添加元素
	bool dequeue(Item & item);//从队头删除元素
};

//QueueTP的方法
template <class Item>
/*显示构造函数*/
QueueTP<Item>::QueueTP(int qs) :qsize(qs)
{
	front = rear = 0;
	items = 0;
}

template <class Item>
/*析构函数*/
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

/*入队函数*/
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
		cout << "内存分配失败！\n";
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

/*出队函数*/
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

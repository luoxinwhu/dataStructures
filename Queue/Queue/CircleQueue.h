#pragma once

#ifndef CIRCLEQUEUE_H
#define CIRCLEQUEUE_H

#include <iostream>
using namespace std;

template <typename T>
class CircleQueue
{
public:
	CircleQueue(int queueSize);
	~CircleQueue();					//销毁队列
	void clearQueue();				//清空队列
	bool QueueEmpty() const;
	bool QueueFull() const;
	int  QueueLength() const;
	bool EnterQueue(T elem);
	bool LeaveQueue(T &elem);
	void QueueTraverse();

private:
	T *m_pQueue;	//队列数组指针
	int m_Qsize;
	int m_Qlength;	
	int m_Qhead;
	int m_Qtail;
};


template <typename T>
CircleQueue<T>::CircleQueue(int queueSize)
{
	this->m_pQueue = new T[queueSize];
	this->m_Qsize = queueSize;
	clearQueue();
}

template <typename T>
CircleQueue<T>::~CircleQueue()
{
	delete[]m_pQueue;
	m_pQueue = NULL;
}

template <typename T>
void CircleQueue<T>::clearQueue()
{
	m_Qlength = 0;
	m_Qhead = 0;
	m_Qtail = 0;
}

template <typename T>
bool CircleQueue<T>::QueueEmpty() const
{
	return m_Qlength == 0 ? true : false;
}

template <typename T>
bool CircleQueue<T>::QueueFull() const
{
	return m_Qlength == m_Qsize ? true : false;
}

template <typename T>
int  CircleQueue<T>::QueueLength() const
{
	return m_Qlength;
}

template <typename T>
bool CircleQueue<T>::EnterQueue(T elem)
{
	if (QueueFull())
	{
		cout << "error：队列已满！" << endl;
		return false;
	}
	else
	{
		cout << "入队列..." << endl;
		m_pQueue[m_Qtail] = elem;
		m_Qtail++;	//队尾指针指向下一次入队的位置
		m_Qtail %= m_Qsize; //当达到最大容量后重新从0开始
		m_Qlength++;
		return true;
	}
}

template <typename T>
bool CircleQueue<T>::LeaveQueue(T &elem)
{
	if (QueueEmpty())
	{
		cout << "error：队列已空！" << endl;
		return false;
	}
	else
	{
		cout << "出队列..." << endl;
		elem = m_pQueue[m_Qhead];
		m_Qhead++; //队头指针指向下一次出队的位置
		m_Qhead %= m_Qsize;
		m_Qlength--;
		return true;
	}
}

template <typename T>
void CircleQueue<T>::QueueTraverse()
{
	for (int i = m_Qhead; i < m_Qlength + m_Qhead; i++)
	{
		/*cout << m_pQueue[i%m_Qsize] << ' ';*/
		m_pQueue[i%m_Qsize].printInfo();
	}
	cout << endl;
}

#endif // !CIRCLEQUEUE_H
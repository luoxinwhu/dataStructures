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
	~CircleQueue();					//���ٶ���
	void clearQueue();				//��ն���
	bool QueueEmpty() const;
	bool QueueFull() const;
	int  QueueLength() const;
	bool EnterQueue(T elem);
	bool LeaveQueue(T &elem);
	void QueueTraverse();

private:
	T *m_pQueue;	//��������ָ��
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
		cout << "error������������" << endl;
		return false;
	}
	else
	{
		cout << "�����..." << endl;
		m_pQueue[m_Qtail] = elem;
		m_Qtail++;	//��βָ��ָ����һ����ӵ�λ��
		m_Qtail %= m_Qsize; //���ﵽ������������´�0��ʼ
		m_Qlength++;
		return true;
	}
}

template <typename T>
bool CircleQueue<T>::LeaveQueue(T &elem)
{
	if (QueueEmpty())
	{
		cout << "error�������ѿգ�" << endl;
		return false;
	}
	else
	{
		cout << "������..." << endl;
		elem = m_pQueue[m_Qhead];
		m_Qhead++; //��ͷָ��ָ����һ�γ��ӵ�λ��
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
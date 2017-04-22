#pragma once

#ifndef MAXPQ_H
#define MAXPQ_H


#include <iostream>
using namespace std;

template <typename T>
class MaxPQ
{
public:
	MaxPQ(int maxN, T *a);

	void InsertPQ(T elem);	//�����ȶ��в���һ��Ԫ��
	T delMaxElem();			//ɾ�����������Ԫ��
	void MaxPQtraverse();
	void heap_Sort();

private:
	void swim(T *a, int k);	//�ϸ�
	void sink(T *a, int k);	//�³�
	int N;	//�ܽڵ���
	T *pq;	//���ڶѵ���ȫ������
};


template <typename T>
MaxPQ<T>::MaxPQ(int maxN, T *a)
{
	pq = new T[maxN + 1];
	N = 0 ;
	for (int i = 0; i < maxN; i++)
	{
		pq[++N] = a[i];
		/*swim(pq, N);*/
	}
}



template <typename T>
void MaxPQ<T>::InsertPQ(T elem)
{
	pq[++N] = elem;
	swim(pq, N);
}

template <typename T>
T MaxPQ<T>::delMaxElem()
{
	T maxElem = pq[1];		//ȡ���Դ�Ԫ��
	swap(pq[1], pq[N--]);	//���һ��Ԫ�������Ԫ�ؽ���λ��
	pq[N + 1] = null;		//ɾ�����Ԫ��
	sink(pq, 1);			//�³��ղŷŵ����˵�Ԫ��
	return maxElem;
}

template <typename T>
void MaxPQ<T>::MaxPQtraverse()
{
	int i = 1;
	while (i <= N)
	{
		cout << pq[i] << "(" << i << ")" << ' ';
		i++;
	}
	cout << endl;
}

template <typename T>
void MaxPQ<T>::swim(T *a, int k)
{ //ֻ��λ�á�k���ϵĽ��������ĸ��ڵ㡾K/2��ʱ�������״̬������
	while (k > 1 && a[k] > a[k / 2])
	{
		swap(a[k / 2], a[k]);
		k = k / 2;
	}
}

template <typename T>
void MaxPQ<T>::sink(T *a, int k)
{ //ֻ��λ�á�k���ϵĽ��С�������ӽڵ㡾2k����2k+1��ʱ�������״̬������
	while (2 * k <= N)
	{
		int j = 2 * k;
		if (j < N && a[j] < a[j + 1]) j++;
		if (!(a[k] < a[j])) break;
		swap(a[k], a[j]);
		k = j;
	}
}


template <typename T>
void MaxPQ<T>::heap_Sort()
{
	int k;
	for (k = N / 2; k >= 1; k--)
	{
		sink(pq, k);
	}
	
	int j = N;
	while (j > 1)
	{
		swap(pq[1],pq[j--]);
		sink(pq, 1);
	}
}


#endif // !MAXPQ_H
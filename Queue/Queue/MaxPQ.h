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

	void InsertPQ(T elem);	//向优先队列插入一个元素
	T delMaxElem();			//删除并返回最大元素
	void MaxPQtraverse();
	void heap_Sort();

private:
	void swim(T *a, int k);	//上浮
	void sink(T *a, int k);	//下沉
	int N;	//总节点数
	T *pq;	//基于堆的完全二叉树
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
	T maxElem = pq[1];		//取出对大元素
	swap(pq[1], pq[N--]);	//最后一个元素与最大元素交换位置
	pq[N + 1] = null;		//删除最大元素
	sink(pq, 1);			//下沉刚才放到顶端的元素
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
{ //只有位置【k】上的结点大于它的父节点【K/2】时，有序堆状态被打破
	while (k > 1 && a[k] > a[k / 2])
	{
		swap(a[k / 2], a[k]);
		k = k / 2;
	}
}

template <typename T>
void MaxPQ<T>::sink(T *a, int k)
{ //只有位置【k】上的结点小于它的子节点【2k】或【2k+1】时，有序堆状态被打破
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
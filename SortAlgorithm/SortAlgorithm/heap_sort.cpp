#pragma once
#include <iostream>
#include <vector>
using namespace std;


void heap_print(char a[], int N);
void MaxHeapFixDown(char a[], int i, int n);
void HeapSort(char a[], int n);


int main(void)
{
	int len = 0;
	char x;
	char *str2 = new char[100];
		
	cin >> x;
	while (x != '#')
	{
		str2[len++] = x;
		cin >> x;
	}
	
	HeapSort(str2, len);
	heap_print(str2, len);
	return 0;
}


void heap_print(char a[], int N)
{
	int i = 0;
	while (i < N)
	{
		cout << a[i] << "(" << i << ")" << ' ';
		i++;
	}
	cout << endl;
}

//堆有序化--下沉
void MaxHeapFixDown(char a[], int i, int size) 
{
	int j = 2 * i + 1;	//指向左孩子，“+1”是因为堆的第一个元素从下标1开始存储
	int temp = a[i];
	while (j<size)
	{
		if (j + 1<size && a[j]<a[j + 1])
			++j;
		if (temp>a[j])	//找到安置点
			break;
		else {
			a[i] = a[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	a[i] = temp;
}

//堆排序
void HeapSort(char a[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)	//构造最大堆
		MaxHeapFixDown(a, i, size);
	for (int i = size - 1; i >= 1; i--)		//调整堆
	{
		swap(a[i], a[0]);					//传入数组从0开始存储元素
		MaxHeapFixDown(a, 0, i);
	}
}
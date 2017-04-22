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

//������--�³�
void MaxHeapFixDown(char a[], int i, int size) 
{
	int j = 2 * i + 1;	//ָ�����ӣ���+1������Ϊ�ѵĵ�һ��Ԫ�ش��±�1��ʼ�洢
	int temp = a[i];
	while (j<size)
	{
		if (j + 1<size && a[j]<a[j + 1])
			++j;
		if (temp>a[j])	//�ҵ����õ�
			break;
		else {
			a[i] = a[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	a[i] = temp;
}

//������
void HeapSort(char a[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)	//��������
		MaxHeapFixDown(a, i, size);
	for (int i = size - 1; i >= 1; i--)		//������
	{
		swap(a[i], a[0]);					//���������0��ʼ�洢Ԫ��
		MaxHeapFixDown(a, 0, i);
	}
}
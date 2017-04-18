#pragma once
/*ѡ������*/



#ifndef SELECTION_H
#define SELECTION_H


template <typename T>
class select_sort
{
public:
	void sort(T &a);	//����������

	void show(const T a);					//��ӡa[]
	bool isSorted(const T a);				//�ж�a[]�Ƿ��Ѿ�����������
	void main(T &a);
};


template <typename T>
void select_sort<T>::sort(T &a)
{
	int len = a.size();
	for (int i = 0; i < len; i++)
	{//��a[i]��a[i+1..N]����С��Ԫ�ؽ���

		int min = i;
		for (int j = i + 1; j < len; j++)
		{//�ҵ���СԪ��
			if (a[j] < a[min]) 
				min = j;
		}
		swap(a[min],a[i]);
	}
}

template <typename T>
void select_sort<T>::show(const T a)
{
	int len = a.size();
	cout << "after sorting: ";
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
template <typename T>
bool select_sort<T>::isSorted(const T a)
{
	int len = a.size();
	for (int i = 1; i < len; i++)
	{
		if (a[i]< a[i - 1])
		{
			return false;
		}
		return true;
	}
}
template <typename T>
void select_sort<T>::main(T &a)
{
	sort(a);
	if (isSorted(a))
	{
		show(a);
	}
}

#endif // !SELECTION_H


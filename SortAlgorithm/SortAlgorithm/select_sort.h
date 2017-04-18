#pragma once
/*选择排序*/



#ifndef SELECTION_H
#define SELECTION_H


template <typename T>
class select_sort
{
public:
	void sort(T &a);	//按升序排序

	void show(const T a);					//打印a[]
	bool isSorted(const T a);				//判断a[]是否已经按升序排列
	void main(T &a);
};


template <typename T>
void select_sort<T>::sort(T &a)
{
	int len = a.size();
	for (int i = 0; i < len; i++)
	{//将a[i]与a[i+1..N]中最小的元素交换

		int min = i;
		for (int j = i + 1; j < len; j++)
		{//找到最小元素
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


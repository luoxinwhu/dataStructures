#pragma once
/*插入排序*/

#ifndef INSERTION_H
#define INSERTION_H


template <typename T>
class insert_sort
{
public:
	void sort(T &a);	//按升序排序
	void show(const T a);					//打印a[]
	bool isSorted(const T a);				//判断a[]是否已经按升序排列
	void main(T &args);
};

template <typename T>
void insert_sort<T>::sort(T &a)
{
	int len = a.size();
	for (int i = 1; i < len; i++)
	{//将a[i]插入到a[i-1] 、a[i-2]...中

		for (int j = i; j >=1 && (a[j]< a[j - 1]); j--)
		{//内层循环将a[j]与前面的所有元素进行比较，若比前面元素小则进行交换
			swap(a[j], a[j - 1]);
		}
	}
}
template <typename T>
void insert_sort<T>::show(const T a)
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
bool insert_sort<T>::isSorted(const T a)
{
	int len = a.size();
	for (int i = 1; i < len; i++)
	{
		if (a[i]<a[i - 1])
		{
			return false;
		}
		return true;
	}
}
template <typename T>
void insert_sort<T>::main(T &args)
{
	sort(args);
	if (isSorted(args))
	{
		show(args);
	}
}
#endif // !INSERTION_H



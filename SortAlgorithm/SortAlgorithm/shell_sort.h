#pragma once
/*希尔排序*/

#ifndef SHELL_H
#define SHELL_H



template <typename T>
class shell_sort
{
public:
	void sort(T &a);

	void show(const T a);					//打印a[]
	bool isSorted(const T a);				//判断a[]是否已经按升序排列
	void main(T &a);
};

template <typename T>
void shell_sort<T>::sort(T &a)
{
	int N = a.size();
	int h = 1;
	while (h < N / 3)
	{//设置h的增量
		h = h * 3 + 1;
	}
	while (h >= 1)
	{//将数组变为h有序

		for (int i = h; i < N; i++)
		{//将a[i]插入到a[i-h],a[i-h*2], a[i-h*3]...之中

			for (int j = i; j >= h && (a[j]< a[j - 1]); j--)
			{
				swap(a[j], a[j - h]);
			}
		}
		h = h / 3;
	}
}

template <typename T>
void shell_sort<T>::show(const T a)
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
bool shell_sort<T>::isSorted(const T a)
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
void shell_sort<T>::main(T &a)
{
	sort(a);
	if (isSorted(a))
	{
		show(a);
	}
}
#endif // !SHELL_H

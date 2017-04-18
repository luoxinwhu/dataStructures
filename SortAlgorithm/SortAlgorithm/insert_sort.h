#pragma once
/*��������*/

#ifndef INSERTION_H
#define INSERTION_H


template <typename T>
class insert_sort
{
public:
	void sort(T &a);	//����������
	void show(const T a);					//��ӡa[]
	bool isSorted(const T a);				//�ж�a[]�Ƿ��Ѿ�����������
	void main(T &args);
};

template <typename T>
void insert_sort<T>::sort(T &a)
{
	int len = a.size();
	for (int i = 1; i < len; i++)
	{//��a[i]���뵽a[i-1] ��a[i-2]...��

		for (int j = i; j >=1 && (a[j]< a[j - 1]); j--)
		{//�ڲ�ѭ����a[j]��ǰ�������Ԫ�ؽ��бȽϣ�����ǰ��Ԫ��С����н���
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



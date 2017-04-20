#pragma once
/*��������*/

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

template <typename T>
class quick_sort
{
public:
	void sort(T &a, int low, int high);
	int partition(T &a, int low, int high);
	void quick3way(T &a, int low, int high);


	void show(const T a);					//��ӡa[]
	bool isSorted(const T a);				//�ж�a[]�Ƿ��Ѿ�����������
	void main(T &a, bool typechoice);
};

template <typename T>
void quick_sort<T>::sort(T &a, int low, int high)
{
	if (high <= low)
		return;
	int i = partition(a, low, high);
	sort(a, low, i-1);
	sort(a, i + 1, high);
}

template <typename T>
int quick_sort<T>::partition(T &a, int low, int high)
{//�������з�Ϊa[low..i-1],a[i],a[i+1..high]

	int i=low, j = high+1;	//����ɨ��ָ��
	char v = a[low];		//�з�Ԫ��

	while (true)
	{//ɨ�����ң����ɨ���Ƿ����������Ԫ��
		while (a[++i] < v)	//������ҵ���һ�����ڻ�׼ֵ��Ԫ��
		{
			if (i == high)	//��ָֹ��Խ��
				break;
		}
		while (v < a[--j])	//���Ҳ��ҵ���һ��С�ڻ�׼ֵ��Ԫ��
		{
			if (j == low)
				break;
		}
		if (i >= j)	
			break;
		swap(a[i], a[j]);	//�����ҵ�������Ԫ�أ�ʹ�ñȻ�׼ֵС��Ԫ�ط�������࣬������ķ����Ҳ�
	}
	swap(a[low],a[j]);		//��v=a[j]������ȷλ��
	return j;				//a[low...j-1],a[j],a[j+1...high]���
}

template <typename T>
void quick_sort<T>::quick3way(T &a, int low, int high)
{/*���� 
	<v a[low..lt-1]  
	=v a[lt...gt]
	>v a[gt+1..high]
  */
	if (low >= high) return;
	
	int lt = low, i = low + 1, gt = high;
	char v = a[low];

	while (i <= gt)
	{
		if (a[i] < v)
			swap(a[lt++], a[i]);
		else if (a[i] > v)
			swap(a[gt--], a[i]);
		else
			i++;
	}
	quick3way(a,low,lt-1);
	quick3way(a, gt + 1, high);
}

template <typename T>
void quick_sort<T>::show(const T a)
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
bool quick_sort<T>::isSorted(const T a)
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
void quick_sort<T>::main(T &a, bool typechoice)
{
	if (isSorted(a)) 
		show(a);
	if(typechoice==0)
		sort(a,0,(int)a.size()-1);
	if (typechoice == 1)
		quick3way(a,0,(int)a.size()-1);
}
#endif // !QUICK_SORT_H

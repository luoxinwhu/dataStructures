#pragma once
/*快速排序*/

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

template <typename T>
class quick_sort
{
public:
	void sort(T &a, int low, int high);
	int partition(T &a, int low, int high);
	void quick3way(T &a, int low, int high);


	void show(const T a);					//打印a[]
	bool isSorted(const T a);				//判断a[]是否已经按升序排列
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
{//将数组切分为a[low..i-1],a[i],a[i+1..high]

	int i=low, j = high+1;	//左右扫描指针
	char v = a[low];		//切分元素

	while (true)
	{//扫描左右，检查扫描是否结束并交换元素
		while (a[++i] < v)	//从左侧找到第一个大于基准值的元素
		{
			if (i == high)	//防止指针越界
				break;
		}
		while (v < a[--j])	//从右侧找到第一个小于基准值的元素
		{
			if (j == low)
				break;
		}
		if (i >= j)	
			break;
		swap(a[i], a[j]);	//交换找到的两个元素，使得比基准值小的元素放在它左侧，比他大的放在右侧
	}
	swap(a[low],a[j]);		//将v=a[j]放入正确位置
	return j;				//a[low...j-1],a[j],a[j+1...high]完成
}

template <typename T>
void quick_sort<T>::quick3way(T &a, int low, int high)
{/*划分 
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

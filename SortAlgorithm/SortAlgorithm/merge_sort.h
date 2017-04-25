
/*�鲢����*/

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

template <typename T>
class merge_sort
{
public:
	void merge(T &a, int low, int mid, int high);
	void sort_up_to_down(T &a, int low, int high);
	void sort_down_to_up(T &a);
	void show(const T a);					//��ӡa[]
	bool isSorted(const T a);				//�ж�a[]�Ƿ��Ѿ�����������
	void main(T &a, bool typechoice);
};

template <typename T>
void merge_sort<T>::sort_up_to_down(T &a, int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int mid = (low + high) / 2;
	sort_up_to_down(a, low, mid);
	sort_up_to_down(a, mid + 1, high);
	merge(a, low, mid, high);
}

template <typename T>
void merge_sort<T>::sort_down_to_up(T &a)
{
	int N = a.size();
	int high;

	for (int subSize = 1; subSize < N; subSize = 2*subSize) //subSize�������С
	{
		for (int subIndex = 0; subIndex < N - subSize; subIndex = subIndex + 2 * subSize) //subIndex����������
		{
			if ((subIndex + 2 * subSize - 1) < (N - 1))
				high = subIndex + 2 * subSize - 1;
			else
				high = N - 1;
			merge(a, subIndex, subIndex + subSize - 1, high);
		}
	}
}

template <typename T>
void merge_sort<T>::merge(T &a, int low, int mid, int high)
{
	int i, j;
	static T aux;

	/*for (i = mid+1; i > low; i--) aux[i-1] = a[i-1];
	for (j = mid; j < high; j++) aux[high + mid - j] = a[j+1];
	for (int k = low; k <= high; k++)
	{
		if (aux[j] < aux[i])
		{
			a[k] = aux[j--];
		}
		else
		{
			a[k] = aux[i++];
		}
	}*/

	//˼·����
	i = low;
	j = mid + 1;
	for (int k = low; k <= high; k++) aux[k] = a[k];	//����a[]����������aux[]��
	for (int k = low; k <= high; k++)
	{
		if (i > mid)				a[k] = aux[j++];	//����þ���ȡ�Ҳ�Ԫ��
		else if (j > high)			a[k] = aux[i++];	//�Ҳ��þ���ȡ���Ԫ��
		else if (aux[j] < aux[i])	a[k] = aux[j++];	//�Ҳ�ĵ�ǰԪ��<��൱ǰԪ�أ�ȡ�Ҳ൱ǰԪ��
		else						a[k] = aux[i++];	//���ĵ�ǰԪ��<�Ҳ൱ǰԪ�أ�ȡ��൱ǰԪ��
	}
}

template <typename T>
void merge_sort<T>::show(const T a)
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
bool merge_sort<T>::isSorted(const T a)
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
void merge_sort<T>::main(T &a,bool typechoice)
{	// typechoise=1, choose up_to_down sort
	// typechoise=0, choose down_to_up sort
	
	if (isSorted(a))
	{
		show(a);
		return;
	}
	else
	{
		if (typechoice == 1)
			sort_up_to_down(a, 0, a.size() - 1);
		else
			sort_down_to_up(a);
	}	
}

#endif // !MERGE_SORT_H

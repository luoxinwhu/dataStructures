#pragma once
/*��������Ķ��ֲ���*/

#include <queue>
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class BinarySearchST
{
public:
	BinarySearchST(int capacity);
	int rank(Key key);					//����<=key�ļ�������
	Value getVal(Key key);
	void putVal(Key key, Value val);
	void deleteKey(Key key);
	queue<Key> getKeys(Key low, Key high);	//��ȡ[low...high]֮������м���������
	void BinarySearch_print();
private:
	Key *keys;
	Value *vals;
	int N;			//�����ǰ����

};

template <typename Key, typename Value>
BinarySearchST<Key, Value>::BinarySearchST(int capacity)
{
	keys = new Key[capacity];
	vals = new Value[capacity];
	N = 0;
}

template <typename Key, typename Value>
int BinarySearchST<Key, Value>::rank(Key key)
{	//������д��ڸü������ظü���λ�ã�����С�����ļ���������
	//��������ڣ����Ƿ��ر���С�ڸü��ļ�����
	//(���õݹ�˼��)

	int low = 0, high = N - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (key < keys[mid])
			high = mid - 1;
		else if (key > keys[mid])
			low = mid + 1;
		else
			return mid;
	}
	return low;
}

template <typename Key, typename Value>
Value BinarySearchST<Key, Value>::getVal(Key key)
{
	if (N == 0)
	{
		cout << "�ձ�" << endl;
		return NULL;
	}
		
	int i = rank(key);
	if (i < N && keys[i] == key)
		return vals[i];
	else
	{
		cout << "û�з���Ҫ��ļ�" << endl;
		return NULL;
	}
			
}

template <typename Key, typename Value>
void BinarySearchST<Key, Value>::putVal(Key key, Value val)
{
	int i = rank(key);
	if (i < N && keys[i] == key)	//�ҵ���Ӧ�ļ�����������
		vals[i] = val;
	else							//δ�ҵ�������Ӽ�
	{								
		for (int j = N; j > i; --j) //�ڳ�λ��
		{
			keys[j] = keys[j - 1];
			vals[j] = vals[j - 1];
		}
		keys[i] = key;
		vals[i] = val;
		N++;
	}
}

template <typename Key, typename Value>
void BinarySearchST<Key, Value>::deleteKey(Key key)
{
	int i = rank(key);
	if (i < N && keys[i] == key)
	{
		for (int j = i; j < N; j++)
		{
			keys[j] = keys[j + 1];
			vals[j] = vals[j + 1];
		}
		N--;
	}
	else
	{
		cout << "δ�ҵ�ƥ��ļ���ɾ��ʧ�ܣ�" << endl;
		return;
	}
}

template <typename Key, typename Value>
queue<Key> BinarySearchST<Key, Value>::getKeys(Key key1, Key key2)
{
	queue<Key> q1;

	int low = rank(key1);
	int high = rank(key2);
	
	for (int i = low; i < high; i++)
	{
		q1.push(keys[i]);
	}
	if (keys[high] == key2)
		q1.push(keys[high]);
	return q1;
}

template <typename Key, typename Value>
void BinarySearchST<Key, Value>::BinarySearch_print()
{
	if (N > 0)
	{
		for (int i = 0; i < N; i++)
		{
			cout << "key: " << keys[i] << " - value: " << vals[i] << endl;
		}
	}
	else
		cout << "����Ϊ�գ�" << endl;
}
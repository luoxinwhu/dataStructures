#pragma once
/*有序数组的二分查找*/

#include <queue>
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class BinarySearchST
{
public:
	BinarySearchST(int capacity);
	int rank(Key key);					//返回<=key的键的数量
	Value getVal(Key key);
	void putVal(Key key, Value val);
	void deleteKey(Key key);
	queue<Key> getKeys(Key low, Key high);	//获取[low...high]之间的所有键，已排序
	void BinarySearch_print();
private:
	Key *keys;
	Value *vals;
	int N;			//有序表当前长度

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
{	//如果表中存在该键，返回该键的位置（表中小于它的键的数量）
	//如果不存在，还是返回表中小于该键的键数量
	//(采用递归思想)

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
		cout << "空表" << endl;
		return NULL;
	}
		
	int i = rank(key);
	if (i < N && keys[i] == key)
		return vals[i];
	else
	{
		cout << "没有符合要求的键" << endl;
		return NULL;
	}
			
}

template <typename Key, typename Value>
void BinarySearchST<Key, Value>::putVal(Key key, Value val)
{
	int i = rank(key);
	if (i < N && keys[i] == key)	//找到对应的键，更新数据
		vals[i] = val;
	else							//未找到，则添加键
	{								
		for (int j = N; j > i; --j) //腾出位置
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
		cout << "未找到匹配的键，删除失败！" << endl;
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
		cout << "链表为空！" << endl;
}
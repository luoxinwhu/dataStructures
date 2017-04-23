#pragma once
/*无序链表的顺序查找*/

#ifndef SEQUENTIAL_SEARCH_ST_H
#define SEQUENTIAL_SEARCH_ST_H

#include "Node.h"
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class SequentialSearchST
{
public:
	SequentialSearchST() { this->first = NULL; }
	Value getVal(Key key);				//查找给定的键，返回相关联的值
	void putVal(Key key, Value val);	//查找给定的键，找到则更新其值，否则在表头插入新建的结点
	void SeqSearch_print();

private:
	Node<Key, Value> *first;
};


template <typename Key, typename Value>
Value SequentialSearchST<Key,Value>::getVal(Key key)
{
	Node<Key, Value> *tmp = first;
	while (tmp != NULL)
	{
		if (key == tmp->key) //找到
			return tmp->val;	
		tmp = tmp->next;
	}
	cout << "no found!" << endl;
	return NULL;			//未找到
}

template <typename Key, typename Value>
void SequentialSearchST<Key, Value>::putVal(Key key, Value val)
{
	Node<Key, Value> *tmp = first;
	while (tmp != NULL)
	{
		if (key == tmp->key)	//找到
		{
			tmp->val = val;
			return;
		}	
		tmp = tmp->next;
	}
	first = new Node<Key, Value>(key, val, first);	//未找到，新建结点
}

template <typename Key, typename Value>
void SequentialSearchST<Key, Value>::SeqSearch_print()
{

	Node<Key, Value> *tmp = first;
	while (tmp != NULL)
	{
		cout << "key: " << tmp->key << " - value: " << tmp->val << endl;
		tmp = tmp->next;
	}
}
#endif // !SEQUENTIAL_SEARCH_ST_H
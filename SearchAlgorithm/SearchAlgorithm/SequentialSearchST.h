#pragma once
/*���������˳�����*/

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
	Value getVal(Key key);				//���Ҹ����ļ��������������ֵ
	void putVal(Key key, Value val);	//���Ҹ����ļ����ҵ��������ֵ�������ڱ�ͷ�����½��Ľ��
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
		if (key == tmp->key) //�ҵ�
			return tmp->val;	
		tmp = tmp->next;
	}
	cout << "no found!" << endl;
	return NULL;			//δ�ҵ�
}

template <typename Key, typename Value>
void SequentialSearchST<Key, Value>::putVal(Key key, Value val)
{
	Node<Key, Value> *tmp = first;
	while (tmp != NULL)
	{
		if (key == tmp->key)	//�ҵ�
		{
			tmp->val = val;
			return;
		}	
		tmp = tmp->next;
	}
	first = new Node<Key, Value>(key, val, first);	//δ�ҵ����½����
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
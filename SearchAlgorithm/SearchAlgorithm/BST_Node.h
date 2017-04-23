#pragma once
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class Node
{
public:
	Node(Key key, Value val, int num)
	{
		this->key = key;
		this->val = val;
		this->N = num;
		left = NULL;
		right = NULL;
	}

	int N;	//�Ըýڵ�Ϊ���������еĽ������
	Key key;
	Value val;
	Node *left, *right;
};

/*���������*/
#pragma once
#ifndef BST_H
#define BST_H

#include "BST_Node.h"
#include <iostream>
#include <queue>
using namespace std;

template <typename Key, typename Value>
class BST
{
public:
	
	int getSize() { 
		return getSize(root);
	}
	int getSize(Node<Key, Value> *x)
	{//������xΪ���ڵ�����Ĵ�С
		if (x != NULL)
			return x->N;
		else
			return 0;
	}		
	Key floor(Key key);							//���Ҳ�����С�ڻ����key������
	Key select(int k);							//��ȡ����Ϊk�ļ�
	int rank(Key key);							//��ȡ��������
	Key getMin();								//��ȡ��С��
	Key getMax();
	queue<Key> getKeys(Key low, Key high);		//��ȡָ����Χ�ļ�
	Value getVal(Key key);						//��ȡָ������ֵ
	void put(Key key, Value val);				//�����
	void vinTrav();								//�������
	void deleteMinKey();						//ɾ����С��ֵ��
	void deleteKey(Key key);					//ɾ��ָ���ļ�

private:
	Node<Key, Value> *root;
	
	Node<Key, Value>* floor(Node<Key, Value> *x, Key key);
	Node<Key, Value>* select(Node<Key, Value> *x, int k);
	int rank(Node<Key, Value> *x, Key key);
	Node<Key, Value>* getMin(Node<Key, Value> *x);
	Node<Key, Value>* getMax(Node<Key, Value> *x);
	void getKeys(Node<Key, Value> *x, Key low, Key high, queue<Key> &q);
	Value getVal(Node<Key, Value> *x, Key key);
	Node<Key, Value>* put(Node<Key, Value> *x, Key key, Value val);
	void vinTrav(Node<Key, Value> *root);
	Node<Key, Value>* deleteMinKey(Node<Key, Value>* x);
	Node<Key, Value>* deleteKey(Node<Key, Value>* x, Key key);
};


//public function
template <typename Key, typename Value>
Key BST<Key, Value> ::floor(Key key)
{
	Node<Key, Value> *tmp = floor(root, key);
	if (tmp == NULL)
		return NULL;
	else
		return tmp->key;
}

template <typename Key, typename Value>
Key BST<Key, Value> ::select(int k)
{
	return select(root, k)->key;
}

template <typename Key, typename Value>
int BST<Key, Value> ::rank(Key key)
{
	return rank(root, key);
}

template <typename Key, typename Value>
Key BST<Key, Value> ::getMin()
{
	return getMin(root)->key;
}

template <typename Key, typename Value>
Key BST<Key, Value> ::getMax()
{
	return getMax(root)->key;
}

template <typename Key, typename Value>
queue<Key> BST<Key, Value> ::getKeys(Key low, Key high)
{
	queue<Key> q;
	getKeys(root, low, high, q);
	return q;
}

template <typename Key, typename Value>
Value BST<Key, Value>::getVal(Key key)
{
	return getVal(root, key);
}

template <typename Key, typename Value>
void BST<Key, Value>::put(Key key, Value val)
{	
	root = put(root, key, val);
}

template <typename Key, typename Value>
void BST<Key, Value>::vinTrav()
{
	vinTrav(root);
}

template <typename Key, typename Value>
void BST<Key, Value>::deleteMinKey()
{
	root = deleteMinKey(root);
}

template <typename Key, typename Value>
void BST<Key, Value>::deleteKey(Key key)
{
	root = deleteKey(root, key);
}






//private function
template <typename Key, typename Value>
Node<Key, Value>* BST<Key, Value>::floor(Node<Key, Value> *x, Key key)
{
	if (x == NULL)
		return NULL;
	if (key == x->key)
		return x;
	if (key < x->key)
		return floor(x->left, key);

	/*ֻ�е����ڵ�����������С�ڵ���key�Ľ��ʱ��
	С�ڵ���key�������Ż�������������У�
	������ڵ��������*/
	Node<Key, Value> *right = floor(x->right, key);
	if (right != NULL)
		return right;	
	else
		return x;
}

template <typename Key, typename Value>
Node<Key, Value>* BST<Key, Value>::select(Node<Key, Value> *x, int k)
{//��������Ϊk�Ľ��

	if (x == NULL)
		return NULL;
	int t = getSize(x->left);
	if (t > k)	//����������Ѱ��
		return select(x->left, k);
	else if (t < k)
		return select(x->right, k-t-1);
	else
		return x;
}

template <typename Key, typename Value>
int BST<Key, Value>::rank(Node<Key, Value> *x, Key key)
{//������xΪ������������С��x.key�ļ�������
	if (x == NULL)
		return NULL;
	if (key < x->key)
		return rank(x->left, key);
	else if (key > x->key)
		return getSize(x->left) + 1 + rank(x->right, key);
	else
		return getSize(x->left);
}

template <typename Key, typename Value>
Node<Key, Value>* BST<Key, Value>::getMin(Node<Key, Value> *x)
{
	if (x->left == NULL)
		return x;
	return getMin(x->left);
}

template <typename Key, typename Value>
Node<Key, Value>* BST<Key, Value>::getMax(Node<Key, Value> *x)
{
	if (x->right == NULL)
		return x;
	return getMax(x->right);
}

template <typename Key, typename Value>
void BST<Key, Value>::getKeys(Node<Key, Value> *x, Key low, Key high, queue<Key> &q)
{
	if (x == NULL)
		return;
	if (low < x->key)
		getKeys(x->left, low, high, q);
	if (low <= x->key && high >= x->key)
		q.push(x->key);
	if (high < x->key)
		getKeys(x->right, low, high, q);
}

template <typename Key, typename Value>
Value BST<Key, Value>::getVal(Node<Key, Value> *x, Key key) {
	//����xΪ���ڵ�������в��ң�������key����Ӧ��ֵ
	if (x == NULL)
		return NULL;
	if (key < x->key)
		return getVal(x->left, key);
	else if (key > x->key)
		return getVal(x->right, key);
	else
		return x->val;
}

template <typename Key, typename Value>
Node<Key, Value>* BST<Key, Value>::put(Node<Key, Value> *x, Key key, Value val) {
	//key��������x���ڵ�������У����������ֵ
	//��������½ڵ���뵽x��������
	if (x == NULL)
		return new Node<Key, Value>(key, val, 1);	//���ڵ�Ĭ�ϴ�1��ʼ���
	if (key < x->key)
		x->left = put(x->left, key, val);
	if (key > x->key)
		x->right = put(x->right, key, val);
	else
		x->val = val;
	
	x->N = getSize(x->left) + getSize(x->right) + 1;
	return x;
}

template <typename Key, typename Value>
void BST<Key, Value>::vinTrav(Node<Key, Value> *root) {
	if (root != NULL)
	{
		vinTrav(root->left);
		cout << "key:" << root->key << " - value:" << root->val << endl;
		vinTrav(root->right);
	}
}

template <typename Key, typename Value>
Node<Key, Value>* BST<Key, Value>::deleteMinKey(Node<Key, Value>* x)
{//���ϼ���������ֱ�������յ������ӣ����ظý��������ӣ��ý�㱻����

	if (x->left == NULL)
		return x->right;
	x->left = deleteMinKey(x->left);
	x->N = getSize(x->left) + getSize(x->right) + 1;
	return x;
}

template <typename Key, typename Value>
Node<Key, Value>* BST<Key, Value>::deleteKey(Node<Key, Value>* x, Key key)
{/*ɾ��Ŀ��ڵ㣬����Ŀ����ĺ�̽�㣨���������е���С�����������λ��*/
	if (x == NULL)
		return NULL;

	if (key < x->key)
		x->left = deleteKey(x->left, key);		//�ݹ�Ѱ�Ҵ�ɾ���Ľ��
	else if (key > x->key)
		x->right = deleteKey(x->right, key);
	else //key==x->key���ҵ�Ŀ����
	{
		if (x->right == NULL)
			return x->left;
		if (x->left == NULL)
			return x->right;

		Node<Key, Value> *tmp = x;				//������ɾ���Ľ�����ӱ���Ϊtmp
		x = getMin(tmp->right);					//xָ�����ĺ�̽��
		x->right = deleteMinKey(tmp->right);	//�ں�̽���ԭ��λ��ɾ����
		x -> left = tmp->left;
	}
	x->N = getSize(x->left) + getSize(x->right) + 1;
	return x;
}

#endif

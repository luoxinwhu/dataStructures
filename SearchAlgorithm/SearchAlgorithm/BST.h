
/*二叉查找树*/
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
	{//返回以x为根节点的数的大小
		if (x != NULL)
			return x->N;
		else
			return 0;
	}		
	Key floor(Key key);							//查找并返回小于或等于key的最大键
	Key select(int k);							//获取排名为k的键
	int rank(Key key);							//获取键的排名
	Key getMin();								//获取最小键
	Key getMax();
	queue<Key> getKeys(Key low, Key high);		//获取指定范围的键
	Value getVal(Key key);						//获取指定键的值
	void put(Key key, Value val);				//插入键
	void vinTrav();								//中序遍历
	void deleteMinKey();						//删除最小键值对
	void deleteKey(Key key);					//删除指定的键

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

	/*只有当根节点右子树存在小于等于key的结点时，
	小于等于key的最大键才会出现在右子树中，
	否则根节点就是最大键*/
	Node<Key, Value> *right = floor(x->right, key);
	if (right != NULL)
		return right;	
	else
		return x;
}

template <typename Key, typename Value>
Node<Key, Value>* BST<Key, Value>::select(Node<Key, Value> *x, int k)
{//返回排名为k的结点

	if (x == NULL)
		return NULL;
	int t = getSize(x->left);
	if (t > k)	//在左子树中寻找
		return select(x->left, k);
	else if (t < k)
		return select(x->right, k-t-1);
	else
		return x;
}

template <typename Key, typename Value>
int BST<Key, Value>::rank(Node<Key, Value> *x, Key key)
{//返回以x为根结点的子树中小于x.key的键的数量
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
	//在以x为根节点的子树中查找，并返回key所对应的值
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
	//key存在于以x根节点的子树中，则更新它的值
	//否则将这个新节点插入到x的子树中
	if (x == NULL)
		return new Node<Key, Value>(key, val, 1);	//根节点默认从1开始存放
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
{//不断检索左子树直到遇见空的左链接，返回该结点的右链接，该结点被回收

	if (x->left == NULL)
		return x->right;
	x->left = deleteMinKey(x->left);
	x->N = getSize(x->left) + getSize(x->right) + 1;
	return x;
}

template <typename Key, typename Value>
Node<Key, Value>* BST<Key, Value>::deleteKey(Node<Key, Value>* x, Key key)
{/*删除目标节点，并用目标结点的后继结点（即右子树中的最小键）替代它的位置*/
	if (x == NULL)
		return NULL;

	if (key < x->key)
		x->left = deleteKey(x->left, key);		//递归寻找待删除的结点
	else if (key > x->key)
		x->right = deleteKey(x->right, key);
	else //key==x->key，找到目标结点
	{
		if (x->right == NULL)
			return x->left;
		if (x->left == NULL)
			return x->right;

		Node<Key, Value> *tmp = x;				//即将被删除的结点链接保存为tmp
		x = getMin(tmp->right);					//x指向它的后继结点
		x->right = deleteMinKey(tmp->right);	//在后继结点的原先位置删除它
		x -> left = tmp->left;
	}
	x->N = getSize(x->left) + getSize(x->right) + 1;
	return x;
}

#endif

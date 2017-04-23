
/*二叉查找树*/
#pragma once
#ifndef BST_H
#define BST_H

#include "BST_Node.h"
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class BST
{
public:
	
	int size() { 
		return size(root);
	}
	int size(Node<Key, Value> *x) {
		if (x != NULL)
			return x->N;
	}
	Value get(Key key);
	void put(Key key, Value val);
	void vinTrav();

private:
	Node<Key, Value> *root;

	Value get(Node<Key, Value> *x, Key key) {
		//在以x为根节点的子树中查找，并返回key所对应的值
		if (x == NULL)
			return NULL;
		if (key < x->key)
			return get(x->left, key);
		else if (key > x->key)
			return get(x->right, key);
		else
			return x->val;
	}
	Node<Key, Value>* put(Node<Key, Value> *x, Key key, Value val) {
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

		x->N = size(x->left) + size(x->right) + 1;
		return x;
	}
	void vinTrav(Node<Key, Value> *root) {
		if (root != NULL)
			{
				vinTrav(root->left);
				cout << "key:" << root->key << " - value:" << root->val << endl;
				vinTrav(root->right);
			}
	}
	
};


//public function

template <typename Key, typename Value>
Value BST<Key, Value>::get(Key key)
{
	return get(root, key);
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

#endif

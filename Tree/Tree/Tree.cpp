//
//  Tree.cpp
//  Tree
//
//  Created by mac on 2017/4/12.
//  Copyright © 2017年 mac. All rights reserved.
//

#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree()
{
	cout << "Tree constructor is called" << endl;
	m_pRoot = new Node();
}

Tree::~Tree()
{
	cout << "Tree destructor is called" << endl;
	m_pRoot->deleteNode();
}

Node* Tree::searchNode(int nodeIndex)
{
	return m_pRoot->searchNode(nodeIndex); //递归调用Node的searchNode()方法
}

bool Tree::addNode(int nodeIndex, bool direction, Node *pNode)
{
	//direction: add in left(0) or right(1)
	//pNode: which is wait for adding

	Node *tmp = searchNode(nodeIndex);
	if (tmp == NULL)
	{
		cout << "error：插入位置不合法！" << endl;
		return false;
	}
	else
	{
		Node *newNode = new Node();
		if (newNode == NULL)
		{
			cout << "error：申请内存失败！" << endl;
			return false;
		}
		//拷贝传入的节点，以免误修改传入的数据
		newNode->index = pNode->index;
		newNode->data = pNode->data;

		if (direction == 0)
		{
			tmp->pLChild = newNode;
		}
		if (direction == 1)
		{
			tmp->pRChild = newNode;
		}

		return true;
	}
}

bool Tree::deleteNode(int nodeIndex, Node *pNode)
{
	Node *tmp = searchNode(nodeIndex);
	if (tmp == NULL)
	{
		cout << "error：删除的位置不合法！" << endl;
		return false;
	}
	else
	{
		//传出节点数据
		if (pNode != NULL)
		{
			pNode->data = tmp->data;
		}

		//删除节点操作
		tmp->deleteNode(); //调用Node的deleteNode()方法
		delete tmp;
		return true;
	}
}


void Tree::preOrderTraverse()
{
	m_pRoot->preOrderTraverse();
}

void Tree::inOrderTraverse()
{
	m_pRoot->inOrderTraverse();
}

void Tree::postOrderTraverse()
{
	m_pRoot->postOrderTraverse();
}



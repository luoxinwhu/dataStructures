//
//  Node.cpp
//  Tree
//
//  Created by mac on 2017/4/12.
//  Copyright © 2017年 mac. All rights reserved.
//

#include "Node.h"
#include <iostream>
using namespace std;


Node::Node()
{
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}

Node *Node::searchNode(int nodeIndex)
{
	//判断本身
	if (this->index == nodeIndex)
	{
		return this;
	}

	//判断左孩子
	if (this->pLChild != NULL)
	{
		if (this->pLChild->index == nodeIndex)
		{
			return this->pLChild;
		}
	}

	//判断右孩子
	if (this->pRChild != NULL)
	{
		if (this->pRChild->index == nodeIndex)
		{
			return this->pRChild;
		}
	}

	return NULL;
}


void Node::deleteNode()
{
	//删除左孩子
	if (this->pLChild != NULL)
	{
		this->pLChild->deleteNode(); //递归调用
	}

	//删除右孩子
	if (this->pRChild != NULL)
	{
		this->pRChild->deleteNode();
	}

	//父节点的指针置空
	if (this->pParent != NULL)
	{
		if (this->pParent->pLChild == this) //当前对象是自己父节点的左孩子
		{
			this->pParent->pLChild = NULL;
		}
		if (this->pParent->pRChild == this) //当前对象是自己父节点的右孩子
		{
			this->pParent->pRChild = NULL;
		}
	}

	//销毁自己
	delete this;
}


void Node::preOrderTraverse()
{
	//输出自己
	cout << this->data << "(" << this->index << ")" << endl;

	//输出左孩子
	if (this->pLChild != NULL)
	{
		this->pLChild->preOrderTraverse();
	}

	//输出右孩子
	if (this->pRChild != NULL)
	{
		this->pRChild->preOrderTraverse();
	}
}


void Node::inOrderTraverse()
{
	//输出左孩子
	if (this->pLChild != NULL)
	{
		this->pLChild->inOrderTraverse();
	}

	//输出自己
	cout << this->data << "(" << this->index << ")" << endl;

	//输出右孩子
	if (this->pRChild != NULL)
	{
		this->pRChild->inOrderTraverse();
	}
}


void Node::postOrderTraverse()
{
	//输出左孩子
	if (this->pLChild != NULL)
	{
		this->pLChild->postOrderTraverse();
	}

	//输出右孩子
	if (this->pRChild != NULL)
	{
		this->pRChild->postOrderTraverse();
	}

	//输出自己
	cout << this->data << "(" << this->index << ")" << endl;

}








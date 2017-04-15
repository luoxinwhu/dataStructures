#pragma once
//
//  Tree.h
//  Tree
//
//  Created by mac on 2017/4/12.
//  Copyright © 2017年 mac. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include "Node.h"
#include <stdio.h>

class Tree
{
public:
	Tree();
	~Tree();
	Node *searchNode(int nodeIndex);    //寻找节点
	bool addNode(int nodeIndex, bool direction, Node *pNode); //pNode是要添加的节点
	bool deleteNode(int nodeIndex, Node *pNode); //pNode保存被删除的节点
	void preOrderTraverse();
	void inOrderTraverse();
	void postOrderTraverse();


private:
	Node *m_pRoot;

};

#endif /* Tree_h */



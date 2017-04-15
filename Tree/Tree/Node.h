//
//  Node.h
//  Tree
//
//  Created by mac on 2017/4/12.
//  Copyright © 2017年 mac. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#define Elem int

class Node
{
public:
	Node();
	Node *searchNode(int nodeIndex);
	void deleteNode();
	void preOrderTraverse();
	void inOrderTraverse();
	void postOrderTraverse();

	int index;
	Elem data;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;
};
#endif /* Node_h */

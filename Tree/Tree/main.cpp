//
//  main.cpp
//  Tree
//
//  Created by mac on 2017/4/12.
//  Copyright © 2017年 mac. All rights reserved.
//

#include "Tree.h"
#include <iostream>
using namespace std;

int main(void)
{
	Tree *tree1 = new Tree();

	Node *node1 = new Node();
	node1->index = 1;
	node1->data = 5;

	Node *node2 = new Node();
	node2->index = 2;
	node2->data = 53;

	Node *node3 = new Node();
	node3->index = 3;
	node3->data = 90;

	Node *node4 = new Node();
	node3->index = 3;
	node3->data = 60;

	tree1->addNode(0, 0, node1);
	tree1->addNode(0, 1, node2);
	tree1->addNode(1, 0, node3);
	tree1->preOrderTraverse();


	delete tree1;
	system("pause");
	return 0;
}

//
//  main.cpp
//  dataStructure
//
//  Created by mac on 2017/4/11.
//  Copyright © 2017年 mac. All rights reserved.
//


#include <iostream>
#include <string>
#include "SingleLinkList.h"
using namespace std;

int main(void)
{
	Node node1;
	node1.data.name="lx";
	node1.data.phone="123";

	SingleLinkList *pSList = new SingleLinkList();
	pSList->ListInsertHead(&node1);
	pSList->ListInsertTail(&node1);
	pSList->ListTraverse();

	delete pSList;
	pSList = NULL;

	return 0;
}

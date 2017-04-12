//
//  main.cpp
//  dataStructure
//
//  Created by mac on 2017/4/11.
//  Copyright © 2017年 mac. All rights reserved.
//


#include <iostream>
#include "Stack.h"
using namespace std;

#define ISFROMBUTTOM true

int main(void)
{
	int arr[] = { 3,5,8,90 };
	int arr_len = sizeof(arr) / sizeof(arr[0]);

	Elem res;
	Stack *pStack = new Stack(10);
	for (int i = 0; i<arr_len; i++)
	{
		if (pStack->push(arr[i])) {}
		else { break; }
	}
	pStack->stackTraverse(ISFROMBUTTOM);

	if (pStack->pop(res))
	{
		res.printCoordinate();
	}

	pStack->clearStack();
	if (pStack->pop(res))
	{
		res.printCoordinate();
	}
	
	delete pStack;
	pStack = NULL;
	system("pause");
	return 0;
}

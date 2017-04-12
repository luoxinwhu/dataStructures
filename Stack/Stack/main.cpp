//
//  main.cpp
//  dataStructure
//
//  Created by mac on 2017/4/11.
//  Copyright © 2017年 mac. All rights reserved.
//


#include <iostream>
#include "Stack.h"
#include "Coordinate.h"
using namespace std;

#define ISFROMBUTTOM true

int main(void)
{
	//实例化Stack类模板
	Stack<Coordinate> *pStack = new Stack<Coordinate>(10);
	Coordinate coor1(1,2), coor2(3,4);
	
	pStack->push(coor1);
	pStack->push(coor2);
	pStack->stackTraverse(ISFROMBUTTOM);

	/*if (pStack->pop(coor1))
	{
		cout << coor1 << endl;
	}

	pStack->clearStack();
	if (pStack->pop(coor1))
	{
		cout << coor1 << endl;
	}
	*/
	delete pStack;
	pStack = NULL;
	system("pause");
	return 0;
}

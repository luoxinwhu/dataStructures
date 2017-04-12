//
//  Stack.hpp
//  dataStructure
//
//  Created by mac on 2017/4/11.
//  Copyright © 2017年 mac. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include "Coordinate.h"
#define Elem Coordinate

class Stack
{
public:
	Stack(int size);
	~Stack();
	bool StackEmpty();
	bool StackFull();
	int StackLength();
	void clearStack();
	bool push(Elem elem);
	bool pop(Elem &elem);
	void stackTraverse(bool fromButtom);

private:
	int m_iLength;  //栈中元素个数
	int m_iSize;    //栈容量
	Elem *m_pStack;
};

#endif /* Stack_h */

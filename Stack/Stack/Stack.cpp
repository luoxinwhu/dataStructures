
//  Stack.cpp
//  dataStructure
//
//  Created by mac on 2017/4/11.
//  Copyright © 2017年 mac. All rights reserved.
//

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size)
{
	m_iSize = size;
	m_iLength = 0;
	m_pStack = new Elem[m_iSize];
}

Stack::~Stack()
{
	delete m_pStack;
	m_pStack = NULL;
}

bool Stack::StackEmpty()
{
	return m_iLength == 0 ? true : false;
}

bool Stack::StackFull()
{
	return m_iLength >= m_iSize ? true : false;
}

int Stack::StackLength()
{
	return m_iLength;
}

void Stack::clearStack()
{
	m_iLength = 0;
}

bool Stack::push(Elem elem)
{
	if (StackFull())
	{
		cout << "error: stack is full!" << endl;
		return false;
	}
	//先入栈再移动栈顶指针
	m_pStack[m_iLength] = elem;
	m_iLength++;
	return true;
}

bool Stack::pop(Elem &elem) //elem可以传入一个对象，通过引用的方式取出pop函数传给它的值
{
	if (StackEmpty())
	{
		cout << "error: stack is empty!" << endl;
		return false;
	}
	m_iLength--;
	elem = m_pStack[m_iLength];
	return true;
}

void Stack::stackTraverse(bool fromButtom)
{
	if (fromButtom)
	{
		for (int i = 0; i < m_iLength; i++)
		{
			m_pStack[i].printCoordinate();
			//或在Coordinate类中重载“<<”运算符

			//Element是普通简单类型，则使用下面cout方法即可
			/*cout << m_pStack[i] << ' ';*/
		}
		cout << endl;
	}
	else
	{
		for (int i = m_iLength - 1; i >= 0; i--)
		{
			m_pStack[i].printCoordinate();
			/*cout << m_pStack[i] << ' ';*/
		}
		cout << endl;
	}
}

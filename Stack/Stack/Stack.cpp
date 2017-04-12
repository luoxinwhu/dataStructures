//
////  Stack.cpp
////  dataStructure
////
////  Created by mac on 2017/4/11.
////  Copyright © 2017年 mac. All rights reserved.
////
//
//#include "Stack.h"
//#include <iostream>
//using namespace std;
//
//template <typename T>
//Stack<T>::Stack(int size)
//{
//	m_iSize = size;
//	m_iLength = 0;
//	m_pStack = new T[m_iSize];
//}
//
//template <typename T>
//Stack<T>::~Stack()
//{
//	delete m_pStack;
//	m_pStack = NULL;
//}
//
//template <typename T>
//bool Stack<T>::StackEmpty()
//{
//	return m_iLength == 0 ? true : false;
//}
//
//template <typename T>
//bool Stack<T>::StackFull()
//{
//	return m_iLength >= m_iSize ? true : false;
//}
//
//template <typename T>
//int Stack<T>::StackLength()
//{
//	return m_iLength;
//}
//
//template <typename T>
//void Stack<T>::clearStack()
//{
//	m_iLength = 0;
//}
//
//template <typename T>
//bool Stack<T>::push(T elem)
//{
//	if (StackFull())
//	{
//		cout << "error: stack is full!" << endl;
//		return false;
//	}
//	//先入栈再移动栈顶指针
//	m_pStack[m_iLength] = elem;
//	m_iLength++;
//	return true;
//}
//
//template <typename T>
//bool Stack<T>::pop(T &elem) //elem可以传入一个对象，通过引用的方式取出pop函数传给它的值
//{
//	if (StackEmpty())
//	{
//		cout << "error: stack is empty!" << endl;
//		return false;
//	}
//	m_iLength--;
//	elem = m_pStack[m_iLength];
//	return true;
//}
//
//template <typename T>
//void Stack<T>::stackTraverse(bool fromButtom)
//{
//	if (fromButtom)
//	{
//		for (int i = 0; i < m_iLength; i++)
//		{
//			/*m_pStack[i].printCoordinate();*/
//			//或在Coordinate类中重载“<<”运算符
//
//			//Element是普通简单类型，则使用下面cout方法即可
//			cout << m_pStack[i] << ' ';
//		}
//		
//	}
//	else
//	{
//		for (int i = m_iLength - 1; i >= 0; i--)
//		{
//			/*m_pStack[i].printCoordinate();*/
//			cout << m_pStack[i] << ' ';
//		}
//	}
//	cout << endl;
//}

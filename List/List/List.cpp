//
//  List.cpp
//  dataStructure
//
//  Created by mac on 2017/4/10.
//  Copyright © 2017年 mac. All rights reserved.


#include "List.h"
#include <iostream>
using namespace std;

List::List(int size)
{
	cout << "List constructor is called" << endl;
	m_iSize = size;
	m_pList = new Elem[m_iSize]; //分配内存空间
	m_iLength = 0;
}

List::~List()
{
	cout << "List destructor is called" << endl;
	delete[]m_pList;   //释放线性表所占用的内存空间
	m_pList = NULL;     //释放指针
}

void List::clearList()
{
	m_iLength = 0;
}

bool List::ListEmpty()
{
	return m_iLength == 0 ? true : false;
	//    if(m_iLength == 0)
	//    {
	//        return true;
	//    }
	//    else{
	//        return false;
	//    }
}

int List::ListLength()
{
	return m_iLength;
}

bool List::getElem(int i, Elem *e)
{
	if (i<0 || i >= m_iLength)
	{
		cout << "error: 获取元素的位置不合法！" << endl;
		return false;
	}
	*e = m_pList[i];
	return true;
}
int List::locateElem(Elem *e)
{
	//返回第一次匹配的位置，比较注意是m_iLength
	for (int i = 0; i<m_iLength; i++)
	{
		if (m_pList[i] == *e)
		{
			return i;
		}
	}
	cout << "error: 未找到匹配元素!" << endl;
	return -1;
}

bool List::getPriorElem(Elem *currElem, Elem *prevElem)
{
	int index = locateElem(currElem);
	if (index == -1 || index == 0)
	{
		return false;
	}
	else {
		*prevElem = m_pList[index - 1];
		return true;
	}

}
bool List::getNextElem(Elem *currElem, Elem *nextElem)
{
	int index = locateElem(currElem);
	if (index == -1 || index == m_iLength - 1)
	{
		return false;
	}
	else {
		*nextElem = m_pList[index + 1];
		return true;
	}

}

void List::ListTraverse()
{
	if (m_iLength > 0) {
		for (int i = 0; i<m_iLength; i++)
		{
			cout << m_pList[i] << ' ';
		}
		cout << endl;
	}
	else {
		cout << "当前链表为空！" << endl;
	}

}


bool List::ListInsert(int i, Elem *e)
{
	if (i<0 || i>m_iLength)
	{
		//m_iLength位置插入意味着在表尾插入
		cout << "error: 插入位置不合法！" << endl;
		return false;
	}
	//先移动
	for (int k = m_iLength - 1; k >= i; --k)
	{
		m_pList[k + 1] = m_pList[k];
	}
	//再插入
	m_pList[i] = *e;
	++m_iLength;
	return true;
}
bool List::ListDelete(int i, Elem *e)
{
	//先删除
	*e = m_pList[i];

	if (i<0 || i >= m_iLength)
	{
		cout << "error: 删除的位置不合法！" << endl;
		return false;
	}
	//再移动
	for (int k = i + 1; k<m_iLength; ++k)
	{
		m_pList[k - 1] = m_pList[k];
	}
	--m_iLength;
	return true;
}


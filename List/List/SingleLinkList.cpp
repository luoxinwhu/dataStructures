//
//  SingleLinkList.cpp
//  dataStructure
//
//  Created by mac on 2017/4/11.
//  Copyright © 2017年 mac. All rights reserved.
//

#include "SingleLinkList.h"
#include <iostream>
using namespace std;

SingleLinkList::SingleLinkList()
{   //创建头结点

	cout << "SingleLinkList constructor is called" << endl;

	m_pList = new Node;
	//  m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}

void SingleLinkList::clearList()
{
	//保留头结点，从第一个节点开始：先读取它的next域，再清除这个节点

	Node *currNode = m_pList->next;
	while (currNode != NULL)
	{
		Node *tmp = currNode->next;
		delete currNode;
		currNode = tmp;
		m_iLength--;
	}

	//最后清除头结点的指针域
	m_pList->next = NULL;
}


SingleLinkList::~SingleLinkList()
{
	//清空链表再释放头指针
	cout << "SLinkList destructor is called" << endl;

	clearList();
	delete m_pList;
	m_pList = NULL;
}

bool SingleLinkList::ListEmpty()
{
	return m_iLength == 0 ? true : false;
}

int SingleLinkList::ListLength()
{
	return m_iLength;
}

bool SingleLinkList::ListInsertHead(Node *pNode)
{
	Node *tmp = m_pList->next;
	Node *newNode = new Node;   //从堆中申请内存
	if (newNode == NULL)
	{
		cout << "error：堆内存申请失败！" << endl;
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = tmp;
	m_pList->next = newNode;
	m_iLength++;
	return true;
}

bool SingleLinkList::ListInsertTail(Node *pNode)
{
	Node *currNode = m_pList;
	//循环找到链表的尾部
	while (currNode->next != NULL)
	{
		currNode = currNode->next;
	}
	Node *newNode = new Node;   //从堆中申请内存
	if (newNode == NULL)
	{
		cout << "error：堆内存申请失败！" << endl;
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = NULL;
	currNode->next = newNode;
	m_iLength++;
	return true;
}

bool SingleLinkList::ListInsert(int i, Node *pNode)
{
	/* i=0, 在头结点后面插入
	* i=m_ilength, 在链表尾部插入
	*/

	if (i<0 || i>m_iLength)
	{
		cout << "error：插入位置不合法！" << endl;
		return false;
	}

	Node *currNode = m_pList;
	for (int k = 0; k<i; k++)
	{
		currNode = currNode->next;
	} //找到第i-1个节点
	Node *newNode = new Node;
	if (newNode == NULL)
	{
		cout << "error：堆内存申请失败！" << endl;
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = currNode->next;
	currNode->next = newNode;
	m_iLength++;
	return true;
}

bool SingleLinkList::ListDelete(int i, Node *pNode)
{
	if (i<0 || i >= m_iLength)
	{
		cout << "error: 删除的位置不合法！" << endl;
		return false;
	}
	Node *currNode = m_pList;
	Node *currNodePrev = NULL;
	for (int k = 0; k <= i; k++)
	{
		currNodePrev = currNode;
		currNode = currNode->next;
	} //找到第i个节点
	pNode->data = currNode->data;
	currNodePrev->next = currNode->next;

	delete currNode; //释放空间
	currNode = NULL; //释放指针
	--m_iLength;
	return true;
}

bool SingleLinkList::getElem(int i, Node *pNode)
{
	if (i<0 || i >= m_iLength)
	{
		cout << "error: 删除的位置不合法！" << endl;
		return false;
	}
	Node *currNode = m_pList; //头指针的next指向头结点
	for (int k = 0; k <= i; k++)
	{
		currNode = currNode->next;
	} //找到第i个节点
	pNode->data = currNode->data;
	return true;
}

int  SingleLinkList::locateElem(Node *pNode)
{
	Node *currNode = m_pList;
	int index = 0;
	while (currNode->next != NULL) //当前节点不是最后一个节点
	{
		currNode = currNode->next;
		if (currNode->data == pNode->data)
		{
			return index; //返回第一个匹配元素的索引
		}
		index++;
	}
	cout << "error: 未找到匹配的节点" << endl;
	return -1;
}

bool SingleLinkList::getPriorElem(Node *pCurrNode, Node *pPrevNode) //获取指定元素的前驱
{
	Node *currNode = m_pList;
	Node *currNodePrev = NULL;

	while (currNode->next != NULL)
	{
		currNodePrev = currNode;
		currNode = currNode->next;
		if (currNode->data == pCurrNode->data)
		{
			if (currNodePrev == m_pList) //判断当前节点是否是头节点
			{
				cout << "error：当前节点是第一个节点，不存在前驱" << endl;
				return false;
			}
			else {
				pPrevNode->data = currNodePrev->data;
				return true;
			}
		}
	}
	cout << "error: 未找到指定元素的前驱" << endl;
	return false;
}

bool SingleLinkList::getNextElem(Node *pCurrNode, Node *pNextNode)
{
	Node *currNode = m_pList;
	while (currNode->next != NULL)
	{
		currNode = currNode->next;
		if (currNode->data == pCurrNode->data)
		{
			if (currNode->next == NULL) {
				cout << "error：当前节点已经是最后一个节点，不存在后继" << endl;
				return false;
			}
			else {
				pNextNode->data = currNode->next->data;
				return true;
			}
		}
	}
	cout << "error: 未找到指定元素的后继" << endl;
	return false;
}

void SingleLinkList::ListTraverse()
{
	if (ListEmpty())
	{
		cout << "当前链表为空！" << endl;
	}
	else {
		Node *currNode = m_pList;
		while (currNode->next != NULL)
		{
			currNode = currNode->next;
			currNode->printNode();
		}
	}

}


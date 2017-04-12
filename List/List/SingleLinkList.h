#pragma once
//
//  SingleLinkList.hpp
//  dataStructure
//
//  Created by mac on 2017/4/11.
//  Copyright © 2017年 mac. All rights reserved.
//

#ifndef SingleLinkList_h
#define SingleLinkList_h

#include "Node.h"
#include <stdio.h>

class SingleLinkList
{
public:
	SingleLinkList();
	~SingleLinkList();
	void clearList();       //清空线性表
	bool ListEmpty();       //判断线性表是否为空
	int  ListLength();      //获取线性表长度
	bool ListInsertHead(Node *pNode);       //在头结点后面插入
	bool ListInsertTail(Node *pNode);       //在链表尾部插入
	bool ListInsert(int i, Node *pNode);    //在链表中部插入
	bool ListDelete(int i, Node *pNode);    //删除链表中的某个节点
	bool getElem(int i, Node *pNode);       //获取指定位置的元素值
	int  locateElem(Node *pNode);           //获取第一个满足e的元素的位置
	bool getPriorElem(Node *pCurrNode, Node *pPrevNode); //获取指定元素的前驱
	bool getNextElem(Node *pCurrNode, Node *pNextNode); //获取指定元素的后继
	void ListTraverse();

private:
	Node *m_pList;
	int m_iLength;
};


#endif /* SingleLinkList_h */

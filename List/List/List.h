#pragma once
//
//  List.hpp
//  dataStructure
//
//  Created by mac on 2017/4/10.
//  Copyright © 2017年 mac. All rights reserved.
//

#ifndef List_h
#define List_h

#define Elem int


class List
{
public:
	List(int size); //构造函数
	~List();        //析构函数
	void clearList();       //清空线性表
	bool ListEmpty();       //判断线性表是否为空
	int ListLength();       //获取线性表长度
	bool getElem(int i, Elem *e);   //获取指定位置的元素值
	int locateElem(Elem *e);        //获取第一个满足e的元素的位置
	bool getPriorElem(Elem *currElem, Elem *prevElem); //获取指定元素的前驱
	bool getNextElem(Elem *currElem, Elem *nextElem); //获取指定元素的后继
	bool ListInsert(int i, Elem *e);
	bool ListDelete(int i, Elem *e);
	void ListTraverse();

private:
	Elem *m_pList;   //指向线性表的指针
	int m_iSize;    //线性表容量
	int m_iLength;  //当前线性表元素数量
};


#endif /* List_h */


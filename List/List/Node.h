#pragma once
//
//  Node.hpp
//  dataStructure
//
//  Created by mac on 2017/4/10.
//  Copyright © 2017年 mac. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include "Person.h"
#include <stdio.h>

#define Elem Person

class Node
{
public:
	Elem data;
	Node *next;
	void printNode();

};

#endif /* Node_h */

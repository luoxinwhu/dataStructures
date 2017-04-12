#pragma once
//
//  Person.hpp
//  dataStructure
//
//  Created by mac on 2017/4/10.
//  Copyright © 2017年 mac. All rights reserved.
//

#ifndef Person_h
#define Person_h


#include <stdio.h>
#include <string>
#include <ostream>
using namespace std;

class Person
{
	friend ostream& operator<< (ostream& out, Person& person); //输出流重载
public:
	string name;
	string phone;
	Person& operator= (Person& person); //重载赋值符号
	bool operator== (Person& person);   //重载比较运算符

};
#endif /* Person_h */

//
//  Person.cpp
//  dataStructure
//
//  Created by mac on 2017/4/10.
//  Copyright © 2017年 mac. All rights reserved.
//

#include "Person.h"
#include <iostream>

ostream& operator<< (ostream& out, Person& person)
{
	out << person.name << "--" << person.phone << endl;
	return out;
}
Person& Person::operator= (Person& person)
{
	this->name = person.name;
	this->phone = person.phone;
	return *this; //将this指针作为对象返回
}

bool Person::operator== (Person& person)
{
	if (this->name == person.name && this->phone == person.phone)
	{
		return true;
	}
	return false;
}


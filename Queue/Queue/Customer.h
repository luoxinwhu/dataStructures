#pragma once

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer
{
public:
	Customer(string name="", int age=0);
	void printInfo();
private:
	string name;
	int age;
};

#endif // !CUSTOMER_H

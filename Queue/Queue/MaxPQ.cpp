#include "MaxPQ.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	MaxPQ<char> maxpq1(8);
	maxpq1.Insert('a');
	maxpq1.Insert('b');
	maxpq1.Insert('c');
	maxpq1.Insert('d');
	maxpq1.Insert('e');
	maxpq1.Insert('f');
	maxpq1.MaxPQtraverse();
	return 0;
}
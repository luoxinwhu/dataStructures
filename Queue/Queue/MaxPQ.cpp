#include "MaxPQ.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;
	cout << "������8���ַ�����" << endl;
	cin >> str1;
	
	
	MaxPQ<char> maxpq1(str1.size(), &str1[0]);
	MaxPQ<char> maxpq2(str1.size(), &str1[0]);


//----------------------------//
	maxpq2.MaxPQtraverse();
	maxpq2.heap_Sort();
	maxpq2.MaxPQtraverse();
	return 0;
}
#include <iostream>
#include <cmath>
#include "Stack.h"
#include "radixTrans.h"
//#include "Coordinate.h"
using namespace std;

int main(void)
{
	//ʵ����Stack��ģ��
	Stack<int> *pStack = new Stack<int>(10);
	int N;

	cin >> N;
	transformation(N, HEXADECIMAL, pStack);

	delete pStack;
	pStack = NULL;
	system("pause");
	return 0;
}
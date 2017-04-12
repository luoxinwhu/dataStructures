/*
* radixTrans.h
* 栈应用——进制转换
* 描述： 输入任意十进制整数N， 输出二进制、八进制、16进制的数
* 公式： N = （N div d) *d + N mod d
*/

#include "Stack.h"

#define ISFROMBUTTOM true
#define ISFROMTOP	 false
#define BINARY		2
#define OCTONARY	8
#define HEXADECIMAL 16

template <typename T>
void transformation(int N, int radix, Stack<T> *pStack)
{
	char model[] = "0123456789ABCDEF";
	int mod = 0;
	int elem = 0;
	while (N != 0)
	{
		mod = N % radix;
		if (!pStack->push(mod))
			break;
		N = N / HEXADECIMAL;
	}

	cout << HEXADECIMAL << "进制数为：";
	while (!pStack->StackEmpty())
	{
		pStack->pop(elem);
		cout << model[elem];
	}
	cout << endl;
}

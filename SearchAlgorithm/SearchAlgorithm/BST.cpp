#include "BST.h"
#include <iostream>
#include <queue>
using namespace std;


int main()
{
	BST<char, int> bst1;
	/*Node<int, int> node1(1,100,3),node2(2,200,0), node3(3,300,0);*/
	
	bst1.put('a',100);
	bst1.put('l', 200);
	bst1.put('j', 105);
	bst1.put('c', 302);
	bst1.put('m', 780);
	bst1.put('p', 404);
	bst1.put('c', 90);
	bst1.put('e', 405);
	bst1.vinTrav();
	/*cout << "�������Ĵ�СΪ�� "<< bst1.getSize() << endl;
	cout << "��'g'��ֵΪ�� " << bst1.getVal('g')<<endl;
	cout << "����Ϊ�� " << bst1.getMax() << endl;
	cout << "��С��Ϊ�� " << bst1.getMin() << endl;*/
	queue<char> q1 = bst1.getKeys('a','m');
	cout << q1.size() << endl;
	while (!q1.empty())
	{
		cout << q1.front()<< endl;
		q1.pop();
	}
	/*cout << "����Ϊ3�ļ��ǣ� " << bst1.select(3) << endl;
	cout << "��'m'������Ϊ�� " << bst1.rank('m') << endl;
	cout << "С�ڵ��ڼ�'l'�������ǣ� " << bst1.floor('l') << endl;
	bst1.deleteKey('j');
	bst1.vinTrav();*/
	return 0;
}


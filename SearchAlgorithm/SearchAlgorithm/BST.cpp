#include "BST.h"
#include <iostream>
using namespace std;


int main()
{
	BST<int, int> bst1;
	/*Node<int, int> node1(1,100,3),node2(2,200,0), node3(3,300,0);*/
	
	bst1.put(1,100);
	bst1.put(2, 200);
	bst1.vinTrav();
	cout<<bst1.get(1)<<endl;
	return 0;
}


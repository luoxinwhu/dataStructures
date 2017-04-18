

#include "AdjArrGraph.h"
#include <iostream>
#include <stdlib.h>
#include <xtree>
using namespace std;

int main(void)
{
	Node node1('A'), node2('B'), node3('C'), node4('D');
	AdjArrGraph gph1(4);
	gph1.addNode(&node1);
	gph1.addNode(&node2);
	gph1.addNode(&node3);
	gph1.addNode(&node4);
	gph1.setValueForUDGraph(0, 1);
	gph1.setValueForUDGraph(0, 2);
	gph1.setValueForUDGraph(0, 3);
	gph1.setValueForUDGraph(1, 0);
	gph1.setValueForUDGraph(2,0);
	gph1.setValueForUDGraph(2,3);
	gph1.setValueForUDGraph(3,0);
	gph1.setValueForUDGraph(3,2);
	gph1.printAdjMatrix();

	system("pause");
	return 0;
}
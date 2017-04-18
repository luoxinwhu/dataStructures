#pragma once
/* AdjArrGraph.h
 * 邻接矩阵存储图
   
        A
	  /   \
	 B     D
    / \   / \
   C   F  G--H
    \ /
	 E
	 
   A B C D E F G H
A    1   1 
B  1   1     1
C    1     1
D  1           1 1     
E      1     1
F    1     1
G        1       1    
H        1     1 
 
 */

#ifndef ADJARRGRAPH_H
#define ADJARRGRAPH_H

#include "Node.h"

class AdjArrGraph
{
public:
	AdjArrGraph(int capacity);
	~AdjArrGraph();
	bool addNode(Node* pNode);
	void resetNode();			//清空访问记录
	bool setValueForDGraph(int row, int col, int val = 1);	//为有向图设置邻接矩阵
	bool setValueForUDGraph(int row, int col, int val = 1);	//为无向图设置邻接矩阵
	void printAdjMatrix();

	void depthFirstTraverse(int nodeIndex);		//深度优先遍历
	void breadthFirstTraverse(int nodeIndex);	//广度优先遍历

private:
	int m_iCapacity;	//图中最多可以容纳的顶点数
	int m_iNodeCount;	//已经添加的顶点数(可充当顶点的索引)
	Node* m_pNodeArray;	//存放顶点数组
	int* m_pMatrix;		//存放邻接矩阵

	bool getValueFromMatrix(int row, int col, int &val);


};

#endif // !ADJARRGRAPH_H
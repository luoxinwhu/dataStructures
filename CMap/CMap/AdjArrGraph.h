#pragma once
/* AdjArrGraph.h
 * �ڽӾ���洢ͼ
   
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
	void resetNode();			//��շ��ʼ�¼
	bool setValueForDGraph(int row, int col, int val = 1);	//Ϊ����ͼ�����ڽӾ���
	bool setValueForUDGraph(int row, int col, int val = 1);	//Ϊ����ͼ�����ڽӾ���
	void printAdjMatrix();

	void depthFirstTraverse(int nodeIndex);		//������ȱ���
	void breadthFirstTraverse(int nodeIndex);	//������ȱ���

private:
	int m_iCapacity;	//ͼ�����������ɵĶ�����
	int m_iNodeCount;	//�Ѿ���ӵĶ�����(�ɳ䵱���������)
	Node* m_pNodeArray;	//��Ŷ�������
	int* m_pMatrix;		//����ڽӾ���

	bool getValueFromMatrix(int row, int col, int &val);


};

#endif // !ADJARRGRAPH_H
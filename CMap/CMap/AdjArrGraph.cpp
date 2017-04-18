#include "AdjArrGraph.h"
#include <iostream>
#include <vector>
using namespace std;


AdjArrGraph::AdjArrGraph(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];
	m_pMatrix = new int[m_iCapacity * m_iCapacity];
	//邻接矩阵置零
	memset(m_pMatrix, 0, m_iCapacity*m_iCapacity * sizeof(int));
}
AdjArrGraph::~AdjArrGraph()
{
	delete[] m_pMatrix;
	delete[] m_pNodeArray;
}

bool AdjArrGraph::addNode(Node* pNode)
{
	m_pNodeArray[m_iNodeCount].m_NodeData = pNode->m_NodeData;
	m_iNodeCount++;
	return true;
}
void AdjArrGraph::resetNode()
{
	for (int i = 0; i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_isVisited = false;
	}
}


bool AdjArrGraph::setValueForDGraph(int row, int col, int val)
{	//为有向图设置邻接矩阵
	m_pMatrix[row*m_iCapacity + col] = val;
	return true;
}
bool AdjArrGraph::setValueForUDGraph(int row, int col, int val)
{	//为无向图设置邻接矩阵
	m_pMatrix[row*m_iCapacity + col] = val;
	m_pMatrix[col*m_iCapacity + row] = val;
	return true;
}
void AdjArrGraph::printAdjMatrix()
{
	for (int i = 0; i < m_iCapacity; i++)
	{
		for (int j = 0; j < m_iCapacity; j++)
		{
			cout << m_pMatrix[i*m_iCapacity + j] << ' ';
		}
		cout << endl;
	}
}

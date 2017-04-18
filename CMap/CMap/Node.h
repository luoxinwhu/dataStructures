#pragma once

#ifndef NODE_H
#define NODE_H

#define Elem char

class Node
{
public:
	Node(Elem data = 0);
	Elem m_NodeData;
	bool m_isVisited; //标识当前节点是否被访问过,true-访问过
};

Node::Node(Elem data)
{
	m_NodeData = data;
	m_isVisited = false;
}

#endif // !NODE_H




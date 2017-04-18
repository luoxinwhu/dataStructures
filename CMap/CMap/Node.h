#pragma once

#ifndef NODE_H
#define NODE_H

#define Elem char

class Node
{
public:
	Node(Elem data = 0);
	Elem m_NodeData;
	bool m_isVisited; //��ʶ��ǰ�ڵ��Ƿ񱻷��ʹ�,true-���ʹ�
};

Node::Node(Elem data)
{
	m_NodeData = data;
	m_isVisited = false;
}

#endif // !NODE_H




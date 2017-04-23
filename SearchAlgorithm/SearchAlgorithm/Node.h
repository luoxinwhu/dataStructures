#pragma once

template <typename Key, typename Value>
class Node
{
public:
	Node(Key key, Value val, Node *next)
	{
		this->key = key;
		this->val = val;
		this->next = next;
	}

	Key key;
	Value val;
	Node *next;
};
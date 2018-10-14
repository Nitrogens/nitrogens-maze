#include "stdafx.h"
#include "Node.h"

Node::Node(DataType _value, Node* _next, Node* _prev):
	value(_value), next(_next), prev(_prev) {}

DataType Node::getValue()
{
	return value;
}

Node* Node::getNext()
{
	return next;
}

Node* Node::getPrev()
{
	return prev;
}

void Node::setValue(DataType _value)
{
	value = _value;
}

void Node::setNext(Node *_next)
{
	next = _next;
}

void Node::setPrev(Node *_prev)
{
	prev = _prev;
}

Node::~Node()
{
}

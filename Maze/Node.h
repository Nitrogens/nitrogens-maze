#pragma once
class Node
{
	/*
		DataType	value	节点的值
		Node		*prev	指向上一个节点的指针
		Node		*next	指向下一个节点的指针
	*/
	DataType value;
	Node *prev, *next;
public:
	/*
		Function Node
		构造函数：用于初始化值
		
		@param	DataType	_value	value的初值
		@param	Node		*next	next的初值
		@param	Node		*prev	prev的初值

		@return void
	*/
	Node(DataType _value = 0, Node *_next = NULL, Node *_prev = NULL);
	/*
		Function getValue
		获取节点的值

		@return DataType
	*/
	DataType getValue();
	/*
		Function getNext
		获取指向下一个节点的指针

		@return Node*
	*/
	Node* getNext();
	/*
		Function getPrev
		获取指向上一个节点的指针

		@return Node*
	*/
	Node* getPrev();
	/*
		Function setValue
		设置节点的值

		@param	DataType	_value	value的值

		@return void
	*/
	void setValue(DataType _value = 0);
	/*
		Function setNext
		设置指向下一个节点的指针

		@param	Node		*next	next的值

		@return void
	*/
	void setNext(Node *_next);
	/*
		Function setPrev
		设置指向上一个节点的指针

		@param	Node		*prev	prev的值

		@return void
	*/
	void setPrev(Node *_prev);
	/*
		Function ~Node
		析构函数

		@return void
	*/
	~Node();
};
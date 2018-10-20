#pragma once
#include "Node.h"
class LinkedList :
	public Node
{
	/*
		Node	*head	指向头节点的指针
		Node	*last	指向最后一个节点的指针
	*/
	Node *head, *last;
public:
	/*
		Function LinkedList
		构造函数：用于初始化值

		@return void
	*/
	LinkedList();
	/*
		Function getHead
		获取指向头节点的指针

		@return Node*
	*/
	Node *getHead();
	/*
		Function getLast
		获取指向最后一个节点的指针

		@return Node*
	*/
	Node *getLast();
	/*
		Function insertNode
		在指定的位置后方插入节点

		@param	DataType	value		新节点的值
		@param	Node		*position	所指定的插入位置

		@return bool	插入是否成功
	*/
	bool insertNode(DataType value, Node *position);
	/*
		Function deleteNode
		删除指定位置的节点

		@param	Node		*position	所指定的删除位置

		@return bool	删除是否成功
	*/
	bool deleteNode(Node *position);
	/*
		Function search
		遍历整个链表，并在每个循环节执行指定的函数

		@param	DataType	data	要查找的数据

		@return Node*	指向节点的指针
	*/
	Node * search(DataType data);
	/*
		Function traverseToFile
		遍历整个链表，并向指定的文件IO类输出数据

		@param	fstream *file	指向文件IO类的指针

		@return bool	遍历是否成功
	*/
	bool traverseToFile(string fileName);
	/*
		Function traverseToScreen
		遍历整个链表，并输出每个节点的数据

		@return bool	遍历是否成功
	*/
	bool traverseToScreen();
	/*
		Function LinkedList
		析构函数：用于释放内存空间

		@return void
	*/
	~LinkedList();
};


#include "stdafx.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = this;	//LinkedList继承自Node, 自身就是头节点
	last = head;
}

Node *LinkedList::getHead()
{
	return head;
}

Node *LinkedList::getLast()
{
	return last;
}

bool LinkedList::insertNode(DataType value, Node *position)
{
	//若目标节点不存在，则返回错误
	if (position == NULL)
		return FAIL;
	Node * pointer = new Node(value, position->getNext(), position);	//创建新节点（即Node类）
	//判断当前节点下一个节点是否存在
	if (position->getNext() != NULL)
		position->getNext()->setPrev(pointer);	//更新当前节点下一个节点的上一个节点
	else
		last = pointer;
	position->setNext(pointer);	//更新当前节点的下一个节点
	return OK;
}

bool LinkedList::deleteNode(Node *position)
{
	//若目标节点不存在或当前节点为头节点，则返回错误
	if (position == NULL || position->getPrev() == NULL)
		return FAIL;
	//判断当前节点下一个节点是否存在
	if (position->getNext() != NULL)
	{
		position->getNext()->setPrev(position->getPrev());	//更新当前节点下一个节点的上一个节点
		position->getPrev()->setNext(position->getNext());	//更新当前节点上一个节点的下一个节点
	}
	else
	{
		last = position->getPrev();
		position->getPrev()->setNext(NULL);	//更新当前节点上一个节点的下一个节点
	}
	delete position;	//释放空间
	return OK;
}

bool LinkedList::search(void (*function)(DataType))
{	
	//判断是否只存在头节点
	if (head->getNext() == NULL)
		return FAIL;
	Node * pointer = head->getNext();
	//若不是尾节点，则向下遍历
	while (pointer != NULL)
	{
		//遍历到的值，传入函数参数中
		function(pointer->getValue());
		//下一个节点
		pointer = pointer->getNext();
	}
	return OK;
}

LinkedList::~LinkedList()
{
	//若只剩下头节点，则结束循环
	while (last->getPrev() != NULL)
	{
		//删除最后一个节点
		deleteNode(last);
	}
}

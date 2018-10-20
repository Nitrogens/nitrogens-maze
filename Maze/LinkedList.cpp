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

Node * LinkedList::search(DataType data)
{	
	//判断是否只存在头节点
	if (head->getNext() == NULL)
		return NULL;
	Node * pointer = head->getNext();
	//若不是尾节点，则向下遍历
	while (pointer != NULL)
	{
		if (data > pointer->getValue() || pointer->getValue() == data)
			return pointer->getPrev();
		//下一个节点
		pointer = pointer->getNext();
	}
	return NULL;
}

bool LinkedList::traverseToFile(string fileName)
{
	// 文件流
	fstream file;
	//打开文件
	file.open(fileName.c_str(), ios::out);
	//判断是否只存在头节点
	if (head->getNext() == NULL)
		return FAIL;
	Node * pointer = head->getNext();
	//若不是尾节点，则向下遍历
	while (pointer != NULL)
	{
		//向文件中输入一行数据
		file << pointer->getValue().getName() << " " << pointer->getValue().getScore() << endl;
		//下一个节点
		pointer = pointer->getNext();
	}
	//关闭文件
	file.close();
	return OK;
}

bool LinkedList::traverseToScreen()
{
	//判断是否只存在头节点
	if (head->getNext() == NULL)
		return FAIL;
	Node * pointer = head->getNext();
	//序号
	int i = 0;
	//若不是尾节点，则向下遍历
	while (pointer != NULL)
	{
		//输出一行数据
		cout << "+--------+---------------+----------+" << endl;
		//获取节点的值
		DataType data = pointer->getValue();
		cout << "|" << setw(8) << (++i)
			<< "|" << setw(15) << data.getName()
			<< "|" << setw(10) << data.getScore()
			<< "|" << endl;
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

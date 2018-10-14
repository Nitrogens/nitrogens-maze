#include "stdafx.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = this;	//LinkedList�̳���Node, �������ͷ�ڵ�
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
	//��Ŀ��ڵ㲻���ڣ��򷵻ش���
	if (position == NULL)
		return FAIL;
	Node * pointer = new Node(value, position->getNext(), position);	//�����½ڵ㣨��Node�ࣩ
	//�жϵ�ǰ�ڵ���һ���ڵ��Ƿ����
	if (position->getNext() != NULL)
		position->getNext()->setPrev(pointer);	//���µ�ǰ�ڵ���һ���ڵ����һ���ڵ�
	else
		last = pointer;
	position->setNext(pointer);	//���µ�ǰ�ڵ����һ���ڵ�
	return OK;
}

bool LinkedList::deleteNode(Node *position)
{
	//��Ŀ��ڵ㲻���ڻ�ǰ�ڵ�Ϊͷ�ڵ㣬�򷵻ش���
	if (position == NULL || position->getPrev() == NULL)
		return FAIL;
	//�жϵ�ǰ�ڵ���һ���ڵ��Ƿ����
	if (position->getNext() != NULL)
	{
		position->getNext()->setPrev(position->getPrev());	//���µ�ǰ�ڵ���һ���ڵ����һ���ڵ�
		position->getPrev()->setNext(position->getNext());	//���µ�ǰ�ڵ���һ���ڵ����һ���ڵ�
	}
	else
	{
		last = position->getPrev();
		position->getPrev()->setNext(NULL);	//���µ�ǰ�ڵ���һ���ڵ����һ���ڵ�
	}
	delete position;	//�ͷſռ�
	return OK;
}

bool LinkedList::search(void (*function)(DataType))
{	
	//�ж��Ƿ�ֻ����ͷ�ڵ�
	if (head->getNext() == NULL)
		return FAIL;
	Node * pointer = head->getNext();
	//������β�ڵ㣬�����±���
	while (pointer != NULL)
	{
		//��������ֵ�����뺯��������
		function(pointer->getValue());
		//��һ���ڵ�
		pointer = pointer->getNext();
	}
	return OK;
}

LinkedList::~LinkedList()
{
	//��ֻʣ��ͷ�ڵ㣬�����ѭ��
	while (last->getPrev() != NULL)
	{
		//ɾ�����һ���ڵ�
		deleteNode(last);
	}
}

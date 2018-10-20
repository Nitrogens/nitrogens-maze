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

Node * LinkedList::search(DataType data)
{	
	//�ж��Ƿ�ֻ����ͷ�ڵ�
	if (head->getNext() == NULL)
		return NULL;
	Node * pointer = head->getNext();
	//������β�ڵ㣬�����±���
	while (pointer != NULL)
	{
		if (data > pointer->getValue() || pointer->getValue() == data)
			return pointer->getPrev();
		//��һ���ڵ�
		pointer = pointer->getNext();
	}
	return NULL;
}

bool LinkedList::traverseToFile(string fileName)
{
	// �ļ���
	fstream file;
	//���ļ�
	file.open(fileName.c_str(), ios::out);
	//�ж��Ƿ�ֻ����ͷ�ڵ�
	if (head->getNext() == NULL)
		return FAIL;
	Node * pointer = head->getNext();
	//������β�ڵ㣬�����±���
	while (pointer != NULL)
	{
		//���ļ�������һ������
		file << pointer->getValue().getName() << " " << pointer->getValue().getScore() << endl;
		//��һ���ڵ�
		pointer = pointer->getNext();
	}
	//�ر��ļ�
	file.close();
	return OK;
}

bool LinkedList::traverseToScreen()
{
	//�ж��Ƿ�ֻ����ͷ�ڵ�
	if (head->getNext() == NULL)
		return FAIL;
	Node * pointer = head->getNext();
	//���
	int i = 0;
	//������β�ڵ㣬�����±���
	while (pointer != NULL)
	{
		//���һ������
		cout << "+--------+---------------+----------+" << endl;
		//��ȡ�ڵ��ֵ
		DataType data = pointer->getValue();
		cout << "|" << setw(8) << (++i)
			<< "|" << setw(15) << data.getName()
			<< "|" << setw(10) << data.getScore()
			<< "|" << endl;
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

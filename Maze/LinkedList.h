#pragma once
#include "Node.h"
class LinkedList :
	public Node
{
	/*
		Node	*head	ָ��ͷ�ڵ��ָ��
		Node	*last	ָ�����һ���ڵ��ָ��
	*/
	Node *head, *last;
public:
	/*
		Function LinkedList
		���캯�������ڳ�ʼ��ֵ

		@return void
	*/
	LinkedList();
	/*
		Function getHead
		��ȡָ��ͷ�ڵ��ָ��

		@return Node*
	*/
	Node *getHead();
	/*
		Function getLast
		��ȡָ�����һ���ڵ��ָ��

		@return Node*
	*/
	Node *getLast();
	/*
		Function insertNode
		��ָ����λ�ú󷽲���ڵ�

		@param	DataType	value		�½ڵ��ֵ
		@param	Node		*position	��ָ���Ĳ���λ��

		@return bool	�����Ƿ�ɹ�
	*/
	bool insertNode(DataType value, Node *position);
	/*
		Function deleteNode
		ɾ��ָ��λ�õĽڵ�

		@param	Node		*position	��ָ����ɾ��λ��

		@return bool	ɾ���Ƿ�ɹ�
	*/
	bool deleteNode(Node *position);
	/*
		Function search
		������������������ÿ��ѭ����ִ��ָ���ĺ���

		@param	void *function(DataType)	��ָ���ĺ���

		@return bool	�����Ƿ�ɹ�
	*/
	bool search(void (*function)(DataType));
	/*
		Function LinkedList
		���������������ͷ��ڴ�ռ�

		@return void
	*/
	~LinkedList();
};

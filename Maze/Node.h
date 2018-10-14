#pragma once
class Node
{
	/*
		DataType	value	�ڵ��ֵ
		Node		*prev	ָ����һ���ڵ��ָ��
		Node		*next	ָ����һ���ڵ��ָ��
	*/
	DataType value;
	Node *prev, *next;
public:
	/*
		Function Node
		���캯�������ڳ�ʼ��ֵ
		
		@param	DataType	_value	value�ĳ�ֵ
		@param	Node		*next	next�ĳ�ֵ
		@param	Node		*prev	prev�ĳ�ֵ

		@return void
	*/
	Node(DataType _value = 0, Node *_next = NULL, Node *_prev = NULL);
	/*
		Function getValue
		��ȡ�ڵ��ֵ

		@return DataType
	*/
	DataType getValue();
	/*
		Function getNext
		��ȡָ����һ���ڵ��ָ��

		@return Node*
	*/
	Node* getNext();
	/*
		Function getPrev
		��ȡָ����һ���ڵ��ָ��

		@return Node*
	*/
	Node* getPrev();
	/*
		Function setValue
		���ýڵ��ֵ

		@param	DataType	_value	value��ֵ

		@return void
	*/
	void setValue(DataType _value = 0);
	/*
		Function setNext
		����ָ����һ���ڵ��ָ��

		@param	Node		*next	next��ֵ

		@return void
	*/
	void setNext(Node *_next);
	/*
		Function setPrev
		����ָ����һ���ڵ��ָ��

		@param	Node		*prev	prev��ֵ

		@return void
	*/
	void setPrev(Node *_prev);
	/*
		Function ~Node
		��������

		@return void
	*/
	~Node();
};
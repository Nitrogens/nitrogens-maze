#pragma once
class FileOp
{

public:
	/*
		Function FileOp
		�����εĹ��캯��

		@param	void

		@return void
	*/
	FileOp();
	/*
		Function getRanklist
		���ļ��ж�ȡ���а����ݵ������У�����ָ�������ָ��

		@param	void

		@return LinkedList*
	*/
	LinkedList * getRanklist();
	/*
		Function updateRanklist
		�������а�ĺ���

		@param	RanklistRecord	data	���а�һ���ڵ�����
		@param	LinkedList		*list	ָ�����а������ָ��

		@return void
	*/
	void updateRanklist(RanklistRecord data, LinkedList * list);
	/*
		Function saveGame
		�浵����

		@param	Game	*G	ָ��Game���ָ��
		@param	Display	*D	ָ��Display���ָ��

		@return void
	*/
	void saveGame(Game *G, Display *D);
	/*
		Function readGame
		��������

		@param	Game	*G	ָ��Game���ָ��
		@param	Display	*D	ָ��Display���ָ��

		@return void
	*/
	void readGame(Game *G, Display *D);
	~FileOp();
};


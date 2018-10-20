#pragma once
class FileOp
{

public:
	/*
		Function FileOp
		不含参的构造函数

		@param	void

		@return void
	*/
	FileOp();
	/*
		Function getRanklist
		从文件中读取排行榜数据到链表中，返回指向链表的指针

		@param	void

		@return LinkedList*
	*/
	LinkedList * getRanklist();
	/*
		Function updateRanklist
		更新排行榜的函数

		@param	RanklistRecord	data	排行榜一行内的数据
		@param	LinkedList		*list	指向排行榜链表的指针

		@return void
	*/
	void updateRanklist(RanklistRecord data, LinkedList * list);
	/*
		Function saveGame
		存档函数

		@param	Game	*G	指向Game类的指针
		@param	Display	*D	指向Display类的指针

		@return void
	*/
	void saveGame(Game *G, Display *D);
	/*
		Function readGame
		读档函数

		@param	Game	*G	指向Game类的指针
		@param	Display	*D	指向Display类的指针

		@return void
	*/
	void readGame(Game *G, Display *D);
	~FileOp();
};


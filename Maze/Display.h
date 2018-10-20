#pragma once
#include "Game.h"
class Display
{
public:
	/*
		Function Display
		不含参的构造函数

		@param	void

		@return void
	*/
	Display();
	/*
		Function clearScreen
		清屏函数

		@param	void

		@return void
	*/
	void clearScreen();
	/*
		Function gotoXY
		将光标移向指定节点的函数

		@param	int	x	要移动到的横坐标
		@param	int	y	要移动到的纵坐标

		@return void
	*/
	void gotoXY(int x, int y);
	/*
		Function printMaze
		输出迷宫的函数

		@param	Game *G	指向Game类的指针

		@return void
	*/
	void printMaze(Game * G);
	/*
		Function printMove
		输出玩家移动后的迷宫的函数

		@param	Game		*G	指向Game类的指针
		@param	direction	D	移动方向

		@return void
	*/
	void printMove(Game *G, direction D);
	/*
		Function printGuidance
		输出开始界面的函数

		@param	void

		@return void
	*/
	void printGuidance();
	/*
		Function printGuidance
		输出排行榜的函数

		@param	void

		@return void
	*/
	void printRankList();
	/*
		Function printInstruction
		输出游戏说明的函数

		@param	void

		@return void
	*/
	void printInstruction();
	~Display();
};
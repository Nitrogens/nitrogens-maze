#pragma once
#include "Game.h"
class Display
{
public:
	/*
		Function Display
		�����εĹ��캯��

		@param	void

		@return void
	*/
	Display();
	/*
		Function clearScreen
		��������

		@param	void

		@return void
	*/
	void clearScreen();
	/*
		Function gotoXY
		���������ָ���ڵ�ĺ���

		@param	int	x	Ҫ�ƶ����ĺ�����
		@param	int	y	Ҫ�ƶ�����������

		@return void
	*/
	void gotoXY(int x, int y);
	/*
		Function printMaze
		����Թ��ĺ���

		@param	Game *G	ָ��Game���ָ��

		@return void
	*/
	void printMaze(Game * G);
	/*
		Function printMove
		�������ƶ�����Թ��ĺ���

		@param	Game		*G	ָ��Game���ָ��
		@param	direction	D	�ƶ�����

		@return void
	*/
	void printMove(Game *G, direction D);
	/*
		Function printGuidance
		�����ʼ����ĺ���

		@param	void

		@return void
	*/
	void printGuidance();
	/*
		Function printGuidance
		������а�ĺ���

		@param	void

		@return void
	*/
	void printRankList();
	/*
		Function printInstruction
		�����Ϸ˵���ĺ���

		@param	void

		@return void
	*/
	void printInstruction();
	~Display();
};
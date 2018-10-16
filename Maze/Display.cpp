#include "stdafx.h"
#include "Display.h"


Display::Display()
{
}

void Display::clearScreen()
{
	system("cls");	//调用系统命令，进行清屏操作
}

void Display::printMaze(Game * G, int x, int y)
{
	clearScreen();	//清空屏幕
	for (int i = 0; i < 2 * SIZE + 1; i++)
	{
		for (int j = 0; j < 2 * SIZE + 1; j++)
		{
			if (i == x && j == y)	//角色所在位置
				cout << "☉";
			else
			{
				if (G->getMatrix(i, j))
					cout << "  ";	//地板
				else
					cout << "█";	//墙
			}
		}
		cout << endl;
	}
}

void Display::printGuidance()
{
	clearScreen();	//清空屏幕
	cout << "+-------+-------+-------+-------+" << endl;
	cout << "|                               |" << endl;
	cout << "|   M       a       z       e   |" << endl;
	cout << "|                               |" << endl;
	cout << "+-------+-------+-------+-------+" << endl;
	cout << "|       |                       |" << endl;
	cout << "|   A   |        开始游戏       |" << endl;
	cout << "|       |                       |" << endl;
	cout << "+-------+-------+-------+-------+" << endl;
	cout << "|       |                       |" << endl;
	cout << "|   B   |         排行榜        |" << endl;
	cout << "|       |                       |" << endl;
	cout << "+-------+-------+-------+-------+" << endl;
	cout << "|       |                       |" << endl;
	cout << "|   C   |        游戏说明       |" << endl;
	cout << "|       |                       |" << endl;
	cout << "+-------+-------+-------+-------+" << endl;
	cout << "|       |                       |" << endl;
	cout << "|   D   |        退出游戏       |" << endl;
	cout << "|       |                       |" << endl;
	cout << "+-------+-------+-------+-------+" << endl;
	cout << "Copyright 2018 Nitrogens(Mingjie XU)." << endl;
	cout << "Licensed under the MIT License." << endl;
}

void Display::printRankList()
{

}

void Display::printInstruction()
{
	clearScreen();	//清空屏幕
	cout << "+-----------------------------------+" << endl;
	cout << "|                                   |" << endl;
	cout << "|              游戏说明             |" << endl;
	cout << "|                                   |" << endl;
	cout << "+-----------------------------------+" << endl;
	cout << "|1. 按方向键控制移动；              |" << endl;
	cout << "+-----------------------------------+" << endl;
	cout << "|2. 按S来保存游戏，按R来读取游戏；  |" << endl;
	cout << "+-----------------------------------+" << endl;
	cout << "|3. 按P键存档并退出，按L键直接退出；|" << endl;
	cout << "+-----------------------------------+" << endl;
	cout << "|4. 走到终点，游戏胜利；           |" << endl;
	cout << "+-----------------------------------+" << endl;
	cout << "|5. 祝您游戏愉快！                  |" << endl;
	cout << "+-----------------------------------+" << endl;
}

Display::~Display()
{
}

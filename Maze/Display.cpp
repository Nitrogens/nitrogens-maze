#include "stdafx.h"
#include "Display.h"


Display::Display()
{
}

void Display::clearScreen()
{
	system("cls");	//调用系统命令，进行清屏操作
}

void Display::gotoXY(int x, int y)
{
	COORD point;	//存储光标的坐标
	HANDLE handle;	//用于控制输出的句柄
	point.X = x;	//设置纵坐标
	point.Y = y;	//设置横坐标
	handle = GetStdHandle(STD_OUTPUT_HANDLE);	//获取输出句柄，并赋值给handle
	SetConsoleCursorPosition(handle, point);	//调用API设置光标位置
}

void Display::printMaze(Game * G)
{
	clearScreen();	//清空屏幕
	for (int i = 0; i < 2 * MAZESIZE + 1; i++)
	{
		for (int j = 0; j < 2 * MAZESIZE + 1; j++)
		{
			P currentPosition = G->getPosition();	//获取角色当前位置
			if (i == currentPosition.first && j == currentPosition.second)	//角色所在位置
				cout << "☉";
			else if (i == 2 * MAZESIZE - 1 && j == 2 * MAZESIZE - 1)	//输出终点
				cout << "★";
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
	cout << "+-----------------------------+" << endl;
	cout << "| S | 保存游戏 | R | 读取游戏 |" << endl;
	cout << "+-----------------------------+" << endl;
	cout << "| P | 存档退出 | L | 直接退出 |" << endl;
	cout << "+-----------------------------+" << endl;
	cout << "| 步数 |" << setw(21) << G->getNumberOfSteps() << " |" << endl;
	cout << "+-----------------------------+" << endl;
}

void Display::printMove(Game *G, direction D)
{
	P currentPosition = G->getPosition();	//获取角色当前位置
	//计算角色上一步位置
	int ox = currentPosition.first - sx[D];
	int oy = currentPosition.second - sy[D];
	//移动光标到上一步的位置
	gotoXY(2 * oy, ox);
	//将上一步的位置置为空格
	cout << " ";
	//移动光标到角色当前位置
	gotoXY(2 * currentPosition.second, currentPosition.first);
	//输出角色的新位置
	cout << "☉";
	//光标移动到最后一行
	gotoXY(0, 2 * MAZESIZE + 6);
	//输出步数
	cout << "| 步数 |" << setw(21) << G->getNumberOfSteps() << " |" << endl;
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
	//实例化控制文件操作的类
	FileOp *file = new FileOp();
	//实例化链表类
	LinkedList *list = file->getRanklist();
	clearScreen();
	cout << "+--------+----------------+---------+" << endl;
	cout << "|                                   |" << endl;
	cout << "|               排行榜              |" << endl;
	cout << "|                                   |" << endl;
	cout << "+--------+---------------+----------+" << endl;
	cout << "|  排名  |      姓名     |   得分   |" << endl;
	
	//遍历整个链表，并将数据输出
	list->traverseToScreen();

	cout << "+--------+---------------+----------+" << endl;
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
	cout << "|4. 走到终点（右下角），游戏胜利；  |" << endl;
	cout << "+-----------------------------------+" << endl;
	cout << "|5. 祝您游戏愉快！                  |" << endl;
	cout << "+-----------------------------------+" << endl;
}

Display::~Display()
{
}

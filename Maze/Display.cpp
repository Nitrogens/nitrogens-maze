#include "stdafx.h"
#include "Display.h"


Display::Display()
{
}

void Display::clearScreen()
{
	system("cls");	//����ϵͳ���������������
}

void Display::printMaze(Game * G, int x, int y)
{
	clearScreen();	//�����Ļ
	for (int i = 0; i < 2 * SIZE + 1; i++)
	{
		for (int j = 0; j < 2 * SIZE + 1; j++)
		{
			if (i == x && j == y)	//��ɫ����λ��
				cout << "��";
			else
			{
				if (G->getMatrix(i, j))
					cout << "  ";	//�ذ�
				else
					cout << "��";	//ǽ
			}
		}
		cout << endl;
	}
}

void Display::printGuidance()
{
	clearScreen();	//�����Ļ
	cout << "+-------+-------+-------+-------+" << endl;
	cout << "|                               |" << endl;
	cout << "|   M       a       z       e   |" << endl;
	cout << "|                               |" << endl;
	cout << "+-------+-------+-------+-------+" << endl;
	cout << "|       |                       |" << endl;
	cout << "|   A   |        ��ʼ��Ϸ       |" << endl;
	cout << "|       |                       |" << endl;
	cout << "+-------+-------+-------+-------+" << endl;
	cout << "|       |                       |" << endl;
	cout << "|   B   |         ���а�        |" << endl;
	cout << "|       |                       |" << endl;
	cout << "+-------+-------+-------+-------+" << endl;
	cout << "|       |                       |" << endl;
	cout << "|   C   |        ��Ϸ˵��       |" << endl;
	cout << "|       |                       |" << endl;
	cout << "+-------+-------+-------+-------+" << endl;
	cout << "|       |                       |" << endl;
	cout << "|   D   |        �˳���Ϸ       |" << endl;
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
	clearScreen();	//�����Ļ
	cout << "+-----------------------------------+" << endl;
	cout << "|                                   |" << endl;
	cout << "|              ��Ϸ˵��             |" << endl;
	cout << "|                                   |" << endl;
	cout << "+-----------------------------------+" << endl;
	cout << "|1. ������������ƶ���              |" << endl;
	cout << "+-----------------------------------+" << endl;
	cout << "|2. ��S��������Ϸ����R����ȡ��Ϸ��  |" << endl;
	cout << "+-----------------------------------+" << endl;
	cout << "|3. ��P���浵���˳�����L��ֱ���˳���|" << endl;
	cout << "+-----------------------------------+" << endl;
	cout << "|4. �ߵ��յ㣬��Ϸʤ����           |" << endl;
	cout << "+-----------------------------------+" << endl;
	cout << "|5. ף����Ϸ��죡                  |" << endl;
	cout << "+-----------------------------------+" << endl;
}

Display::~Display()
{
}

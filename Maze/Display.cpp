#include "stdafx.h"
#include "Display.h"


Display::Display()
{
}

void Display::clearScreen()
{
	system("cls");	//����ϵͳ���������������
}

void Display::gotoXY(int x, int y)
{
	COORD point;	//�洢��������
	HANDLE handle;	//���ڿ�������ľ��
	point.X = x;	//����������
	point.Y = y;	//���ú�����
	handle = GetStdHandle(STD_OUTPUT_HANDLE);	//��ȡ������������ֵ��handle
	SetConsoleCursorPosition(handle, point);	//����API���ù��λ��
}

void Display::printMaze(Game * G)
{
	clearScreen();	//�����Ļ
	for (int i = 0; i < 2 * MAZESIZE + 1; i++)
	{
		for (int j = 0; j < 2 * MAZESIZE + 1; j++)
		{
			P currentPosition = G->getPosition();	//��ȡ��ɫ��ǰλ��
			if (i == currentPosition.first && j == currentPosition.second)	//��ɫ����λ��
				cout << "��";
			else if (i == 2 * MAZESIZE - 1 && j == 2 * MAZESIZE - 1)	//����յ�
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
	cout << "+-----------------------------+" << endl;
	cout << "| S | ������Ϸ | R | ��ȡ��Ϸ |" << endl;
	cout << "+-----------------------------+" << endl;
	cout << "| P | �浵�˳� | L | ֱ���˳� |" << endl;
	cout << "+-----------------------------+" << endl;
	cout << "| ���� |" << setw(21) << G->getNumberOfSteps() << " |" << endl;
	cout << "+-----------------------------+" << endl;
}

void Display::printMove(Game *G, direction D)
{
	P currentPosition = G->getPosition();	//��ȡ��ɫ��ǰλ��
	//�����ɫ��һ��λ��
	int ox = currentPosition.first - sx[D];
	int oy = currentPosition.second - sy[D];
	//�ƶ���굽��һ����λ��
	gotoXY(2 * oy, ox);
	//����һ����λ����Ϊ�ո�
	cout << " ";
	//�ƶ���굽��ɫ��ǰλ��
	gotoXY(2 * currentPosition.second, currentPosition.first);
	//�����ɫ����λ��
	cout << "��";
	//����ƶ������һ��
	gotoXY(0, 2 * MAZESIZE + 6);
	//�������
	cout << "| ���� |" << setw(21) << G->getNumberOfSteps() << " |" << endl;
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
	//ʵ���������ļ���������
	FileOp *file = new FileOp();
	//ʵ����������
	LinkedList *list = file->getRanklist();
	clearScreen();
	cout << "+--------+----------------+---------+" << endl;
	cout << "|                                   |" << endl;
	cout << "|               ���а�              |" << endl;
	cout << "|                                   |" << endl;
	cout << "+--------+---------------+----------+" << endl;
	cout << "|  ����  |      ����     |   �÷�   |" << endl;
	
	//�����������������������
	list->traverseToScreen();

	cout << "+--------+---------------+----------+" << endl;
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
	cout << "|4. �ߵ��յ㣨���½ǣ�����Ϸʤ����  |" << endl;
	cout << "+-----------------------------------+" << endl;
	cout << "|5. ף����Ϸ��죡                  |" << endl;
	cout << "+-----------------------------------+" << endl;
}

Display::~Display()
{
}

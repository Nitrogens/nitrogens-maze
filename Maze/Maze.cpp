#include "stdafx.h"
void playGame(Display *UI)
{
	//实例化控制游戏逻辑进程的类
	Game *gameProcess = new Game(1, 1);
	//实例化控制文件操作的类
	FileOp *file = new FileOp();
	//随机生成新的迷宫
	gameProcess->makeMaze(1, 1);
	//输出迷宫
	UI->printMaze(gameProcess);
	//开始计时
	gameProcess->startGame();

	while (true)
	{
		//若走到终点，则游戏结束，跳出循环
		if (gameProcess->isEnd())
			break;
		if (int ch1 = _getch())
		{
			switch (ch1)
			{
			case 224:	//若监测到方向键，则需进行二次监测
				switch (int ch2 = _getch())
				{
				case 72:	//监测到上方向键
					//尝试移动，若移动成功，则更新屏幕（局部更新）
					if (gameProcess->playerMove(north))
						UI->printMove(gameProcess, north);
					break;

				case 80:	//监测到下方向键
					//尝试移动，若移动成功，则更新屏幕（局部更新）
					if (gameProcess->playerMove(south))
						UI->printMove(gameProcess, south);
					break;

				case 75:	//监测到左方向键
					//尝试移动，若移动成功，则更新屏幕（局部更新）
					if (gameProcess->playerMove(west))
						UI->printMove(gameProcess, west);
					break;

				case 77:	//监测到右方向键
					//尝试移动，若移动成功，则更新屏幕（局部更新）
					if (gameProcess->playerMove(east))
						UI->printMove(gameProcess, east);
					break;
				}
				break;
			case 115:	//按下"S"键，进行存档操作
				file->saveGame(gameProcess, UI);
				continue;
				break;

			case 114:	//按下"R"键，进行读档操作
				file->readGame(gameProcess, UI);
				//重新输出迷宫
				UI->printMaze(gameProcess);
				continue;
				break;

			case 112:    //按下"P"键，保存并退出
				file->saveGame(gameProcess, UI);
				return;
				break;

			case 108:	//按下"L"键，直接退出
				return;
				break;
			}
		}
	}
	//移动到显示步数那一行的下一行
	UI->gotoXY(0, 2 * MAZESIZE + 8);
	//玩家姓名
	string name;
	//玩家得分
	int score;
	//排行榜中的一行数据
	RanklistRecord line;
	cout << "游戏结束！" << endl;
	score = gameProcess->calcScore();
	cout << "您的得分是：" << score << endl;
	cout << "请输入您的姓名：";
	cin >> name;
	line.setName(name);
	//设置游戏分数
	line.setScore(score);
	//更新排行榜
	file->updateRanklist(line, file->getRanklist());
}
int main(void)
{
	//实例化控制UI的类
	Display *UI = new Display();
	while (true)
	{
		UI->printGuidance();	//输出开始界面
		if (char ch = _getch())	//监测键盘输入
		{
			switch (ch)
			{
			case 97:	//键盘按下A
				playGame(UI);
				printf("请按任意键继续：");
				//等待按键输入
				if (_getch());
				break;

			case 98:	//键盘按下B
				UI->printRankList();	//输出排行榜
				printf("请按任意键继续：");
				//等待按键输入
				if (_getch());
				break;

			case 99:	//键盘按下C
				UI->printInstruction();	//输出游戏说明
				printf("请按任意键继续：");
				//等待按键输入
				if (_getch());
				break;

			case 100:	//键盘按下D
				return 0;	//结束程序
				break;
			}
		}
	}

	system("pause");

    return 0;
}


#include "stdafx.h"
#include "Game.h"

Game::Game(int _x, int _y) : x(_x), y(_y)
{
	//初始化记录访问情况的数组
	memset(isVisited, false, sizeof(isVisited));
	//清空栈
	while (!step.empty())
		step.pop();
}

void Game::makeMaze(int x, int y)
{
	isVisited[x][y] = true;	//将起点标记为已访问
	srand((unsigned int)time(NULL));	//将当前时间设置为随机数种子
	do
	{
		string directions;	//存储可以走到且未被访问过的方向
		for (int i = 0; i < 4; i++)
		{
			//计算目标节点的坐标
			int tx = x + dx[i];
			int ty = y + dy[i];
			//判断坐标的合法性和是否被访问过
			if (tx >= 0 && tx < 2 * SIZE + 1 && ty >= 0 && ty < 2 * SIZE + 1 && !isVisited[tx][ty])
				directions += i;
		}
		if (directions.length() > 0)
		{
			step.push(P(x, y));	//将当前节点压入栈
			//随机生成方向
			int id = rand() % directions.length();
			id = directions[id];
			//计算目标节点坐标
			int tx = x + dx[id];
			int ty = y + dy[id];
			//将目标节点设置为已访问
			isVisited[tx][ty] = true;
			//计算当前节点与目标节点中间节点的坐标
			int midx = (x + tx) >> 1;
			int midy = (y + ty) >> 1;
			//将中间节点设置为已访问
			isVisited[midx][midy] = true;
			//将目标节点作为新的当前节点
			x = tx;
			y = ty;
		}
		else if(!step.empty())	
		{
			//若当前节点四周已无可以访问的节点，则将栈顶坐标作为当前坐标，并进行弹栈操作
			P newPoint = step.top();
			step.pop();
			x = newPoint.first;
			y = newPoint.second;
		}
	} while (!step.empty());	//若栈为空，证明迷宫生成完毕
	//已访问过的节点为地板，未访问过的节点为墙壁
	memcpy(matrix, isVisited, sizeof(isVisited));
}

bool Game::getMatrix(int x, int y)
{
	//返回指定坐标的情况
	return matrix[x][y];
}

void Game::playerMove(direction D)
{
	//计算目标节点坐标
	int tx = x + sx[D];
	int ty = y + sy[D];
	//若目标节点不是墙，则进行移动
	if (matrix[tx][ty])
	{
		//更新当前坐标
		x = tx;
		y = ty;
		//步数加一
		numberOfSteps++;
	}
}

bool Game::isEnd()
{
	//返回当前节点是否为终点，若为终点，则游戏结束
	return (x == 2 * SIZE - 1 && y == 2 * SIZE - 1);
}

Game::~Game()
{
}

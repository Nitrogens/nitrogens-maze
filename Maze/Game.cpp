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
			if (tx >= 0 && tx < 2 * MAZESIZE + 1 && ty >= 0 && ty < 2 * MAZESIZE + 1 && !isVisited[tx][ty])
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

int Game::getBestSolution()
{
	//清空记录访问情况的数组
	memset(isVisited, false, sizeof(isVisited));
	//广度优先搜索所用队列
	queue <BFSNode> Q;
	//将起点压入队列中
	Q.push(BFSNode(1, 1, 0));
	//队列非空，则取队首节点，并分析其四周可以走的点
	while (!Q.empty())
	{
		BFSNode currentNode = Q.front();
		Q.pop();

		isVisited[currentNode.x][currentNode.y] = true;

		//判断是否走到终点
		if (currentNode.x == 2 * MAZESIZE - 1 && currentNode.y == 2 * MAZESIZE - 1)
			return currentNode.numberOfSteps;

		for (int i = 0; i < 4; i++)
		{
			int tx = currentNode.x + sx[i];
			int ty = currentNode.y + sy[i];
			//坐标合法性判断
			if (tx >= 0 && tx < 2 * MAZESIZE + 1 && ty >= 0 && ty < 2 * MAZESIZE + 1 && !isVisited[tx][ty] && matrix[tx][ty])
				Q.push(BFSNode(tx, ty, currentNode.numberOfSteps + 1));
		}
	}
}

bool Game::getMatrix(int x, int y)
{
	//返回指定坐标的情况
	return matrix[x][y];
}

bool Game::playerMove(direction D)
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
		//返回移动成功的信息
		return true;
	}
	//返回移动失败的信息
	return false;
}

P Game::getPosition()
{
	return P(x, y);
}

int Game::getNumberOfSteps()
{
	return numberOfSteps;
}

bool Game::isEnd()
{
	//返回当前节点是否为终点，若为终点，则游戏结束
	return (x == 2 * MAZESIZE - 1 && y == 2 * MAZESIZE - 1);
}

void Game::startGame()
{
	//设置开始时间，相当于开始计时
	startTime = time(NULL);
}

int Game::calcScore()
{
	//获取结束时间
	time_t endTime = time(NULL);
	//计算持续时长
	int length = difftime(endTime, startTime);
	//计算分数
	int score = 10000 - 100 * (numberOfSteps - getBestSolution()) - 10 * length;
	if (score < 0)
		score = 0;
	return score;
}

Game::~Game()
{
}

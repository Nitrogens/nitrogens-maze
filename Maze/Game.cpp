#include "stdafx.h"
#include "Game.h"

Game::Game(int _x, int _y) : x(_x), y(_y)
{
	//��ʼ����¼�������������
	memset(isVisited, false, sizeof(isVisited));
	//���ջ
	while (!step.empty())
		step.pop();
}

void Game::makeMaze(int x, int y)
{
	isVisited[x][y] = true;	//�������Ϊ�ѷ���
	srand((unsigned int)time(NULL));	//����ǰʱ������Ϊ���������
	do
	{
		string directions;	//�洢�����ߵ���δ�����ʹ��ķ���
		for (int i = 0; i < 4; i++)
		{
			//����Ŀ��ڵ������
			int tx = x + dx[i];
			int ty = y + dy[i];
			//�ж�����ĺϷ��Ժ��Ƿ񱻷��ʹ�
			if (tx >= 0 && tx < 2 * MAZESIZE + 1 && ty >= 0 && ty < 2 * MAZESIZE + 1 && !isVisited[tx][ty])
				directions += i;
		}
		if (directions.length() > 0)
		{
			step.push(P(x, y));	//����ǰ�ڵ�ѹ��ջ
			//������ɷ���
			int id = rand() % directions.length();
			id = directions[id];
			//����Ŀ��ڵ�����
			int tx = x + dx[id];
			int ty = y + dy[id];
			//��Ŀ��ڵ�����Ϊ�ѷ���
			isVisited[tx][ty] = true;
			//���㵱ǰ�ڵ���Ŀ��ڵ��м�ڵ������
			int midx = (x + tx) >> 1;
			int midy = (y + ty) >> 1;
			//���м�ڵ�����Ϊ�ѷ���
			isVisited[midx][midy] = true;
			//��Ŀ��ڵ���Ϊ�µĵ�ǰ�ڵ�
			x = tx;
			y = ty;
		}
		else if(!step.empty())	
		{
			//����ǰ�ڵ��������޿��Է��ʵĽڵ㣬��ջ��������Ϊ��ǰ���꣬�����е�ջ����
			P newPoint = step.top();
			step.pop();
			x = newPoint.first;
			y = newPoint.second;
		}
	} while (!step.empty());	//��ջΪ�գ�֤���Թ��������
	//�ѷ��ʹ��Ľڵ�Ϊ�ذ壬δ���ʹ��Ľڵ�Ϊǽ��
	memcpy(matrix, isVisited, sizeof(isVisited));
}

int Game::getBestSolution()
{
	//��ռ�¼�������������
	memset(isVisited, false, sizeof(isVisited));
	//��������������ö���
	queue <BFSNode> Q;
	//�����ѹ�������
	Q.push(BFSNode(1, 1, 0));
	//���зǿգ���ȡ���׽ڵ㣬�����������ܿ����ߵĵ�
	while (!Q.empty())
	{
		BFSNode currentNode = Q.front();
		Q.pop();

		isVisited[currentNode.x][currentNode.y] = true;

		//�ж��Ƿ��ߵ��յ�
		if (currentNode.x == 2 * MAZESIZE - 1 && currentNode.y == 2 * MAZESIZE - 1)
			return currentNode.numberOfSteps;

		for (int i = 0; i < 4; i++)
		{
			int tx = currentNode.x + sx[i];
			int ty = currentNode.y + sy[i];
			//����Ϸ����ж�
			if (tx >= 0 && tx < 2 * MAZESIZE + 1 && ty >= 0 && ty < 2 * MAZESIZE + 1 && !isVisited[tx][ty] && matrix[tx][ty])
				Q.push(BFSNode(tx, ty, currentNode.numberOfSteps + 1));
		}
	}
}

bool Game::getMatrix(int x, int y)
{
	//����ָ����������
	return matrix[x][y];
}

bool Game::playerMove(direction D)
{
	//����Ŀ��ڵ�����
	int tx = x + sx[D];
	int ty = y + sy[D];
	//��Ŀ��ڵ㲻��ǽ��������ƶ�
	if (matrix[tx][ty])
	{
		//���µ�ǰ����
		x = tx;
		y = ty;
		//������һ
		numberOfSteps++;
		//�����ƶ��ɹ�����Ϣ
		return true;
	}
	//�����ƶ�ʧ�ܵ���Ϣ
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
	//���ص�ǰ�ڵ��Ƿ�Ϊ�յ㣬��Ϊ�յ㣬����Ϸ����
	return (x == 2 * MAZESIZE - 1 && y == 2 * MAZESIZE - 1);
}

void Game::startGame()
{
	//���ÿ�ʼʱ�䣬�൱�ڿ�ʼ��ʱ
	startTime = time(NULL);
}

int Game::calcScore()
{
	//��ȡ����ʱ��
	time_t endTime = time(NULL);
	//�������ʱ��
	int length = difftime(endTime, startTime);
	//�������
	int score = 10000 - 100 * (numberOfSteps - getBestSolution()) - 10 * length;
	if (score < 0)
		score = 0;
	return score;
}

Game::~Game()
{
}

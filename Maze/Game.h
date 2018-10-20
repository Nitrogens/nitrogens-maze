#pragma once
//广度优先搜索时压入队列的节点
struct BFSNode
{
	/*
		int	x				当前节点的纵坐标
		int	y				当前节点的横坐标
		int numberOfSteps	当前节点已走过的步数
	*/
	int x;
	int y;
	int numberOfSteps;

	BFSNode(int _x, int _y, int _numberOfSteps):
		x(_x), y(_y), numberOfSteps(_numberOfSteps) {}
};
class Game
{
	/*
		int		x				当前纵坐标
		int		y				当前横坐标
		int		numberOfSteps	已经走过的步数
		time_t	startTime		游戏开始的时间
		bool	isVisited[][]	标记节点是否被访问过的数组（用于迷宫生成环节）
		bool	matrix[][]		记录迷宫结构的数组，1为墙，0为地板
		stack	step			存储已经走过的节点的栈（用于迷宫生成环节）
	*/
	int x;
	int y;
	int numberOfSteps;
	time_t startTime;
	bool isVisited[2 * MAZESIZE + 1][2 * MAZESIZE + 1];
	bool matrix[2 * MAZESIZE + 1][2 * MAZESIZE + 1];
	stack <pair<int, int> > step;
public:
	/*
		Function Game
		构造函数：用于初始化变量和数组，并清空栈

		@return void
	*/
	Game(int _x, int _y);
	/*
		Function makeMaze
		用于随机生成迷宫的函数
		采用深度优先搜索(DFS)算法
		鸣谢：
			(1)https://www.jianshu.com/p/26798290ed43
			(2)https://blog.csdn.net/juzihongle1/article/details/73135920
			(3)https://blog.csdn.net/qq_36278071/article/details/73199252
			(4)https://blog.csdn.net/dark00800/article/details/76359988

		@param	int	x	起点的纵坐标
		@param	int y	起点的横坐标

		@return void
	*/
	void makeMaze(int x, int y);
	/*
		Function getBestSolution
		获取迷宫求解最少步数的函数
		（利用广度优先搜索）

		@return int
	*/
	int getBestSolution();
	/*
		Function getMatrix
		获取迷宫中某个坐标情况的函数

		@param	int	x	纵坐标
		@param	int y	横坐标

		@return bool
	*/
	bool getMatrix(int x, int y);
	/*
		Function playerMove
		处理角色移动的函数

		@param	direction	D	移动方向

		@return bool	true表明成功移动
	*/
	bool playerMove(direction D);
	/*
		Function getPosition
		获取玩家当前坐标

		@param void

		@return pair<int, int>
	*/
	P getPosition();
	/*
		Function getNumberOfSteps
		获取玩家当前已走步数

		@param void

		@return int
	*/
	int getNumberOfSteps();
	/*
		Function isEnd
		判断游戏是否结束的函数

		@param void

		@return bool
	*/
	bool isEnd();
	/*
		Function startGame
		负责游戏开始时的开始计时操作

		@param void

		@return void
	*/
	void startGame();
	/*
		Function calcScore
		计算游戏分数

		@param void

		@return int
	*/
	int calcScore();
	~Game();
};


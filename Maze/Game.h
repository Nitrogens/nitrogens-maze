#pragma once
//�����������ʱѹ����еĽڵ�
struct BFSNode
{
	/*
		int	x				��ǰ�ڵ��������
		int	y				��ǰ�ڵ�ĺ�����
		int numberOfSteps	��ǰ�ڵ����߹��Ĳ���
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
		int		x				��ǰ������
		int		y				��ǰ������
		int		numberOfSteps	�Ѿ��߹��Ĳ���
		time_t	startTime		��Ϸ��ʼ��ʱ��
		bool	isVisited[][]	��ǽڵ��Ƿ񱻷��ʹ������飨�����Թ����ɻ��ڣ�
		bool	matrix[][]		��¼�Թ��ṹ�����飬1Ϊǽ��0Ϊ�ذ�
		stack	step			�洢�Ѿ��߹��Ľڵ��ջ�������Թ����ɻ��ڣ�
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
		���캯�������ڳ�ʼ�����������飬�����ջ

		@return void
	*/
	Game(int _x, int _y);
	/*
		Function makeMaze
		������������Թ��ĺ���
		���������������(DFS)�㷨
		��л��
			(1)https://www.jianshu.com/p/26798290ed43
			(2)https://blog.csdn.net/juzihongle1/article/details/73135920
			(3)https://blog.csdn.net/qq_36278071/article/details/73199252
			(4)https://blog.csdn.net/dark00800/article/details/76359988

		@param	int	x	����������
		@param	int y	���ĺ�����

		@return void
	*/
	void makeMaze(int x, int y);
	/*
		Function getBestSolution
		��ȡ�Թ�������ٲ����ĺ���
		�����ù������������

		@return int
	*/
	int getBestSolution();
	/*
		Function getMatrix
		��ȡ�Թ���ĳ����������ĺ���

		@param	int	x	������
		@param	int y	������

		@return bool
	*/
	bool getMatrix(int x, int y);
	/*
		Function playerMove
		�����ɫ�ƶ��ĺ���

		@param	direction	D	�ƶ�����

		@return bool	true�����ɹ��ƶ�
	*/
	bool playerMove(direction D);
	/*
		Function getPosition
		��ȡ��ҵ�ǰ����

		@param void

		@return pair<int, int>
	*/
	P getPosition();
	/*
		Function getNumberOfSteps
		��ȡ��ҵ�ǰ���߲���

		@param void

		@return int
	*/
	int getNumberOfSteps();
	/*
		Function isEnd
		�ж���Ϸ�Ƿ�����ĺ���

		@param void

		@return bool
	*/
	bool isEnd();
	/*
		Function startGame
		������Ϸ��ʼʱ�Ŀ�ʼ��ʱ����

		@param void

		@return void
	*/
	void startGame();
	/*
		Function calcScore
		������Ϸ����

		@param void

		@return int
	*/
	int calcScore();
	~Game();
};


#pragma once
typedef pair<int, int> P;
class Game
{
	/*
		int		x				��ǰ������
		int		y				��ǰ������
		int		numberOfSteps	�Ѿ��߹��Ĳ���
		bool	isVisited[][]	��ǽڵ��Ƿ񱻷��ʹ������飨�����Թ����ɻ��ڣ�
		bool	matrix[][]		��¼�Թ��ṹ�����飬1Ϊǽ��0Ϊ�ذ�
		stack	step			�洢�Ѿ��߹��Ľڵ��ջ�������Թ����ɻ��ڣ�
	*/
	int x;
	int y;
	int numberOfSteps;
	bool isVisited[2 * SIZE + 1][2 * SIZE + 1];
	bool matrix[2 * SIZE + 1][2 * SIZE + 1];
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

		@return void
	*/
	void playerMove(direction D);
	/*
		Function isEnd
		�ж���Ϸ�Ƿ�����ĺ���

		@param void

		@return bool
	*/
	bool isEnd();
	~Game();
};


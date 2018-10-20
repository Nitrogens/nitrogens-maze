#pragma once
//��ʾ���а���һ�����ݵ���
class RanklistRecord
{
	/*
		string	name	����
		string	score	����
	*/
	string name;
	int score;

public:
	/*
		Function RanklistRecord
		�����εĹ��캯��

		@param	void

		@return void
	*/
	RanklistRecord();
	/*
		Function RanklistRecord
		���εĹ��캯������ʼ�����Ե�ֵ

		@param	string	_name	���������
		@param	int		_score	����ķ���

		@return void
	*/
	RanklistRecord(string _name, int _score);
	/*
		Function getName
		��ȡ�����ĺ���

		@param	void

		@return string
	*/
	string getName();
	/*
		Function getScore
		��ȡ�����ĺ���

		@param	void

		@return int
	*/
	int getScore();
	/*
		Function setName
		���������ĺ���

		@param	string _name	����

		@return void
	*/
	void setName(string _name);
	/*
		Function setScore
		���÷����ĺ���

		@param	int	_score	����

		@return void
	*/
	void setScore(int _score);
	/*
		Function operator >
		���ش��������

		@param	RanklistRecord	a	��һ��������
		@param	RanklistRecord	b	�ڶ���������

		@return bool
	*/
	friend bool operator > (const RanklistRecord a, const RanklistRecord b);
	/*
		Function operator >
		������������

		@param	RanklistRecord	a	��һ��������
		@param	RanklistRecord	b	�ڶ���������

		@return bool
	*/
	friend bool operator == (const RanklistRecord a, const RanklistRecord b);
	~RanklistRecord();
};
typedef RanklistRecord DataType;
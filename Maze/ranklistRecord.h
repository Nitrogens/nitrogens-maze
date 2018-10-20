#pragma once
//表示排行榜中一行数据的类
class RanklistRecord
{
	/*
		string	name	姓名
		string	score	分数
	*/
	string name;
	int score;

public:
	/*
		Function RanklistRecord
		不含参的构造函数

		@param	void

		@return void
	*/
	RanklistRecord();
	/*
		Function RanklistRecord
		含参的构造函数：初始化属性的值

		@param	string	_name	输入的姓名
		@param	int		_score	输入的分数

		@return void
	*/
	RanklistRecord(string _name, int _score);
	/*
		Function getName
		获取姓名的函数

		@param	void

		@return string
	*/
	string getName();
	/*
		Function getScore
		获取分数的函数

		@param	void

		@return int
	*/
	int getScore();
	/*
		Function setName
		设置姓名的函数

		@param	string _name	姓名

		@return void
	*/
	void setName(string _name);
	/*
		Function setScore
		设置分数的函数

		@param	int	_score	分数

		@return void
	*/
	void setScore(int _score);
	/*
		Function operator >
		重载大于运算符

		@param	RanklistRecord	a	第一个操作数
		@param	RanklistRecord	b	第二个操作数

		@return bool
	*/
	friend bool operator > (const RanklistRecord a, const RanklistRecord b);
	/*
		Function operator >
		重载相等运算符

		@param	RanklistRecord	a	第一个操作数
		@param	RanklistRecord	b	第二个操作数

		@return bool
	*/
	friend bool operator == (const RanklistRecord a, const RanklistRecord b);
	~RanklistRecord();
};
typedef RanklistRecord DataType;
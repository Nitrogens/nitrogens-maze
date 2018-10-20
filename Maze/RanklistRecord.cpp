#include "stdafx.h"

RanklistRecord::RanklistRecord()
{

}

RanklistRecord::RanklistRecord(string _name = "", int _score = 0) :
	name(_name), score(_score) {}

string RanklistRecord::getName()
{
	return name;
}

int RanklistRecord::getScore()
{
	return score;
}

void RanklistRecord::setName(string _name)
{
	name = _name;
}

void RanklistRecord::setScore(int _score)
{
	score = _score;
}

bool operator > (const RanklistRecord a, const RanklistRecord b)
{
	//�Է�����Ϊ�Ƚ�����
	return a.score > b.score;
}

bool operator == (const RanklistRecord a, const RanklistRecord b)
{
	//�Է�����Ϊ�Ƚ�����
	return a.score == b.score;
}

RanklistRecord::~RanklistRecord()
{
}

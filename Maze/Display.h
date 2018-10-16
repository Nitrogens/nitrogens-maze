#pragma once
#include "Game.h"
class Display
{
public:
	Display();
	void clearScreen();
	void printMaze(Game * G, int x, int y);
	void printGuidance();
	void printRankList();
	void printInstruction();
	~Display();
};
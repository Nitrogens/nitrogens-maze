#include "stdafx.h"
int main(void)
{
	Game * G = new Game();
	Display * D = new Display();

	G->makeMaze(1, 1);

	D->printMaze(G, 1, 1);

	system("pause");

    return 0;
}


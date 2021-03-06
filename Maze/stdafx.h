// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <conio.h>
#include <tchar.h>
#include <windows.h>

using namespace std;

typedef pair<int, int> P;

//迷宫大小
const int MAZESIZE = 10;
const bool OK = true;
const bool FAIL = false;

//两步移动
static int dx[] = { 0, 2, 0, -2 };
static int dy[] = { 2, 0, -2, 0 };

//一步移动
static int sx[] = { 0, 1, 0, -1 };
static int sy[] = { 1, 0, -1, 0 };

//方向
enum direction
{
	east, south, west, north
};


#include "FileOpenException.h"
#include "Display.h"
#include "Game.h"
#include "ranklistRecord.h"
#include "Node.h"
#include "LinkedList.h"
#include "FileOp.h"
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
#include <fstream>
#include <string>
#include <stack>
#include <algorithm>
#include <tchar.h>

using namespace std;

typedef int DataType;
const int SIZE = 21;
const bool OK = true;
const bool FAIL = false;

static int dx[] = { 0, 2, 0, -2 };
static int dy[] = { 2, 0, -2, 0 };
static int sx[] = { 0, 1, 0, -1 };
static int sy[] = { 1, 0, -1, 0 };

enum direction
{
	right, down, left, up
};

// TODO: 在此处引用程序需要的其他头文件

#include "Display.h"
#include "Game.h"
#include "LinkedList.h"
#include "Node.h"
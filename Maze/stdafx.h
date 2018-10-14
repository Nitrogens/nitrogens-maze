// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <tchar.h>

using namespace std;

typedef int DataType;
const int SIZE = 100;
const bool OK = true;
const bool FAIL = false;

bool matrix[SIZE][SIZE];

// TODO: 在此处引用程序需要的其他头文件

#include "Display.h"
#include "Game.h"
#include "LinkedList.h"
#include "Node.h"
#ifndef __MAZE_H__
#define __MAZE_H__

#include "Stack.h"

#define N 6

//简单版
//static int maze[N][N] = {
//	{ 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 1, 1, 1 },
//	{ 0, 0, 1, 0, 0, 0 },
//};
//int GetMazePath(pos entry, pos exit);

////进阶版-不带环
//static int maze[N][N] = {
//	{ 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 1, 1, 1, 1 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 1, 1, 1 },
//	{ 0, 0, 1, 0, 0, 0 },
//};

//进阶版-带环
static int maze[N][N] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 },
};


int GetMazePath(pos entry);
void PrintMaze();
void test();

#endif //__MAZE_H__
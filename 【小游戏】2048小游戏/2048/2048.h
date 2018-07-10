/****************************************************
文件名称：2048小游戏
文件描述：实现控制台的2048逻辑代码
编译环境：VS2013
最后修改：Hunter
修改日期：2018.7.10
【教程】：‘up’‘down’‘left’‘down’

****************************************************/
#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

extern int map[4][4]; //定义一个二维数组 初始化为0.

void Print();  //打印函数
void Add(int);
void Move();
void MoveUp();
void MoveDown();
void MoveLeft();
void MoveRight();

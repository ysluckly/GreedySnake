#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
 
enum APP
{
	EXIT,
	PLAY
};

#define EASY 10
#define HARD 30

#define ROW 10
#define COL 10

#define ROWS (ROW+2)
#define COLS (COL+2)

void InitMap(char arr[ROWS][COLS], int row,int col, char set);
void PrintMap(char arr[ROWS][COLS], int row, int col);
void SetMy(char arr[ROWS][COLS], int row, int col, int count);
void SweepMap(char my_map[ROWS][COLS], char player_map[ROWS][COLS], int row, int cow, int sum);
void MoveLei(char my_map[ROWS][COLS], int x, int y);
void GetCount(char my_map[ROWS][COLS], char player_map[ROWS][COLS], int x, int y);


#endif
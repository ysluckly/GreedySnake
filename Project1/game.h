
#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
 
typedef unsigned int uint;

enum APP
{
	EXIT,
	START
};

#define ROW 3
#define  COL 3

 
void InitBoard(char board[ROW][COL], int row, int col);
void PrintBoard(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
char is_win(char board[ROW][COL], int row, int col);


#endif //__GAME_H__
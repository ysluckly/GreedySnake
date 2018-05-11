#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', sizeof(char)* row*col);
}//memset函数用来对一段内存空间全部设置为某个字符

void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i != 2)
		{
			printf("---|---|---\n");
		}
	}
}

void  PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入落子的坐标：\n");
	while (1)
	{
		scanf("%d%d", &x, &y);
		//保证输入坐标的合法性,玩家输入的坐标是从1开始的
		if (((x >= 1) && (x <= row)) && ((y >= 1) && (y <= col)))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';//玩家落子
				break;
			}
			else
			{
				printf("该坐标已被占用，请换一个坐标：\n");
			}
		}
		else
		{
			printf("输入坐标不合法，请重新输入：\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;//利用rand函数生成随机坐标
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}

}

static int is_full(char board[ROW][COL], int row, int col)
//函数is_full只在is_win中被调用，可以加上static改变其链接属性
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}//判断棋盘是否下满了

char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][2] != ' '))
		{
			return  board[i][1];
		}
	}
	for (j = 0; j < col; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[2][j] != ' '))
		{
			return  board[1][j];
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] != ' '))
	{
		return board[1][1];
	}
	else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != ' '))
	{
		return board[1][1];
	}
	else if (is_full(board, ROW, COL) == 1)
	{
		return 'Q';//表示棋盘下满了
	}
	else
		return ' ';
}
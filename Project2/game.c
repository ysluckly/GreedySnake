#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitMap(char arr[ROWS][COLS], int row, int col, char set)
{
	memset(arr, set, col*row*sizeof(arr[0][0]));
}

void PrintMap(char arr[ROWS][COLS], int row, int col)
{
		int i = 0;
		int j = 0;
		printf("   ");
		for (i = 1; i<=row ; i++)
		{
			printf("%3d", i);
		}
		printf("\n");
		for (i = 0; i<=row; i++)
		{
			printf("---");
		}
		printf("\n");
		for (i = 1; i <= row; i++)
		{								 
			printf("%2d|", i);
			for (j = 1; j <= col ; j++)
			{
				printf("%3c", arr[i][j]);
			}
			printf("\n");
		}
	 
}
void SetMy(char arr[ROWS][COLS], int row, int col, int count)
{
	
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}

void SweepMap(char my_map[ROWS][COLS],char player_map[ROWS][COLS], int row, int col, int sum)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int temp = 0;
	int win = 0;
	
	while (win < (row * col - sum))
	{
		printf("请输入你扫雷坐标:>");
		scanf("%d%d", &x, &y);
		temp++;
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{

			while ((my_map[x][y] == '1') && (temp == 1))
			{
				//保证玩家第一次不死
				MoveLei(my_map, x, y);
				//对周围的雷数进行遍历
				GetCount(my_map, player_map, x, y);
			}

			if (my_map[x][y] == '1')
			{
				printf("\n恭喜你，壮烈牺牲\n");
				PrintMap(my_map, ROW, COL);
				break;
			}
			else
			{
				GetCount(my_map, player_map, x, y);
				printf("\n");
				win++;
			}
			PrintMap(player_map, ROW, COL);
		}
		else
		{
			printf("坐标输入有误\n");
		}

	}
	if(win == (row * col - sum))
	{
		printf("恭喜你，排完了\n");
	}
	
}

//若输入的坐标无雷，则要遍历周围，统计雷数  
//若周围无雷，则递归遍历，统计周围雷数  
void GetCount(char my_map[ROWS][COLS], char player_map[ROWS][COLS], int x, int y)
{


	if ((my_map[x][y] == '0'))
	{
		int count = 0;

		if (my_map[x - 1][y - 1] == '1')
			count++;

		if (my_map[x - 1][y] == '1')
			count++;

		if (my_map[x - 1][y + 1] == '1')
			count++;

		if (my_map[x][y - 1] == '1')
			count++;

		if (my_map[x][y + 1] == '1')
			count++;
		if (my_map[x + 1][y - 1] == '1')
			count++;

		if (my_map[x + 1][y] == '1')
			count++;

		if (my_map[x + 1][y + 1] == '1')
			count++;

		player_map[x][y] = (count + '0');
	}

	if (player_map[x][y] == '0')
	{
		if (player_map[x - 1][y - 1] == '*')
			GetCount(my_map, player_map, x - 1, y - 1);

		if (player_map[x - 1][y] == '*')
			GetCount(my_map, player_map, x - 1, y);

		if (player_map[x - 1][y + 1] == '*')
			GetCount(my_map, player_map, x - 1, y + 1);

		if (player_map[x][y - 1] == '*')
			GetCount(my_map, player_map, x, y - 1);

		if (player_map[x][y + 1] == '*')
			GetCount(my_map, player_map, x, y + 1);

		if (player_map[x + 1][y - 1] == '*')
			GetCount(my_map, player_map, x + 1, y - 1);

		if (player_map[x + 1][y] == '*')
			GetCount(my_map, player_map, x + 1, y);

		if (player_map[x + 1][y + 1] == '*')
			GetCount(my_map, player_map, x + 1, y + 1);
	}
}

//为提高游戏体验，设置玩家第一次无论如何都不会被炸死  
void MoveLei(char my_map[ROWS][COLS], int x, int y)
{
	int ret = 1;
	do
	{
		my_map[x][y] = '0';
		while (ret)
		{
			x = rand() % ROW + 1;
			y = rand() % COL + 1;
			if (my_map[x][y] == '0')
			{
				my_map[x][y] = '1';
			}
			ret--;
		}
	} while (ret);
}


//玩家对以确定的雷的位置，可以进行标记
//void Mark1Mine(char player_map[ROWS][COLS])     
//{  		
//  int x = 0;  
//  int y = 0;  
//  printf("请输入您要标记的位置：<");  
//  scanf("%d%d", &x, &y);  
//  printf("\n");  
//  if (x == 0 && y == 0)  
//      return 0;  
//  else  
//      show[x][y] = '$';  
//}  
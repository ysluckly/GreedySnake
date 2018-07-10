#include "2048.h"

//打印
void Print()
{
	printf("\n\t\t    ******欢迎来到2048小游戏******\n");
	printf("\n\t\t\t┏━━━━┳━━━━┳━━━━┳━━━━┓\n");
	printf("\t\t\t┃ %2d ┃ %2d ┃ %2d ┃ %2d ┃\n", map[0][0], map[0][1], map[0][2], map[0][3]);
	printf("\t\t\t┣━━━━╋━━━━╋━━━━╋━━━━┫\n");
	printf("\t\t\t┃ %2d ┃ %2d ┃ %2d ┃ %2d ┃\n", map[1][0], map[1][1], map[1][2], map[1][3]);
	printf("\t\t\t┣━━━━╋━━━━╋━━━━╋━━━━┫\n");
	printf("\t\t\t┃ %2d ┃ %2d ┃ %2d ┃ %2d ┃\n", map[2][0], map[2][1], map[2][2], map[2][3]);
	printf("\t\t\t┣━━━━╋━━━━╋━━━━╋━━━━┫\n");
	printf("\t\t\t┃ %2d ┃ %2d ┃ %2d ┃ %2d ┃\n", map[3][0], map[3][1], map[3][2], map[3][3]);
	printf("\t\t\t┗━━━━┻━━━━┻━━━━┻━━━━┛\n");

}

//增加数值的函数
//增加数值的函数  dir=0第一次进入界面 dir=1往上 dir=2往下  dir=3往左 dir=4往右 
void Add(int dir)
{
	srand((unsigned int)time(NULL)); //随机数
	int num, flag; //2 4
	int row, col;
	row = rand() % 4; //0-3
	col = rand() % 4; //0-3
	flag = rand() % 2; //flag 0 1
	if (flag == 0)
		num = 2;
	else
		num = 4;
	switch (dir)
	{
	case 0:
		map[row][col] = num;
		break;
	case 1: //上
		if (map[3][col] == 0) //先随机一个  判断一下是不是0
		{
			map[3][col] = num;
		}
		else
		{
			for (col = 0; col < 4; col++)
			{
				if (map[3][col] == 0)
				{
					map[3][col] = num;
					break;
				}
			}
		}
		break;
	case 2: //下
		if (map[0][col] == 0)
		{
			map[0][col] = num;
		}
		else
		{
			for (col = 0; col < 4; col++)
			{
				if (map[0][col] == 0)
				{
					map[0][col] = num;
					break;
				}
			}
		}

		break;
	case 3: //左
		if (map[row][3] == 0)
		{
			map[row][3] = num;
		}
		else
		{
			for (row = 0; row < 4; row++)
			{
				if (map[row][3] == 0)
				{
					map[row][3] = num;
					break;
				}
			}
		}
		break;


	case 4: //右
		if (map[row][0] == 0)
		{
			map[row][0] = num;
		}
		else
		{
			for (row = 0; row < 4; row++)
			{
				if (map[row][0] == 0)
				{
					map[row][0] = num;
					break;
				}
			}
		}
		break;
	}
}

//控制函数 返回方向
void Move()
{
	char ch; //字符
	ch = _getch();//getchar()需要显示回文 按下enter之后接收 getch()不显示 直接接收
	switch (ch)
	{
	case 72://上
		MoveUp();
		break;

	case 80://下
		MoveDown();
		break;

	case 75:  //左
		MoveLeft();
		break;

	case 77:  //右
		MoveRight();
		break;
	}
	//return dir;
}


void MoveUp()
{
	int row, col, tep;

	for (col = 0; col < 4; col++)
	{
		//实现一列 往上移动
		int n = 4;
		while (n--)
		{
			for (row = 0; row < 3; row++) //第0列 每一行的数值
			{
				if (map[row][col] == 0)
				{
					for (tep = row; tep < 3; tep++)
					{
						map[tep][col] = map[tep + 1][col];
						map[tep + 1][col] = 0;
					}
				}
			}
		}

		//实现加法
		for (row = 0; row < 3; row++)
		{
			if (map[row][col] == map[row + 1][col])
			{
				map[row][col] *= 2;
				//map[row + 1][col] = 0; //可要可不要
				for (tep = row + 1; tep < 3; tep++)
				{
					map[tep][col] = map[tep + 1][col];
					map[tep + 1][col] = 0;
				}
			}
		}
	}
	Add(1);
}

void MoveDown()
{
	int row, col, tep;

	for (col = 0; col < 4; col++)
	{
		int n = 4;
		while (n--)
		{
			for (row = 3; row>0; row--)
			{
				if (map[row][col] == 0)
				{
					for (tep = row; tep > 0; tep--)
					{
						map[tep][col] = map[tep - 1][col];
						map[tep - 1][col] = 0;
					}
				}
			}
		}

		for (row = 3; row > 0; row--)
		{
			if (map[row][col] == map[row - 1][col])
			{
				map[row][col] *= 2;

				for (tep = row - 1; tep > 0; tep--)
				{
					map[tep][col] = map[tep - 1][col];
					map[tep - 1][col] = 0;
				}
			}
		}
	}
	Add(2);
}

void MoveLeft()
{
	int row, col, tep;

	for (row = 0; row < 4; row++)
	{
		int n = 4;
		while (n--)
		{
			for (col = 0; col < 3; col++)
			{
				if (map[row][col] == 0)
				{
					for (tep = col; tep <3; tep++)
					{
						map[row][tep] = map[row][tep + 1];
						map[row][tep + 1] = 0;
					}
				}
			}
		}

		for (col = 0; col < 3; col++)
		{
			if (map[row][col] == map[row][col + 1])
			{
				map[row][col] *= 2;

				for (tep = col + 1; tep <3; tep++)
				{
					map[row][tep] = map[row][tep + 1];
					map[row][tep + 1] = 0;
				}
			}
		}
	}
	Add(3);
}

void MoveRight()
{

	int row, col, tep;

	for (row = 0; row < 4; row++)
	{
		int n = 4;
		while (n--)
		{
			for (col = 3; col >0; col--)
			{
				if (map[row][col] == 0)
				{
					for (tep = col; tep >0; tep--)
					{
						map[row][tep] = map[row][tep - 1];
						map[row][tep - 1] = 0;
					}
				}
			}
		}

		for (col = 3; col >0; col--)
		{
			if (map[row][col] == map[row][col - 1])
			{
				map[row][col] *= 2;

				for (tep = col - 1; tep >0; tep--)
				{
					map[row][tep] = map[row][tep - 1];
					map[row][tep - 1] = 0;
				}
			}
		}
	}
	Add(4);
}

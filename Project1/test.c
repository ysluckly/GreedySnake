#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("***** 《三子棋游戏》*****\n");
	printf("******   1.play   *******\n");
	printf("******   0.exit   *******\n");
	printf("*************************\n");
	printf("*************************\n");
}

void game()
{
	char ret;
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	while (1)
	{
		printf("玩家走：\n");
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != ' ')
			break;
		printf("电脑走：\n");
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != ' ')
			break;
	}
	if (ret == 'X')
	{
		printf(" 你赢了！\n");
	}
	else if (ret == '0')
	{
		printf(" 你输了\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}

void test()
{

	int input = 0;
	srand((uint)time(NULL));
	do {
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case START:
			game();
			break;
		case EXIT:
			break;
		default:
			break;
		}

	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}
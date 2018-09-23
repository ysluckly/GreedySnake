#define _CRT_SECURE_NO_WARNINGS 1

#include "Snake.h"

snake *head, *tail;
char name[20];
int score = 0;
char click = 1;
int speed;


int main()
{
	system("color 0A");	  //其中color后面的0是背景色代号，A是前景色代号
	welcome();
	creatgraph();
	creatfood();
	if (ClickControl() == 0) return 0;
	return 0;
}
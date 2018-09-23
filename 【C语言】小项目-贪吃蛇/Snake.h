#ifndef __SANKE_H__
#define __SANKE_H__

#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>


#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
#define stop 'p'

/*全局变量 + 预处理：*/
typedef struct Snakes
{
	int x;
	int y;
	struct Snakes *next;
}snake;



struct Food
{
	int x;
	int y;
}food;

extern snake *head, *tail;
extern char name[20];
extern int score ;
extern char click;
extern int speed;



void welcome();               //开始界面
void Finish();                //结束界面
void creatgraph();            //围墙打印
void gotoxy(int x, int y);    //光标跳转，横为X 0,1,2..
void gotoprint(int x, int y); //跳转打印
void gotodelete(int x, int y);//跳转删除
void creatfood();             //食物产生
int ClickControl();           //获取键盘信号
int Judge();                  //游戏结束判断
void MovingBody();			  //蛇的移动 
void Eating();                //蛇吃到东西后的操作（伸长）
void ChangeBody(int a, int b); //蛇的坐标变换,后一个复制前一个STRUCT,a,b为head之前坐标 





#endif //__SANKE_H__
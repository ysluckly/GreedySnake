#define _CRT_SECURE_NO_WARNINGS 1
/*****************************************************
*                     项目名称：扫雷游戏             *
*					  编译环境：Vs 2013				 *
*                     创建日期：2018.4.28            *
*                     项目修改：Mr.Yao               *
******************************************************/
//知识点：
//1.数组
//2.函数
//3.循环
//4.图形库	(.cpp中运用)
//5.扩展内容： 递归 (内存换取时间)


#include<stdio.h>
#include<time.h>//后面随机数  srand rand  时间 随机数的种子
#include<graphics.h>//TC2.0编译器的头文件,目前此头文件需要EeayX图形库支持编译且只支持c++
#include<mmsystem.h>//多媒体设备接口  底层驱动
#pragma comment(lib,"winmm.lib")//加载winmm静态库

//函数
int win = 0;
void drawmap(int map[][10], IMAGE img[])//绘图函数
{
	//贴图
	/*
	数字图->空白图
	1.用-1~9  贴数字  +20  19~29 ->default
	--->2.用-1~9 做空白  点开之后加20
	*/
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			//map[i][j]是什么  贴什么图 if 
			if (29 <= map[i][j] && map[i][j] <= 39)
			{
				//标记的部分
				putimage(64 * j, 64 * i, &img[10]);
				continue;
			}
			switch (map[i][j])
			{
			case 20:putimage(64 * j, 64 * i, &img[0]); break;
			case 21:putimage(64 * j, 64 * i, &img[1]); break;
			case 22:putimage(64 * j, 64 * i, &img[2]); break;
			case 23:putimage(64 * j, 64 * i, &img[3]); break;
			case 24:putimage(64 * j, 64 * i, &img[4]); break;
			case 25:putimage(64 * j, 64 * i, &img[5]); break;
			case 26:putimage(64 * j, 64 * i, &img[6]); break;
			case 27:putimage(64 * j, 64 * i, &img[7]); break;
			case 28:putimage(64 * j, 64 * i, &img[8]); break;
				//case 9:putimage(64 * j, 64 * i, &img[9]); break;
			case 19:putimage(64 * j, 64 * i, &img[12]); break;//雷
			default:putimage(64 * j, 64 * i, &img[11]); break;//空白图
			}
		}
	}
}
//栈溢出 没办法使用
void play(int map[][10],int x,int y)//递归函数 数组名 坐标
{
	//map[x][y]==0
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (0 <= i&&i <= 9 && 0 <= j&&j <= 9)
			{
				if (map[i][j] == 0)
				{
					play(map, i, j);//自己调用自己
				}
				else if (map[i][j] <= 9)
				{
					map[i][j] += 20;
					win++;
				}
			}
		}
	}
}
int playgame(int map[][10])
{
	//
	//界面做好了  game start
	//鼠标信息
	MOUSEMSG msg;
	while (1)
	{
		msg = GetMouseMsg();//获取当前的鼠标信息
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			//左键点下
			//msg.x msg.y 鼠标点击的位置
			//整数除法  3/4  0 
			if (map[msg.y / 64][msg.x / 64] == -1)
			{
				//踩到雷
				//游戏结束
				map[msg.y / 64][msg.x / 64] += 20;
				return -1;
			}
			else if (map[msg.y / 64][msg.x / 64] == 0)
			{
				//1.掀开9个
				for (int i = msg.y / 64 - 1; i <= msg.y / 64 + 1; i++)
				{
					for (int j = msg.x / 64 - 1; j <= msg.x / 64 + 1; j++)
					{
						if (0 <= i&&i <= 9 && 0 <= j&&j <= 9)//防止越界
						{
							if (map[i][j] <= 9)//是否被翻开
							{
								map[i][j] += 20;
								win++;
							}
						}
					}
				}
				//play(map, msg.y / 64, msg.x / 64);
				return 0;

			}
			else if (0 < map[msg.y / 64][msg.x / 64] && map[msg.y / 64][msg.x / 64] <= 9)
			{
				//没有踩到雷
				map[msg.y / 64][msg.x / 64] += 20;
				win++;
				return win;
			}
			break;
		case WM_RBUTTONDOWN:
			//右键按下
			if ((-1 <= map[msg.y / 64][msg.x / 64] && map[msg.y / 64][msg.x / 64] <= 9))
			{
				map[msg.y / 64][msg.x / 64] += 30;//标记
				return 0;
			}
			else if (29 <= map[msg.y / 64][msg.x / 64] && map[msg.y / 64][msg.x / 64] <= 39)
			{
				map[msg.y / 64][msg.x / 64] -= 30;//反标记
				return 0;
			}

		}


	}
}
int main()
{
	//窗口大小  640*640
	initgraph(640, 640);//10*10  图片64*64
	HWND hwnd = GetHWnd();//获取窗口句柄
	int map[10][10] = { 0 };//地图
	mciSendString(L"open 林中鸟.mp3 alias song", 0, 0, 0);
	////1.函数名  2.文件目录 3.空格
	mciSendString(L"play song", 0, 0, 0);
	////PlaySound wav 格式 
	//PlaySound(L"./music/b.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	//导入图片 loadimage  
	IMAGE img[13];
	loadimage(&img[0], L"0.jpg", 64, 64);//L多字节
	loadimage(&img[1], L"1.jpg", 64, 64);
	loadimage(&img[2], L"2.jpg", 64, 64);
	loadimage(&img[3], L"3.jpg", 64, 64);
	loadimage(&img[4], L"4.jpg", 64, 64);
	loadimage(&img[5], L"5.jpg", 64, 64);
	loadimage(&img[6], L"6.jpg", 64, 64);
	loadimage(&img[7], L"7.jpg", 64, 64);
	loadimage(&img[8], L"8.jpg", 64, 64);
	loadimage(&img[9], L"9.jpg", 64, 64);
	loadimage(&img[10], L"标记.jpg", 64, 64);
	loadimage(&img[11], L"空.jpg", 64, 64);
	loadimage(&img[12], L"雷.jpg", 64, 64);
	//埋雷   这里取10个
	//随机数 time 
	int x, y;
	srand((unsigned)time(NULL));//设置种子
	for (int n = 0; n < 10;)
	{
		x = rand() % 10;//生成0~9 
		y = rand() % 10;
		if (map[x][y] != -1)//雷  
		{
			//保证不重复
			map[x][y] = -1;
			n++;
		}
	}
	//生成地图
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{//二维数组 二重循环
			//从头到尾 一个个审视
			//1.给雷周围的元素 加1
			if (map[i][j] == -1)
			{
				//判断是不是越界  第二个判断是不是雷  +1
				for (int x = i - 1; x <= i + 1; x++)
				{
					for (int y = j - 1; y <= j + 1; y++)
					{//判断周围8个  和他本身
						if (x >= 0 && x < 10 && y >= 0 && y < 10)
						{
							if (map[x][y] != -1)
							{
								map[x][y]++;
							}
						}
					}
				}
			}
			//2.找一个元素周围的雷

		}
	}
	while (1)
	{
		drawmap(map, img);
		if (playgame(map) == -1)
		{
			drawmap(map, img);
			MessageBox(hwnd, L"Lose", L"GameOver", MB_YESNO);//窗口最前
			break;
		}
		else if (win == 10 * 10 - 10)
		{
			drawmap(map, img);
			MessageBox(hwnd, L"Win", L"GG", MB_YESNO);//窗口最前
			break;
		}

		//是否赢了
		//1. 标记所有的雷 都标记  限制标记的数量
		//2.记录“点开不是雷“的数目，它如果等于总数减去雷的数目就算赢
	}
	//贴图 putimage 
	//putimage(0,0,&img[0]);
	//getchar();
	closegraph();
	return 0;

}

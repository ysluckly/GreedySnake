#define _CRT_SECURE_NO_WARNINGS 1

#include "ScoreSystem.h"

//菜单
void meau()
{
		printf("\n\n\t\t\t**************欢迎使用************\n");
		printf("\n\n\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t\t┃ 西安科技大学运动会计分系统系统┃\n");
		printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t\t┃	   ①信息输入		┃\n");
		printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t\t┃	   ②统计输出		┃\n");
		printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t\t┃ 	   ③排序输出		┃\n");
		printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t\t┃	   ④信息查询		┃\n");
		printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t\t┃	   0 退出系统		┃\n");
		printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\t\t\t请选择:>");

}

//界面初始化
void BeginInit()
{
	IMAGE bkImg, bk1;
	//MP3格式
	mciSendString(L"open ./music/bkmusic.mp3 alias bgm", 0, 0, 0);//歌名取别名bgm
	mciSendString(L"play bgm repeat", 0, 0, 0);
	//WAV格式
	//PlaySound(L"./music/b.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	loadimage(&bkImg, L"./photo/b.jpg", 600, 400);//按照比例缩放加载
	loadimage(&bk1, L"./photo/c.jpg", 200, 50);//按照比例缩放加载
	putimage(0, 0, &bkImg);
	

	settextstyle(30, 0, L"楷体");
	settextcolor(RGB(0, 0, 255));
	setbkmode(TRANSPARENT);	//背景透明
	outtextxy(100, 20, L"运动会分数统计系统 1.0 -v");

	outtextxy(210, 165, L"点击Here进入");

	outtextxy(320, 340, L"2018.6.25创建");
	outtextxy(355, 370, L" ---by 第三小组");

}

//鼠标点击进入
void Press()
{
	//定义鼠标信息
	MOUSEMSG msg = { 0 };
	while (true)
	{
		msg = GetMouseMsg();

		//uMsg  鼠标当前信息
		switch (msg.uMsg)
		{
			//左键按下
		case WM_LBUTTONDOWN:
			if (msg.x >= 180 && msg.x <= 380 && msg.y >= 160 && msg.y <= 210)
			{

				closegraph();

			}


			goto flag;
		}
	}
flag:
	;
}

//保存信息到文件
void savetofile()
{
	FILE *fp;
	int i;
	if ((fp = fopen("file.txt", "w")) == NULL)
	{
		printf("cannot open the file\n");
		return;
	}
	for (i = 0; i<N; i++)
	{
		if (a[i].snum != '\0')
		if (fwrite(&a[i], sizeof(snode), 1, fp) != 1)
		{
			printf("file write error\n");
			return;
		}
	}
	fclose(fp);
}
//从文件中读取
void readfromfile() 
{
	int i;
	FILE *fp;
	if ((fp = fopen("file.txt", "rb")) == NULL)
	{
		printf("不能打开文件\n");
		return;
	}
	for (i = 0; i<N; i++)
		fread(&a[i], sizeof(snode), 1, fp);
	fclose(fp);
}
// ①信息输入
void InputInformation(int n, int m, int w)
{ 
	printf("\n\n\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t┃ 西安科技大学运动会计分系统系统┃\n");
	printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t┃	   ①信息输入		┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	int i, j, s, k, q = 0;
	for (i = 1; i<n + 1; i++)
	{
		printf("第%d个学校编号 :", i);
		scanf("%d", &a[i].snum); /* 输入学校信息 */
		for (j = 0; j<m + w; j++)
		{
			printf(" 项目编号 :");
			scanf("%d", &a[i].t[j].inum);
			printf(" 项目取前 3 名或前 5 名(3 或 5):");
			scanf("%d", &a[i].t[j].top);
			if (a[i].t[j].top == 3)
				printf("获得名次个数 (1-3)：");
			else
				printf("获得名次个数 (1-5)：");
			scanf("%d", &k); /* 输入项目信息 */
			for (s = 0; s<k; s++)
			{
				if (a[i].t[j].top == 3)
					printf(" 所获名次 (1--3):");
				else
					printf(" 所获名次 (1--5):");
				scanf("%d", &a[i].t[j].range[s]); /* 输入所获名次信息 */
			}
			printf("\n");
		}
	}
	for (i = 0; i<n; i++)
	{
		a[i].score = 0;
		a[i].mscore = 0;
		a[i].wscore = 0;
	} /* 初始化分数 */
	for (i = 0; i<n+1; i++)
	for (j = 0; j<m + w; j++)
	for (s = 0; s<5; s++)
	{
		if (a[i].t[j].top == 3)
			switch (a[i].t[j].range[s])
		{
			case 0: a[i].t[j].mark[s] = 0; break;
			case 1: a[i].t[j].mark[s] = 5; break;
			case 2: a[i].t[j].mark[s] = 3; break;
			case 3: a[i].t[j].mark[s] = 2; break;
			case 4: a[i].t[j].mark[s] = 0; break;
			case 5: a[i].t[j].mark[s] = 0; break;
		}
		else if (a[i].t[j].top == 5)
			switch (a[i].t[j].range[s])
		{
			case 0: a[i].t[j].mark[s] = 0; break;
			case 1: a[i].t[j].mark[s] = 7; break;
			case 2: a[i].t[j].mark[s] = 5; break;
			case 3: a[i].t[j].mark[s] = 3; break;
			case 4: a[i].t[j].mark[s] = 2; break;
			case 5: a[i].t[j].mark[s] = 1; break;
		}
		a[i].score = a[i].score + a[i].t[j].mark[s]; /*记学校总分 */
		if (j <= m - 1)
			a[i].mscore = a[i].mscore + a[i].t[j].mark[s]; /*记男子团体总分 */
		else
			a[i].wscore = a[i].wscore + a[i].t[j].mark[s]; /*记女子团体总分 */
	}
	printf(" 输入完毕 !返回? 1 是 2 否\n"); /*返回菜单 */
	scanf("%d", &q);
	printf("\n");
	if (q != 1)
		printf("不能再添加信息 !");
	printf("\n");
	savetofile(); /*将信息存入文件 file*/
	system("cls");//清屏

} 
// ②统计输出
void OutInformation(int n, int m, int w)
{
	printf("\n\n\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t┃ 西安科技大学运动会计分系统系统┃\n");
	printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t┃	   ②统计输出		┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	readfromfile();
	int i, j, s, q = 0;
	for (i = 0; i<n; i++) /*显示结果 */
	{
		printf("学校编号:%d\t 学校总分:%d\t 男团总分:%d\t 女团总分:%d\n", a[i].snum, a[i].score, a[i].mscore, a[i].wscore);
		for (j = 0; j<m + w; j++)
		{
			printf("项目编号:%d 所取名次数量:%d\n", a[i].t[j].inum, a[i].t[j].top);
			for (s = 0; s<5; s++)
			{
				if (a[i].t[j].range[s] != 0)
					printf("名次:%d\t 分数:%d\n", a[i].t[j].range[s], a[i].t[j].mark[s]);
			}
		}
		printf("\n");
	}
	printf("请选择:1.返回主菜单 2.继续查询"); /*返回菜单或继续查询 */
	scanf("%d", &q);
	printf("\n");
	system("cls");//清屏


}
// ③排序输出
void OutSort(int n, int m, int w)
{
	readfromfile();
	int c, i, j, k, q = 0;
	int temp[N];
	printf("\n\n\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t┃ 西安科技大学运动会计分系统系统┃\n");
	printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t┃	   ③排序输出		┃\n");
	printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t┃	1. 按学校编号输出	┃\n");
	printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t┃	2. 按学校总分输出	┃\n");
	printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t┃ 	3. 按男团总分输出	┃\n");
	printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t┃	4. 按女团总分输出	┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	do
	{
		printf("请选择要实现功能的编号 (1--4):");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			for (i = 0; i<n; i++)
				temp[i] = i;
			for (i = 0; i<n; i++)
			{
				for (j = i + 1; j<n; j++)
				if (a[temp[i]].snum>a[j].snum)
				{
					k = temp[i];
					temp[i] = temp[j];
					temp[j] = k;
				}
			} /* 用冒泡排序方法排序 */
			for (i = 0; i<n; i++)
			{
				printf("学校编号:%d\t 学校总分:%d\t 男团总分:%d\t 女团总分:%d\n", a[temp[i]].snum, a[temp[i]].score, a[temp[i]].mscore, a[temp[i]].wscore);
			} /*按学校编号输出 */
			break;
		case 2:
			for (i = 0; i<n; i++)
				temp[i] = i;
			for (i = 0; i<n; i++)
			{
				for (j = i + 1; j<n; j++)
				if (a[temp[i]].score<a[j].score)
				{
					k = temp[i];
					temp[i] = temp[j];
					temp[j] = k;
				}
			} /* 用冒泡排序方法排序 */
			for (i = 0; i<n; i++)
			{
				printf("学校编号:%d\t 学校总分:%d\t 男团总分:%d\t 女团总分:%d\n", a[temp[i]].snum, a[temp[i]].score, a[temp[i]].mscore, a[temp[i]].wscore);
			} /* 按学校总分输出 */
			break;
		case 3:
			for (i = 0; i<n; i++)
				temp[i] = i;
			for (i = 0; i<n; i++)
			{
				for (j = i + 1; j<n; j++)
				if (a[temp[i]].mscore<a[j].mscore)
				{
					k = temp[i];
					temp[i] = temp[j];
					temp[j] = k;
				}
			} /* 用冒泡排序方法排序 */
			for (i = 0; i<n; i++)
			{
				printf("学校编号:%d\t 学校总分:%d\t 男团总分:%d\t 女团总分:%d\n", a[temp[i]].snum, a[temp[i]].score, a[temp[i]].mscore, a[temp[i]].wscore);
			} /* 按男团总分输出 */
			break;
		case 4:
			for (i = 0; i<n; i++)
				temp[i] = i;
			for (i = 0; i<n; i++)
			{
				for (j = i + 1; j<n; j++)
				if (a[temp[i]].wscore<a[j].wscore)
				{
					k = temp[i];
					temp[i] = temp[j];
					temp[j] = k;
				}
			} /* 用冒泡排序方法排序 */
			for (i = 0; i<n; i++)
			{
				printf("学校编号:%d\t 学校总分:%d\t 男团总分:%d\t 女团总分:%d\n", a[temp[i]].snum, a[temp[i]].score, a[temp[i]].mscore, a[temp[i]].wscore);
			} /* 按女团总分输出 */
			break;
		default:
			printf("输入错误 ,请重试\n");
		}
		printf("请选择：按1返回主菜单  按2继续排序"); /*返回菜单或继续排序 */
		scanf("%d", &q);
		printf("\n");
	} while (q == 2);
	printf("\n");
	system("cls");//清屏

}
// ④信息查询
void OutSearch(int n, int m, int w)
{
	readfromfile();
	int c, i, j, k, d, l, q = 0;
	printf("\n\n\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t\t┃ 西安科技大学运动会计分系统系统┃\n");
	printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t┃	   ④信息查询		┃\n");
	printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t┃	1. 按学校编号查询	┃\n");
	printf("\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t┃	2. 按学校总分查询	┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	do
	{
		k = -1; d = -1; l = -1;
		printf(" 请选择要实现功能的编号 (1--2):");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			printf(" 要查询的学校编号 :"); /*查找学校编号下标 */
			scanf("%d", &c);
			for (i = 0; i<n; i++)
			{
				if (a[i].snum == c)
					k = i;
			}
			if (k == -1)
				printf("该学校未参加此次运动会 !\n");
			else
			{
				printf("要查询的项目编号:"); /*查找项目编号下标 */
				scanf("%d", &c);
				for (j = 0; j<m + w; j++)
				{
					if (a[k].t[j].inum == c)
						d = j;
				}
				if (d == -1)
					printf("此次运动会没有这个项目\n");
				else /* 显示结果 */
				{
					printf("这个项目取前%d名,该学校的成绩如下:\n", a[k].t[d].top);
					for (i = 0; i<5; i++)
					if (a[k].t[d].range[i] != 0)
						printf("名次:%d\n", a[k].t[d].range[i]);
				}
			}
			break;
		case 2:
			printf("要查询的项目编号:"); /*查找项目编号下标 */
			scanf("%d", &c);
			for (i = 0; i<n; i++)
			for (j = 0; j<m + w; j++)
			if (a[i].t[j].inum == c)
				l = j;
			if (l == -1)
				printf("此次运动会没有这个项目 \n");
			else /*显示结果 */
			{
				printf("该项目取前%d名,取得名次的学校\n", a[0].t[l].top);
				for (i = 0; i<n; i++)
				for (j = 0; j<5; j++)
				if (a[i].t[l].range[j] != 0)
					printf("学校编号:%d,名次:%d\n", a[i].snum, a[i].t[l].range[j]);
			}
			break;
		default:
			printf("输入错误,请重试\n");
		}
		printf("请选择:1.返回主菜单 2.继续查询"); /*返回菜单或继续查询 */
		scanf("%d", &q);
		printf("\n");
	} while (q == 2);
	printf("\n");
	system("cls");//清屏

}
// ⑤退出系统
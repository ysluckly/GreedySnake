
#define _CRT_SECURE_NO_WARNINGS 1

#include "ScoreSystem.h"
snode a[N];    //定义一个学校数组


int main()
{	
	int n, m, w;
	int input;
	initgraph(WINDOS_WIDE, WINDOS_HIGH);//创建图形界面
	BeginInit();
	Press();
	printf("\n\n\t\t\t**************欢迎使用************\n");
	printf("请输入运动会主要信息:\n");
	printf("\t请输入学校个数>:");
	scanf("%d", &n);
	printf("\t请输入男项目总数>:");
	scanf("%d", &m);
	printf("\t请输入女项目总数>:");
	scanf("%d", &w);

	do
	{  
		meau();
		scanf("%d", &input);
		system("cls");//清屏

		switch (input)
		{
		case 1:
			// ①信息输入
			
			InputInformation(n,m,w);
			break;
		case 2:
			// ②统计输出
			OutInformation(n,m,w);
			break;
		case 3:
			// ③排序输出
			OutSort(n,m,w);
			break;
		case 4:
			// ④信息查询
			OutSearch(n,m,w);
			break;
		case 0:
			// 0 退出系统
			printf("\n\n\t\t\t*************欢迎再次使用***********\n");

			break;
		default:
			printf("\t\t\t输入有误，请重新输入:\n");
		}
		

	} while (input);

	//vs2013防止闪屏
	system("pause");
	return 0;
}


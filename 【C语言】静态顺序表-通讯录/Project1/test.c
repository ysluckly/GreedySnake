/***********************************************************
*                      程序名称：通讯录（静态顺序表）     *
*                      编译环境：VS2013                    *
*                      编制日期：2018.5.28                 *
*                                      -----by Hunter	   *
***********************************************************/

#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"
void meau()
{
	printf("\t\t\t******         《通讯录》       ********\n");
	printf("\t\t\t****************************************\n");
	printf("\t\t\t****** 1.添加信息       2.查找信息******\n");
	printf("\t\t\t****** 3.删除信息       4.修改信息******\n");
	printf("\t\t\t****** 5.按姓排序       6.信息列表******\n");
	printf("\t\t\t****** 7.清空信息       8.退出    ******\n");
	printf("\t\t\t****************************************\n");
}

void test()
{
	int input = 0;
	Contact pc;
	InitContact(&pc);
	do
	{
		meau();
		printf("\t\t\t请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&pc);
			break;
		case SEARCH:
			SearchContact(&pc);
			break;
		case DEIETE:
			DeleteContact(&pc);
			break;
		case MODIFY:
			ModifyContact(&pc);
			break;
		case SORT:
			SortContact(&pc);
			break;
		case SHOW:
			ShowContact(&pc);
			break;
		case EMPTY:
			EmptyContact(&pc);
			break;
		case EXIT:
			exit(0);
			break;
		default:
			printf("\t\t\t输入有误，请重新输入:>");
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



#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"
void meau()
{
	printf("\t\t\t******         《通讯录》       ********\n");
	printf("\t\t\t****************************************\n");
	printf("\t\t\t****** 1.添加信息       2.查找信息******\n");
	printf("\t\t\t****** 3.删除信息       4.修改信息******\n");
	printf("\t\t\t****** 5.按姓排序       6.信息列表******\n");
	printf("\t\t\t****** 7.清空信息       0.退出    ******\n");
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
			break;
		default:
			printf("\t\t\t输入有误，请重新输入:>");
			break;
		}

	} while (input);

}

int main()
{
	Contact pc;
	test();
	
	//销毁通讯录
	DestoryContact(&pc);
	system("pause");
	return 0;
}


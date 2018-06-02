#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//初始化通讯录
void InitContact(pContact pc)
{
	assert(pc);
	pc->size = 0;
	pc->capacity = 3;
	pc->data = (pPeoInfo)malloc((pc->capacity)*sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("\t\t\t内存分配失败");
		exit(EXIT_FAILURE);
	}
	memset(pc->data,0,sizeof(pc->data));
}
//检查扩容
void CheckCapacity(pContact pc)
{
	assert(pc);
	pPeoInfo *p = NULL;
	if (pc->size == pc->capacity)
	{
		p = (pPeoInfo)realloc(pc->data, (pc->capacity + 2)*sizeof(PeoInfo));
		if (p != NULL)
		{
			pc->data = p;

		}
		else
		{
			printf("\t\t\t增容失败");
			exit(EXIT_FAILURE);
		}

		pc->capacity += 2;
		printf("\t\t\t增容成功\n");
	}
}
//添加联系人
void AddContact(pContact pc)
{
	assert(pc);
	if (pc->size == MAX_SIZE)
	{
		printf("\t\t\t空间不足");
		return;
	}
	CheckCapacity(pc);
	printf("\t\t\t请输入姓名:>");
	scanf("%s", pc->data[pc->size].Name);
	printf("\t\t\t请输入性别:>");
	scanf("%s", pc->data[pc->size].Sex);
	printf("\t\t\t请输入年龄:>");
	scanf("%d", &pc->data[pc->size].age);
	printf("\t\t\t请输入电话号:>");
	scanf("%s", pc->data[pc->size].Tel);
	printf("\t\t\t请输入地址:>");
	scanf("%s", pc->data[pc->size].Addr);
	pc->size++;
	printf("\t\t\t添加成功\n");
}
//查找联系人
int SearchContact(pContact pc)
{
	char name[MAX_NAME];
	int i = 0;
	assert(pc);
	if (0 == pc->size)
	{
		printf("\t\t\t无此联系人\n");
		return -1;
	}
	printf("\t\t\t");
	scanf("%s", name);
	printf("\t\t\tName\tSex\tAge\tTel\t\tAddr\n");
	for (i = 0; i < pc->size; i++)
	{
		if (0 == strcmp(pc->data[i].Name, name))
		{

			printf("\t\t\t%-5s\t%-5s\t%-5d\t%-12s\t%-15s\n",
				pc->data[i].Name,
				pc->data[i].Sex,
				pc->data[i].age,
				pc->data[i].Tel,
				pc->data[i].Addr);
			return i;
		}
	}
	printf("\t\t\t无此联系人\n");
	return -1;

}
//删除联系人
void DeleteContact(pContact pc)
{
	int i = 0;
	int num = 0;
	assert(pc);
	if (0 == pc->size)
	{
		printf("\t\t\t无联系人\n");
		return;
	}
	num = SearchContact(pc);
	if (num != -1)
	{
		int n = 0;
		printf("\t\t\t确定删除？  1.yes,  2.no:>");
		printf("\t\t\t");
		scanf("%d", &n);
		if (1 == n)
		{
			for (i = num; i < (pc->size) - 1; i++)
			{
				pc->data[i] = pc->data[i + 1];

			}
			pc->size--;
			printf("\t\t\t删除成功\n");
		}
		else
		{
			return;
		}
	}

}

//交换
void Swap(pPeoInfo *a, pPeoInfo *b)
{
	pPeoInfo *Tmp;
	Tmp = *a;
	*a = *b;
	*b = Tmp;

}


//修改联系人
void ModifyContact(pContact pc)
{
	int modify = 0;
	assert(pc);
	if (0 == pc->size)
	{
		printf("\t\t\t无联系人\n");
		return;
	}
	modify = SearchContact(pc);
	if (modify != -1)
	{
		int n = 0;
		printf("\t\t\t确认修改？1.yes  2.no:>");
		printf("\t\t\t");
		scanf("%d", &n);
		if (1 == n)
		{
			printf("\t\t\t请输入姓名:>");
			scanf("%s", pc->data[modify].Name);
			printf("\t\t\t请输入性别:>");
			scanf("%s", pc->data[modify].Sex);
			printf("\t\t\t请输入年龄:>");
			scanf("%d", &pc->data[modify].age);
			printf("\t\t\t请输入电话号:>");
			scanf("%s", pc->data[modify].Tel);
			printf("\t\t\t请输入地址:>");
			scanf("%s", pc->data[modify].Addr);
			printf("\t\t\t修改成功\n");


		}
		else
		{
			return;
		}
	}


}
//按姓排序
void SortContact(pContact pc)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	assert(pc);
	if (0 == pc->size)
	{
		printf("\t\t\t无联系人\n");
		return;
	}
	// 冒泡次数
	for (i = 0; i < pc->size - 1; i++)
	{
		//冒泡排序
		for (j = 0; j < pc->size - i - 1; j++)
		{
			if (strcmp(pc->data[j].Name, pc->data[j + 1].Name)>0)
			{
				Swap(&pc->data[j], &pc->data[j + 1]);
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
	printf("排序成功\n");
}
//列表联系人
void ShowContact(pContact pc)
{
	int i = 0;
	assert(pc);
	if (0 == pc->size)
	{
		printf("\t\t\t无联系人\n");
		return;
	}
	printf("\t\t\tName\tSex\tAge\tTel\t\tAddr\n");
	for (i = 0; i < pc->size; i++)
	{
		printf("\t\t\t%-5s\t%-5s\t%-5d\t%-12s\t%-15s\n",
			pc->data[i].Name,
			pc->data[i].Sex,
			pc->data[i].age,
			pc->data[i].Tel,
			pc->data[i].Addr);

	}

}
//清空联系人
void EmptyContact(pContact pc)
{
	assert(pc);
	pc->size = 0;
	printf("\t\t\t清空成功");
}
//销毁通讯录
void DestoryContact(pContact pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->size = 0;
	printf("\t\t\t销毁成功");
}
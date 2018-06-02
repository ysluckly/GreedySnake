#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

enum OPPTION
{
	EXIT,
	ADD,
	SEARCH,
	DEIETE,
	MODIFY,
	SORT,
	SHOW,
	EMPTY
};

typedef char datatype;

#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TEL 11
#define MAX_ADDR 30
#define MAX_SIZE 1000

typedef struct PeoInfo
{
	datatype Name[MAX_NAME];
	datatype Sex[MAX_SEX];
	int age;
	datatype Tel[MAX_TEL];
	datatype Addr[MAX_ADDR];
}PeoInfo, *pPeoInfo;

typedef struct Contact
{
	pPeoInfo data;
	int size;
	int capacity;
}Contact, *pContact;

//初始化通讯录
void InitContact(pContact pc);
//添加联系人
void AddContact(pContact pc);
//删除联系人
void DeleteContact(pContact pc);
//查找联系人
int SearchContact(pContact pc);
//修改联系人
void ModifyContact(pContact pc);
//按姓排序
void SortContact(pContact pc);
//列表联系人
void ShowContact(pContact pc);
//清空联系人
void EmptyContact(pContact pc);
//销毁
void DestoryContact(pContact pc);


#endif //__CONTACT_H__
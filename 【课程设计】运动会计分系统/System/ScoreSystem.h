/*********************************************************************
*                  功能描述：实现西安科技大学运动会分数统计系统      *
*                  编译环境：VS 2013                                 *
*                  创建团体：物联网1601班第三小组                    *
*                  创建时间：2018.6.26                               *
*声明：															     *
*		1.该项目C语言编写，本应该.c文件，但由于加入图形界面库，		 *
*		  仅支持C++语言，所以更名为.cpp文件。						 *	
*		2.因时间原因，所以只在系统开始时引用了图形界面      		 *	   						 *
**********************************************************************/

#ifndef __SYSTEM_H__  //防止头文件的重复引用
#define __SYSTEM_H__

#include <stdio.h>
#include <conio.h>	//鼠标
#include <graphics.h>//TC2.0编译器的头文件,目前此头文件需要EeayX图形库支持编译且只支持c++
#include <mmsystem.h>//多媒体设备接口  底层驱动
#pragma comment(lib,"winmm.lib")//加载winmm静态库



//图形界面大小
#define WINDOS_WIDE 600
#define WINDOS_HIGH 400

#define N 20 //学校最大数目
#define M 20 //男项目最大数目
#define W 20 //女项目最大数目

//项目信息
typedef struct Project
{
	int inum;//项目编号
	int top; //名次数目
	int range[5]; //名次数组
	int mark[5];//分数

}itemnode; 

//学校信息
typedef struct school
{
	int snum;//学校编号
	int score;//学校总分
	int mscore;//男团体总分
	int wscore;//女团体总分
	itemnode t[M+W];//项目总数

}snode;	
extern snode a[N];    //定义一个学校数组







//菜单选项
void meau();
//界面初始化
void BeginInit();
//鼠标点击进入
void Press();
//保存信息
void savetofile();
//读取信息
void readfromfile();

// ①信息输入
void InputInformation(int n,int m,int w);
//// ②统计输出
void OutInformation(int n, int m, int w);
// ③排序输出
void OutSort(int n,int m,int w);
// ④信息查询
void OutSearch(int n,int m,int w);





#endif	 //__SYSTEM_H__
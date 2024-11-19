/**
**************************************************
*   版本号：1.0
*   作者：X
*   生成日期：2024—4—15
*   说明：Init类函数包含初始化，退出，返回等基本函数
**************************************************
**/

#include<graphics.h>
#include"init.h"

/****************************************
FUNCTION:ClearGraph
DESCRIBETION:清空屏幕，用指定颜色填充，重新初始化鼠标
INPUT:color
RETURN:void
****************************************/
void ClearGraph(int color)
{
    mouseinit();
    setfillstyle(1, color);
    bar(0, 0, 640, 480);
}

/****************************************
FUNCTION:DrawCloseButton
DESCRIBETION:绘制关闭按钮
INPUT:void
RETURN:void
****************************************/
void DrawCloseButton()
{
    setcolor(BLUE);
    setlinestyle(0, 0, 1);
    rectangle(610,0,639,29);
    line(610,0,639,29);
    line(610,29,639,0);
}

/****************************************
FUNCTION:DrawReturnButton
DESCRIBETION:绘制退出按钮
INPUT:void
RETURN:void
****************************************/
void DrawReturnButton()
{
    setcolor(BLUE);
    setlinestyle(0, 0, 1);
    rectangle(0,0,29,29);
    line(5,15,25,15);
    line(5,15,15,5);
    line(5,15,15,25);
}

/***********************
FUNCTION:Draw
DESCRIBETION:绘制设置
INPUT:void
REUTRUN:void
***********************/
void Draw(int color)
{
	
	setbkcolor(WHITE);
	setcolor(color);
	setlinestyle(0,0,1);
	setviewport(0,0,639,479,0);//set
}
/**
**************************************************
*   �汾�ţ�1.0
*   ���ߣ�X
*   �������ڣ�2024��4��15
*   ˵����Init�ຯ��������ʼ�����˳������صȻ�������
**************************************************
**/

#include<graphics.h>
#include"init.h"

/****************************************
FUNCTION:ClearGraph
DESCRIBETION:�����Ļ����ָ����ɫ��䣬���³�ʼ�����
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
DESCRIBETION:���ƹرհ�ť
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
DESCRIBETION:�����˳���ť
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
DESCRIBETION:��������
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
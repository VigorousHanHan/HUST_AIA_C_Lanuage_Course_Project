/**
**************************************************?
*   版本号：1.0
*   作者：X
*   生成日期：2024—3—10
*   说明：Page类函数实现打开页面功能
**************************************************?
**/

#include<graphics.h>
#include"display.h"
#include"hz.h"
#include"menu.h"
#include"mouse.h"
#include"navigat.h"
#include"page.h"
/****************************************
FUNCTION:OpenMainPage
DESCRIBETION:打开主页
INPUT:void
RETURN:void
****************************************/
void OpenMainPage()
{
    while(1)
    {
        int main_page_ret = 1;
        ClearGraph(WHITE);
        DrawCloseButton();
        DrawMenuButton();
        DrawDisplayButton();
        DrawNavigationButton();
        main_page_ret = MainPageMouse();
        if(!main_page_ret)
            return ;
    }
    
}



/****************************************
FUNCTION:DrawMenuButton
DESCRIBETION:绘制菜单按钮
INPUT:void
RETURN:void
****************************************/
void DrawMenuButton()
{
    setcolor(BLUE);
    setlinestyle(0, 0, 1);
    setfillstyle(1, BLUE);

    rectangle(80, 40, 240, 230);
    line(80, 200, 240, 200);
    puthz(117, 203, "菜单", 24, 62, BLUE);

    fillellipse(124, 72, 12, 12);
    fillellipse(124, 120, 12, 12);
    fillellipse(124, 168, 12, 12);
    bar(144, 60, 220, 84);
    bar(144, 108, 220, 132);
    bar(144, 156, 220, 180);
}

/****************************************
FUNCTION:DrawDisplayButton
DESCRIBETION:绘制显示按钮
INPUT:void
RETURN:void
****************************************/
void DrawDisplayButton()
{
    setcolor(BLUE);
    setlinestyle(0, 0, 1);
    setfillstyle(1, BLUE);

    rectangle(400, 40, 560, 230);
    line(400, 200, 560, 200);
    puthz(437, 203, "显示", 24, 62, BLUE);

    line(430, 60, 530, 60);
    line(430, 180, 530, 180);
    line(420, 70, 420, 170);
    line(540, 70, 540, 170);
    ellipse(430, 70, 90, 180, 10, 10);
    ellipse(530, 70, 0, 90, 10, 10);
    ellipse(430, 170, 180, 270, 10, 10);
    ellipse(530, 170, 270, 360, 10, 10);
    line(480, 180, 540, 100);
    floodfill(410, 50, BLUE);
}

/****************************************
FUNCTION:DrawNavigationButton()
DESCRIBETION:绘制导航按钮
INPUT:void
RETURN:void
****************************************/
void DrawNavigationButton()
{
    int point[10] = {160, 300, 100, 420, 160, 390, 220, 420, 160, 300};

    setcolor(BLUE);
    setlinestyle(0, 0, 1);
    setfillstyle(1, BLUE);

    rectangle(80, 280, 240, 470);
    line(80, 440, 240, 440);
    puthz(117, 443, "导航", 24, 62, BLUE);

    drawpoly(5, point);
    floodfill(160, 360, BLUE);
}

/****************************************
FUNCTION:MainPageMouse
DESCRIBETION:主页鼠标
INPUT:void
RETURN:int
****************************************/
int MainPageMouse()
{
    int page[5] = {0, 0, 0, 0, 0};
    while(1)
    {
        //绘制鼠标和设置按钮
        newmouse(&MouseX, &MouseY, &press);
        page[1] = mouse_press(80, 40, 240, 230);
        page[2] = mouse_press(400, 40, 560, 230);
        page[3] = mouse_press(80, 280, 240, 470);
        page[0] = mouse_press(610, 0, 639, 29);

        //判断选项
        if(page[1] == 1)
        {
            ClearGraph(WHITE);
			OpenMenu();
			break;
        }
        else if(page[2] == 1)
        {
			ClearGraph(WHITE);
			OpenDisplay();
            break;      
        }
        else if(page[3] == 1)
        {
			ClearGraph(WHITE);
			OpenNavigation();
            break;
        }
        else if(page[0] == 1)
        {
			closegraph();
			return 0;
        }
    }
    return 1;
}

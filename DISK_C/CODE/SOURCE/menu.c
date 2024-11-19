/**
**************************************************?
*   版本号：1.0
*   作者：X
*   生成日期：2024—3—19
*   说明：Menu类函数实现菜单功能
**************************************************?
**/

#include"ac.h"
#include"battery.h"
#include"door.h"
#include"drive.h"
#include"init.h"
#include"light.h"
#include"menu.h"
#include"page.h"
#include"window.h"
#include"wiper.h"
#include"sunroof.h"
#include"tire.h"

/****************************************
FUNCTION:OpenMenu
DESCRIBETION:打开菜单页
INPUT:void
RETURN:void
****************************************/
void OpenMenu()
{
    while(1)
    {
        int menu_ret = 1;
        //绘制界面
        ClearGraph(WHITE);
        DrawDriveButton();
        DrawBatteryButton();
        DrawAirconditionButton();
        DrawLightButton();
        DrawDoorButton();
        DrawWindowButton();
        DrawWiperButton();
        DrawSunroofButton();
        DrawTireButton();
        DrawMenuBackButton();
        menu_ret = MenuMouse();

        if(!menu_ret)
            return ;
    }

}

/****************************************
FUNCTION:DrawDriveButton
DESCRIBETION:绘制驾驶按钮
INPUT:void
RETURN:void
****************************************/
void DrawDriveButton()
{
    setcolor(BLUE);
    setlinestyle(0, 0, 1);

    rectangle(14, 20, 114, 220);
    line(14, 180, 114, 180);
    puthz(31, 188, "驾驶", 24, 42, BLUE);

    setcolor(DARKGRAY);
    setfillstyle(1, DARKGRAY);

    circle(64, 100, 45);
    circle(64, 100, 35);
    circle(64, 98, 5);
    ellipse(64, 100, 30, 150, 15, 15);
    line(30, 92, 60, 92);
    line(68, 92, 98, 92);
    line(30, 104, 50, 104);
    line(78, 104, 98, 104);
    line(60, 114, 60, 135);
    line(68, 114, 68, 135);
    ellipse(50, 114, 0, 90, 10, 10);
    ellipse(78, 114, 90, 180, 10, 10);
    floodfill(64, 60, DARKGRAY);
    floodfill(64, 90, DARKGRAY);

}

/****************************************
FUNCTION:DrawBatteryButton
DESCRIBETION:绘制电池按钮
INPUT:void
RETURN:void
****************************************/
void DrawBatteryButton()
{
    int point[12] = {162, 30, 187, 30, 187, 25, 197, 25, 197, 30, 222, 30};

    setcolor(BLUE);
    setlinestyle(0, 0, 1);

    rectangle(142, 20, 242, 220);
    line(142, 180, 242, 180);
    puthz(159, 188, "电池", 24, 42, BLUE);

    setcolor(DARKGRAY);
    setfillstyle(1, DARKGRAY);

    line(147, 45, 147, 160);
    line(157, 45, 157, 160);
    line(162, 165, 222, 165);
    line(162, 175, 222, 175);
    line(227, 45, 227, 160);
    line(237, 45, 237, 160);
    line(162, 40, 222, 40);
    drawpoly(6, point);
    ellipse(222, 45, 0, 90, 5, 5);
    ellipse(222, 45, 0, 90, 15, 15);
    ellipse(162, 45, 90, 180, 5, 5);
    ellipse(162, 45, 90, 180, 15, 15);
    ellipse(162, 160, 180, 270, 5, 5);
    ellipse(162, 160, 180, 270, 15, 15);
    ellipse(222, 160, 270, 0, 5, 5);
    ellipse(222, 160, 270, 0, 15, 15);
    floodfill(192, 30, DARKGRAY);

    setfillstyle(1, GREEN);
    floodfill(192, 100, DARKGRAY);
}

/****************************************
FUNCTION:DrawAirconditionButton
DESCRIBETION:绘制空调按钮
INPUT:void
RETURN:void
****************************************/
void DrawAirconditionButton()
{
    setcolor(BLUE);
    setlinestyle(0, 0, 1);
    setfillstyle(1, BLUE);

    rectangle(270, 20, 370, 220);
    line(270, 180, 370, 180);
    puthz(287, 188, "空调", 24, 42, BLUE);

    setcolor(LIGHTBLUE);

    line(320, 75, 310, 65);
    line(320, 75, 330, 65);
    line(320, 125, 310, 135);
    line(320, 125, 330, 135);
    line(298, 112, 294, 126);
    line(298, 112, 284, 108);
    line(298, 87, 294, 73);
    line(298, 87, 284, 91);
    line(342, 87, 356, 91);
    line(342, 87, 346, 73);
    line(342, 112, 346, 127);
    line(342, 112, 356, 109);

    setlinestyle(0, 0, 3);

    line(320, 60, 320, 140);
    line(285, 80, 355, 120);
    line(285, 120, 355, 80);
}

/****************************************
FUNCTION:DrawLightButton
DESCRIBETION:绘制灯光按钮
INPUT:void
RETURN:void
****************************************/
void DrawLightButton()
{
    setcolor(BLUE);
    setlinestyle(0, 0, 1);

    rectangle(398, 20, 498, 220);
    line(398, 180, 498, 180);
    puthz(415, 188, "灯光", 24, 42, BLUE);

    setcolor(DARKGRAY);
    setfillstyle(1, DARKGRAY);
    
    ellipse(448, 80, -60, 240, 45, 45);
    line(425, 118, 425, 138);
    line(471, 118, 471, 138);
    line(425, 118, 471, 118);
    ellipse(448, 138, 180, 360, 23, 23);
    floodfill(448, 138, DARKGRAY);

    setfillstyle(1, YELLOW);
    floodfill(448, 80, DARKGRAY);
}

/****************************************
FUNCTION:DrawDoorButton
DESCRIBETION:绘制车门按钮
INPUT:void
RETURN:void
****************************************/
void DrawDoorButton()
{
    int point_out[12] = {571, 30, 531, 100, 531, 170, 621, 170, 621, 30, 571, 30};
    int point_in[10] = {571, 35, 536, 100, 616, 100, 616, 35, 571, 35};

    setcolor(BLUE);
    setlinestyle(0, 0, 1);

    rectangle(526, 20, 626, 220);
    line(526, 180, 626, 180);
    puthz(543, 188, "车门", 24, 42, BLUE);

    setcolor(DARKGRAY);
    setfillstyle(1, DARKGRAY);

    drawpoly(6, point_out);
    drawpoly(5, point_in);
    floodfill(576, 101, DARKGRAY);
}

/****************************************
FUNCTION:DrawWindowButton
DESCRIBETION:绘制车窗按钮
INPUT:void
RETURN:void
****************************************/
void DrawWindowButton()
{
    int point_out[12] = {59, 270, 19, 340, 19, 410, 109, 410, 109, 270, 59, 270};
    int point_in[10] = {59, 275, 24, 340, 104, 340, 104, 275, 59, 275};

    setcolor(BLUE);
    setlinestyle(0, 0, 1);

    rectangle(14, 260, 114, 460);
    line(14, 420, 114, 420);
    puthz(31, 428, "车窗", 24, 42, BLUE);

    setcolor(DARKGRAY);

    drawpoly(6, point_out);
    drawpoly(5, point_in);

    setfillstyle(1, LIGHTCYAN);

    floodfill(64, 339, DARKGRAY);
}

/****************************************
FUNCTION:DrawWiperButton
DESCRIBETION:绘制雨刷按钮
INPUT:void
RETURN:void
****************************************/
void DrawWiperButton()
{
    setcolor(BLUE);
    setlinestyle(0, 0, 1);


    rectangle(142, 260, 242, 460);
    line(142, 420, 242, 420);
    puthz(159, 428, "雨刷", 24, 42, BLUE);

    setcolor(DARKGRAY); 

    line(177, 365, 177, 340);
    line(207, 365, 207, 340);

    setlinestyle(0, 0, 3);

    circle(207, 365, 2);
    circle(177, 365, 2);
    line(152, 300, 232, 300);
    line(237, 305, 237, 355);
    line(152, 360, 232, 360);
    line(147, 305, 147, 355);
    ellipse(232, 305, 0, 90, 5, 5);
    ellipse(152, 305, 90, 180, 5, 5);
    ellipse(152, 355, 180, 270, 5, 5);
    ellipse(232, 355, 270, 360, 5, 5);
    line(162, 355, 197, 320);
    line(192, 355, 227, 320);
}

/****************************************
FUNCTION:DrawSunroofButton
DESCRIBETION:绘制天窗按钮
INPUT:void
RETURN:void
****************************************/
void DrawSunroofButton()
{
    setcolor(BLUE);
    setlinestyle(0, 0, 1);

    rectangle(270, 260, 370, 460);
    line(270, 420, 370, 420);
    puthz(287, 428, "天窗", 24, 42, BLUE);

    setcolor(DARKGRAY);
    setlinestyle(0, 0, 3);
    setfillstyle(1, LIGHTCYAN);

    line(280, 270, 360, 270);
    line(365, 275, 365, 405);
    line(280, 410, 360, 410);
    line(275, 275, 275, 405);
    ellipse(360, 275, 0, 90, 5, 5);
    ellipse(280, 275, 90, 180, 5, 5);
    ellipse(280, 405, 180, 270, 5, 5);
    ellipse(360, 405, 270, 360, 5, 5);
    line(285, 300, 355, 300);
    line(360, 305, 360, 375);
    line(285, 380, 355, 380);
    line(280, 305, 280, 375);
    ellipse(355, 305, 0, 90, 5, 5);
    ellipse(285, 305, 90, 180, 5, 5);
    ellipse(285, 375, 180, 270, 5, 5);
    ellipse(355, 375, 270, 360, 5, 5);
    floodfill(320, 340, DARKGRAY);
}

/****************************************
FUNCTION:DrawTireButton
DESCRIBETION:绘制胎压按钮
INPUT:void
RETURN:void
****************************************/
void DrawTireButton()
{
    setcolor(BLUE);
    setlinestyle(0, 0, 1);

    rectangle(398, 260, 498, 460);
    line(398, 420, 498, 420);
    puthz(415, 428, "胎压", 24, 42, BLUE);

    setcolor(DARKGRAY);
    setfillstyle(1, DARKGRAY);

    circle(448, 340, 5);
    circle(448, 340, 10);
    circle(448, 340, 20);
    circle(448, 340, 25);
    circle(448, 340, 30);
    circle(448, 340, 45);
    floodfill(448, 347, DARKGRAY);
    floodfill(448, 362, DARKGRAY);
    floodfill(448, 380, DARKGRAY);

    setlinestyle(0, 0, 3);

    line(448, 330, 448, 320);
    line(448, 350, 448, 360);
    line(438, 340, 428, 340);
    line(458, 340, 468, 340);
    line(433, 355, 441, 347);
    line(463, 325, 455, 333);
    line(433, 325, 441, 333);
    line(463, 355, 455, 347);
}

/****************************************
FUNCTION:DrawMenuBackButton
DESCRIBETION:绘制菜单页返回按钮
INPUT:void
RETURN:void
****************************************/
void DrawMenuBackButton()
{
    int point_up[14] = {596, 315, 541, 315, 541, 310, 531, 323, 541, 335, 541, 330, 596, 330};
    int point_down[8] = {596, 350, 531, 350, 531, 365, 596, 365};
    setcolor(BLUE);
    setlinestyle(0, 0, 1);
    setfillstyle(1, BLUE);

    rectangle(526, 260, 626, 460);
    line(526, 420, 626, 420);
    puthz(543, 428, "返回", 24, 42, BLUE);
    
    setcolor(DARKGRAY);
    setfillstyle(1, DARKGRAY);

    drawpoly(7, point_up);
    drawpoly(4, point_down);
    ellipse(596, 340, -90, 90, 10, 10);
    ellipse(596, 340, -90, 90, 25, 25);
    floodfill(541, 318, DARKGRAY);
}

/****************************************
FUNCTION:MenuMouse
DESCRIBETION:菜单页鼠标
INPUT:void
RETURN:int
****************************************/
int MenuMouse()
{
    int choice[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(1)
    {
        //绘制鼠标和设置按钮
        newmouse(&MouseX, &MouseY, &press);
        choice[1] = mouse_press(14, 20, 114, 220);
        choice[2] = mouse_press(142, 20, 242, 220);
        choice[3] = mouse_press(270, 20, 370, 220);
        choice[4] = mouse_press(398, 20, 498, 220);
        choice[5] = mouse_press(526, 20, 626, 220);
        choice[6] = mouse_press(14, 260, 114, 460);
        choice[7] = mouse_press(142, 260, 242, 460);
        choice[8] = mouse_press(270, 260, 370, 460);
        choice[9] = mouse_press(398, 260, 498, 460);
        choice[0] = mouse_press(526, 260, 626, 460);

        //判断选项
        if(choice[1] == 1)
        {
            ClearGraph(WHITE);
            OpenDrive();
            break;
        }
        else if(choice[2] == 1)
        {
            ClearGraph(WHITE);
            OpenBattery();
            break;
        }
        else if(choice[3] == 1)
        {
            ClearGraph(WHITE);
            OpenAircondition();
            break;
        }
        else if(choice[4] == 1)
        {
            ClearGraph(WHITE);
			OpenLight();
            break;
        }
        else if(choice[5] == 1)
        {
            ClearGraph(WHITE);
			OpenDoor();
            break;
        }
        else if(choice[6] == 1)
        {
            ClearGraph(WHITE);
            OpenWindow();
            break;
        }
        else if(choice[7] == 1)
        {
            ClearGraph(WHITE);
            OpenWiper();
            break;
        }
        else if(choice[8] == 1)
        {
            ClearGraph(WHITE);
            OpenSunroof();
            break;
        }
        else if(choice[9] == 1)
        {
            ClearGraph(WHITE);
            OpenTire();
            break;
        }
        else if(choice[0] == 1)
        {
            return 0;
        }
    }
    return 1;
}
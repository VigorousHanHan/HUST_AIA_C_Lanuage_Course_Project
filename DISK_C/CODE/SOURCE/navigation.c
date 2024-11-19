/**
**************************************************?
*   版本号：1.0
*   作者：X
*   生成日期：2024—3—28
*   说明：Navigation类函数实现导航功能
**************************************************?
**/

#include"init.h"
#include"map.h"
#include"navigat.h"
#include"plan.h"

/****************************************
FUNCTION:OpenNavigation
DESCRIBETION:打开导航页
INPUT:void
RETURN:void
****************************************/
void OpenNavigation()
{
    int mode[2] = {1, 1};
    while(1)
    {
        int navigation_ret = 1;
        ClearGraph(WHITE);
        DrawReturnButton();
        DrawMap();
        DrawNavigationTopButton();
        navigation_ret = NavigationMouse(mode);
        if(!navigation_ret)
            return ;
    }
}

/****************************************
FUNCTION:DrawNavigationTopButton
DESCRIBETION:绘制导航页顶部按钮
INPUT:void
RETURN:void
****************************************/
void DrawNavigationTopButton()
{
    setlinestyle(0, 0, 1);
    setcolor(BLUE);

    rectangle(45, 0, 165, 28);
    puthz(48, 2, "选择起点", 24, 30, BLUE);

    rectangle(195, 0, 315, 28);
    puthz(198, 2, "选择终点", 24, 30, BLUE);

    rectangle(345, 0, 465, 28);
    puthz(348, 2, "重新选择", 24, 30, BLUE);

    rectangle(495, 0, 615, 28);
    puthz(498, 2, "开始规划", 24, 30, BLUE);
}

/****************************************
FUNCTION:NavigationMouse
DESCRIBETION:导航页鼠标
INPUT:int* mode
RETURN:int
****************************************/
int NavigationMouse(int* mode)
{
    int choice[5] = {0}, start = -1, end = -1, distance = 0;
    char dist[10];
    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);

        choice[0]=mouse_press(0,0,29,29);
        choice[1]=mouse_press(45, 0, 165, 28);
        choice[2]=mouse_press(195, 0, 315, 28);
        choice[3]=mouse_press(345, 0, 465, 28);
        choice[4]=mouse_press(495, 0, 615, 28);

        if(choice[0] == 1)
        {
            return 0;
        }
        if(choice[1] == 1)
        {
            if(mode[0])
            {
                start = ChoosePlace();
                mode[0] = 0;
            }
        }
        if(choice[2] == 1)
        {
            if(mode[1])
            {
                end = ChoosePlace();
                mode[1] = 0;
            }
        }
        if(choice[3] == 1)
        {
            mode[0] = 1;
            mode[1] = 1;
            break;
        }
        if(choice[4] == 1 && start != -1 && end != -1)
        {
            distance = PlanPath(start, end);
            DrawRoute();
            setcolor(RED);
            settextstyle(2, 0, 6);

            itoa(distance, dist, 10);
            puthz(3, 33, "预", 24, 0, BLUE);
            puthz(3, 63, "计", 24, 0, BLUE);
            puthz(3, 93, "里", 24, 0, BLUE);
            puthz(3, 123, "程", 24, 0, BLUE);
            outtextxy(0, 150, dist);
            puthz(3, 170, "米", 24, 0, BLUE);

            itoa(distance/5, dist, 10);
            puthz(3, 233, "预", 24, 0, BLUE);
            puthz(3, 263, "计", 24, 0, BLUE);
            puthz(3, 293, "用", 24, 0, BLUE);
            puthz(3, 323, "时", 24, 0, BLUE);
            outtextxy(0, 350, dist);
            puthz(3, 370, "秒", 24, 0, BLUE);

            start = -1, end = -1;
        }

    }
    return 1;
}

/****************************************
FUNCTION:ChoosePlace
DESCRIBETION:选择地点
INPUT:void
RETURN:int
****************************************/
int ChoosePlace()
{
    int place[14] = {0}, i = 0;
    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);
        place[ 0]=mouse_press(40,40,120,70);        //科技楼北楼
        place[ 1]=mouse_press(40,90,120,120);       //科技楼南楼
        place[ 2]=mouse_press(30, 150, 80, 270);    //图书馆
        place[ 3]=mouse_press(60, 340, 110, 370);   //南三楼
        place[ 4]=mouse_press(40, 440, 110, 470);   //建规学院
        place[ 5]=mouse_press(135, 335, 205, 365)+mouse_press(135, 395, 205, 425)+\
        mouse_press(305, 335, 375, 365)+mouse_press(305, 395, 375, 425)+mouse_press(175, 365, 335, 395);
        place[ 6]=mouse_press(215, 335, 295, 360);  //南六楼
        place[ 7]=mouse_press(160, 240, 260, 290);  //校史馆
        place[ 8]=mouse_press(140, 140, 320, 220);  //停车场
        place[ 9]=mouse_press(340, 80, 390, 110);   //网球场
        place[10]=mouse_press(430, 140, 530, 170);  //东八楼
        place[11]=mouse_press(405, 175, 555, 225);  //东一楼
        place[12]=mouse_press(570, 250, 620, 280);  //东三楼
        place[13]=mouse_press(450, 440, 500, 480);  //游泳馆
        
        setfillstyle(1, GREEN);
        if(place[0]==1)
        {
            fillellipse(80, 55, 5, 5);
        }
        else if(place[1]==1)
        {
            fillellipse(80, 105, 5, 5);
        }
        else if(place[2]==1)
        {
            fillellipse(55, 210, 5, 5);
        }
        else if(place[3]==1)
        {
            fillellipse(85, 355, 5, 5);
        }
        else if(place[4]==1)
        {
            fillellipse(75, 455, 5, 5);
        }
        else if(place[5]==1)
        {
            fillellipse(255, 380, 5, 5);
        }
        else if(place[6]==1)
        {
            fillellipse(255, 348, 5, 5);
        }
        else if(place[7]==1)
        {
            fillellipse(210, 265, 5, 5);
        }
        else if(place[8]==1)
        {
            fillellipse(230, 180, 5, 5);
        }
        else if(place[9]==1)
        {
            fillellipse(365, 95, 5, 5);
        }
        else if(place[10]==1)
        {
            fillellipse(480, 155, 5, 5);
        }
        else if(place[11]==1)
        {
            fillellipse(480, 200, 5, 5);
        }
        else if(place[12]==1)
        {
            fillellipse(595, 265, 5, 5);
        }
        else if(place[13]==1)
        {
            fillellipse(475, 460, 5, 5);
        }

        for(i = 0; i < 14; i++)
        {
            if(place[i] == 1)
                return i;
        }
    }
}
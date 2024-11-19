/**
**************************************************?
*   版本号：1.0
*   作者：X
*   生成日期：2024—3—6
*   说明：Sunroof类函数实现天窗功能
**************************************************?
**/

#include"init.h"
#include"sunroof.h"

/****************************************
FUNCTION:OpenSunroof
DESCRIBETION:打开天窗页
INPUT:void
RETURN:void
****************************************/
void OpenSunroof()
{
    while(1)
    {
        int sunroof_ret = 1, i = 0, num[4];
        FILE* sunroof_text;

        setfillstyle(1, WHITE);
        bar(0, 0, 640, 480);

        sunroof_text = fopen("..\\CODE\\text\\sunroof.txt", "rt");
        for(i = 0; i < 5; i++)
        {
            fscanf(sunroof_text, "%d ", &num[i]);
        }
        fclose(sunroof_text);

        DrawReturnButton();
        DrawPartSunroofButton();
        DrawSunroof();
        DrawSunroofChangePart(num);
        PutSunroofHz();
        sunroof_ret = SunroofMouse(num);


        sunroof_text = fopen("..\\CODE\\text\\sunroof.txt", "wt");
        for(i = 0; i < 4; i++)
        {
            fprintf(sunroof_text, "%d ", num[i]);
        }
        fclose(sunroof_text);

        if(!sunroof_ret)
            return ;
    }
}

/****************************************
FUNCTION:DrawPartSunroofButton
DESCRIBETION:绘制天窗页部分按钮
INPUT:void
RETURN:void
****************************************/
void DrawPartSunroofButton()
{
    setlinestyle(0, 0, 3);
    line(65, 70, 255, 70);
    line(65, 110, 255, 110);
    ellipse(65, 90, 90, 270, 20, 20);
    ellipse(255, 90, 270, 450, 20, 20);
    puthz(65, 74, "天窗锁", 32, 47+32, BLUE);
    circle(100, 150, 20);   //on
    circle(220, 150, 20);   //off

    setlinestyle(0, 0, 3);
    line(65, 70+120, 255, 70+120);
    line(65, 110+120, 255, 110+120);
    ellipse(65, 90+120, 90, 270, 20, 20);
    ellipse(255, 90+120, 270, 450, 20, 20);
    puthz(65, 74+120, "微通风", 32, 47+32, BLUE);
    circle(100, 150+120, 20);   //on
    circle(220, 150+120, 20);   //off

    setlinestyle(0, 0, 3);
    line(65, 70+240, 255, 70+240);
    line(65, 110+240, 255, 110+240);
    ellipse(65, 90+240, 90, 270, 20, 20);
    ellipse(255, 90+240, 270, 450, 20, 20);
    puthz(65, 74+240, "热保护", 32, 47+32, BLUE);
    settextstyle(8, 0, 2);
    circle(100, 150+240, 20);   //on
    circle(220, 150+240, 20);   //off
}

/****************************************
FUNCTION:DrawSunroof
DESCRIBETION:绘制天窗
INPUT:void
RETURN:void
****************************************/
void DrawSunroof()
{
    setcolor(DARKGRAY);
    //天窗外框
    ellipse(620, 105, 0, 90, 5, 5);
    ellipse(340, 105, 90, 180, 5, 5);
    ellipse(340, 315, 180, 270, 5, 5);
    ellipse(620, 315, 270, 360, 5, 5);
    line(620, 100, 340, 100);
    line(335, 105, 335, 315);
    line(340, 320, 620, 320);
    line(625, 315, 625, 105);
    //天窗内框
    ellipse(575, 115, 0, 90, 5, 5);
    ellipse(385, 115, 90, 180, 5, 5);
    ellipse(385, 305, 180, 270, 5, 5);
    ellipse(575, 305, 270, 360, 5, 5);
    line(575, 110, 385, 110);
    line(380, 115, 380, 305);
    line(385, 310, 575, 310);
    line(580, 310, 580, 110);
    
    //天窗按钮
    setcolor(BLUE);
    circle(400, 350, 20);
    line(410, 340, 390, 350);
    line(410, 360, 390, 350);
    circle(560, 350, 20);
    line(550, 340, 570, 350);
    line(550, 360, 570, 350);
}

/****************************************
FUNCTION:DrawSunroofChangePart
DESCRIBETION:绘制天窗页变化部分
INPUT:int"* 
RETURN:void
****************************************/
void DrawSunroofChangePart(int* num)
{
    if(num[0] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(100, 150, BLUE);
        setfillstyle(1, LIGHTCYAN);
        floodfill(480, 210, DARKGRAY);
    }
    else if(num[0] == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(220, 150, BLUE);
        if(num[1] == 1)
        {
            floodfill(100, 150+120, BLUE);
        }
        else if(num[1] == 2)
        {
            floodfill(220, 150+120, BLUE);
        }
        if(num[2] == 1)
        {
            floodfill(100, 150+240, BLUE);
        }
        else if(num[2] == 2)
        {
            floodfill(220, 150+240, BLUE);
        }
        if(num[3])
        {
            setlinestyle(0, 0, 3);
            setcolor(DARKGRAY);
            line(380+22*num[3], 110, 380+22*num[3], 310);
            setfillstyle(1, LIGHTCYAN);
            floodfill(390, 210, DARKGRAY);
            setcolor(LIGHTCYAN);
            line(380+22*num[3], 112, 380+22*num[3], 308);
        }    
    }
}

/****************************************
FUNCTION:PutSunroofHz
DESCRIBETION:显示天窗页文本
INPUT:void
RETURN:void
****************************************/
void PutSunroofHz()
{
    settextstyle(8, 0, 2);
    setcolor(BLUE);
    outtextxy(87, 132, "on");    
    outtextxy(205, 132, "off");
    outtextxy(87, 132+120, "on");
    outtextxy(205, 132+120, "off");
    outtextxy(87, 132+240, "on");
    outtextxy(205, 132+240, "off");
}

/****************************************
FUNCTION:SunroofMouse
DESCRIBETION:天窗页鼠标
INPUT:int*
RETURN:int
****************************************/
int SunroofMouse(int* num)
{
    int choice[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(1)
    {
        //绘制鼠标和设置按钮
        newmouse(&MouseX,&MouseY,&press);

        choice[0]=mouse_press(0,0,29,29);

        //天窗锁
        choice[1]=mouse_press(80, 130, 120, 170);  //on
        choice[2]=mouse_press(200, 130, 240, 170);  //off
        //微通风
        choice[3]=mouse_press(80, 130+120, 120, 170+120);  //on
        choice[4]=mouse_press(200, 130+120, 240, 170+120);  //off
        //热保护
        choice[5]=mouse_press(80, 130+240, 120, 170+240);  //on
        choice[6]=mouse_press(200, 130+240, 240, 170+240);  //off
        //天窗
        choice[7]=mouse_press(380, 330, 420, 370);  //左
        choice[8]=mouse_press(540, 330, 580, 370);  //右

        //判断选项
        if(choice[0]==1)
        {
            ClearGraph(WHITE);
            return 0;
        }
        else if(choice[1]==1)
        {
            num[0] = 1;
            num[3] = 9;
            break;
        }
		else if(choice[2]==1)
        {
            num[0] = 2;
            break;
        }
        else if(choice[3]==1)
        {
            num[1] = 1;
            break;
        }
        else if(choice[4]==1)
        {
            num[1] = 2;
            break;
        }
        else if(choice[5]==1)
        {
            num[2] = 1;
            break;
        }
        else if(choice[6]==1)
        {
            num[2] = 2;
            break;
        }
        else if(choice[7]==1)
        {
            if(num[3] > 0)
            {
                num[3]-=1;
            }
            break;
        }
        else if(choice[8]==1)
        {
            if(num[3] < 9)
            {
                num[3]+=1;
            }
            break;
        }
    }
    return 1;
}
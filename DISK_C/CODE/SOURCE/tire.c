/**
**************************************************?
*   版本号：1.0
*   作者：X
*   生成日期：2024—3—7
*   说明：Tire类函数实现胎压功能
**************************************************?
**/

#include<time.h>
#include"init.h"
#include"tire.h"

/****************************************
FUNCTION:OpenTire
DESCRIBETION:打开胎压页
INPUT:void
RETURN:void
****************************************/
void OpenTire()
{
    while(1)
    {
        int tire_ret = 1, i = 0, num[5]={0};
        FILE* tire_text;

        setfillstyle(1, WHITE);
        bar(0, 0, 640, 480);

        tire_text = fopen("..\\CODE\\text\\tire.txt", "rt");
        for(i = 0; i < 4; i++)
        {
            fscanf(tire_text, "%d ", &num[i]);
            if(num[i]<230 || num[i]>280)
            {
                num[4] = 1;
            }
        }
        fclose(tire_text);

        DrawReturnButton();
        DrawTireCar();
        PutTireBar(407, 100, num[0]);
        PutTireBar(407, 300, num[1]);
        PutTireBar(513, 100, num[2]);
        PutTireBar(513, 300, num[3]);
        DrawTireChangePart(num);
        tire_ret = TireMouse(num);

        tire_text = fopen("..\\CODE\\text\\tire.txt", "wt");
        for(i = 0; i < 5; i++)
        {
            fprintf(tire_text, "%d ", num[i]);
        }
        fclose(tire_text);

        if (!tire_ret)
            return ;
    }
}

/****************************************
FUNCTION:DrawOneTire
DESCRIBETION:绘制一个轮胎
INPUT:int x, int y
RETURN:void
****************************************/
void DrawOneTire(int x, int y)
{
    setcolor(DARKGRAY);
    setfillstyle(1, DARKGRAY);
    setlinestyle(0, 0, 1);
    line(0+x, 0+y, 0+x, 30+y);
    line(10+x, 0+y, 10+x, 30+y);
    ellipse(5+x, 0+y, 0, 180, 5, 2);
    ellipse(5+x, 30+y, 180, 360, 5, 2);
    floodfill(5+x, 15+y, DARKGRAY);
}

/****************************************
FUNCTION:PutTireBar
DESCRIBETION:显示胎压
INPUT:int x, int y
RETURN:void
****************************************/
void PutTireBar(int x, int y, int bar)
{
	char pressure[10];
    itoa(bar, pressure, 10);
    if(bar>=230 && bar<=280)
    {
        setcolor(BLUE);     
    }
    else if(bar<230 || bar>280)
    {
        setcolor(RED);
    }
    settextstyle(8, 0, 2);
    outtextxy(x, y, pressure); 
}

/****************************************
FUNCTION:DrawTireCar
DESCRIBETION:绘制胎压页汽车
INPUT:void
RETURN:void
****************************************/
void DrawTireCar()
{
    setcolor(DARKGRAY);
    setlinestyle(0, 0, 3);
    moveto(390, 80);
    lineto(390, 180);
    lineto(370, 200);
    lineto(390, 200);
    lineto(390, 360);
    lineto(400, 380);
    moveto(560, 380);
    lineto(570, 360);
    lineto(570, 200);
    lineto(590, 200);
    lineto(570, 180);
    lineto(570, 80);
    ellipse(430, 80, 90, 180, 40, 10);
    ellipse(530, 80, 0, 90, 40, 10);
    ellipse(480, 73, 0, 180, 50, 10);
    ellipse(480, 380, 180, 360, 80, 10);
    DrawOneTire(395, 100);
    DrawOneTire(395, 300);
    DrawOneTire(555, 100);
    DrawOneTire(555, 300);
    puthz(436, 40, "单位：", 16, 18, BLUE);
    setcolor(BLUE);
    settextstyle(8, 0, 2);
    outtextxy(480, 30, "kpa"); 

    puthz(36, 44, "快速修复", 32, 32, BLUE);
    rectangle(20, 40, 180, 80);
}

/****************************************
FUNCTION:DrawTireChangePart
DESCRIBETION:绘制胎压页的可变部分
INPUT:int* num
RETURN:void
****************************************/
void DrawTireChangePart(int* num)
{
    if(num[4] == 1)
    {
        if(num[0]<230 || num[0]>280)
        {
            puthz(20, 200, "左前轮胎压异常", 32, 32, RED);
        }
        if(num[1]<230 || num[1]>280)
        {
            puthz(20, 240, "左后轮胎压异常", 32, 32, RED);
        }
        if(num[2]<230 || num[2]>280)
        {
            puthz(20, 280, "右前轮胎压异常", 32, 32, RED);
        }
        if(num[3]<230 || num[3]>280)
        {
            puthz(20, 320, "右后轮胎压异常", 32, 32, RED);
        }
    }
}

/****************************************
FUNCTION:TireMouse
DESCRIBETION:胎压页鼠标
INPUT:int* num
RETURN:int
****************************************/
int TireMouse(int* num)
{
    int choice[2] = {0}, i;
    while(1)
    {
        //绘制鼠标和设置按钮
        newmouse(&MouseX,&MouseY,&press);

        choice[0]=mouse_press(0,0,29,29);
        choice[1]=mouse_press(20, 40, 180, 80);
        //判断选项
        if(choice[0]==1)
        {
            ClearGraph(WHITE);
            return 0;  
        }
        else if(choice[1]==1)
        {
            for(i = 0; i < 4; i++)
            {
                if(num[i]<230 || num[i]>280)
                {
                    srand(time(NULL));
                    num[i] = rand()%50+230;
                    delay(1000);
                }
            }
            break;
        }
    }
    return 1;
}
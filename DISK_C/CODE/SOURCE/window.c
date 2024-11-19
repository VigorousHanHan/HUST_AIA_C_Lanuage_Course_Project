/**
**************************************************?
*   版本号：1.0
*   作者：X
*   生成日期：2024—3—8
*   说明：Window类函数实现车窗功能
**************************************************?
**/

#include"init.h"
#include"window.h"

/****************************************
FUNCTION:OpenWindow
DESCRIBETION:打开车窗页
INPUT:void
RETURN:void
****************************************/
void OpenWindow()
{
    while(1)
    {
        int i = 0, num[8], window_ret = 1;
        FILE* window_text;

        window_text = fopen("..\\CODE\\text\\window.txt", "rt");
        for(i = 0; i < 8; i++)
        {
            fscanf(window_text, "%d ", &num[i]);
        }
        fclose(window_text);

        setfillstyle(1, WHITE);
        bar(0, 0, 640, 480);

        DrawReturnButton();
        DrawOneWindow(0, 0);    //Left Ahead
        DrawOneWindow(300, 0);  //Right Ahead
        DrawOneWindow(0, 220);  //Left Behind
        DrawOneWindow(300, 220);//Right Behind
        DrawWindowChangePart(num);
        PutWindowHz();
        window_ret = WindowMouse(num);

        window_text = fopen("..\\CODE\\text\\window.txt", "wt");
        for(i = 0; i < 8; i++)
        {
            fprintf(window_text, "%d ", num[i]);
        }
        fclose(window_text);

        if(!window_ret) //If zero, then return
            return ;
    }
}

/****************************************
FUNCTION:DrawOneWindow
DESCRIBETION:绘制一个车窗
INPUT:int x, int y
RETURN:void
****************************************/
void DrawOneWindow(int x, int y)
{
    //绘制方框
    setcolor(BLUE);
    setlinestyle(0, 0, 1);
    rectangle(40+x, 40+y, 300+x, 220+y);
    line(80+x, 40+y, 80+x, 220+y);
    line(190+x, 40+y, 190+x, 220+y);
    line(80+x, 180+y, 300+x, 180+y);
    line(135+x, 180+y, 135+x, 220+y);
    //绘制上下按钮
    setlinestyle(0, 0, 3);
    line(90+x, 215+y, 107+x, 190+y);
    line(108+x, 190+y, 125+x, 215+y);
    line(145+x, 190+y, 162+x, 215+y);
    line(163+x, 215+y, 180+x, 190+y);
    //绘制车窗 (85, 60) (185, 160)
    setcolor(LIGHTGRAY);
    ellipse(90+x, 65+y, 90, 180, 5, 5);
    ellipse(90+x, 155+y, 180, 270, 5, 5);
    ellipse(180+x, 155+y, 270, 360, 5, 5);
    ellipse(180+x, 65+y, 0, 90, 5, 5);
    line(90+x, 60+y, 180+x, 60+y);
    line(90+x, 160+y, 180+x, 160+y);
    line(85+x, 65+y, 85+x, 155+y);
    line(185+x, 65+y, 185+x, 155+y);

    //绘制儿童锁
    puthz(193+x, 184+y, "儿童锁", 32, 36, BLUE);
    setcolor(BROWN);
    setlinestyle(0, 0, 1);
    setfillstyle(1, BROWN);
    rectangle(200+x, 110+y, 290+x, 160+y);
    floodfill(245+x, 135+y, BROWN);
    setcolor(DARKGRAY);
    setfillstyle(1, DARKGRAY);
    circle(245+x, 135+y, 5);
    floodfill(245+x, 135+y, DARKGRAY);
    setcolor(LIGHTGRAY);
    setfillstyle(1, LIGHTGRAY);
    line(225+x, 80+y, 225+x, 109+y);
    line(225+x, 109+y, 235+x, 109+y);
    line(235+x, 109+y, 235+x, 80+y);
    line(265+x, 80+y, 265+x, 109+y);
    line(265+x, 109+y, 255+x, 109+y);
    line(255+x, 109+y, 255+x, 80+y);
    ellipse(245+x, 80+y, 0, 180, 10, 10);
    ellipse(245+x, 80+y, 0, 180, 20, 20);
    floodfill(245+x, 65+y, LIGHTGRAY);
}

/****************************************
FUNCTION:DrawWindowChangePart
DESCRIBETION:绘制车窗页面可变的部分
INPUT:int* num
RETURN:void
****************************************/
void DrawWindowChangePart(int* num)
{
    if(num[4])
    {
        setfillstyle(1, LIGHTCYAN);
        floodfill(135, 110, LIGHTGRAY);
    }
    else
    {
        if(num[0] && num[0]!=10)
        {
            setcolor(LIGHTGRAY);
            setlinestyle(0, 0, 1);
            line(85, 160-10*num[0], 185, 160-10*num[0]);
            setfillstyle(1, LIGHTCYAN);
            floodfill(135, 155, LIGHTGRAY);  
        }
        else if(num[0]==10)
        {
            setfillstyle(1, LIGHTCYAN);
            floodfill(135, 110, LIGHTGRAY);
        }
        setfillstyle(1, WHITE);
        bar(225, 80, 235, 109);
    }

    if(num[5])
    {
        setfillstyle(1, LIGHTCYAN);
        floodfill(135 + 300, 110, LIGHTGRAY);
    }
    else
    {
        if(num[1] && num[1]!=10)
        {
            setcolor(LIGHTGRAY);
            setlinestyle(0, 0, 1);
            line(85+300, 160-10*num[1], 185+300, 160-10*num[1]);
            setfillstyle(1, LIGHTCYAN);
            floodfill(135+300, 155, LIGHTGRAY);  
        }
        if(num[1]==10)
        {
            setfillstyle(1, LIGHTCYAN);
            floodfill(135 + 300, 110, LIGHTGRAY);
        }
        setfillstyle(1, WHITE);
        bar(225+300, 80, 235+300, 109);
    }

    if(num[6])
    {
        setfillstyle(1, LIGHTCYAN);
        floodfill(135, 110 + 220, LIGHTGRAY);
    }
    else
    {
        if(num[2] && num[2]!=10)
        {
            setcolor(LIGHTGRAY);
            setlinestyle(0, 0, 1);
            line(85, 160-10*num[2]+220, 185, 160-10*num[2]+220);
            setfillstyle(1, LIGHTCYAN);
            floodfill(135, 155+220, LIGHTGRAY);  
        }
        else if(num[2]==10)
        {
            setfillstyle(1, LIGHTCYAN);
            floodfill(135, 110 + 220, LIGHTGRAY);
        }
        setfillstyle(1, WHITE);
        bar(225, 80+220, 235, 109+220);
    }

    if(num[7])
    {
        setfillstyle(1, LIGHTCYAN);
        floodfill(135 + 300, 110 + 220, LIGHTGRAY);
    }
    else
    {
        if(num[3] && num[3]!=10)
        {
            setcolor(LIGHTGRAY);
            setlinestyle(0, 0, 1);
            line(85+300, 160-10*num[3]+220, 185+300, 160-10*num[3]+220);
            setfillstyle(1, LIGHTCYAN);
            floodfill(135+300, 155+220, LIGHTGRAY);  
        }
        else if(num[3]==10)
        {
            setfillstyle(1, LIGHTCYAN);
            floodfill(135 + 300, 110 + 220, LIGHTGRAY);
        }
        setfillstyle(1, WHITE);
        bar(225+300, 80+220, 235+300, 109+220);
    }
}

/****************************************
FUNCTION:PutWindowHz
DESCRIBETION:显示车窗页汉字
INPUT:void
RETURN:void
****************************************/
void PutWindowHz()
{
    //左前窗
    puthz(44, 61, "左", 32, 0, BLUE);
    puthz(44, 114, "前", 32, 0, BLUE);
    puthz(44, 167, "窗", 32, 0, BLUE);
    //右前窗
    puthz(44 + 300, 61, "右", 32, 0, BLUE);
    puthz(44 + 300, 114, "前", 32, 0, BLUE);
    puthz(44 + 300, 167, "窗", 32, 0, BLUE);
    //左后窗
    puthz(44, 61 + 220, "左", 32, 0, BLUE);
    puthz(44, 114 + 220, "后", 32, 0, BLUE);
    puthz(44, 167 + 220, "窗", 32, 0, BLUE);
    //右后窗
    puthz(44 + 300, 61 + 220, "右", 32, 0, BLUE);
    puthz(44 + 300, 114 + 220, "后", 32, 0, BLUE);
    puthz(44 + 300, 167 + 220, "窗", 32, 0, BLUE);
}

/****************************************
FUNCTION:WindowMouse
DESCRIBETION:车窗页的鼠标功能
INPUT:int*
RETURN:int
****************************************/
int WindowMouse(int* num)
{
    int choice[13] = {0};
    while(1)
        {
            //绘制鼠标和设置按钮
            newmouse(&MouseX,&MouseY,&press);

            choice[0]=mouse_press(0,0,29,29);
            //左前窗
            choice[1]=mouse_press(80,180,135,220);   //上
            choice[2]=mouse_press(135,180,190,220);   //下
            choice[3]=mouse_press(190,180,300,220);  //锁
            //右前窗
            choice[4]=mouse_press(80+300, 180, 135+300, 220);   //上
            choice[5]=mouse_press(135+300, 180, 190+300, 220);   //下
            choice[6]=mouse_press(190+300, 180, 300+300, 220);  //锁
            //左后窗
            choice[7]=mouse_press(80, 180+220, 135, 220+220);   //上
            choice[8]=mouse_press(135, 180+220, 190, 220+220);   //下
            choice[9]=mouse_press(190, 180+220, 300, 220+220);  //锁
            //右后窗
            choice[10]=mouse_press(80+300, 180+220, 135+300, 220+220);   //上
            choice[11]=mouse_press(135+300, 180+220, 190+300, 220+220);   //下
            choice[12]=mouse_press(190+300, 180+220, 300+300, 220+220);  //锁

            //判断选项
            if(choice[0]==1)
            {
                ClearGraph(WHITE);
                return 0;
            }
            else if(choice[1]==1)
            {
                if(num[0]<10)
                    num[0]+=1;
                break;
            }
            else if(choice[2]==1)
            {
                if(num[0]>0)
                    num[0]-=1;
                break;
            }
            else if(choice[3]==1)
            {
                num[4]^=1;
                num[0]=10;
                break;
            }
            else if(choice[4]==1)
            {
                if(num[1]<10)
                    num[1]+=1;
                break;
            }
            else if(choice[5]==1)
            {
                if(num[1]>0)
                    num[1]-=1;
                break;
            }
            else if(choice[6]==1)
            {
                num[5]^=1;
                num[1]=10;
                break;
            }
            else if(choice[7]==1)
            {
                if(num[2]<10)
                    num[2]+=1;
                break;
            }
            else if(choice[8]==1)
            {
                if(num[2]>0)
                    num[2]-=1;
                break;
            }
            else if(choice[9]==1)
            {
                num[6]^=1;
                num[2]=10;
                break;
            }
            else if(choice[10]==1)
            {
                if(num[3]<10)
                    num[3]+=1;
                break;
            }
            else if(choice[11]==1)
            {
                if(num[3]>0)
                    num[3]-=1;
                break;
            }
            else if(choice[12]==1)
            {
                num[7]^=1;
                num[3]=10;
                break;
            }
        }
    return 1;
}
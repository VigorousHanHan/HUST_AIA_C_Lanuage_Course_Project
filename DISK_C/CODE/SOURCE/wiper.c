/**
**************************************************?
*   版本号：1.0
*   作者：X
*   生成日期：2024—3—9
*   说明：Wiper类函数实现雨刷功能
**************************************************?
**/

#include"init.h"
#include"wiper.h"

/****************************************
FUNCTION:OpenWiper
DESCRIBETION:打开雨刷页
INPUT:void
REUTRUN:void
****************************************/
void OpenWiper()
{
    while(1)
    {
        int i = 0, num[4] = {0}, wiper_ret = 1;
        FILE* wiper_text;

        setfillstyle(1, WHITE);
        bar(0, 0, 640, 480);

        wiper_text = fopen("..\\CODE\\text\\wiper.txt", "rt");
        for(i = 0; i < 4; i++)
        {
            fscanf(wiper_text, "%d ", &num[i]);
        
        }
        fclose(wiper_text);

		DrawReturnButton();
        DrawAheadWiper();
        DrawBehindWiper();
        DrawWiperChangePart(num);
        PutWiperHz();
        wiper_ret = WiperMouse(num);

        wiper_text = fopen("..\\CODE\\text\\wiper.txt", "wt");
        for(i = 0; i < 4; i++)
        {
            fprintf(wiper_text, "%d ", num[i]);
        }
        fclose(wiper_text);

        if(!wiper_ret)
            return ;
    }
}


/****************************************
FUNCTION:DrawAheadWiper
DESCRIBETION:绘制前雨刷
INPUT:void
RETURN:void
****************************************/
void DrawAheadWiper()
{
    //绘制前雨刷
    setlinestyle(0, 0, 3);
    line(65, 245, 255, 245);
    line(65, 285, 255, 285);
    ellipse(65, 265, 90, 270, 20, 20);
    ellipse(255, 265, 270, 450, 20, 20);
    puthz(65, 249, "前雨刷", 32, 47+32, BLUE);
    settextstyle(8, 0, 2);
    circle(100, 315, 20);   //on
    circle(220, 315, 20);   //off
    line(65, 345, 255, 345);
    line(65, 385, 255, 385);
    ellipse(65, 365, 90, 270, 20, 20);
    ellipse(255, 365, 270, 450, 20, 20);
    puthz(98, 349, "速度", 32, 60+32, BLUE);
    circle(80, 415, 20);    //快
    circle(160, 415, 20);   //中
    circle(240, 415, 20);   //慢
    //绘制雨刷图形
    setcolor(DARKGRAY);
    line(65, 60, 255, 60);
    line(60, 65, 60, 195);
    line(65, 200, 255, 200);
    line(260, 65, 260, 195);
    ellipse(255, 65, 0, 90, 5, 5);
    ellipse(65, 65, 90, 180, 5, 5);
    ellipse(65, 195, 180, 270, 5, 5);
    ellipse(255, 195, 270, 360, 5, 5);
    setlinestyle(0, 0, 1);
    setfillstyle(1, DARKGRAY);
    circle(125, 210, 5);
    circle(190, 210, 5);
    floodfill(125, 210, DARKGRAY);
    floodfill(190, 210, DARKGRAY);
    line(125, 210, 125, 170);
    line(190, 210, 190, 170);
    setlinestyle(0, 0, 3);
    line(105, 190, 175, 120);
    line(170, 190, 240, 120);
}

/****************************************
FUNCTION:DrawBehindWiper
DESCRIBETION:绘制后雨刷
INPUT:void
RETURN:void
****************************************/
void DrawBehindWiper()
{
    //绘制后雨刷
    setcolor(BLUE);
    setlinestyle(0, 0, 1);
    setlinestyle(0, 0, 3);
    line(65+320, 245, 255+320, 245);
    line(65+320, 285, 255+320, 285);
    ellipse(65+320, 265, 90, 270, 20, 20);
    ellipse(255+320, 265, 270, 450, 20, 20);
    puthz(65+320, 249, "后雨刷", 32, 47+32, BLUE);
    settextstyle(8, 0, 2);
    circle(100+320, 315, 20);   //on
    circle(220+320, 315, 20);   //off
    line(65+320, 345, 255+320, 345);
    line(65+320, 385, 255+320, 385);
    ellipse(65+320, 365, 90, 270, 20, 20);
    ellipse(255+320, 365, 270, 450, 20, 20);
    puthz(98+320, 349, "速度", 32, 60+32, BLUE);
    circle(80+320, 415, 20);    //快
    circle(160+320, 415, 20);   //中
    circle(240+320, 415, 20);   //慢

    //绘制雨刷图形
    setcolor(DARKGRAY);
    line(65+320, 60, 255+320, 60);
    line(60+320, 65, 60+320, 195);
    line(65+320, 200, 255+320, 200);
    line(260+320, 65, 260+320, 195);
    ellipse(255+320, 65, 0, 90, 5, 5);
    ellipse(65+320, 65, 90, 180, 5, 5);
    ellipse(65+320, 195, 180, 270, 5, 5);
    ellipse(255+320, 195, 270, 360, 5, 5);
    setfillstyle(1, DARKGRAY);
    circle(480, 210, 5);
    floodfill(480, 210, DARKGRAY);
    setlinestyle(0, 0, 1);
    line(480, 210, 480, 180);
    setlinestyle(0, 0, 3);
    line(470, 190, 510, 150);
}

/****************************************
FUNCTION:DrawWiperChangePart
DESCRIBETION:绘制雨刷页的可变部分
INPUT:int* num
RETURN:void
****************************************/
void DrawWiperChangePart(int* num)
{
    if(num[0] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(100, 315, BLUE);
    }
    if(num[0] == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(220, 315, BLUE);
    }
    if(num[1] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(80, 415, BLUE);
    }
    if(num[1] == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(160, 415, BLUE);
    }
    if(num[1] == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(240, 415, BLUE);
    }
    if(num[2] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(100+320, 315, BLUE);
    }
    if(num[2] == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(220+320, 315, BLUE);
    }
    if(num[3] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(80+320, 415, BLUE);
    }
    if(num[3] == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(160+320, 415, BLUE);
    }
    if(num[3] == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(240+320, 415, BLUE);
    }
}

/****************************************
FUNCTION:PutWiperHz
DESCRIBETION:显示雨刷页汉字
INPUT:void
RETURN:void
****************************************/
void PutWiperHz()
{
    setcolor(BLUE);
    outtextxy(87, 297, "on");
    outtextxy(205, 297, "off");
    puthz(64, 399, "快", 32, 0, BLUE);
    puthz(144, 399, "中", 32, 0, BLUE);
    puthz(224, 399, "慢", 32, 0, BLUE);
    outtextxy(87+320, 297, "on");
    outtextxy(205+320, 297, "off");
    puthz(64+320, 399, "快", 32, 0, BLUE);
    puthz(144+320, 399, "中", 32, 0, BLUE);
    puthz(224+320, 399, "慢", 32, 0, BLUE);
}

/****************************************
FUNCTION:WiperMouse
DESCRIBETION:雨刷页的鼠标功能
INPUT:int*
RETURN:int
****************************************/
int WiperMouse(int* num)
{
    int choice[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(1)
    {
        //绘制鼠标和设置按钮
        
        newmouse(&MouseX,&MouseY,&press);

        choice[0]=mouse_press(0,0,29,29);
        //前雨刷
        choice[1]=mouse_press(80, 295, 120, 335);  //on
        choice[2]=mouse_press(200, 295, 240, 335);  //off
        choice[3]=mouse_press(60, 395, 100, 435);  //快
        choice[4]=mouse_press(140, 395, 180, 435);  //中
        choice[5]=mouse_press(220, 395, 260, 435);  //慢
        //后雨刷
        choice[6]=mouse_press(80+320, 295, 120+320, 335);  //on
        choice[7]=mouse_press(200+320, 295, 240+320, 335);  //off
        choice[8]=mouse_press(60+320, 395, 100+320, 435);  //快
        choice[9]=mouse_press(140+320, 395, 180+320, 435);  //中
        choice[10]=mouse_press(220+320, 395, 260+320, 435);  //慢

        //判断选项
        if(choice[0]==1)
        {
            ClearGraph(WHITE);
            return 0;
        }
        else if(choice[1]==1)
        {
            num[0] = 1;
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
            num[1] = 3;
            break;
        }
        else if(choice[6]==1)
        {
            num[2] = 1;
            break;
        }
        else if(choice[7]==1)
        {
            num[2] = 2;
            break;
        }
        else if(choice[8]==1)
        {
            num[3] = 1;
            break;
        }
        else if(choice[9]==1)
        {
            num[3] = 2;
            break;
        }
        else if(choice[10]==1)
        {
            num[3] = 3;
            break;
        }
    }
    return 1;
}
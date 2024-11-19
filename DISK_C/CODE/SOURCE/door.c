/**
**************************************************?
*	版本号：1.0
*	作者：Y
*	生成日期：2024—3—15
*	说明：Door类函数实现车门功能
**************************************************?
**/

#include"init.h"
#include"display.h"
#include"door.h"

/****************************************
FUNCTION:OpenDoor
DESCRIBETION:打开菜单中车门页
INPUT:void
REUTRUN:void
****************************************/
void OpenDoor()
{
	while(1)
    {
        int door_ret = 1, num[9], i = 0;
        FILE* door_text;

	    setfillstyle(1, WHITE);
        bar(0, 0, 640, 480);

		door_text = fopen("..\\CODE\\text\\door.txt", "rt");
        for(i = 0; i < 9; i++)
        {
            fscanf(door_text, "%d ", &num[i]);
        }
        fclose(door_text);

		DrawDoorSButton();
		DrawDoorChangePart(num);
		PutDoorHz();
		door_ret = DoorMouse(num);

        door_text = fopen("..\\CODE\\text\\door.txt", "wt");
        for(i = 0; i < 9; i++)
        {
            fprintf(door_text, "%d ", num[i]);
        }
        fclose(door_text);
        if(!door_ret)
            return ;
    }
}

/****************************************
FUNCTION:DrawDoorSButton
DESCRIBETION:绘制菜单中车门所有按钮
INPUT:void
REUTRUN:void
****************************************/
void DrawDoorSButton()
{
	//int v1[]={276,179,263,192,275,188},v2[]={379,180,390,195,379,189};
	Draw(BLUE);
	
    DrawReturnButton();
	
	puthz(290,45,"车门控制",24,27,BLUE);
	line(140,270,180,270);
	line(140,300,180,300);
	ellipse(140,285,90,270,15,15);
	ellipse(180,285,-90,90,15,15);
	
	line(140,315,180,315);
	line(140,345,180,345);
	ellipse(140,330,90,270,15,15);
	ellipse(180,330,-90,90,15,15);
	line(150,323,156,323);
	line(156,323,160,326);
	line(160,326,160,333);
	line(150,323,150,333);
	line(150,333,152,333);
	line(160,333,158,333);
	circle(155,333,3);
	floodfill(151,324,BLUE);
	
	line(280,400,365,400);
	line(280,430,365,430);
	ellipse(280,415,90,270,15,15);
	ellipse(365,415,-90,90,15,15);//关闭按钮
	
	line(455,277,470,277);
	line(455,293,470,293);
	line(455,318,470,318);
	line(455,334,470,334);
	ellipse(455,285,90,270,8,8);
	ellipse(455,326,90,270,8,8);
	circle(470,285,8);
	circle(470,326,8);
	puthz(494,276,"前门手动模式",16,20,BLUE);
	puthz(494,318,"后门手动模式",16,20,BLUE);
	circle(400,216,10);
	line(400,216,400-3,216-4);
	line(400,216,400-3,216+4);
	circle(400,272,10);
	line(400,272,400-3,272-4);
	line(400,272,400-3,272+4);
	circle(252,216,10);
	line(252,216,252+3,216-4);
	line(252,216,252+3,216+4);
	circle(252,272,10);
	line(252,272,252+3,272-4);
	line(252,272,252+3,272+4);//set
	
	DrawCar(326,240,0.35);
}

/****************************************
FUNCTION:DrawDoorChangePart
DESCRIBETION:绘制车门页的可变部分
INPUT:int* num
RETURN:void
****************************************/
void DrawDoorChangePart(int* num)
{
	int i;
	if(num[0] == 1)
    {
        setfillstyle(1,DARKGRAY);
	    floodfill(160,285,BLUE);
	    num[1]=0;
	    num[2]=0;
	    num[5]=0;
	    num[6]=0;
	    num[7]=0;
	    num[8]=0;
    }
	if(num[1] == 1 )
    {
        setfillstyle(1, GREEN);
        floodfill(140,316,BLUE);
        num[0]=0;
        num[2]=0;
        num[5]=1;
	    num[6]=1;
	    num[7]=1;
	    num[8]=1;
    }
    if(num[2] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(280,415,BLUE);
        num[0]=0;
        num[1]=0;
        num[3]=0;
        num[4]=0;
    }
    if(num[3] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(455,285,BLUE);
        num[0]=0;
        num[1]=0;
    }
    if(num[4] == 1)
    {
        setfillstyle(1,GREEN);
	    floodfill(455,326,BLUE);
	    num[0]=0;
        num[1]=0;
    }
    if(num[5] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(401,217,BLUE);
	}
	if(num[6] == 1)
	{
		setfillstyle(1, GREEN);
		floodfill(401,273,BLUE);
    }
    if(num[7] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(252,217,BLUE);
    }
    if(num[8] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(252,273,BLUE);
    }
}

/****************************************
FUNCTION:PutDoorHz
DESCRIBETION:显示车门页汉字
INPUT:void
RETURN:void
****************************************/
void PutDoorHz()
{
	puthz(300,410,"关闭",16,27,BLUE);
	puthz(130,276,"一键关门",16,15,BLUE);
}

/****************************************
FUNCTION:DoorMouse
DESCRIBETION:车门页鼠标
INPUT:int* num
REUTRUN:int
****************************************/
int DoorMouse(int* num)
{
	int choice[10]={0};
	while(1)
    {
        //绘制鼠标和设置按钮
        newmouse(&MouseX, &MouseY, &press);
		choice[1]=mouse_press(140,270,180,300);
		choice[2]=mouse_press(140,315,180,345);//
		choice[3]=mouse_press(265,400,380,430);//
		choice[4]=mouse_press(455,277,470,293);
		choice[5]=mouse_press(455,318,470,334);//
		choice[6]=mouse_press(390,206,410,226);
		choice[7]=mouse_press(390,262,410,282);
		choice[8]=mouse_press(242,206,262,226);
		choice[9]=mouse_press(242,262,262,282);
		choice[0]=mouse_press(0,0,29,29);

		//判断选项
		if(choice[0] == 1)
		{
			ClearGraph(WHITE);
		   	return 0;
	    }
		else if(choice[1] == 1)
		{
            num[0]^=1;
            break;
		}
		else if(choice[2] == 1)
		{
		    num[1]^=1;
            break;
		}
		else if(choice[3] == 1)
		{
			num[2]^=1;
		}
		else if(choice[4] == 1)
		{
			num[3]^=1;
            break;
		}
		else if(choice[5] == 1)
		{
           	num[4]^=1;
            break;
		}
		else if(choice[6] == 1)
		{
            if(num[3])
			{
				num[5]^=1;
			}
            break;
		}
		else if(choice[7] == 1)
		{
            if(num[4])
			{
				num[6]^=1;
			}
            break;
		}
		else if(choice[8] == 1)
		{
			if(num[3])
			{
				num[7]^=1;
			}
            break; 
		}
		else if(choice[9] == 1)
		{
            if(num[4])
			{
				num[8]^=1;
			}
			break;
		}	
    }
	delay(100);
	return 1;
}
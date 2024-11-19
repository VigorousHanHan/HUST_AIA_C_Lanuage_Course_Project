/**
**************************************************?
*	版本号：1.0
*	作者：Y
*	生成日期：2024—3—17
*	说明：Battery类函数实现电池功能
**************************************************?
**/

#include"init.h"
#include"battery.h"

/****************************************
FUNCTION:OpenBattery
DESCRIBETION:打开菜单中电池页
INPUT:void
REUTRUN:void
****************************************/
void OpenBattery()
{
	while(1)
    {
        int battery_ret = 1, num[4], i = 0;
        FILE* battery_text;

	    setfillstyle(1, WHITE);
        bar(0, 0, 640, 480);

		battery_text = fopen("..\\CODE\\text\\battery.txt", "rt");
        for(i = 0; i < 4; i++)
        {
            fscanf(battery_text, "%d ", &num[i]);
        }
        fclose(battery_text);

		DrawBatterySButton(num);
		DrawBatteryChangePart(num);
		puthz(305-40,50,"电池充电",24,27,BLUE);
		battery_ret = BatteryMouse(num);
		
		battery_text = fopen("..\\CODE\\text\\battery.txt", "wt");
        for(i = 0; i < 4; i++)
        {
            fprintf(battery_text, "%d ", num[i]);
        }
        fclose(battery_text);
        if(!battery_ret)
            return ;
    }
}

/****************************************
FUNCTION:DrawBatterySButton
DESCRIBETION:绘制菜单中电池所有按钮
INPUT:int
REUTRUN:void
****************************************/

void DrawBatterySButton(int *num)
{
	char p[5];
	int i;
	Draw(BLUE);
	
	rectangle(280-40,20,430-40,100);
	circle(65,115,10);
	circle(65,115,6);
	circle(420,115,10);
	circle(420,115,6);
	
	puthz(85,105,"电池充满模式",24,27,BLUE);
	puthz(440,105,"电池养护模式",24,27,BLUE);//set
	
	line(60,150,615,150);
	line(60,385,615,385);
	line(45,165,45,370);
	line(630,165,630,370);
	ellipse(60,165,90,180,15,15);
	ellipse(60,370,180,270,15,15);
	ellipse(615,165,0,90,15,15);
	ellipse(615,370,-90,0,15,15);
	rectangle(170,170,605,360);
	line(305,170,305,360);
	line(170,230,605,230);
	line(170,280,605,280);
	puthz(190,185,"电池容量",24,27,BLUE);
	puthz(330,185,"可充至",24,27,BLUE);
	puthz(190,240,"电池寿命",24,27,BLUE);
	puthz(190,305,"推荐对象",24,27,BLUE);
	DrawReturnButton();

	setcolor(DARKGRAY);
	setfillstyle(1, DARKGRAY);
	line(105,190,120,190);
	line(105,198,120,198);
	ellipse(105,194,90,270,5,4);
	ellipse(120,194,-90,90,5,4);
	floodfill(105,194,DARKGRAY);
	line(95,200,130,200);
	line(95,340,130,340);
	line(85,210,85,330);
	line(140,210,140,330);
	ellipse(95,210,90,180,10,10);
	ellipse(95,330,180,270,10,10);
	ellipse(130,330,-90,0,10,10);
	ellipse(130,210,0,90,10,10);
	line(97,211,128,211);
	line(97,329,128,329);
	line(95,213,95,327);
	line(130,213,130,327);
	ellipse(97,213,90,180,2,2);
	ellipse(97,327,180,270,2,2);
	ellipse(128,327,-90,0,2,2);
	ellipse(128,213,0,90,2,2);
	floodfill(95,210,DARKGRAY);

	setcolor(GREEN);
	setfillstyle(1,GREEN);
	
	itoa(num[0],p,10);
	settextstyle(3,0,3);
	outtextxy(80,345,p);
	outtextxy(125,345,"%");
	
    for(i=0;i< num[0]/10;i++)
	{
    	rectangle(97,216+11*(9-i),128,225+11*(9-i));
    	floodfill(98,217+11*(9-i),GREEN);
    }
}

/****************************************
FUNCTION:DrawBatteryChangePart
DESCRIBETION:绘制电池页的可变部分
INPUT:int* num
RETURN:void
****************************************/
void DrawBatteryChangePart(int* num)
{
	int i;
    if(num[1] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(65,115,BLUE);
        settextstyle(3,0,3);
    	outtextxy(415,180,"100%");
    	puthz(330,240,"较长",24,27,BLUE);
    	puthz(320,290,"不会对电池造成永久性",16,27,BLUE);	
    	puthz(320,312,"损害，长期满充可能会",16,27,BLUE);
    	puthz(320,334,"降低电池性能。",16,27,BLUE);
    }
    if(num[1] == 2)
    {
        setfillstyle(1,GREEN);
	    floodfill(420,115,BLUE);
	    settextstyle(3,0,3);
	    outtextxy(415,180,"80%");
	    puthz(330,240,"更长",24,27,BLUE);
    	puthz(320,290,"经常使用外接电源供电，",24,27,BLUE);
	    puthz(320,320,"续航能力要求并不太高",24,27,BLUE);//表格	
    }
}

/****************************************
FUNCTION:BatteryPlus
DESCRIBETION:电池页的充电功能
INPUT:int* num
REUTRUN:void
****************************************/
void BatteryPlus(int *num)
{
	int i,t,mode;
	char p[5],q[5];
     
	if(num[1]==1)
	{
		mode=100;
	}
	if(num[1]==2)
	{
		mode=80;
	}
	
	while(num[2])
	{
		t=(mode-num[0])/10.0;
		if(t<=0)
		{
			t=0;
		}
		num[3]=t;
		setcolor(WHITE);
		setfillstyle(1, WHITE);
	    bar(80,345,125,380);
	    bar(150,395,180,500);
	    itoa(num[3],p,10);
	    itoa(num[0],q,10);
	    
	    setcolor(GREEN);
	    settextstyle(3,0,3);
	    setfillstyle(1, GREEN);
        floodfill(320,35,BLUE);
        puthz(40,400,"还需充电",24,27,BLUE);
	    puthz(180,400,"小时",24,27,BLUE); 
	    outtextxy(80,345,q);
    	outtextxy(150,395,p);
		
    	delay(100);
    	
		if(num[2] && num[0]<mode)
		{
			num[0]++;
		
	     	for(i=0;i< num[0]/10;i++)
	    	{
	    		setcolor(GREEN);
	    		setfillstyle(1, GREEN);
	    		rectangle(97,216+11*(9-i),128,225+11*(9-i));
	     		floodfill(98,217+11*(9-i),GREEN);
	    	}
	    	if(num[0]>=mode)
	    	{
	    		num[2]=0;
			}
		}
		else 
		{
			num[2]=0;
		}
	    sleep(1);
	}	
}

/****************************************
FUNCTION:BatteryMouse
DESCRIBETION:电池页的鼠标功能
INPUT:int* num
REUTRUN:int
****************************************/
int BatteryMouse(int* num)
{
	int choice[10]={0};

	while(1)
    {
        //绘制鼠标和设置按钮
        newmouse(&MouseX, &MouseY, &press);
        
        choice[1]= mouse_press(55,105,75,125);
        choice[2]= mouse_press(410,105,430,125);
        choice[3]= mouse_press(300,40,380,80);
        choice[0]= mouse_press(0,0,29,29);

        //判断选项
		if(choice[0] == 1)
		{
			ClearGraph(WHITE);
			return 0;
	    }
		else if(choice[1] == 1)
		{
			num[1]=1;
            break;
		}
		else if(choice[2] == 1)
		{
			num[1]=2;
            break;
		}
		else if(choice[3] == 1)
		{
			num[2]^=1;
			BatteryPlus(num);
            break;
		}
	}
    delay(100);
	return 1;
}
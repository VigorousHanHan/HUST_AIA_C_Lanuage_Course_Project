/**
**************************************************?
*	版本号：1.0
*	作者：Y
*	生成日期：2024—4—20
*	说明：Display类函数实现显示功能
**************************************************?
**/

#include"init.h"
#include<time.h>
#include<math.h>
#include"display.h"
#include<stdlib.h>
#include<time.h>
#include"normal.h"

/*********************
FUNCTION:OpenDisplay
DESCRIBETION:打开显示界面
INPUT:void
RETURN:void
*********************/
void OpenDisplay()
{
	while(1)
	{
		int display_ret=-1,num[10]={0},i;
		FILE *display_text,*battery_text;
		
		setfillstyle(1, WHITE);
        bar(0, 0, 640, 480);
        
        display_text=fopen("..\\CODE\\text\\display.txt","rt");
        for(i=0;i<10;i++)
        {
            fscanf(display_text,"%d ",&num[i]);
        }
        fclose(display_text);
        
		DrawDisplaySButton(num);
		DrawDisplayChangePart(num);
	    display_ret =DisplayMouse(num);
		
	    display_text=fopen("..\\CODE\\text\\display.txt","wt");
        for(i=0;i<10;i++)
        {
            fprintf(display_text,"%d ",num[i]);
        }
        fclose(display_text);

		battery_text = fopen("..\\CODE\\text\\battery.txt", "wt");
        fprintf(battery_text, "%d %d %d %d ",num[2],1,0,0);
        fclose(battery_text);
        if(!display_ret)
            return ;
	}
}

/****************************************
FUNCTION:DrawDisplaySButton
DESCRIBETION:绘制显示中所有按钮
INPUT:void
RETURN:void
****************************************/

void DrawDisplaySButton(int *num)
{
	int i,j,t;
	char *p;
	float pi=3.1415926535,k;
	k=pi/180;
	num[1]=0;
	
	Draw(BLUE);
    DrawReturnButton();
    DrawCar(320,240,0.2);
    
    DrawArrow();
    
	for(i=-1;i<2;i+=2)
	{
		circle(320+210*i,230,40);
        circle(320+210*i,230,44);
        circle(320+210*i,230,60);
        circle(320+210*i,230,65);
        circle(320+210*i,230,70);
        ellipse(320+210*i,230,-60-90*i,60+90*i,80,80);
        ellipse(320+210*i,230,35-90*i,145-90*i,90,90);
        rectangle(310+210*i,220,330+210*i,240);
        for(j=0;j<36;j++)
        {
        	t=j/3;
    	    line(320+210*i+65*cos(10*k*j),230-65*sin(10*k*j),320+210*i+70*cos(10*k*j),230-70*sin(10*k*j));
			line(320+210*i+55*cos(30*k*t),230-55*sin(30*k*t),320+210*i+65*cos(30*k*t),230-65*sin(30*k*t));
    	}
    	
        p=(int *) malloc(10*sizeof(int));
    	for(j=0;j<10;j++)
        {
    	    t=(j+1)/5;
            itoa(t*50,p,10);
    	    settextstyle(2,0,3);
    	    outtextxy(315+210*i+95*cos((-90+40*i+50*t*i)*k),225-96*sin((-90+40*i+50*t*i)*k),p);
	    }
        free(p);
        p=(int *) malloc(11*sizeof(int));
	    for(j=0;j<11;j++)
	    {
	    	itoa(j*10,p,10);
    	    settextstyle(2,0,3);
			outtextxy(110+55*cos((-120-30*j)*k),225-50*sin((-120-30*j)*k),p);
		}
        free(p);
        p=(int *) malloc(12*sizeof(int));
		for(j=0;j<6;j++)
		{
			itoa(-100+50*j,p,10);
			outtextxy(527+55*cos((-120-30*j)*k),225-50*sin((-120-30*j)*k),p);
			itoa(150-50*j,p,10);
			outtextxy(527+55*cos((-270-30*j)*k),225-50*sin((-270-30*j)*k),p);
		}
        free(p);
	}
    settextstyle(2,0,5);
    outtextxy(95,270,"km/h");
    outtextxy(525,270,"kw");
    puthz(28,315,"湿度",16,20,BLUE);
    puthz(499,210,"前",16,20,BLUE);
    puthz(499,230,"驱",16,20,BLUE);
    puthz(550,210,"后",16,20,BLUE);
    puthz(550,230,"驱",16,20,BLUE);
    settextstyle(3,0,1);
    outtextxy(527,217,"R");
    puthz(560,320,"电量",16,20,BLUE);
    setcolor(GREEN);
    setfillstyle(1, GREEN);
    rectangle(600,315,620,335);
    rectangle(608,311,612,315);
	floodfill(609,312,GREEN);	
	line(613,316,607,322);
	line(607,322,613,328);
	line(613,328,607,334);//电池
	DrawDailnumber(num);//表盘
    
    setcolor(BLUE);
    line(0,340,155,340);
    line(155,340,220,400);
    line(420,400,485,340);
    line(485,340,640,340);
	line(220,400,420,400);//分界
	circle(320,430,20);
	line(320,440,320,420);
	line(320,420,310,430);
	line(320,420,330,430);
	puthz(295,450,"启动",24,27,BLUE);//启动
	
	puthz(23,360,"温度",16,27,BLUE);
	outtextxy(67,355,":");
	puthz(100,360,"摄氏度",16,20,BLUE);
	puthz(23,400,"空气质量优",16,20,BLUE);
	puthz(23,440,"天气晴",16,20,BLUE);
	puthz(470,360,"状态",16,20,BLUE);
	outtextxy(510,355,":");
	puthz(515,360,"正常",16,20,BLUE);/////////
	puthz(470,400,"续航里程",16,20,BLUE);
	outtextxy(550,395,":");
	outtextxy(555,395,"500KM");
	puthz(470,440,"驾驶模式",16,20,BLUE);
	outtextxy(550,435,":");
	puthz(555,440,"自动",16,20,BLUE);

	line(250,40,250,400);
	line(270,40,270,400);
	line(380,40,380,400);
	line(400,40,400,400);
}

/****************************************
FUNCTION:DrawDailnumber
DESCRIBETION:绘制表盘等上的数据（如温度，湿度等）
INPUT:void
RETURN:void
****************************************/
void DrawDailnumber(int *num)
{
	int i,j,n,a,b,temperature,humidity,battery,front,rear,m[5]={1};
	char *p;
	FILE *ac_text,*battery_text;
	float pi=3.1415926535,k;
	k=pi/180;

	front=rear=0;

	ac_text=fopen("..\\CODE\\text\\ac.txt","rt");
	fscanf(ac_text,"%d %d %d %d %d %d %d ",&i,&j,&n,&a,&b,&temperature,&humidity);
	fclose(ac_text);

	battery_text=fopen("..\\CODE\\text\\battery.txt","rt");
    fscanf(battery_text,"%d %d %d %d ",&battery,&m[0],&m[1],&m[2]);
	fclose(battery_text);
	num[2]=battery;
	DisplayChange(num,num[2]);

	Draw(BLUE);
	for(j=0;j<humidity/10.0;j++)
	{
		line(110+82*cos((-125-11*j)*k),230-82*sin((-125-11*j)*k),110+88*cos((-125-11*j)*k),230-88*sin((-125-11*j)*k));
		line(110+82*cos((-135-11*j)*k),230-82*sin((-135-11*j)*k),110+88*cos((-135-11*j)*k),230-88*sin((-135-11*j)*k));
		line(110+82*cos((-125-11*j)*k),230-82*sin((-125-11*j)*k),110+82*cos((-135-11*j)*k),230-82*sin((-135-11*j)*k));
		line(110+88*cos((-125-11*j)*k),230-88*sin((-125-11*j)*k),110+88*cos((-135-11*j)*k),230-88*sin((-135-11*j)*k));
		setfillstyle(1, GREEN);
		floodfill(110+85*cos((-130-11*j)*k),230-85*sin((-130-11*j)*k), BLUE);
	}
	p=(int *) malloc(sizeof(int));
	itoa(humidity,p,10);
	settextstyle(3,0,1);
	outtextxy(66,310,":");
	outtextxy(70,310,p);
	outtextxy(110,310,"%");//湿度
	free(p);

	p=(int *) malloc(sizeof(int));
	itoa(temperature,p,10);
	outtextxy(70,355,p);//温度
	free(p);

	for(j=0;j<(front+100)*0.06;j++)
	{
		setfillstyle(1, RED);
		floodfill(530+67*cos((-125-10*j)*k),230-67*sin((-125-10*j)*k),BLUE);
		floodfill(530+62*cos((-125-10*j)*k),230-62*sin((-125-10*j)*k),BLUE);
	}//前驱

	for(j=0;j<(rear+100)*0.06;j++)
	{
		setfillstyle(1, DARKGRAY);
		floodfill(530+67*cos((-55+10*j)*k),230-67*sin((-55+10*j)*k),BLUE);
		floodfill(530+62*cos((-55+10*j)*k),230-62*sin((-55+10*j)*k),BLUE);
	}//后驱
}

/****************************************
FUNCTION:DrawCar
DESCRIBETION:绘制车
INPUT:int
RETURN:void
****************************************/
void DrawCar(int x,int y,float k)//x,y确定位置，k可确定大小
{
	int i;

	line((325-230)*k+x,(275-300)*k+y,(350-230)*k+x,(196-300)*k+y);
	line((350-230)*k+x,(181-300)*k+y,(350-230)*k+x,(196-300)*k+y);
	line((350-230)*k+x,(181-300)*k+y,(321-230)*k+x,(164-300)*k+y);
	line((321-230)*k+x,(164-300)*k+y,(144-230)*k+x,(165-300)*k+y);
	line((144-230)*k+x,(165-300)*k+y,(116-230)*k+x,(180-300)*k+y);
	line((116-230)*k+x,(180-300)*k+y,(115-230)*k+x,(201-300)*k+y);
	line((135-230)*k+x,(275-300)*k+y,(115-230)*k+x,(201-300)*k+y);
	line((229-230)*k+x,(266-300)*k+y,(135-230)*k+x,(275-300)*k+y);
	line((229-230)*k+x,(266-300)*k+y,(325-230)*k+x,(275-300)*k+y);//前窗

	line((147-230)*k+x,(424-300)*k+y,(230-230)*k+x,(428-300)*k+y);
	line((230-230)*k+x,(428-300)*k+y,(316-230)*k+x,(422-300)*k+y);
	line((316-230)*k+x,(422-300)*k+y,(326-230)*k+x,(496-300)*k+y);
	line((326-230)*k+x,(496-300)*k+y,(296-230)*k+x,(511-300)*k+y);
	line((296-230)*k+x,(511-300)*k+y,(230-230)*k+x,(522-300)*k+y);
	line((230-230)*k+x,(522-300)*k+y,(171-230)*k+x,(512-300)*k+y);
	line((171-230)*k+x,(512-300)*k+y,(138-230)*k+x,(497-300)*k+y);
	line((138-230)*k+x,(497-300)*k+y,(147-230)*k+x,(424-300)*k+y);//后窗

	for(i=-1;i<2;i+=2)
	{
		line((150-230)*i*k+x,(55-300)*k+y,(114-230)*i*k+x,(143-300)*k+y);
		line((114-230)*i*k+x,(143-300)*k+y,(107-230)*i*k+x,(180-300)*k+y);
		line((107-230)*i*k+x,(180-300)*k+y,(105-230)*i*k+x,(207-300)*k+y);
		line((105-230)*i*k+x,(207-300)*k+y,(131-230)*i*k+x,(296-300)*k+y);
		line((131-230)*i*k+x,(296-300)*k+y,(132-230)*i*k+x,(398-300)*k+y);
		line((132-230)*i*k+x,(398-300)*k+y,(116-230)*i*k+x,(444-300)*k+y);
		line((116-230)*i*k+x,(444-300)*k+y,(105-230)*i*k+x,(360-300)*k+y);
		line((105-230)*i*k+x,(360-300)*k+y,(104-230)*i*k+x,(227-300)*k+y);
		line((104-230)*i*k+x,(227-300)*k+y,(105-230)*i*k+x,(214-300)*k+y);
		line((105-230)*i*k+x,(214-300)*k+y,(101-230)*i*k+x,(211-300)*k+y);
		line((101-230)*i*k+x,(211-300)*k+y,(105-230)*i*k+x,(156-300)*k+y);
		line((105-230)*i*k+x,(156-300)*k+y,(134-230)*i*k+x,(84-300)*k+y);
		line((134-230)*i*k+x,(84-300)*k+y,(150-230)*i*k+x,(55-300)*k+y);
		line((115-230)*i*k+x,(82-300)*k+y,(105-230)*i*k+x,(156-300)*k+y);
		line((115-230)*i*k+x,(82-300)*k+y,(129-230)*i*k+x,(39-300)*k+y);
		line((129-230)*i*k+x,(39-300)*k+y,(174-230)*i*k+x,(16-300)*k+y);
		line((174-230)*i*k+x,(16-300)*k+y,(230-230)*i*k+x,(11-300)*k+y);
		line((174-230)*i*k+x,(16-300)*k+y,(142-230)*i*k+x,(23-300)*k+y);
		line((142-230)*i*k+x,(23-300)*k+y,(115-230)*i*k+x,(39-300)*k+y);
		line((115-230)*i*k+x,(39-300)*k+y,(111-230)*i*k+x,(49-300)*k+y);
		line((111-230)*i*k+x,(49-300)*k+y,(129-230)*i*k+x,(38-300)*k+y);
		line((112-230)*i*k+x,(42-300)*k+y,(89-230)*i*k+x,(84-300)*k+y);
		line((89-230)*i*k+x,(84-300)*k+y,(104-230)*i*k+x,(40-300)*k+y);
		line((104-230)*i*k+x,(40-300)*k+y,(104-230)*i*k+x,(40-300)*k+y);
		line((104-230)*i*k+x,(40-300)*k+y,(230-230)*i*k+x,(4-300)*k+y);
		line((89-230)*i*k+x,(84-300)*k+y,(89-230)*i*k+x,(221-300)*k+y);
		line((89-230)*i*k+x,(221-300)*k+y,(102-230)*i*k+x,(211-300)*k+y);
		line((94-230)*i*k+x,(217-300)*k+y,(103-230)*i*k+x,(222-300)*k+y);
		line((91-230)*i*k+x,(221-300)*k+y,(103-230)*i*k+x,(227-300)*k+y);
		line((89-230)*i*k+x,(221-300)*k+y,(72-230)*i*k+x,(232-300)*k+y);
		line((72-230)*i*k+x,(232-300)*k+y,(69-230)*i*k+x,(240-300)*k+y);
		line((69-230)*i*k+x,(240-300)*k+y,(78-230)*i*k+x,(242-300)*k+y);
		line((78-230)*i*k+x,(242-300)*k+y,(104-230)*i*k+x,(231-300)*k+y);
        line((89-230)*i*k+x,(236-300)*k+y,(91-230)*i*k+x,(495-300)*k+y);
        ellipse((109-230)*i*k+x,(495-300)*k+y,-90-45*(i+1),0-45*(i+1),18*k,62*k);
        line((109-230)*i*k+x,(557-300)*k+y,(230-230)*i*k+x,(576-300)*k+y);
        ellipse((230-230)*i*k+x,(557-300)*k+y,-90-45*(i+1),0-45*(i+1),121*k,19*k);
        line((133-230)*i*k+x,(497-300)*k+y,(130-230)*i*k+x,(559-300)*k+y);
        line((104-230)*i*k+x,(349-300)*k+y,(132-230)*i*k+x,(349-300)*k+y);
        line((90-230)*i*k+x,(352-300)*k+y,(104-230)*i*k+x,(349-300)*k+y);
        line((89-230)*i*k+x,(194-300)*k+y,(101-230)*i*k+x,(197-300)*k+y);//左右主体
    }
}

/****************************************
FUNCTION:DrawArrow
DESCRIBETION:绘制箭头
INPUT:void
RETURN:void
****************************************/
void DrawArrow()
{
    setcolor(BLUE);
    setlinestyle(0, 0, 1);
    rectangle(25, 35, 175, 85);
    rectangle(75, 35, 125, 85);

	moveto(30, 60);
	lineto(50, 40);
	lineto(50, 55);
	lineto(70, 55);
	lineto(70, 65);
	lineto(50, 65);
	lineto(50, 80);
	lineto(30, 60);

	moveto(100, 40);
	lineto(120, 60);
	lineto(105, 60);
	lineto(105, 80);
	lineto(95, 80);
	lineto(95, 60);
	lineto(80, 60);
	lineto(100, 40);

	moveto(170, 60);
	lineto(150, 40);
	lineto(150, 55);
	lineto(130, 55);
	lineto(130, 65);
	lineto(150, 65);
	lineto(150, 80);
	lineto(170, 60);
}

/****************************************
FUNCTION:DrawTime
DESCRIBETION:显示时间
INPUT:int
now[0]=info->tm_sec;
RETURN:void
****************************************/
void DrawTime(int x,int y,int k)//x,y确定位置，k可确定大小
{
	time_t curtime;
	
	setfillstyle(1, WHITE);
	time(&curtime);
    bar(x,y,x+270*k,y+20*k);
    settextstyle(3,0,k);
    setcolor(BLUE);
    outtextxy(x,y,ctime(&curtime));
    bar(x+160*k,y,x+270*k,y+20);
    delay(100);

}

/****************************************
FUNCTION:DrawDisplayChangePart
DESCRIBETION:显示页可变部分
INPUT:int* num
RETURN:int
****************************************/
void DrawDisplayChangePart(int *num)
{
	if(num[0]==1)
	{
		if(num[2]>20 && num[2]<=100)
        {
             Run(num);
             num[0]=0;
        }
        else if(num[2]<=20)
        {
            puthz(410,40,"电量不足",16,27,BLUE);
            num[0]=0;
        }
        else
        {
            puthz(410,40,"电量异常",16,27,BLUE);
            Run(num);
            num[0]=0;
        }
	}
}

/****************************************
FUNCTION:DisplayMouse
DESCRIBETION:显示页鼠标
INPUT:int* num
RETURN:int
****************************************/
int DisplayMouse(int* num)
{
	int choice[10]={0};
	
	time_t current_time;
	DrawTime(32,2,1);
	while(1)
    {
        //绘制鼠标和设置按钮
        newmouse(&MouseX, &MouseY, &press);
        
	    choice[1]=mouse_press(300,410,340,450);
		choice[0]=mouse_press(0,0,29,29);
        
        current_time=time(NULL);
        
        if(current_time%60==0)
        {
            DrawTime(32,2,1);//显示时间
		}
		
		//判断选项
		if(choice[0] == 1)
		{
			num[0]=0;
			ClearGraph(WHITE);
		   	return 0;
	    }
		else if(choice[1] == 1)
		{
            num[0]^=1;
            break;
		}
		
	}
	delay(100);
	return 1;
}

/****************************************
FUNCTION:Run
DESCRIBETION:运行,车辆行进
INPUT:int *num
RETURN:void
****************************************/
void Run(int *num)
{
	int i,j,k,n[5]={1},battery;
	FILE *battery_text,*display_text;
	NormalRun(num);

	line(220,400,420,400);//分界
	circle(320,430,20);
	line(320,440,320,420);
	line(320,420,310,430);
	line(320,420,330,430);
	puthz(295,450,"启动",24,27,BLUE);//启动
	num[3]=num[4]=num[5]=0;
	num[0]=num[1]=0;
}

/****************************************
FUNCTION:DrawBackground
DESCRIBETION:绘制背景，设置障碍物
INPUT:int *num
RETURN:void
****************************************/
void DrawBackground(int *num)
{
    int i=0,j,k,n[5]={1},m,s=5;
    FILE *battery_text;
    
    i=num[3];
    j=num[4];
    k=num[5];
    Draw(BLUE);
    setfillstyle(1,WHITE);
    line(250,40,250,400);
    line(270,40,270,400);
    line(380,40,380,400);
    line(400,40,400,400);
    
	srand((unsigned) time(NULL));
	m=rand()%20;
    while(1)
    {
        DisplayChange(num,num[2]);

        while(1)
        {
            Draw(BLUE);
            setfillstyle(1,WHITE);

            delay(30);
            bar(300,0,340,479);
            DrawCar(320,240,0.2);
            for(k=0;k<200;k++)
            {
                setfillstyle(1,WHITE);
                rectangle(310,-100+s*j-110*k,330,0+s*j-110*k);
            }
            srand((unsigned) time(NULL));
            if(m<30)
			{
				n[i]=rand()%12000;//不可避开障碍物
				setfillstyle(1,RED);
				fillellipse(320,-fabs(n[i])+s*j,20,20);
            }
            setfillstyle(1,WHITE);

            bar(230,0,400,40);
            bar(230,400,400,479);
            bar(280,182,360,292);
            DrawCar(320,240,0.2);
            if(j%200==0)
            {
                num[2]--;
            }

            num[1]=s*6;
            DisplayChange(num,num[2]);
			if(m<30)
			{
				if(-fabs(n[i])+s*j+20>42 && -fabs(n[i])+s*j-20<160)
				{
					s=0;
					num[1]=s*6;
					goto end;
				}
				else if(-fabs(n[i])+s*j+20>160 && -fabs(n[i])+s*j-20<295)
				{
					bar(300,-fabs(n[i])+s*j-20,340,-fabs(n[i])+s*j+20);
				}
				else ;
			}
            j++;
            if(j%5==0)
            {
                break;
            }
        }
        DisplayChange(num,num[2]);
        
        end:
        if(!s)
        {
			DisplayChange(num,num[2]);
            rectangle(310,410,370,450);
            puthz(320,420,"清除",16,27,BLUE);
            puthz(500,10,"发现障碍物",16,27,RED);
            do
            {
                newmouse(&MouseX, &MouseY, &press);

            }while(!(mouse_press(310,410,370,450)==1));

            setfillstyle(1,WHITE);
			bar(500, 10, 640, 30);
            bar(300,-fabs(n[i])+s*j-20,340,-fabs(n[i])+s*j+20);
            s=5;
        } 
        else
        {
            num[3]=i;num[4]=j;num[5]=k;
            break;
        }
    }
}

/***************************
FUNCTION:DisplayChange
DESCRIBETION:改变速度和电量
INPUT:int *num,int battery
RETURN:void
***************************/
void DisplayChange(int *num,int battery)
{
	FILE *battery_text;
	int speed,a,n[5]={1};
	float pi=3.1415926535,k;
	char *p;
	k=pi/180;
    speed=num[1];

	if(battery>100 || battery<0)
	{
		battery=0;
	}
    
    Draw(BLUE);
	for(a=0;a<11;a++)
    {
        line(530+80*cos((-55+11*a)*k),230-82*sin((-55+11*a)*k),530+90*cos((-55+11*a)*k),230-90*sin((-55+11*a)*k));
    }
    for(a=0;a<battery/10.0;a++)
    {
        setfillstyle(1, GREEN);
        floodfill(530+85*cos((-50+11*a)*k),230-85*sin((-50+11*a)*k), BLUE);
    }
	for(a=battery/10.0;a<10;a++)
	{
		setfillstyle(1, WHITE);
        floodfill(530+85*cos((-50+11*a)*k),230-85*sin((-50+11*a)*k), BLUE);
	}
    
    Draw(BLUE);
    p=(int *) malloc(sizeof(int));
	itoa(num[2],p,10);
	settextstyle(3,0,1);
	setfillstyle(1,WHITE);
	bar(500,314,560,343);
	outtextxy(500,314,p);
	outtextxy(540,314,"%");//电量
    free(p);
	
	for(a=0;a<speed*0.3;a++)
    {
    	setfillstyle(1, RED);
        floodfill(110+67*cos((-125-10*a)*k),230-67*sin((-125-10*a)*k),BLUE);
        floodfill(110+62*cos((-125-10*a)*k),230-62*sin((-125-10*a)*k),BLUE);
	}
	for(a=speed*0.3;a<10;a++)
	{
		setfillstyle(1, WHITE);
        floodfill(110+67*cos((-125-10*a)*k),230-67*sin((-125-10*a)*k),BLUE);
        floodfill(110+62*cos((-125-10*a)*k),230-62*sin((-125-10*a)*k),BLUE);
	}//速度
}

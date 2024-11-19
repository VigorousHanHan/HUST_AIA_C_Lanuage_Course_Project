/**
**************************************************?
*	版本号：1.0
*	作者：Y
*	生成日期：2024—3—18
*	说明：Ac类函数实现空调功能
**************************************************?
**/

#include"ac.h"
#include"init.h"

/****************************************
FUNCTION:OpenAircondition
DESCRIBETION:打开菜单中空调页
INPUT:void
REUTRUN:void
****************************************/

void OpenAircondition()
{
	while(1)
    {
		int aircondition_ret = 1, i = 0;
		int num[8];
		FILE* ac_text;

		setfillstyle(1, WHITE);
		bar(0, 0, 640, 480);

		ac_text = fopen("..\\CODE\\text\\ac.txt", "rt");
		for(i = 0; i < 8; i++)
		{
			fscanf(ac_text, "%d ", &num[i]);
		}
		fclose(ac_text);

		DrawAirconditionSButton(num);
		DrawAirconditionChangePart(num);
		aircondition_ret = AirconditionMouse(num);

		ac_text = fopen("..\\CODE\\text\\ac.txt", "wt");
		for(i = 0; i < 8; i++)
		{
			fprintf(ac_text, "%d ", num[i]);
		}
		fclose(ac_text);

		if(!aircondition_ret)
			return ;
	}
}


/****************************************
FUNCTION:DrawAirconditionChangePart
DESCRIBETION:绘制雨刷页的可变部分
INPUT:int* num
RETURN:void
****************************************/

void DrawAirconditionChangePart(int* num)
{
	if(num[0] == 1)
	{
		setfillstyle(1, GREEN);
		floodfill(145,360, BLUE);
	}
	if(num[0] == 2)
	{
		setfillstyle(1,GREEN);
		floodfill(472,360,BLUE);
	}
	if(num[1] == 1)
    {
	    setfillstyle(1, GREEN);
	    floodfill(171,161,BLUE);	
    }
    if(num[2] == 1)
    {
     	setfillstyle(1, GREEN);
    	floodfill(471,161,BLUE);    	
    }
}

/****************************************
FUNCTION:DrawAirconditionSButton
DESCRIBETION:绘制菜单中空调所有按钮
INPUT:void
REUTRUN:void
****************************************/
void DrawAirconditionSButton(int *num)
{
    float pi=3.1415926535,a,b;
	char *p;
	int i,k;
	a=-pi/2;
	b=pi/100;
	Draw(BLUE);
	DrawReturnButton();

	circle(170,200-40,20);
	line(160,200-40,180,200-40);
	circle(320,200-40,60);
	circle(320,200-40,75);
	circle(320,200-40,90);
	circle(470,200-40,20);
	line(460,200-40,480,200-40);
	line(470,190-40,470,210-40);
	setfillstyle(1,GREEN);
	floodfill(320,200-40,BLUE);

	circle(245-100,365-30,30);
	puthz(220-100,400-30,"温度",24,27,BLUE);
	ellipse(245-100,370-30,-230,50,10,10);
	ellipse(245-100,370-30,-230,50,6,6);
	line(250-100,368-30,250-100,363-30);
	line(240-100,368-30,240-100,363-30);
	line(250-100,363-30,240-100,363-30);
	line(251-100,366-30,251-100,356-30);
	line(239-100,366-30,239-100,356-30);
	ellipse(245-100,356-30,0,180,6,6);
	setfillstyle(1,DARKGRAY);
	floodfill(245-100,370-30,BLUE);//温度按钮

	circle(372+100,365-30,30);
	ellipse(372+100,370-30,-180,0,8,8);
	ellipse(372+100,370-30-4,-40,210,8,20);
	ellipse(372+100,370-30,180,260,4,4);
	puthz(352+100,400-30,"湿度",24,27,BLUE);//湿度按钮
	
	if(num[0]==2)
	{
	    k=(num[4]-20)/60.0*200;
		p=(int *) malloc(11*sizeof(int));
	    itoa(num[4],p,10);
		             	
	    settextstyle(3,0,5);
	    outtextxy(285,170-40,p);
	    settextstyle(3,0,3);
	    outtextxy(345,170-40,"%");
	    puthz(284,230-40,"预设湿度",16,20,BLUE);//湿度显示
		free(p);
    }
    else
    {
		
    	k=(num[3]-16)/14.0*200;
		p=(int *) malloc(11*sizeof(int));
    	itoa(num[3],p,10);
    	
    	settextstyle(3,0,5);
	    outtextxy(285,170-40,p);
	    puthz(284,230-40,"预设温度",16,20,BLUE);
		free(p);
		
	}
	
	for(i=0;i<k;i++)
	{
		line(320+75*cos(a-b*i),200-40-75*sin(a-b*i),320+90*cos(a-b*i),200-40-90*sin(a-b*i));
	}
	
	settextstyle(3,0,3);
	circle(300,335,30);
	ellipse(300,335,-180,0,15,15);
	line(300,320,300,340);
	puthz(275,370,"开关",24,27,BLUE);
	puthz(50,400,"当前温度",24,27,BLUE);
	
	p=(int *) malloc(11*sizeof(int));
	itoa(num[5],p,10);
	outtextxy(155,395,":");
	outtextxy(165,395,p);
	free(p);
	
	puthz(205,400,"摄氏度",24,27,BLUE);
	puthz(350,400,"当前湿度",24,27,BLUE);
	
	p=(int *) malloc(11*sizeof(int));
	itoa(num[6],p,10);
	outtextxy(460,395,":");
	outtextxy(470,395,p);
	outtextxy(520,395,"%");
	free(p);
	
}

/****************************************
FUNCTION:AirconditionMouse
DESCRIBETION:空调页鼠标功能
INPUT:int* num
REUTRUN:int
****************************************/
int AirconditionMouse(int* num)
{
	int choice[10]={0};
	
	while(1)
	{
		//绘制鼠标和设置按钮
		newmouse(&MouseX, &MouseY, &press);
		choice[1]= mouse_press(150,140,190,180);
		choice[2]= mouse_press(450,140,490,180);
		choice[3]= mouse_press(115,305,175,365);
		choice[4]= mouse_press(442,305,502,365);
        choice[5]= mouse_press(270,305,330,365);
        
		choice[0]= mouse_press(0,0,29,29);

		//判断选项
		if(choice[0] == 1)
		{
			ClearGraph(WHITE);
			return 0;
		}
		else if(choice[1] == 1)
		{
			num[1]^=1;
			if(num[0]==1)
			{
				if(num[3]>16)
	    	    {
	    		    num[3]--;
			    }
			}
			if(num[0]==2)
			{
				if(num[4]>20)
	    	    {
	    		    num[4]--;
			    }
			}
			break;
		} 
		else if(choice[2] == 1) 
		{
			num[2]^=1;
			if(num[0]==1)
			{
				if(num[3]<30)
	    	    {
	    		    num[3]++;
			    }
			}
			if(num[0]==2)
			{
				if(num[4]<80)
	    	    {
	    		    num[4]++;
			    }
			}
			break;
		}
		else if(choice[3] == 1)
		{
			num[0]=1;
			break;
		}
		else if(choice[4] == 1)
		{
			num[0]=2;
			break;
		}
		else if(choice[5] == 1)
		{
			num[7]^=1;
		    Aircondition(num);
			break;
		}
	}
    delay(100);
	return 1;
}

/****************************************
FUNCTION:Aircondition
DESCRIBETION:空调页温度湿度的改变
INPUT:int* num
REUTRUN:void
****************************************/
void Aircondition(int* num)
{
	char *p;
	int i;
	
			while(num[7])
				{
					setfillstyle(1, GREEN);
					floodfill(301,335,BLUE);
					setfillstyle(1, WHITE);
					Draw(BLUE);
					if(num[3]>num[5])
					{
						for(i=0;i<=num[3]-num[5];i++)
						{
							bar(165,395,200,420);
							num[5]++;

							p=(int *) malloc(11*sizeof(int));
							itoa(num[5],p,10);
							outtextxy(155,395,":");
							outtextxy(165,395,p);
							free(p);
							
							delay(1000);
						}
					}  
					else if(num[3]<num[5])
					{
						for(i=0;i<=num[5]-num[3];i++)
						{
							bar(165,395,200,420);
							num[5]--;
							
							p=(int *) malloc(11*sizeof(int));
							itoa(num[5],p,10);
							outtextxy(155,395,":");
							outtextxy(165,395,p);
							free(p);
							
							delay(1000);
						}
					} 
						
					if(num[4]>num[6])
					{
						for(i=0;i<=num[4]-num[6];i++)
						{
							bar(470,395,520,420);
							num[6]++;
							
							p=(int *) malloc(11*sizeof(int));
							itoa(num[6],p,10);
							outtextxy(460,395,":");
							outtextxy(470,395,p);
							free(p);
							
							outtextxy(520,395,"%");
							delay(1000);
						}
					}  
					else if(num[4]<num[6])
					{
						for(i=0;i<=num[6]-num[4];i++)
						{
							bar(470,395,520,420);
							num[6]--;
							
							p=(int *) malloc(11*sizeof(int));
							itoa(num[6],p,10);
							outtextxy(460,395,":");
							outtextxy(470,395,p);
							free(p);
							
							outtextxy(520,395,"%");
							delay(1000);
						}
					}
					
					if(num[3]==num[5] && num[4]==num[6])
					{
						num[7]=0;
					}
				}
}
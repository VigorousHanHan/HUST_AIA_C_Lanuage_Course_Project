/**
**************************************************?
*	�汾�ţ�1.0
*	���ߣ�Y
*	�������ڣ�2024��3��10
*	˵����Drive�ຯ��ʵ�ּ�ʻ����
**************************************************?
**/

#include"drive.h"
#include"init.h"

/****************************************
FUNCTION:OpenDrive
DESCRIBETION:�򿪲˵��м�ʻҳ
INPUT:void
REUTRUN:void
****************************************/

void OpenDrive()
{
	while(1)
    {
        int drive_ret = 1, num[5]={0}, i=0;
        FILE* drive_text;

		setfillstyle(1, WHITE);
        bar(0, 0, 640, 480);

		drive_text=fopen("..\\CODE\\text\\drive.txt","rt");
		for(i = 0; i < 5; i++)
		{
			fscanf(drive_text, "%d " ,&num[i]);
		}
		fclose(drive_text);

		DrawReturnButton();
		DrawDriveSButton();//����
		DrawDriveChangePart(num);
		PutDriveHz();
		drive_ret = DriveMouse(num);
  
        drive_text = fopen("..\\CODE\\text\\drive.txt", "wt");
        for(i = 0; i < 5; i++)
        {
            fprintf(drive_text, "%d ", num[i]);
        }
        fclose(drive_text);

		if(!drive_ret)
			return ;
    }
}

/****************************************
FUNCTION:DrawDriveSButton
DESCRIBETION:���Ʋ˵��м�ʻ���а�ť
INPUT:void
REUTRUN:void
****************************************/

void DrawDriveSButton()
{
	rectangle(0+10,140,195+10,180);
	rectangle(0+10,215,195+10,255);
	rectangle(0+10,290,195+10,330);
	line(65+10,140,65+10,180);
	line(130+10,140,130+10,180);
	line(65+10,215,65+10,255);
	line(130+10,215,130+10,255);
	line(65+10,290,65+10,330);
	line(130+10,290,130+10,330);//����

	line(33+10,295,33+10,325);
	line(10+10,310,55+10,310);//+

	line(140+10,310,185+10,310);//-

	rectangle(340,155-10,610,425-10);
	rectangle(430,155-10,520,425-10);
	rectangle(340,245-10,610,335-10);
	circle(475,290-10,40-10);
	line(340,155-10,430,245-10);

	line(475,240-10,475,160-10);
	line(475,160-10,435,195-10);
	line(475,160-10,515,195-10);

	line(475,420-10,475,340-10);
	line(475,420-10,435,385-10);
	line(475,420-10,515,385-10);

	line(345,290-10,425,290-10);
	line(345,290-10,380,250-10);
	line(345,290-10,380,330-10);//car set

	line(525,290-10,605,290-10);
	line(605,290-10,570,250-10);
	line(605,290-10,570,330-10);
	rectangle(150,380,150+100,380+50);
	circle(150+50,380+25,20);
	circle(150+50,380+75,20);
	rectangle(150+30,380+30,150+70,380+70);
	rectangle(150+30,380+40,150+60,380+50);
	rectangle(150+40,380+40,150+70,380+50);//���Ƴ�
}

/****************************************
FUNCTION:DrawDriveChangePart
DESCRIBETION:���Ƽ�ʻҳ��ɱ�Ĳ���
INPUT:int* num
RETURN:void
****************************************/
void DrawDriveChangePart(int* num)
{
	char *p;
	if(num[0]==1)
	{
		setfillstyle(1,YELLOW);
		floodfill(1+10,141,BLUE);
	}
	if(num[0]==2)
	{
		setfillstyle(1,YELLOW);
		floodfill(66+10,141,BLUE);
	}
	if(num[0]==3)
	{
		setfillstyle(1,YELLOW);
		floodfill(136+10,141,BLUE);
	}
	if(num[1]==1)
	{
		setfillstyle(1,YELLOW);
		floodfill(1+10,216,BLUE);
	}
	if(num[1]==2)
	{
		setfillstyle(1,YELLOW);
		floodfill(66+10,216,BLUE);
	}
	if(num[1]==3)
	{
		setfillstyle(1,YELLOW);
		floodfill(136+10,216,BLUE);
	}
	if(num[3]==1)
	{
		setfillstyle(1,YELLOW);
		floodfill(421+10,156-10,BLUE);
	}
	if(num[3]==2)
	{
		setfillstyle(1,YELLOW);
		floodfill(421+10,336-10,BLUE);
	}
	if(num[3]==3)
	{
		setfillstyle(1,YELLOW);
		floodfill(331+10,246-10,BLUE);
	}
	if(num[3]==4)
	{
		setfillstyle(1,YELLOW);
		floodfill(511+10,246-10,BLUE);
	}
	if(num[4]==1)
	{
		setfillstyle(1,YELLOW);
		floodfill(421+10,246-10,BLUE);
	}
	if(num[4]==2)
	{
		setfillstyle(1,YELLOW);
		floodfill(331+10,156-10,BLUE);
	}
    
	p=(int *) malloc(11*sizeof(int));
	itoa(num[2],p,10);
	settextstyle(3,0,1);
	outtextxy(95+6,300,p);
	free(p);
}

/****************************************
FUNCTION:PutDriveHz
DESCRIBETION:��ʾ��ʻҳ����
INPUT:void
RETURN:void
****************************************/
void PutDriveHz()
{
	puthz(250+10,35,"��ʻ",48,54,BLUE);
	puthz(45+10,115,"ת����ʽ",24,27,BLUE);
	puthz(25+10,190,"�ƶ���������",24,27,BLUE);
	puthz(70+10,265,"�ٶ�",24,27,BLUE);//set

	puthz(15+10,155,"����",16,24,BLUE);
	puthz(80+10,155,"��׼",16,24,BLUE);
	puthz(145+10,155,"�˶�",16,24,BLUE);
	puthz(25+10,230,"��",16,24,BLUE);
	puthz(80+10,230,"��׼",16,24,BLUE);
	puthz(155+10,230,"��",16,24,BLUE);//��λ
}

/****************************************
FUNCTION:DriveMouse
DESCRIBETION:��ʻҳ����깦��
INPUT:int*
RETURN:int
****************************************/
int DriveMouse(int* num)
{
	int choice[15]={0};
	while(1)
    {
        //�����������ð�ť
        newmouse(&MouseX,&MouseY,&press);

        choice[0]=mouse_press(0,0,29,29);
        
        choice[1]=mouse_press(0+10,140,65+10,180);
        choice[2]=mouse_press(65+10,140,130+10,180);
        choice[3]=mouse_press(130+10,140,195+10,180);
        
        choice[4]=mouse_press(0+10,215,65+10,255);
        choice[5]=mouse_press(65+10,215,130+10,255);
        choice[6]=mouse_press(130+10,215,195+10,255);
        
        choice[7]=mouse_press(0+10,290,65+10,330);
        choice[8]=mouse_press(130+10,290,195+10,330);
        
        choice[9]=mouse_press(420+10,155-10,510+10,245-10);
        choice[10]=mouse_press(420+10,335-10,510+10,425-10);
        choice[11]=mouse_press(330+10,245-10,420+10,335-10);
        choice[12]=mouse_press(510+10,245-10,600+10,335-10);
        choice[13]=mouse_press(420+10,245-10,510+10,335-10);
        choice[14]=mouse_press(330+10,155-10,420+10,245-10);

        //�ж�ѡ��
		if(choice[0] == 1)		//����
		{
			ClearGraph(WHITE);
			return 0;
		}
		else if(choice[1] == 1)	//����
		{
			num[0]=1;
			break;
		}
		else if(choice[2] == 1)	//��׼
		{
			num[0]=2;
			break;
		}
		else if(choice[3] == 1)	//�˶�
		{
			num[0]=3;
			break;
		}
		else if(choice[4] == 1)	//��
		{
			num[1]=1;
			break;
		}
		else if(choice[5] == 1)	//��׼
		{
			num[1]=2;
			break;
		}
		else if(choice[6] == 1)	//��
		{
			num[1]=3;
			break;
		}
		else if(choice[7] == 1)	//�ٶ�����
		{
			if(num[2]<99&&num[4]==1)
				num[2]++;
			break;
		}
		else if(choice[8] == 1)	//�ٶȼ���
		{
			if(num[2]>0&&num[4]==1)
				num[2]--;
			break;
		}
		else if(choice[9] == 1)	//ǰ��
		{
			num[4]=1;
            num[3]=1;
			break;
		}
		else if(choice[10] == 1)	//����
		{
			num[4]=1;
            num[3]=2;
			break;
		}
		else if(choice[11] == 1)	//��ת
		{
            num[4]=1;
            num[3]=3;
			break;
		}
		else if(choice[12] == 1)	//��ת
		{
            num[4]=1;
            num[3]=4;
			break;
		}
		else if(choice[13] == 1)	//����
		{
			num[4]=1;
			break;
		}
		else if(choice[14] == 1)	//ɲ��
		{
			num[4]=2;
			num[3]=0;
			num[2]=0;
			break;
		}
    }
	delay(100);
	return 1;
}
/**
**************************************************?
*   �汾�ţ�1.0
*   ���ߣ�Y
*   �������ڣ�2024��3��5
*   ˵����Light�ຯ��ʵ�ֵƹ⹦��
**************************************************?
**/

#include"init.h"
#include"light.h"

/****************************************
FUNCTION:OpenLight
DESCRIBETION:�򿪲˵��еƹ�ҳ
INPUT:void
REUTRUN:void
****************************************/
void OpenLight()
{
	while(1)
    {
    	int light_ret = 1, i=0, num[10]={0};
    	FILE *light_text;
    	
    	setfillstyle(1, WHITE);
        bar(0, 0, 640, 480);

        light_text = fopen("..\\CODE\\text\\light.txt", "rt");
		for(i = 0; i < 6; i++)
        {
            fscanf(light_text, "%d ", &num[i]);
        }
        fclose(light_text);
        
        DrawLightSButton();
        DrawLightChangePart(num);
        PutLightHz();
		light_ret = LightMouse(num);
        
        light_text = fopen("..\\CODE\\text\\light.txt", "wt");
        for(i = 0; i < 6; i++)
        {
			fprintf(light_text, "%d ", num[i]);
        }
        fclose(light_text);

        if(!light_ret)
            return ;
    }
}

/****************************************
FUNCTION:DrawLightSButton
DESCRIBETION:���Ʋ˵��еƹ����а�ť
INPUT:void
REUTRUN:void
****************************************/
void DrawLightSButton()
{
	Draw(BLUE);
	line(130,85,480,85);
	line(130,115,480,115);
	ellipse(130,100,90,270,30,15);
	ellipse(480,100,-90,90,30,15);
	line(140,165,210,165);
	line(140,195,210,195);
	ellipse(140,180,90,270,30,15);
	ellipse(210,180,-90,90,30,15);
	line(420,165,490,165);
	line(420,195,490,195);
	ellipse(420,180,90,270,30,15);
	ellipse(490,180,-90,90,30,15);//out
	line(130,320,480,320);
	line(130,350,480,350);
	ellipse(130,335,90,270,30,15);
	ellipse(480,335,-90,90,30,15);
	line(130,400,200,400);
	line(130,430,200,430);
	ellipse(130,415,90,270,30,15);
	ellipse(200,415,-90,90,30,15);
	line(420,405,480,405);
	line(420,435,480,435);
	ellipse(420,420,90,270,30,15);
	ellipse(480,420,-90,90,30,15);//in
	
	line(217,85,217,115);
	line(304,85,304,115);
	line(391,85,391,115);
	line(217,320,217,350);
	line(304,320,304,350);
	line(391,320,391,350);	
	
	DrawReturnButton();
}

/****************************************
FUNCTION:DrawLightChangePart
DESCRIBETION:���Ƶƹ�ҳ�Ŀɱ䲿��
INPUT:int* num
RETURN:void
****************************************/
void DrawLightChangePart(int* num)
{
    if(num[0] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(130, 100, BLUE);
    }
    if(num[0] == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(221, 100, BLUE);
    }
    if(num[0] == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(311, 100, BLUE);
    }
    if(num[0] == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(401, 100, BLUE);
    }
    if(num[1] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(130, 330, BLUE);
    }
    if(num[1] == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(220, 330, BLUE);
    }
    if(num[1] == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(310, 330, BLUE);
    }
    if(num[1] == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(400,330, BLUE);
    }
    if(num[2] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(140, 180, BLUE);
    }
    if(num[3] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(420, 180, BLUE);
    }
    if(num[4] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(130, 415, BLUE);
    }
    if(num[5] == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(420, 420, BLUE);
    }
}

/****************************************
FUNCTION:PutLightHz
DESCRIBETION:��ʾ�ƹ�ҳ����
INPUT:void
RETURN:void
****************************************/
void PutLightHz()
{
	puthz(120,30,"�ⲿ�ƹ�",32,54,BLUE);
	puthz(140,175,"������",16,27,BLUE);
	puthz(430,175,"���",16,27,BLUE);
	puthz(110,260,"�ڲ��ƹ�",32,54,BLUE);
	puthz(130,405,"������",16,27,BLUE);
	puthz(420,415,"��Χ��",16,27,BLUE);
	settextstyle(3,0,1);
	outtextxy(130,85,"off        parking     auto         on");
	outtextxy(130,320,"off        parking     auto         on");
}

/****************************************
FUNCTION:LightMouse
DESCRIBETION:�ƹ�ҳ����깦��
INPUT:int* num
REUTRUN:int
****************************************/
int LightMouse(int* num)
{
	int choice[13]={0};
	while(1)
    {
        //�����������ð�ť
        newmouse(&MouseX, &MouseY, &press);
        
        choice[1]= mouse_press(130,85,217,115);
        choice[2]= mouse_press(217,85,304,115);
        choice[3]= mouse_press(304,85,391,115);
        choice[4]= mouse_press(391,85,480,115);//out  auto....

        choice[5]= mouse_press(130,320,217,350);
        choice[6]= mouse_press(217,320,304,350);
        choice[7]= mouse_press(304,320,391,350);
        choice[8]= mouse_press(391,320,480,350);//in  auto....
        
        choice[9]= mouse_press(140, 165, 210, 195);
        choice[10]= mouse_press(420, 165, 490, 195);
        choice[11]= mouse_press(130,400,200,430);
        choice[12]= mouse_press(420,405,480,435);

        choice[0]= mouse_press(0,0,29,29);
		
		//�ж�ѡ��
		if(choice[0]==1)
        {
            //����
            ClearGraph(WHITE);
            return 0;           
        }
        else if(choice[1]==1)
        {
            //off
            num[0]=1;
            break;
        }
        else if(choice[2]==1)
        {
            //parking
            num[0]=2;
            break;
        }
        else if(choice[3]==1)
        {
            //auto
            num[0]=3;
            break;
        }
        else if(choice[4]==1)
        {
            //on
            num[0]=4;
            break;
        }
        else if(choice[5]==1)
        {
            //off
            num[1]=1;
            break;
        }
        else if(choice[6]==1)
        {
            //parking
            num[1]=2;
            break;
        }
        else if(choice[7]==1)
        {
            //auto
            num[1]=3;
            break;
        }
        else if(choice[8]==1)
        {
            //on
            num[1]=4;
            break;
        }
        else if(choice[9]==1)
        {
            //out ������
            num[2]^=1;
            break;
        }
        else if(choice[10]==1)
        {
            //out ���
            num[3]^=1;
            break;
        }
        else if(choice[11]==1)
        {
            //in ������
            num[4]^=1;
            break;
        }
        else if(choice[12]==1)
        {
            //in  ��Χ��
            num[5]^=1;
            break;
        }
    }
    delay(100);
    return 1;
}
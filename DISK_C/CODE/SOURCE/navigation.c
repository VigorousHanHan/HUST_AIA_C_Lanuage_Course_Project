/**
**************************************************?
*   �汾�ţ�1.0
*   ���ߣ�X
*   �������ڣ�2024��3��28
*   ˵����Navigation�ຯ��ʵ�ֵ�������
**************************************************?
**/

#include"init.h"
#include"map.h"
#include"navigat.h"
#include"plan.h"

/****************************************
FUNCTION:OpenNavigation
DESCRIBETION:�򿪵���ҳ
INPUT:void
RETURN:void
****************************************/
void OpenNavigation()
{
    int mode[2] = {1, 1};
    while(1)
    {
        int navigation_ret = 1;
        ClearGraph(WHITE);
        DrawReturnButton();
        DrawMap();
        DrawNavigationTopButton();
        navigation_ret = NavigationMouse(mode);
        if(!navigation_ret)
            return ;
    }
}

/****************************************
FUNCTION:DrawNavigationTopButton
DESCRIBETION:���Ƶ���ҳ������ť
INPUT:void
RETURN:void
****************************************/
void DrawNavigationTopButton()
{
    setlinestyle(0, 0, 1);
    setcolor(BLUE);

    rectangle(45, 0, 165, 28);
    puthz(48, 2, "ѡ�����", 24, 30, BLUE);

    rectangle(195, 0, 315, 28);
    puthz(198, 2, "ѡ���յ�", 24, 30, BLUE);

    rectangle(345, 0, 465, 28);
    puthz(348, 2, "����ѡ��", 24, 30, BLUE);

    rectangle(495, 0, 615, 28);
    puthz(498, 2, "��ʼ�滮", 24, 30, BLUE);
}

/****************************************
FUNCTION:NavigationMouse
DESCRIBETION:����ҳ���
INPUT:int* mode
RETURN:int
****************************************/
int NavigationMouse(int* mode)
{
    int choice[5] = {0}, start = -1, end = -1, distance = 0;
    char dist[10];
    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);

        choice[0]=mouse_press(0,0,29,29);
        choice[1]=mouse_press(45, 0, 165, 28);
        choice[2]=mouse_press(195, 0, 315, 28);
        choice[3]=mouse_press(345, 0, 465, 28);
        choice[4]=mouse_press(495, 0, 615, 28);

        if(choice[0] == 1)
        {
            return 0;
        }
        if(choice[1] == 1)
        {
            if(mode[0])
            {
                start = ChoosePlace();
                mode[0] = 0;
            }
        }
        if(choice[2] == 1)
        {
            if(mode[1])
            {
                end = ChoosePlace();
                mode[1] = 0;
            }
        }
        if(choice[3] == 1)
        {
            mode[0] = 1;
            mode[1] = 1;
            break;
        }
        if(choice[4] == 1 && start != -1 && end != -1)
        {
            distance = PlanPath(start, end);
            DrawRoute();
            setcolor(RED);
            settextstyle(2, 0, 6);

            itoa(distance, dist, 10);
            puthz(3, 33, "Ԥ", 24, 0, BLUE);
            puthz(3, 63, "��", 24, 0, BLUE);
            puthz(3, 93, "��", 24, 0, BLUE);
            puthz(3, 123, "��", 24, 0, BLUE);
            outtextxy(0, 150, dist);
            puthz(3, 170, "��", 24, 0, BLUE);

            itoa(distance/5, dist, 10);
            puthz(3, 233, "Ԥ", 24, 0, BLUE);
            puthz(3, 263, "��", 24, 0, BLUE);
            puthz(3, 293, "��", 24, 0, BLUE);
            puthz(3, 323, "ʱ", 24, 0, BLUE);
            outtextxy(0, 350, dist);
            puthz(3, 370, "��", 24, 0, BLUE);

            start = -1, end = -1;
        }

    }
    return 1;
}

/****************************************
FUNCTION:ChoosePlace
DESCRIBETION:ѡ��ص�
INPUT:void
RETURN:int
****************************************/
int ChoosePlace()
{
    int place[14] = {0}, i = 0;
    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);
        place[ 0]=mouse_press(40,40,120,70);        //�Ƽ�¥��¥
        place[ 1]=mouse_press(40,90,120,120);       //�Ƽ�¥��¥
        place[ 2]=mouse_press(30, 150, 80, 270);    //ͼ���
        place[ 3]=mouse_press(60, 340, 110, 370);   //����¥
        place[ 4]=mouse_press(40, 440, 110, 470);   //����ѧԺ
        place[ 5]=mouse_press(135, 335, 205, 365)+mouse_press(135, 395, 205, 425)+\
        mouse_press(305, 335, 375, 365)+mouse_press(305, 395, 375, 425)+mouse_press(175, 365, 335, 395);
        place[ 6]=mouse_press(215, 335, 295, 360);  //����¥
        place[ 7]=mouse_press(160, 240, 260, 290);  //Уʷ��
        place[ 8]=mouse_press(140, 140, 320, 220);  //ͣ����
        place[ 9]=mouse_press(340, 80, 390, 110);   //����
        place[10]=mouse_press(430, 140, 530, 170);  //����¥
        place[11]=mouse_press(405, 175, 555, 225);  //��һ¥
        place[12]=mouse_press(570, 250, 620, 280);  //����¥
        place[13]=mouse_press(450, 440, 500, 480);  //��Ӿ��
        
        setfillstyle(1, GREEN);
        if(place[0]==1)
        {
            fillellipse(80, 55, 5, 5);
        }
        else if(place[1]==1)
        {
            fillellipse(80, 105, 5, 5);
        }
        else if(place[2]==1)
        {
            fillellipse(55, 210, 5, 5);
        }
        else if(place[3]==1)
        {
            fillellipse(85, 355, 5, 5);
        }
        else if(place[4]==1)
        {
            fillellipse(75, 455, 5, 5);
        }
        else if(place[5]==1)
        {
            fillellipse(255, 380, 5, 5);
        }
        else if(place[6]==1)
        {
            fillellipse(255, 348, 5, 5);
        }
        else if(place[7]==1)
        {
            fillellipse(210, 265, 5, 5);
        }
        else if(place[8]==1)
        {
            fillellipse(230, 180, 5, 5);
        }
        else if(place[9]==1)
        {
            fillellipse(365, 95, 5, 5);
        }
        else if(place[10]==1)
        {
            fillellipse(480, 155, 5, 5);
        }
        else if(place[11]==1)
        {
            fillellipse(480, 200, 5, 5);
        }
        else if(place[12]==1)
        {
            fillellipse(595, 265, 5, 5);
        }
        else if(place[13]==1)
        {
            fillellipse(475, 460, 5, 5);
        }

        for(i = 0; i < 14; i++)
        {
            if(place[i] == 1)
                return i;
        }
    }
}
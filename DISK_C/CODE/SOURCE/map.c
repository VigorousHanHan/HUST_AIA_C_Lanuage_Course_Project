/**
**************************************************?
*   �汾�ţ�1.0
*   ���ߣ�X
*   �������ڣ�2024��4��10
*   ˵����Map�ຯ�����Ƶ�ͼ
**************************************************?
**/

#include<graphics.h>
#include<hz.h>
#include"map.h"

/****************************************
FUNCTION:DrawMap
DESCRIBETION:���Ƶ�ͼ
INPUT:void
RETURN:void
****************************************/
void DrawMap()
{
    DrawRoad();
    DrawBuilding();

    setlinestyle(0, 0, 3);
    setcolor(DARKGRAY);
    line(30, 30, 30, 479);
    line(30, 30, 639, 30);
}

/****************************************
FUNCTION:DrawRoad
DESCRIBETION:���Ƶ�·
INPUT:void
RETURN:void
****************************************/
void DrawRoad()
{
    setlinestyle(0, 0, 1);
    setcolor(LIGHTGRAY);

    DrawVerticalRoad(130, 30, 400);     //����· x=130, 30<y<430
    DrawVerticalRoad(230, 130, 10);       //x=230, 130<y<140
    DrawVerticalRoad(230, 220, 10);       //x=230, 220<y<230
    DrawVerticalRoad(330, 30, 300);     //��һ· x=330, 30<y<330
    DrawVerticalRoad(630, 30, 450);     //����· x=630, 30<y<480
    DrawVerticalRoad(380, 330, 102);    // x=380, 330<y<430
    DrawVerticalRoad(430, 230, 250);    // x=430, 230<y<480

    DrawParallelRoad(30, 130, 600);     //����· y=130, 30<x<630
    DrawParallelRoad(80, 230, 550);     //����· y=230, 80<x<630
    DrawParallelRoad(30, 330, 600);     //�Ͼ�· y=330, 30<x<630
    DrawParallelRoad(130, 380, 45);     //y=380, 130<x<175
    DrawParallelRoad(335, 380, 45);     //y=380, 335<x<380
    DrawParallelRoad(30, 430, 352);     // y=430, 30<x<380
    DrawParallelRoad(430, 430, 200);    // y=430, 430<x<630

    setlinestyle(0, 0, 1);
    setcolor(WHITE);
    
    DrawCrossing(130, 130, 1, 1, 1, 1); //����· ����· 14
    DrawCrossing(130, 230, 1, 1, 1, 1); //����· ����· 15
    DrawCrossing(130, 330, 1, 1, 1, 1); //����· �Ͼ�· 16
    DrawCrossing(130, 380, 1, 1, 0, 1); //����· y=380  17
    DrawCrossing(130, 430, 1, 0, 1, 1); //����· y=430  18

    DrawCrossing(230, 130, 0, 1, 1, 1); //              19
    DrawCrossing(230, 230, 1, 0, 1, 1); //              20

    DrawCrossing(330, 130, 1, 1, 1, 1); //��һ· ����· 21
    DrawCrossing(330, 230, 1, 1, 1, 1); //��һ· ����· 22
    DrawCrossing(330, 330, 1, 0, 1, 1); //��һ· �Ͼ�· 23
    
    DrawCrossing(380, 330, 0, 1, 1, 1); //x=380 �Ͼ�·  24
    DrawCrossing(380, 380, 1, 1, 1, 0); //x=380 y=380   25
    DrawCrossing(380, 430, 1, 0, 1, 0); //x=380 y=430   26

    DrawCrossing(430, 230, 0, 1, 1, 1); //x=430 y=230   27
    DrawCrossing(430, 330, 1, 1, 1, 1); //x=430 y=330   28
    DrawCrossing(430, 430, 1, 1, 0, 1); //x=430 y=430   29

    DrawCrossing(630, 130, 1, 1, 1, 0); //����· ����· 30
    DrawCrossing(630, 230, 1, 1, 1, 0); //����· ����· 31
    DrawCrossing(630, 330, 1, 1, 1, 0); //����· �Ͼ�· 32
    DrawCrossing(630, 430, 1, 1, 1, 0); //����· y=430  33
}

/****************************************
FUNCTION:DrawParallelRoad
DESCRIBETION:���ƺ����·
INPUT:int x, int y, int d
RETURN:void
****************************************/
void DrawParallelRoad(int x, int y, int d)
{
    line(x, y-2, x+d, y-2);
    line(x, y+2, x+d, y+2);

}

/****************************************
FUNCTION:DrawVerticalRoad
DESCRIBETION:���������·
INPUT:int x, int y, int d
RETURN:void
****************************************/
void DrawVerticalRoad(int x, int y, int d)
{
    line(x-2, y, x-2, y+d);
    line(x+2, y, x+2, y+d);
}

/****************************************
FUNCTION:DrawCrossing
DESCRIBETION:��������ʮ��·��
INPUT:int x, int y, int north, int south, int west, int east
RETURN:void
****************************************/
void DrawCrossing(int x, int y, int north, int south, int west, int east)
{
    if(north)
        line(x-1, y-2, x+1, y-2);
    if(south)
        line(x-1, y+2, x+1, y+2);
    if(west)
        line(x-2, y-1, x-2, y+1);
    if(east)
        line(x+2, y-1, x+2, y+1);
}

/****************************************
FUNCTION:DrawBuilding
DESCRIBETION:���ƽ�����
INPUT:void
RETURN:void
****************************************/
void DrawBuilding()
{
    setlinestyle(0, 0, 1);
    setcolor(DARKGRAY);
    rectangle(40, 40, 120, 70);     //�Ƽ�¥��¥    0
    puthz(40, 47, "�Ƽ�¥��¥", 16, 16, DARKGRAY);
    rectangle(40, 90, 120, 120);    //�Ƽ�¥��¥    1
    puthz(40, 97, "�Ƽ�¥��¥", 16, 16, DARKGRAY);
    rectangle(30, 150, 80, 270);    //ͼ���        2
    puthz(43, 162, "ͼ", 24, 0, DARKGRAY);
    puthz(43, 198, "��", 24, 0, DARKGRAY);
    puthz(43, 234, "��", 24, 0, DARKGRAY);
    rectangle(60, 340, 110, 370);   //����¥        3
    puthz(61, 347, "����¥", 16, 17, DARKGRAY);
    rectangle(40, 440, 110, 470);   //����ѧԺ      4
    puthz(41, 447, "����ѧԺ", 16, 17, DARKGRAY);
    DrawSouthBuildingOne();         //��һ¥        5
    rectangle(215, 335, 295, 360);  //����¥        6
    puthz(223, 340, "����¥", 16, 24, DARKGRAY);
    rectangle(160, 240, 260, 290);  //Уʷ��        7
    puthz(167, 253, "Уʷ��", 24, 31, DARKGRAY);
    DrawParkingLot();               //ͣ����        8
    rectangle(340, 80, 390, 110);   //����        9
    puthz(341, 87, "����", 16, 17, DARKGRAY);
    rectangle(430, 140, 530, 170);  //����¥        10
    puthz(437, 143, "����¥", 24, 31, DARKGRAY);
    rectangle(405, 175, 555, 225);  //��һ¥        11
    puthz(419, 184, "��һ¥", 32, 45, DARKGRAY);
    rectangle(570, 250, 620, 280);  //����¥        12
    puthz(571, 257, "����¥", 16, 17, DARKGRAY);
    rectangle(450, 440, 500, 480);  //��Ӿ��        13
    puthz(451, 447, "��Ӿ��", 16, 17, DARKGRAY);
}

/****************************************
FUNCTION:DrawSouthBuildingOne
DESCRIBETION:������һ¥
INPUT:void
RETURN:void
****************************************/
void DrawSouthBuildingOne()
{
    moveto(135, 335);
    lineto(205, 335);
    lineto(205, 365);
    lineto(305, 365);
    lineto(305, 335);
    lineto(375, 335);
    lineto(375, 365);
    lineto(335, 365);
    lineto(335, 395);
    lineto(375, 395);
    lineto(375, 425);
    lineto(305, 425);
    lineto(305, 395);
    lineto(205, 395);
    lineto(205, 425);
    lineto(135, 425);
    lineto(135, 395);
    lineto(175, 395);
    lineto(175, 365);
    lineto(135, 365);
    lineto(135, 335);               //��һ¥
    puthz(197, 368, "��һ¥", 24, 46, DARKGRAY);
}

/****************************************
FUNCTION:DrawParkingLot
DESCRIBETION:����
INPUT:void
RETURN:void
****************************************/
void DrawParkingLot()
{
    rectangle(140, 140, 320, 220);  //ͣ����
    circle(168, 180, 16);
    settextstyle(10, 0, 2);
    outtextxy(161, 154, "P");    
    puthz(194, 164, "ͣ����", 32, 42, DARKGRAY);

}
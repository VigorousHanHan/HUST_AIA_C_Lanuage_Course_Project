/**
**************************************************?
*   版本号：1.0
*   作者：X
*   生成日期：2024—4—10
*   说明：Map类函数绘制地图
**************************************************?
**/

#include<graphics.h>
#include<hz.h>
#include"map.h"

/****************************************
FUNCTION:DrawMap
DESCRIBETION:绘制地图
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
DESCRIBETION:绘制道路
INPUT:void
RETURN:void
****************************************/
void DrawRoad()
{
    setlinestyle(0, 0, 1);
    setcolor(LIGHTGRAY);

    DrawVerticalRoad(130, 30, 400);     //华中路 x=130, 30<y<430
    DrawVerticalRoad(230, 130, 10);       //x=230, 130<y<140
    DrawVerticalRoad(230, 220, 10);       //x=230, 220<y<230
    DrawVerticalRoad(330, 30, 300);     //东一路 x=330, 30<y<330
    DrawVerticalRoad(630, 30, 450);     //醉晚路 x=630, 30<y<480
    DrawVerticalRoad(380, 330, 102);    // x=380, 330<y<430
    DrawVerticalRoad(430, 230, 250);    // x=430, 230<y<480

    DrawParallelRoad(30, 130, 600);     //红棉路 y=130, 30<x<630
    DrawParallelRoad(80, 230, 550);     //南三路 y=230, 80<x<630
    DrawParallelRoad(30, 330, 600);     //紫荆路 y=330, 30<x<630
    DrawParallelRoad(130, 380, 45);     //y=380, 130<x<175
    DrawParallelRoad(335, 380, 45);     //y=380, 335<x<380
    DrawParallelRoad(30, 430, 352);     // y=430, 30<x<380
    DrawParallelRoad(430, 430, 200);    // y=430, 430<x<630

    setlinestyle(0, 0, 1);
    setcolor(WHITE);
    
    DrawCrossing(130, 130, 1, 1, 1, 1); //华中路 红棉路 14
    DrawCrossing(130, 230, 1, 1, 1, 1); //华中路 南三路 15
    DrawCrossing(130, 330, 1, 1, 1, 1); //华中路 紫荆路 16
    DrawCrossing(130, 380, 1, 1, 0, 1); //华中路 y=380  17
    DrawCrossing(130, 430, 1, 0, 1, 1); //华中路 y=430  18

    DrawCrossing(230, 130, 0, 1, 1, 1); //              19
    DrawCrossing(230, 230, 1, 0, 1, 1); //              20

    DrawCrossing(330, 130, 1, 1, 1, 1); //东一路 红棉路 21
    DrawCrossing(330, 230, 1, 1, 1, 1); //东一路 南三路 22
    DrawCrossing(330, 330, 1, 0, 1, 1); //东一路 紫荆路 23
    
    DrawCrossing(380, 330, 0, 1, 1, 1); //x=380 紫荆路  24
    DrawCrossing(380, 380, 1, 1, 1, 0); //x=380 y=380   25
    DrawCrossing(380, 430, 1, 0, 1, 0); //x=380 y=430   26

    DrawCrossing(430, 230, 0, 1, 1, 1); //x=430 y=230   27
    DrawCrossing(430, 330, 1, 1, 1, 1); //x=430 y=330   28
    DrawCrossing(430, 430, 1, 1, 0, 1); //x=430 y=430   29

    DrawCrossing(630, 130, 1, 1, 1, 0); //醉晚路 红棉路 30
    DrawCrossing(630, 230, 1, 1, 1, 0); //醉晚路 南三路 31
    DrawCrossing(630, 330, 1, 1, 1, 0); //醉晚路 紫荆路 32
    DrawCrossing(630, 430, 1, 1, 1, 0); //醉晚路 y=430  33
}

/****************************************
FUNCTION:DrawParallelRoad
DESCRIBETION:绘制横向道路
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
DESCRIBETION:绘制纵向道路
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
DESCRIBETION:绘制纵向十字路口
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
DESCRIBETION:绘制建筑物
INPUT:void
RETURN:void
****************************************/
void DrawBuilding()
{
    setlinestyle(0, 0, 1);
    setcolor(DARKGRAY);
    rectangle(40, 40, 120, 70);     //科技楼北楼    0
    puthz(40, 47, "科技楼北楼", 16, 16, DARKGRAY);
    rectangle(40, 90, 120, 120);    //科技楼南楼    1
    puthz(40, 97, "科技楼南楼", 16, 16, DARKGRAY);
    rectangle(30, 150, 80, 270);    //图书馆        2
    puthz(43, 162, "图", 24, 0, DARKGRAY);
    puthz(43, 198, "书", 24, 0, DARKGRAY);
    puthz(43, 234, "馆", 24, 0, DARKGRAY);
    rectangle(60, 340, 110, 370);   //南三楼        3
    puthz(61, 347, "南三楼", 16, 17, DARKGRAY);
    rectangle(40, 440, 110, 470);   //建规学院      4
    puthz(41, 447, "建规学院", 16, 17, DARKGRAY);
    DrawSouthBuildingOne();         //南一楼        5
    rectangle(215, 335, 295, 360);  //南六楼        6
    puthz(223, 340, "南六楼", 16, 24, DARKGRAY);
    rectangle(160, 240, 260, 290);  //校史馆        7
    puthz(167, 253, "校史馆", 24, 31, DARKGRAY);
    DrawParkingLot();               //停车场        8
    rectangle(340, 80, 390, 110);   //网球场        9
    puthz(341, 87, "网球场", 16, 17, DARKGRAY);
    rectangle(430, 140, 530, 170);  //东八楼        10
    puthz(437, 143, "东八楼", 24, 31, DARKGRAY);
    rectangle(405, 175, 555, 225);  //东一楼        11
    puthz(419, 184, "东一楼", 32, 45, DARKGRAY);
    rectangle(570, 250, 620, 280);  //东三楼        12
    puthz(571, 257, "东三楼", 16, 17, DARKGRAY);
    rectangle(450, 440, 500, 480);  //游泳馆        13
    puthz(451, 447, "游泳馆", 16, 17, DARKGRAY);
}

/****************************************
FUNCTION:DrawSouthBuildingOne
DESCRIBETION:绘制南一楼
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
    lineto(135, 335);               //南一楼
    puthz(197, 368, "南一楼", 24, 46, DARKGRAY);
}

/****************************************
FUNCTION:DrawParkingLot
DESCRIBETION:绘制
INPUT:void
RETURN:void
****************************************/
void DrawParkingLot()
{
    rectangle(140, 140, 320, 220);  //停车场
    circle(168, 180, 16);
    settextstyle(10, 0, 2);
    outtextxy(161, 154, "P");    
    puthz(194, 164, "停车场", 32, 42, DARKGRAY);

}
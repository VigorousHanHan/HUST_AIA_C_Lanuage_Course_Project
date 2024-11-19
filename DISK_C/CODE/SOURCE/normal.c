/**
**************************************************?
*   版本号：1.0
*   作者：X
*   生成日期：2024—4—21
*   说明：Normal类函数表示正常情况下运行
**************************************************?
**/

#include<stdarg.h>
#include"init.h"
#include"normal.h"

/****************************************
FUNCTION:NormalRun
DESCRIBETION:正常情况下运行
INPUT:int*
REUTRUN:int
****************************************/
int NormalRun(int* bg)
{
    int distance[40] = {0}, place[40] = {0};
    int i, num = -1, sum_distance = 0, now_distance;
    char text[10];
    FILE* path_text;

    path_text = fopen("..\\CODE\\text\\path.txt", "rt");
    do
    {
        num++;
        fscanf(path_text, "%d %d ", &place[num], &distance[num]);
        sum_distance+=distance[num];
    } while (distance[num]!=1000);
    fclose(path_text);
    place[num+1] = 1000;
    sum_distance-=1000;
    now_distance=sum_distance;
    setfillstyle(1, WHITE);
    bar(0, 106, 200, 140);
    puthz(25, 108, "剩余里程", 16, 16, BLUE);
    puthz(25, 124, "剩余时间", 16, 16, BLUE);
    puthz(113, 108, "米", 16, 16, BLUE);
    puthz(113, 124, "秒", 16, 16, BLUE);
    setcolor(RED);
    settextstyle(2, 0, 5);
    itoa(sum_distance, text, 10);
    outtextxy(89, 108, text);
    itoa(sum_distance/5, text, 10);
    outtextxy(89, 124, text);
 
    for(i = num; i > -1; i--)
    {
        CaseRun(bg, place, distance, i, &now_distance);
    }
    return 1;
}

/****************************************
FUNCTION:CaseRun
DESCRIBETION:根据不同的情况选择在不同的道路上运行
INPUT:int* place, int* distance, int i, int* now_distance
REUTRUN:void
****************************************/
void CaseRun(int* bg, int* place, int* distance, int i, int* pnow_distance)
{
    int j;
    if(i == 0)
    {
        FillArrow(4);
        setfillstyle(1, WHITE);
        bar(0, 90, 200, 140);
        puthz(25, 90, "到达目的地附近", 16, 16, BLUE);
        return;
    }

    if(place[i]==0){
        FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过华中路");}
    else if(place[i]==1){
        if(place[i-1]==0){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过华中路");}
        else if(place[i-1]==14){
            if(place[i-2]==15){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过华中路");}
            else if(place[i-2]==19){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过华中路", "左转，进入红棉路");}}}
    else if(place[i]==2){
        if(place[i-1]==15){
            if(place[i-2]==7){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过南三路");}
            else if(place[i-2]==14){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过南三路", "左转，进入华中路");}
            else if(place[i-2]==16){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过南三路", "右转，进入华中路");}}}
    else if(place[i]==3){
        if(place[i-2]==6){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过紫荆路");}
        else if(place[i-2]==15){
            FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过紫荆路", "左转，进入华中路");}
        else if(place[i-2]==17){
            FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过紫荆路", "右转，进入华中路");}}
    else if(place[i]==4){
        if(place[i-2]==17){
            FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过无名路", "左转，进入华中路");}
        else if(place[i-2]==26){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过无名路");}}
    else if(place[i]==5){
        if(place[i-1]==17){
            if(place[i-2]==16){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行后右转，进入华中路", "右转，进入华中路");}
            else if(place[i-2]==18){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行后左转，进入华中路", "左转，进入华中路");}}
        if(place[i-1]==25){
            if(place[i-2]==24){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行后左转，进入无名路", "左转，进入无名路");}
            else if(place[i-2]==26){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行后右转，进入无名路", "右转，进入无名路");}}}
    else if(place[i]==6){
        if(place[i-1]==16){
            if(place[i-2]==3){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过紫荆路");}
            else if(place[i-2]==15){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过紫荆路", "右转，进入华中路");}
            else if(place[i-2]==17){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过紫荆路", "左转，进入华中路");}}
        else if(place[i-1]==23){
            if(place[i-2]==22){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过紫荆路", "左转，进入东一路");}
            else if(place[i-2]==24){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过紫荆路");}}}
    else if(place[i]==7){
        if(place[i-1]==15){
            if(place[i-2]==2){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过南三路");}
            else if(place[i-2]==14){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过南三路", "右转，进入华中路");}
            else if(place[i-2]==16){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过南三路", "左转，进入华中路");}}
        else if(place[i-1]==20){
            if(place[i-2]==8){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过南三路", "左转，进入停车场");}
            else if(place[i-2]==22){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过南三路");}}}
    else if(place[i]==8){
        if(place[i-1]==19){
            if(place[i-2]==14){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "", "左转，进入红棉路");}
            else if(place[i-2]==21){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "", "右转，进入红棉路");}}
        else if(place[i-1]==20){
            if(place[i-2]==7){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "", "右转，进入南三路");}
            else if(place[i-2]==22){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "", "左转，进入南三路");}}}
    else if(place[i]==9){
        if(place[i-2]==10){
            FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过东一路", "左转，进入红棉路");}
        else if(place[i-2]==19){
            FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过东一路", "右转，进入红棉路");}
        else if(place[i-2]==22){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过东一路");}}
    else if(place[i]==10){
        if(place[i-1]==21){
            if(place[i-2]==9){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过红棉路", "右转，进入东一路");}
            else if(place[i-2]==19){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过红棉路");}
            else if(place[i-2]==22){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过红棉路", "左转，进入东一路");}}
        if(place[i-1]==30){
            FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过红棉路", "右转，进入醉晚路");}}
    else if(place[i]==11){
        if(place[i-1]==27){
            if(place[i-2]==22){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过南三路");}
            else if(place[i-2]==28){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过南三路", "左转，进入无名路");}}
        else if(place[i-1]==31){
            if(place[i-2]==12){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过南三路", "右转，进入醉晚路");}
            else if(place[i-2]==30){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过南三路", "左转，进入醉晚路");}}}
    else if(place[i]==12){
        if(place[i-1]==31){
            if(place[i-2]==11){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过醉晚路", "左转，进入南三路");}
            else if(place[i-2]==30){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过醉晚路");}}
        else if(place[i-1]==32){
            if(place[i-2]==28){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过醉晚路", "右转，进入紫荆路");}
            else if(place[i-2]==33){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过醉晚路");}}}
    else if(place[i]==13){
        if(place[i-1]==29){
            FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过无名路", "右转，进入无名路");}
        else if(place[i-1]==33){
            FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过无名路", "左转，进入醉晚场");}}
    else if(place[i]==14){
        if(place[i-1]==1){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过华中路");}
        else if(place[i-1]==15){
            if(place[i-2]==2){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过华中路", "右转，进入南三路");}
            else if(place[i-2]==7){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过华中路", "左转，进入南三路");}
            else if(place[i-2]==16){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过华中路");}}
        else if(place[i-1]==19){
            if(place[i-2]==8){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过红棉路", "右转，进入停车场");}
            else if(place[i-2]==21){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过红棉路");}}}
    else if(place[i]==15){
        if(place[i-1]==2 || place[i-1]==7){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过南三路");}
        else if(place[i-1]==14){
            if(place[i-2]==1){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过华中路");}
            else if(place[i-2]==19){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过华中路", "右转，进入红棉路");}}
        else if(place[i-1]==16){
            if(place[i-2]==3){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过华中路", "右转，进入紫荆路");}
            else if(place[i-2]==6){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过华中路", "左转，进入紫荆路");}
            else if(place[i-2]==17){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过华中路");}}}
    else if(place[i]==16){
        if(place[i-1]==3 || place[i-1]==6){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过紫荆路");}
        else if(place[i-1]==15){
            if(place[i-2]==2){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过华中路", "左转，进入南三路");}
            else if(place[i-2]==7){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过华中路", "右转，进入南三路");}
            else if(place[i-2]==14){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过华中路");}}
        else if(place[i-1]==17){
            if(place[i-2]==5){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过华中路", "左转，到达南一楼");}
            else if(place[i-2]==18){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过华中路");}}}
    else if(place[i]==17){
        if(place[i-1]==5){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，到达南一楼");}
        else if(place[i-1]==16){
            if(place[i-2]==3){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过华中路", "左转，进入紫荆路");}
            else if(place[i-2]==6){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过华中路", "右转，进入紫荆路");}
            else if(place[i-2]==15){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过华中路");}}
        else if(place[i-1]==18){
            if(place[i-2]==4){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过华中路", "右转，到达建规学院");}
            else if(place[i-2]==26){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过华中路", "左转，进入无名路");}}}
    else if(place[i]==18){
        if(place[i-1]==4){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，到达建规学院");}
        else if(place[i-1]==17){
            if(place[i-2]==5){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过华中路", "右转，到达南一楼");}
            else if(place[i-2]==16){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过华中路");}}
        else if(place[i-1]==26){
            FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过无名路", "左转，进入无名路");}}
    else if(place[i]==19){
        if(place[i-1]==8){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，到达停车场");}
        else if(place[i-1]==14){
            if(place[i-2]==1){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过红棉路", "右转，进入华中路");}
            else if(place[i-2]==15){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过红棉路", "左转，进入华中路");}}
        else if(place[i-1]==21){
            if(place[i-2]==9){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过红棉路", "左转，进入东一路");}
            else if(place[i-2]==10){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过红棉路");}
            else if(place[i-2]==22){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过红棉路", "右转，进入东一路");}}}
    else if(place[i]==20){
        if(place[i-1]==7){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过南三路");}
        else if(place[i-1]==8){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，到达停车场");}
        else if(place[i-1]==22){
            if(place[i-2]==21){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过南三路", "左转，进入东一路");}
            else if(place[i-2]==23){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过南三路", "右转，进入华中路");}
            else if(place[i-2]==27){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过南三路");}}}
    else if(place[i]==21){
        if(place[i-1]==9){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过东一路");}
        else if(place[i-1]==10){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过红棉路");}
        else if(place[i-1]==19){
            if(place[i-2]==8){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过红棉路", "左转，进入停车场");}
            else if(place[i-2]==14){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过红棉路");}}
        else if(place[i-1]==22){
            if(place[i-2]==20){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过东一路", "右转，进入南三路");}
            else if(place[i-2]==23){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过东一路");}
            else if(place[i-2]==27){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过东一路");}}}
    else if(place[i]==22){
        if(place[i-1]==20){
            if(place[i-2]==8){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过南三路", "右转，进入停车场");}
            else if(place[i-2]==7){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过南三路");}}
        else if(place[i-1]==21){
            if(place[i-2]==9){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过东一路");}
            else if(place[i-2]==10){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过东一路", "右转，进入红棉路");}
            else if(place[i-2]==19){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过东一路", "左转，进入红棉路");}}
        else if(place[i-1]==23){
            if(place[i-2]==6){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过东一路", "右转，进入紫荆路");}
            else if(place[i-2]==24){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过东一路", "左转，进入紫荆路");}}
        else if(place[i-1]==27){
            if(place[i-2]==11){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过南三路");}
            else if(place[i-2]==28){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过东一路", "右转，进入无名路");}}}
    else if(place[i]==23){
        if(place[i-1]==6){
             FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过紫荆路");}
        else if(place[i-1]==22){
            if(place[i-2]==20){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过东一路", "左转，进入南三路");}
            else if(place[i-2]==21){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过东一路");}
            else if(place[i-2]==27){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过东一路", "右转，进入南三路");}}
        else if(place[i-1]==24){
            if(place[i-2]==25){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过紫荆路", "右转，进入无名路");}
            else if(place[i-2]==28){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过紫荆路");}}}
    else if(place[i]==24){
        if(place[i-1]==23){
            if(place[i-2]==6){FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过紫荆路");}
            else if(place[i-2]==22){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过紫荆路", "右转，进入东一路");}}
        else if(place[i-1]==25){
            if(place[i-2]==5){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过无名路", "右转，到达南一楼");}
            else if(place[i-2]==26){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过无名路");}}
        else if(place[i-1]==28){
            if(place[i-2]==27){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过紫荆路", "左转，进入无名路");}
            else if(place[i-2]==29){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过紫荆路", "右转，进入无名路");}
            else if(place[i-2]==32){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过紫荆路");}}}
    else if(place[i]==25){
        if(place[i-1]==5){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，到达南一楼");}
        else if(place[i-1]==24){
            if(place[i-2]==23){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过无名路", "左转，进入紫荆路");}
            else if(place[i-2]==28){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过无名路", "右转，进入紫荆路");}}
        else if(place[i-1]==26){
            FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过无名路", "右转，进入无名路");}}
    else if(place[i]==26){
        if(place[i-1]==18){
            if(place[i-2]==4){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过无名路");}
            else if(place[i-2]==17){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过无名路", "右转，进入华中路");}}
        else if(place[i-1]==25){
            if(place[i-2]==5){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过无名路", "左转，到达南一楼");}
            else if(place[i-2]==24){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过无名路");}}}
    else if(place[i]==27){
        if(place[i-1]==11){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过南三路");}
        else if(place[i-1]==22){
            if(place[i-2]==20){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过南三路");}
            else if(place[i-2]==21){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过南三路", "右转，进入东一路");}
            else if(place[i-2]==23){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过南三路", "左转，进入东一路");}}
        else if(place[i-1]==28){
            if(place[i-2]==24){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过无名路", "右转，进入紫荆路");}
            else if(place[i-2]==29){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过无名路");}
            else if(place[i-2]==32){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过无名路", "左转，进入紫荆路");}}}
    else if(place[i]==28){
        if(place[i-1]==24){
            if(place[i-2]==23){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过紫荆路");}
            else if(place[i-2]==25){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过紫荆路", "左转，进入无名路");}}
        else if(place[i-1]==27){
            if(place[i-2]==11){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过无名路", "右转，进入南三路");}
            else if(place[i-2]==22){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过无名路", "左转，进入南三路");}}
        else if(place[i-1]==29){
            FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过无名路", "左转，进入无名路");}
        else if(place[i-1]==32){
            if(place[i-2]==31){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过紫荆路", "左转，进入醉晚路");}
            else if(place[i-2]==33){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过紫荆路", "右转，进入醉晚路");}}}
    else if(place[i]==29){
        if(place[i-1]==13){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过无名路");}
        else if(place[i-1]==24){
            if(place[i-2]==25){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过紫荆路", "右转，进入无名路");}
            else if(place[i-2]==28){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过紫荆路");}}
        else if(place[i-1]==28){
            if(place[i-2]==24){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过无名路", "左转，进入紫荆路");}
            else if(place[i-2]==27){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过无名路");}
            else if(place[i-2]==32){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过无名路", "右转，进入紫荆路");}}}
    else if(place[i]==30){
        if(place[i-1]==10){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过红棉路");}
        else if(place[i-1]==31){
            if(place[i-2]==11){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过醉晚路", "右转，进入南三路");}
            else if(place[i-2]==12){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过醉晚路");}}}
    else if(place[i]==31){
        if(place[i-1]==11){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过南三路");}
        else if(place[i-1]==12){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过醉晚路");}
        else if(place[i-1]==30){
            FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过醉晚路", "左转，进入红棉路");}}
    else if(place[i]==32){
        if(place[i-1]==12){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过醉晚路");}
        else if(place[i-1]==28){
            if(place[i-2]==24){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过紫荆路");}
            else if(place[i-2]==27){
                FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过紫荆路", "右转，进入无名路");}
            else if(place[i-2]==29){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过紫荆路", "左转，进入无名路");}}
        else if(place[i-1]==33){
            FragmentRun(bg, distance, i, RIGHT, pnow_distance, 2, "直行，通过醉晚路", "右转，进入无名路");}}
    else if(place[i]==33){
        if(place[i-1]==13){
            FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过无名路");}
        else if(place[i-1]==32){
            if(place[i-2]==12){
                FragmentRun(bg, distance, i, STRIGHT, pnow_distance, 1, "直行，通过醉晚路");}
            else if(place[i-2]==28){
                FragmentRun(bg, distance, i, LEFT, pnow_distance, 2, "直行，通过醉晚路", "左转，进入紫荆路");}}}
}

/****************************************
FUNCTION:FragmentRun
DESCRIBETION:运行一段道路
INPUT:int*distance, int i, int direction, int* pnow_distance, int num, ...
REUTRUN:void
****************************************/
void FragmentRun(int* bg, int*distance, int i, int direction, int* pnow_distance, int num, ...)
{
    int j;
    char hanzi[2][100];
    va_list args;
    va_start(args, num);
    strcpy(hanzi[0], va_arg(args, const char*));
    if(num==2)
        strcpy(hanzi[1], va_arg(args, const char*));

    setfillstyle(1, WHITE);
    bar(0, 90, 200, 106);
    puthz(25, 90, hanzi[0], 16, 16, BLUE);
    for(j = 0; j < distance[i-1]-10; j++)
        RoutineRun(bg,pnow_distance, STRIGHT);
    if(direction == STRIGHT)
    {
        for(j = distance[i-1]-10; j < distance[i-1]; j++)
            RoutineRun(bg,pnow_distance, direction);
    }
    else if(direction == LEFT)
    {
        setfillstyle(1, WHITE);
        bar(0, 90, 200, 106);
        puthz(25, 90, hanzi[1], 16, 16, BLUE);
        for(j = distance[i-1]-10; j < distance[i-1]; j++)
            RoutineRun(bg,pnow_distance, direction);
    }
    else if(direction == RIGHT)
    {
        setfillstyle(1, WHITE);
        bar(0, 90, 200, 106);
        puthz(25, 90, hanzi[1], 16, 16, BLUE);
        for(j = distance[i-1]-10; j < distance[i-1]; j++)
            RoutineRun(bg,pnow_distance, direction);
    }
}

/****************************************
FUNCTION:RoutineRun
DESCRIBETION:直行
INPUT:int* pnow_distance, int direction
REUTRUN:
****************************************/
void RoutineRun(int* bg, int* pnow_distance, int direction)
{
    FillArrow(direction);
    *pnow_distance-=1;
    PutMiles(pnow_distance);
	DrawBackground(bg);
}

/****************************************
FUNCTION:FillArrow
DESCRIBETION:填充箭头
INPUT:mode
REUTRUN:void
****************************************/
void FillArrow(int mode)
{
    setfillstyle(1, WHITE);
    floodfill(50, 60, BLUE);
    floodfill(100, 60, BLUE);
    floodfill(150, 60, BLUE);

    setfillstyle(1, YELLOW);
    switch (mode)
    {
    case LEFT:
        floodfill(50, 60, BLUE);
        break;
    case STRIGHT:
        floodfill(100, 60, BLUE);
        break;
    case RIGHT:
        floodfill(150, 60, BLUE);
        break;
    default:
        break;
    }
}

/****************************************
FUNCTION:PutMiles
DESCRIBETION:显示里程等信息
INPUT:int* pnow_distance
REUTRUN:void
****************************************/
void PutMiles(int* pnow_distance)
{
    char text[10];
    setfillstyle(1, WHITE);
    bar(89, 108, 113, 140);
    setcolor(RED);
    settextstyle(2, 0, 5);
    itoa(*pnow_distance, text, 10);
    outtextxy(89, 108, text);
    itoa((*pnow_distance)/5, text, 10);
    outtextxy(89, 124, text);
}


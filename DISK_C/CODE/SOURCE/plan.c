/**
**************************************************?
*   版本号：1.0
*   作者：X
*   生成日期：2024—3—30
*   说明：Plan类函数实现路径规划功能
**************************************************?
**/

#include<graphics.h>
#include<stdio.h>
#include"plan.h"
#define MAX 9999
#define N 34

/****************************************
FUNCTION:PlanPath
DESCRIBETION:规划路线
INPUT:int start, int end
RETURN:int
****************************************/
int PlanPath(int start, int end)
{
    int distance[N][N] =
    {
         //0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33 
        {  0, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  // 0
        { 50,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 25,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  // 1
        {MAX,MAX,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  // 2
        {MAX,MAX,MAX,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  // 3
        {MAX,MAX,MAX,MAX,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  // 4
        {MAX,MAX,MAX,MAX,MAX,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  // 5
        {MAX,MAX,MAX,MAX,MAX,MAX,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,125,MAX,MAX,MAX,MAX,MAX,MAX, 75,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  // 6
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 75,MAX,MAX,MAX,MAX, 25,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  // 7
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 10, 10,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  // 8
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 25,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  // 9
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,150,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,150,MAX,MAX,MAX},  //10
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,MAX,MAX,MAX,150,MAX,MAX},  //11
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 25, 75,MAX},  //12
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,MAX,MAX,MAX,150},  //13
        {MAX, 25,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,  0,100,MAX,MAX,MAX,100,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  //14
        {MAX,MAX, 50,MAX,MAX,MAX,MAX, 75,MAX,MAX,MAX,MAX,MAX,MAX,100,  0,100,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  //15
        {MAX,MAX,MAX, 50,MAX,MAX,125,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,100,  0, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  //16
        {MAX,MAX,MAX,MAX,MAX, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,  0, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  //17
        {MAX,MAX,MAX,MAX, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX,250,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  //18
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 10,MAX,MAX,MAX,MAX,MAX,100,MAX,MAX,MAX,MAX,  0,MAX,100,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  //19
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX, 25, 10,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,  0,MAX,100,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  //20
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 25,150,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,100,MAX,  0,100,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  //21
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,100,100,  0,100,MAX,MAX,MAX,100,MAX,MAX,MAX,MAX,MAX,MAX},  //22
        {MAX,MAX,MAX,MAX,MAX,MAX, 75,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,100,  0, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  //23
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,  0, 50,MAX,MAX, 50,MAX,MAX,MAX,MAX,MAX},  //24
        {MAX,MAX,MAX,MAX,MAX, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,  0, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  //25
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,250,MAX,MAX,MAX,MAX,MAX,MAX, 50,  0,MAX,MAX,MAX,MAX,MAX,MAX,MAX},  //26
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,100,MAX,MAX,MAX,MAX,  0,100,MAX,MAX,MAX,MAX,MAX},  //27
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,MAX,MAX,100,  0,100,MAX,MAX,200,MAX},  //28
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 50,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,100,  0,MAX,MAX,MAX,MAX},  //29
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,150,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,  0,100,MAX,MAX},  //30
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,150, 25,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,100,  0,MAX,MAX},  //31
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX, 75,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,200,MAX,MAX,MAX,  0,100},  //32
        {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,150,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,100,  0},  //33
    };
    return Dijkstra(start, end, distance);
}

/****************************************
FUNCTION:Dijkstra
DESCRIBETION:实现迪杰斯特拉算法
INPUT:int start, int end, int distance[][34]
RETURN:int
****************************************/
int Dijkstra(int start, int end, int distance[][N])
{
    int start_distance[N], vertex[N] = {0};
    int i, u, v;
    FILE* path_text;
    PathNode path_node[N], *temp = &path_node[end];

    for(i = 0; i < N; i++)
    {
        start_distance[i] = MAX;
        path_node[i].node = i;
        path_node[i].next = NULL;
    }
    start_distance[start] = 0;

    while(!vertex[end])
    {
        u = MinDistance(start_distance, vertex);
        vertex[u] = 1;



        for(v = 0; v < N; v++)
        {
            if((u!=5&&u!=8&&start!=5&&start!=8)||start==5||start==8)
            {
                if(!vertex[v] && distance[u][v]!=MAX && start_distance[u] + distance[u][v] < start_distance[v])
                {
                    start_distance[v] = start_distance[u] + distance[u][v];
                    path_node[v].next = &path_node[u];
                }
            }
        }
    }
        
    path_text = fopen("..\\CODE\\text\\path.txt", "wt");
    do
    {
        fprintf(path_text, "%d %d ", (*temp).node, distance[(*temp).node][(*((*temp).next)).node]);
        temp = (*temp).next;
    }while((*temp).next!=NULL);
    fprintf(path_text, "%d %d ", start, 1000);
    fclose(path_text);
    return start_distance[end];
}

/****************************************
FUNCTION:MinDistance
DESCRIBETION:返回尚未包含在最短路径树中的最小距离的顶点的索引
INPUT:int* distance, int* vertex
RETURN:int
****************************************/
int MinDistance(int* start_distance, int* vertex)
{
    int min = MAX, min_index, v;

    for (v = 0; v < N; v++)
        if (vertex[v] == 0 && start_distance[v] <= min)
            min = start_distance[v], min_index = v;

    return min_index;
}

/****************************************
FUNCTION:DrawRoute
DESCRIBETION:绘制路线
INPUT:void
RETURN:void
****************************************/
void DrawRoute()
{
    int place[35] = {0}, i = -1;
    int x_1, x_2, y_1, y_2;
    FILE* path_text;
    path_text = fopen("..\\CODE\\text\\path.txt", "rt");
    do
    {
        i++;
        fscanf(path_text, "%d %d ", &place[i], &place[i+1]);
    } while (place[i+1] != 1000);
    fclose(path_text);

    i = 0;
    setcolor(GREEN);
    DrawStartEnd(place[i]);     //end
    while(place[i+1] != 1000)
    {
        ReturnCoordinates(i, place, &x_1, &y_1);
        ReturnCoordinates(i+1, place, &x_2, &y_2);
        line(x_1, y_1, x_2, y_2);
        i++;
    }
    DrawStartEnd(place[i]);     //start
    return ;
}

/****************************************
FUNCTION:ReturnCoordinates
DESCRIBETION:返回路线的坐标
INPUT:int i, int* place, int* x, int* y
RETURN:void
****************************************/
void ReturnCoordinates(int i, int* place, int* x, int* y)
{
    switch (place[i])
    {
    case 0:
        *x = 130, *y = 55;
        break;
    case 1:
        *x = 130, *y = 105;
        break;
    case 2:
        *x = 80, *y = 230;
        break;
    case 3:
        *x = 80, *y = 330;
        break;
    case 4:
        *x = 80, *y = 430;
        break;
    case 5:
        if(place[i+1] == 1000)
        {
            if(place[i-1] == 17)
                *x = 175, *y = 380;
            else if(place[i-1] == 25)
                *x = 335, *y = 380;
        }
        else
        {
            if(place[i+1] == 17)
                *x = 175, *y = 380;
            else if(place[i+1] == 25)
                *x = 335, *y = 380;
        }
        break;
    case 6:
        *x = 255, *y = 330;
        break;
    case 7:
        *x = 205, *y = 230;
        break;
    case 8:
        if(place[i+1] == 1000)
        {
            if(place[i-1] == 19)
                *x = 230, *y = 140;
            else if(place[i-1] == 20)
                *x = 230, *y = 220;
        }
        else
        {
            if(place[i+1] == 19)
                *x = 230, *y = 140;
            else if(place[i+1] == 20)
                *x = 230, *y = 220;
        }
        break;
    case 9:
        *x = 330, *y = 105;
        break;
    case 10:
        *x = 480, *y = 130;
        break;
    case 11:
        *x = 480, *y = 230;
        break;
    case 12:
        *x = 630, *y = 255;
        break;
    case 13:
        *x = 480, *y = 430;
        break;
    case 14:
        *x = 130, *y = 130;
        break;
    case 15:
        *x = 130, *y = 230;
        break;
    case 16:
        *x = 130, *y = 330;
        break;
    case 17:
        *x = 130, *y = 380;
        break;
    case 18:
        *x = 130, *y = 430;
        break;
    case 19:
        *x = 230, *y = 130;
        break;
    case 20:
        *x = 230, *y = 230;
        break;
    case 21:
        *x = 330, *y = 130;
        break;
    case 22:
        *x = 330, *y = 230;
        break;
    case 23:
        *x = 330, *y = 330;
        break;
    case 24:
        *x = 380, *y = 330;
        break;
    case 25:
        *x = 380, *y = 380;
        break;
    case 26:
        *x = 380, *y = 430;
        break;
    case 27:
        *x = 430, *y = 230;
        break;
    case 28:
        *x = 430, *y = 330;
        break;
    case 29:
        *x = 430, *y = 430;
        break;
    case 30:
        *x = 630, *y = 130;
        break;
    case 31:
        *x = 630, *y = 230;
        break;
    case 32:
        *x = 630, *y = 330;
        break;
    case 33:
        *x = 630, *y = 430;
        break;
    case 34:
        *x = 630, *y = 530;
        break;
    }
    return ;
}

/****************************************
FUNCTION:DrawStartEnd
DESCRIBETION:绘制起点或终点处的路线
INPUT:int num
RETURN:void
****************************************/
void DrawStartEnd(int num)
{
    setcolor(GREEN);
    switch (num)
    {
    case 0:
        line(130, 55, 120, 55);
        break;
    case 1:
        line(130, 105, 120, 105);
        break;
    case 2:
        break;
    case 3:
        line(80, 330, 80, 340);
        break;
    case 4:
        line(80, 430, 80, 440);
        break;
    case 5:
        break;
    case 6:
        line(255, 330, 255, 335);
        break;
    case 7:
        line(205, 230, 205, 240);
        break;
    case 8:
        break;
    case 9:
        line(330, 105, 340, 105);
        break;
    case 10:
        line(480, 130, 480, 140);
        break;
    case 11:
        line(480, 230, 480, 225);
        break;
    case 12:
        line(630, 255, 620, 255);
        break;
    case 13:
        line(480, 430, 480, 440);
        break;
    }
}
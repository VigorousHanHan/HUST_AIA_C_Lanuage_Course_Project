#ifndef _PLAN_H_
#define _PLAN_H_

typedef struct PathNode {
    int node;               // �ڵ���
    struct PathNode* next;  // ָ����һ���ڵ��ָ��
} PathNode;

int PlanPath(int start, int end);
int Dijkstra(int start, int end, int distance[][34]);
int MinDistance(int* start_distance, int* vertex);
void DrawRoute(void);
void ReturnCoordinates(int i, int* place, int* x, int* y);
void DrawStartEnd(int num);

#endif
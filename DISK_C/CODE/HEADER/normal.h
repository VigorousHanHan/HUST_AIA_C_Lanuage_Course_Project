#ifndef _NORMAL_H_
#define _NORMAL_H_

int NormalRun(int* bg);
void CaseRun(int* bg, int* place, int* distance, int i, int* now_distance);
void RoutineRun(int* bg, int* pnow_distance, int direction);
void FillArrow(int mode);
void PutMiles(int* pnow_distance);
void FragmentRun(int* bg, int*distance, int i, int direction, int* pnow_distance, int num, ...);
enum DIRECTION{LEFT, STRIGHT, RIGHT};

#endif
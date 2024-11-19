#ifndef _DISPLAY_H_
#define _DISPLAY_H_

void OpenDisplay(void);
void DrawDisplaySButton(int *num);
void DrawCar(int x,int y,float k);
void DrawTime(int x,int y,int k);
int DisplayMouse(int* num);
void DrawDailnumber();
void DrawDisplayChangePart(int *num);
void Run(int *num);
void DrawArrow(void);
void DrawBackground(int *num);
void DisplayChange(int *num,int battery);

#endif
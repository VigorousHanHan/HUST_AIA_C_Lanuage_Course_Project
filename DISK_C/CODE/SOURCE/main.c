/**
**************************************************?
*	�汾�ţ�1.0
*	���ߣ�X
*	�������ڣ�2024-2-28
*	˵����Main��������������
**************************************************?
**/

#include<graphics.h>
#include"init.h"
#include"page.h"


int main()
{
	int gd = VGA, gm = VGAHI;
	initgraph(&gd, &gm, "..\\BORLANDC\\BGI");
	while(1)
	{
		ClearGraph(WHITE);
		OpenMainPage();		
	}
}

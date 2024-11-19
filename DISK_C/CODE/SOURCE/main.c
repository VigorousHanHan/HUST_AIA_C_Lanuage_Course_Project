/**
**************************************************?
*	版本号：1.0
*	作者：X
*	生成日期：2024-2-28
*	说明：Main函数（主函数）
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

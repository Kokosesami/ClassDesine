#ifndef END_MOVIE_H
#define END_MOVIE_H

#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <time.h>
using namespace std;

int endTimer(int delay, int no)
{
	static int StartTime[10];
	int endTime = clock();
	if (endTime - StartTime[no] > delay)
	{
		StartTime[no] = endTime;
		return 1;
	}
	return 0;
}

void kokofloat()
{
	IMAGE bye;
	loadimage(&bye, "byebye.jpg", 1200, 691);

	//图片移动JustForFun
	IMAGE kokomi[2];
	loadimage(&kokomi[0], "kokomi2.jpg", 100, 100);//掩码图
	loadimage(&kokomi[1], "kokomi1.jpg", 100, 100);//背景图
	int x = 0, y = 0;
	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;
	int changedx = 0;
	int changedy = 0;
	int timecount = 0;
	int timeremain = 0;
	char toptext[100] = { '0' };
	BeginBatchDraw();//双缓冲解决闪烁问题
	ExMessage msg;
	while (1)
	{
		putimage(0, 0, &bye);
		timeremain = (500 - timecount) / 100;
		IMAGE topPicture;
		loadimage(&topPicture, "byebye.jpg", 1200, 691);
		putimage(0, 0, &topPicture);
		sprintf(toptext, "                      窗口关闭倒计时%d                       ", timeremain+1);
		setbkcolor(WHITE);
		setbkmode(OPAQUE);
		settextstyle(40, 0, "正楷");
		settextcolor(BLACK);
		outtextxy(0, 0, toptext);
		outtextxy(0, 40, "               按下上下左右移动kokomi（不动的那只）          ");
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "隶书");
		settextcolor(RGB(239, 202, 240));
		outtextxy(1100-x, 641-y, "拜拜");
		putimage(x, y+100, &kokomi[0], SRCAND);
		putimage(x, y+100, &kokomi[1], SRCPAINT);
		putimage(x1, y1, &kokomi[0], SRCAND);
		putimage(x1, y1, &kokomi[1], SRCPAINT);
		if (endTimer(8, 0))
		{
			if (GetAsyncKeyState(VK_UP))
			{
				y1 -= 5;
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				y1 += 5;
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				x1 += 5;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				x1 -= 5;
			}
			if (x == 0)
			{
				changedx = 0;
			}
			if (x == 1100)
			{
				changedx = 1;
			}
			if (changedx == 0)
			{
				x++;
			}
			else
			{
				x--;
			}
			if (y == 0)
			{
				changedy = 0;
			}
			if (y == 441)
			{
				changedy = 1;
			}
			if (changedy == 0)
			{
				y++;
			}
			else
			{
				y--;
			}
			timecount++;
		}
		//Sleep(1); 阻塞导致程序影响，使用定时器就不会影响程序
		FlushBatchDraw();
		if (timecount==500)
		{
			return;
		}
	}
	EndBatchDraw();
}

#endif // !END_MOVING_H
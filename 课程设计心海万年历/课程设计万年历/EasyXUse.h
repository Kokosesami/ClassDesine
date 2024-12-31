#ifndef EASY_X_USE_H
#define EASY_X_USE_H

#include <graphics.h>

using namespace std;

//计时器
int Timer(int delay, int no)
{
    static int StartTime[100];
    int endTime = clock();
    if (endTime - StartTime[no] > delay)
    {
        StartTime[no] = endTime;
        return 1;
    }
    return 0;
}

void bk()
{
    initgraph(1200, 691, 1);
    IMAGE img;
    loadimage(&img, "kokomibk.jpg", 1200, 691);
    putimage(0, 0, &img);
    //选项图片
    IMAGE menu[5];
    loadimage(&menu[0], "计算日期2.png", 150, 50);
    loadimage(&menu[1], "公历转农历2.png", 200, 50);
    loadimage(&menu[2], "农历节气查询年份2.png", 300, 50);
    loadimage(&menu[3], "年历查询2.png", 150, 50);
    loadimage(&menu[4], "退出程序2.png", 150, 50);
    putimage(505, 200, &menu[0]);
    putimage(490, 250, &menu[1]);
    putimage(445, 300, &menu[2]);
    putimage(505, 350, &menu[3]);
    putimage(505, 400, &menu[4]);
    //菜单文本
    setbkmode(TRANSPARENT);
    settextcolor(RGB(99, 114, 156));
    settextstyle(50, 0, "隶书");
    outtextxy(200, 100, "============万年历============");
    outtextxy(200, 150, "==============================");
    outtextxy(200, 450, "==============================");
}

#endif // !EASY_X_USE_H



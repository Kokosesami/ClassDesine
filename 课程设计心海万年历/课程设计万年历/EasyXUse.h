#ifndef EASY_X_USE_H
#define EASY_X_USE_H

#include <graphics.h>

using namespace std;

//��ʱ��
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
    //ѡ��ͼƬ
    IMAGE menu[5];
    loadimage(&menu[0], "��������2.png", 150, 50);
    loadimage(&menu[1], "����תũ��2.png", 200, 50);
    loadimage(&menu[2], "ũ��������ѯ���2.png", 300, 50);
    loadimage(&menu[3], "������ѯ2.png", 150, 50);
    loadimage(&menu[4], "�˳�����2.png", 150, 50);
    putimage(505, 200, &menu[0]);
    putimage(490, 250, &menu[1]);
    putimage(445, 300, &menu[2]);
    putimage(505, 350, &menu[3]);
    putimage(505, 400, &menu[4]);
    //�˵��ı�
    setbkmode(TRANSPARENT);
    settextcolor(RGB(99, 114, 156));
    settextstyle(50, 0, "����");
    outtextxy(200, 100, "============������============");
    outtextxy(200, 150, "==============================");
    outtextxy(200, 450, "==============================");
}

#endif // !EASY_X_USE_H



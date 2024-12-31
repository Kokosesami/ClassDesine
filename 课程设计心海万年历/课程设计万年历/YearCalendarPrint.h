#ifndef YEAR_CALENDAR_PRINT_H
#define YEAR_CALENDAR_PRINT_H

#include <iostream>
#include <graphics.h>

void YearPrint(int year)
{
    char pictureName[20] = { 0 };

    // 将 year 转换为字符串存入 pictureName
    for (int i = 3; i >= 0; i--) 
    {
        pictureName[i] = '0' + (year % 10); // 提取每一位数字并转为字符
        year /= 10;
    }

    // 拼接文件后缀 ".png"
    pictureName[4] = '.';
    pictureName[5] = 'p';
    pictureName[6] = 'n';
    pictureName[7] = 'g';
    pictureName[8] = '\0';

    initgraph(1200, 691, 1);
    IMAGE img;// 初始化图像变量
    loadimage(&img, pictureName, 1200, 650); // 加载 PNG 图片
    putimage(0, 41, &img);                    // 将图片绘制到窗口
    system("cls");
    cout << "请按任意键以关闭万年历" << endl;
    setbkmode(TRANSPARENT);
    settextstyle(30, 0, "隶书");
    settextcolor(WHITE);
    outtextxy(430, 0, "请按任意键以关闭万年历");
    _getch();
    closegraph();
}

#endif // !YEAR_CALENDAR_PRINT_H

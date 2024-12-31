#ifndef YEAR_CALENDAR_PRINT_H
#define YEAR_CALENDAR_PRINT_H

#include <iostream>
#include <graphics.h>

void YearPrint(int year)
{
    char pictureName[20] = { 0 };

    // �� year ת��Ϊ�ַ������� pictureName
    for (int i = 3; i >= 0; i--) 
    {
        pictureName[i] = '0' + (year % 10); // ��ȡÿһλ���ֲ�תΪ�ַ�
        year /= 10;
    }

    // ƴ���ļ���׺ ".png"
    pictureName[4] = '.';
    pictureName[5] = 'p';
    pictureName[6] = 'n';
    pictureName[7] = 'g';
    pictureName[8] = '\0';

    initgraph(1200, 691, 1);
    IMAGE img;// ��ʼ��ͼ�����
    loadimage(&img, pictureName, 1200, 650); // ���� PNG ͼƬ
    putimage(0, 41, &img);                    // ��ͼƬ���Ƶ�����
    system("cls");
    cout << "�밴������Թر�������" << endl;
    setbkmode(TRANSPARENT);
    settextstyle(30, 0, "����");
    settextcolor(WHITE);
    outtextxy(430, 0, "�밴������Թر�������");
    _getch();
    closegraph();
}

#endif // !YEAR_CALENDAR_PRINT_H

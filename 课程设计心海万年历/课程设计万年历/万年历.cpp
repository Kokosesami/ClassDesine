#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <graphics.h>

//EasyX���ڣ������˵���
#include "EasyXUse.h"

//����1
#include "DateUtils.h"
#include "CASE1.h"

//����2
#include "LunarUtils.h"
#include "CASE2.h"

//����3
#include "LunarToYear.h"
#include "YearCalendarPrint.h"
#include "CASE3.h"

//�˳�����
#include "endMovie.h"
//�Լ���ӵĹ��ܣ�������ѯ
#include "CASE4.h"
using namespace std;

int main()
{
    bk();
    char a;//ѡ��
    IMAGE menu[5];
    ExMessage msg;
    while(1)
    {
        //ͼƬ��Ӧ
        loadimage(&menu[0], "��������1.png", 150, 50);
        loadimage(&menu[1], "����תũ��1.png", 200, 50);
        loadimage(&menu[2], "ũ��������ѯ���1.png", 300, 50);
        loadimage(&menu[3], "������ѯ1.png", 150, 50);
        loadimage(&menu[4],"�˳�����1.png", 150, 50);
        while (peekmessage(&msg))
        {
            if ((msg.message) == WM_LBUTTONDOWN)
            {
                int x = msg.x;
                int y = msg.y;
                if (x >= 520 && x <= 670 && y >= 200 && y <= 250)
                {
                    putimage(505, 200, &menu[0]);
                    Sleep(200);
                    closegraph();
                    case1();
                    Sleep(200);
                    bk();
                }//1
                if (x >= 505 && x <= 705 && y >= 250 && y <= 300)
                {
                    putimage(490, 250, &menu[1]);
                    Sleep(200);
                    closegraph();
                    case2();
                    Sleep(200);
                    bk();
                }//2
                if (x >= 460 && x <= 760 && y >= 300 && y <= 350)
                {
                    putimage(445, 300, &menu[2]);
                    Sleep(200);
                    closegraph();
                    case3();
                    Sleep(200);
                    bk();
                }//3
                if (x >= 520 && x <= 670 && y >= 350 && y <= 400)
                {
                    putimage(505, 350, &menu[3]);
                    Sleep(200);
                    closegraph();
                    case4();
                    Sleep(200);
                    bk();
                }//4
                if (x >= 520 && x <= 670 && y >= 400 && y <= 450)
                {
                    putimage(505, 400, &menu[4]);
                    Sleep(200);
                    system("cls");
                    kokofloat();
                    closegraph();
                    return 0;
                }//0
            }
        }
    }
    return 0;
}

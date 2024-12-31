#ifndef CASE_2_H
#define CASE_2_H


#include<iostream>
#include"LunarUtils.h"
#include"DateUtils.h"
using namespace std;

void case2()
{
    system("cls");
    const char* ChDay[] = { "*","��һ","����","����","����","����",//ÿ�µ�ũ������
                                   "����","����","����","����","��ʮ",
                                   "ʮһ","ʮ��","ʮ��","ʮ��","ʮ��",
                                   "ʮ��","ʮ��","ʮ��","ʮ��","��ʮ",
                                   "إһ","إ��","إ��","إ��","إ��",
                                   "إ��","إ��","إ��","إ��","��ʮ"
    };
    const char* ChMonth[] = { "*","��","��","��","��","��","��","��","��","��","ʮ","��","��" };
    struct tm* Local;
    long t;
    int year, month, day;
    char str[13] = "";
    cout << "���������ڣ���ʽ���� �� �գ���\n";
    do
    {
        do
        {
            cout << "�꣺" << endl;
            cin >> year;
            // ��������Ƿ�ʧ��
            if (cin.fail())
            {
                system("cls");
                cout << "�������������һ��������" << endl;
                // �������״̬
                cin.clear();
                // ������뻺����
                cin.ignore();
            }
            else
            {
                break;
            }
        } while (true);
        do
        {
            cout << "�£�" << endl;
            cin >> month;
            // ��������Ƿ�ʧ��
            if (cin.fail())
            {
                system("cls");
                cout << "�������������һ��������" << endl;
                // �������״̬
                cin.clear();
                // ������뻺����
                cin.ignore();
            }
            else
            {
                break;
            }
        } while (true);
        do
        {
            cout << "�գ�" << endl;
            cin >> day;
            // ��������Ƿ�ʧ��
            if (cin.fail())
            {
                system("cls");
                cout << "�������������һ��������" << endl;
                // �������״̬
                cin.clear();
                // ������뻺����
                cin.ignore();
            }
            else
            {
                break;
            }
        } while (true);

        if (!isValidDate(year, month, day))
        {
            system("cls");
            cout << "�������ݳ�����Χ�����������룺" << endl;
        }
    } while (!isValidDate(year, month, day));
    Lunar l;
    LunarDate ld = l.GetLunarDate(year, month, day);
    cout << "ũ�������ǣ�" << ((ld.IsLeap == true) ? "�c" : "") << ChMonth[ld.Month] << "��" << ChDay[ld.Day] << std::endl;
    cout << "�밴������Է��ز˵�" << endl;
    _getch();
}

#endif // !CASE_2_h

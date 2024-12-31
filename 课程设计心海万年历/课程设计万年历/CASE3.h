#ifndef CASE_3_H
#define CASE_3_H


#include <iostream>
#include <fstream>

#include "LunarToYear.h"
#include "CalendarPrint.h"
#include "YearCalendarPrint.h"
using namespace std;
void case3()
{
    system("cls");
    ofstream file("text.txt", ios::trunc); // �Խض�ģʽ���ļ����������
    if (file.is_open())
    {
        file.close();
    }
    int num;
    char solar_terms[9999];
    string target_lunar_date;
    int year, month, day;
    int target_year[30] = { 0 };
    
    int if_ok;
    do
    {
        cout << "������Ҫ��ѯ�Ľ�����";
        cin >> solar_terms;
        for (year = 1940; year < 2041; year++)
        {
            if_ok = get_date_by_solar_term(year, solar_terms);
            if (if_ok == 1)
            {
                break;
            }
            else
            {
                if_ok = 0;
            }
        }
        if (if_ok==0)
        {
            break;
        }
    } while (true);

    ifstream fin("text.txt");

    cout << "������Ҫ��ѯ��ũ����";
    cin >> target_lunar_date;

    vector<int> years;             // �洢���
    vector<string> lunarDays;      // �洢ũ������
    int yearFin;
    string lunarDay;
    //���ļ������ȡ
    while (fin >> yearFin >> lunarDay)
    {
        years.push_back(yearFin);
        lunarDays.push_back(lunarDay);
    }
    fin.close();
    int k = 0;
    for (int i = 0; i < years.size(); i++)
    {
        if (lunarDays[i] == target_lunar_date)
        {
            target_year[k] = years[i];
            k++;
        }
    }
    int printyear = 0;
    if (target_year[0] == 0)
    {
        cout << "δ���ҵ�����Ҫ�����ݻ��������������������أ�" << endl;
        _getch();
    }
    for (int i = 0; i < 30; i++)
    {
        if (target_year[i] == 0)
        {
            break;
        }
        printyear = target_year[i];
        system("cls");
        cout << "���ҵ�һ����ݣ�" << printyear <<"\n�밴���������ʾ�����������" << endl;
        _getch();
        YearPrint(printyear);
    }
}

#endif // !CASE_3_h

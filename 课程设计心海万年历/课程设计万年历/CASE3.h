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
    ofstream file("text.txt", ios::trunc); // 以截断模式打开文件，清除内容
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
        cout << "请输入要查询的节气：";
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

    cout << "请输入要查询的农历：";
    cin >> target_lunar_date;

    vector<int> years;             // 存储年份
    vector<string> lunarDays;      // 存储农历日期
    int yearFin;
    string lunarDay;
    //从文件逐个读取
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
        cout << "未查找到符合要求的年份或输入出错！（按任意键返回）" << endl;
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
        cout << "查找到一个年份：" << printyear <<"\n请按任意键以显示该年份万年历" << endl;
        _getch();
        YearPrint(printyear);
    }
}

#endif // !CASE_3_h

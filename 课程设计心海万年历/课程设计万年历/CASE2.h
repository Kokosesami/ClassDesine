#ifndef CASE_2_H
#define CASE_2_H


#include<iostream>
#include"LunarUtils.h"
#include"DateUtils.h"
using namespace std;

void case2()
{
    system("cls");
    const char* ChDay[] = { "*","初一","初二","初三","初四","初五",//每月的农历日期
                                   "初六","初七","初八","初九","初十",
                                   "十一","十二","十三","十四","十五",
                                   "十六","十七","十八","十九","二十",
                                   "廿一","廿二","廿三","廿四","廿五",
                                   "廿六","廿七","廿八","廿九","三十"
    };
    const char* ChMonth[] = { "*","正","二","三","四","五","六","七","八","九","十","冬","腊" };
    struct tm* Local;
    long t;
    int year, month, day;
    char str[13] = "";
    cout << "请输入日期（格式：年 月 日）：\n";
    do
    {
        do
        {
            cout << "年：" << endl;
            cin >> year;
            // 检测输入是否失败
            if (cin.fail())
            {
                system("cls");
                cout << "输入错误，请输入一个整数！" << endl;
                // 清除错误状态
                cin.clear();
                // 清空输入缓冲区
                cin.ignore();
            }
            else
            {
                break;
            }
        } while (true);
        do
        {
            cout << "月：" << endl;
            cin >> month;
            // 检测输入是否失败
            if (cin.fail())
            {
                system("cls");
                cout << "输入错误，请输入一个整数！" << endl;
                // 清除错误状态
                cin.clear();
                // 清空输入缓冲区
                cin.ignore();
            }
            else
            {
                break;
            }
        } while (true);
        do
        {
            cout << "日：" << endl;
            cin >> day;
            // 检测输入是否失败
            if (cin.fail())
            {
                system("cls");
                cout << "输入错误，请输入一个整数！" << endl;
                // 清除错误状态
                cin.clear();
                // 清空输入缓冲区
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
            cout << "输入数据超出范围！请重新输入：" << endl;
        }
    } while (!isValidDate(year, month, day));
    Lunar l;
    LunarDate ld = l.GetLunarDate(year, month, day);
    cout << "农历日期是：" << ((ld.IsLeap == true) ? "閏" : "") << ChMonth[ld.Month] << "月" << ChDay[ld.Day] << std::endl;
    cout << "请按任意键以返回菜单" << endl;
    _getch();
}

#endif // !CASE_2_h

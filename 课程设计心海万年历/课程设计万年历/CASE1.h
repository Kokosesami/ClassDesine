#ifndef CASE_1_H
#define CASE_1_H


#include <iostream>
#include "DateUtils.h"
using namespace std;

// 判断是否为闰年的辅助函数，这里简单示例，实际可结合更准确的天文规则等完善
bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算从起始年份到目标年份（包含）之间所有年份的总天数
int totalDaysBetweenYears(int start_year, int end_year)
{
    int total_days = 0;
    for (int year = start_year; year <= end_year; ++year)
    {
        int days_in_year = 365;
        if (isLeapYear(year))
        {
            days_in_year = 366;
        }
        total_days += days_in_year;
    }
    return total_days;
}

void case1() 
{
    system("cls");
    int input_year, input_month, input_day;
    int current_year, current_month, current_day;

    // 获取当前系统时间
    Get_time(current_year, current_month, current_day);

    // 获取用户输入的日期，进行合法性校验
    do
    {
        cout << "请输入日期（格式：年 月 日）：\n";
        do
        {
            cout << "年：" << endl;
            cin >> input_year;
            // 检测输入是否失败
            if (cin.fail()) {
                system("cls");
                cout << "输入错误，请输入一个整数！" << endl;

            }
            else {
                break;
            }
        } while (true);
        do
        {
            cout << "月：" << endl;
            cin >> input_month;
            // 检测输入是否失败
            if (cin.fail()) {
                system("cls");
                cout << "输入错误，请输入一个整数！" << endl;

            }
            else
            {
                break;
            }
        } while (true);
        do
        {
            cout << "日：" << endl;
            cin >> input_day;
            // 检测输入是否失败
            if (cin.fail())
            {
                system("cls");
                cout << "输入错误，请输入一个整数！" << endl;

            }
            else {
                break;
            }
        } while (true);
        if (!isValidDate(input_year, input_month, input_day))
        {
            system("cls");
            cout << "输入数据超出范围！请重新输入：" << endl;
        }
    } while (!isValidDate(input_year, input_month, input_day));

    // 分别计算输入日期和当前日期距离各自年份1月1日的总天数
    int input_total_days = totalDaysFromYearStart(input_year, input_month, input_day);
    int current_total_days = totalDaysFromYearStart(current_year, current_month, current_day);

    // 计算天数差
    int days_diff = 0;
    if (input_year == current_year)
    {
        days_diff = abs(input_total_days - current_total_days);
    }
    else
    {
        if (input_year < current_year)
        {
            // 先计算中间年份的总天数
            days_diff = totalDaysBetweenYears(input_year, current_year - 2);
            // 加上当前年份已过天数和输入年份剩余天数
            days_diff += current_total_days + (totalDaysFromYearStart(input_year, 12, 31) - input_total_days);
        }
        else
        {
            days_diff = totalDaysBetweenYears(current_year, input_year - 1);
            days_diff += input_total_days + (totalDaysFromYearStart(current_year, 12, 31) - current_total_days);
        }
    }
    cout << "距离当前日期相差 " << days_diff << " 天。" << endl;

    // 计算输入日期是星期几
    int week_index = The_week(input_year, input_month, input_day);
    string week_days[] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
    cout << "输入的日期是 " << week_days[week_index] << "。" << endl;
    cout << "请按任意键以返回菜单" << endl;
    _getch();
}


#endif // !CASE_1_H
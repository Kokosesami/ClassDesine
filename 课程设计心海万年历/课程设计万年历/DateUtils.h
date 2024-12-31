#ifndef DATEUTILS_H
#define DATEUTILS_H

#include <ctime>
#include <string>
#include <cstdlib>

// 宏定义判断闰年
#define LEAP(y) (!(y % (y % 100 ? 4 : 400)))

// 判断给定年份和月份下，日期是否合法
bool isValidDate(int year, int month, int day)
{
    if (month < 1 || month > 12) return false;
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (LEAP(year)) daysInMonth[2] = 29;
    return day >= 1 && day <= daysInMonth[month];
}

// 计算给定日期距离当年1月1日的总天数
int totalDaysFromYearStart(int year, int month, int day)
{
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int total_days = 0;
    days[2] = 28 + LEAP(year);
    for (int m = 1; m < month; m++)
    {
        total_days += days[m];
    }
    total_days += day;
    return total_days;
}

// 计算给定日期是星期几，返回0表示星期日，1表示星期一，以此类推
int The_week(int year, int month, int day)
{
    int total_days = totalDaysFromYearStart(year, month, day);
    return total_days % 7;
}

// 获取系统当前时间对应的年月日
void Get_time(int& year, int& month, int& day)
{
    time_t now;
    struct tm* timenow;
    time(&now);
    timenow = localtime(&now);
    year = timenow->tm_year + 1900;
    month = timenow->tm_mon + 1;
    day = timenow->tm_mday;
}

#endif // DATEUTILS_H

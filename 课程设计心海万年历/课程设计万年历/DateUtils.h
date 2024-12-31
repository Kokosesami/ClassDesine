#ifndef DATEUTILS_H
#define DATEUTILS_H

#include <ctime>
#include <string>
#include <cstdlib>

// �궨���ж�����
#define LEAP(y) (!(y % (y % 100 ? 4 : 400)))

// �жϸ�����ݺ��·��£������Ƿ�Ϸ�
bool isValidDate(int year, int month, int day)
{
    if (month < 1 || month > 12) return false;
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (LEAP(year)) daysInMonth[2] = 29;
    return day >= 1 && day <= daysInMonth[month];
}

// ����������ھ��뵱��1��1�յ�������
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

// ����������������ڼ�������0��ʾ�����գ�1��ʾ����һ���Դ�����
int The_week(int year, int month, int day)
{
    int total_days = totalDaysFromYearStart(year, month, day);
    return total_days % 7;
}

// ��ȡϵͳ��ǰʱ���Ӧ��������
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

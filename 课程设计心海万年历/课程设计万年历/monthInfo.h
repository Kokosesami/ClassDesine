#ifndef MONTH_INFO_H
#define MONTH_INFO_H

#include <iostream>
#include <cmath>
#include <string>
using namespace std;



string lunarMonth[] = { " ","正月","二月","三月","四月","五月","六月","七月","八月","九月","十月","冬月","腊月" };
string lunarDay[] = { "零","初一","初二","初三","初四","初五","初六","初七","初八","初九","初十","十一","十二","十三","十四","十五","十六","十七","十八","十九","二十","廿一","廿二","廿三","廿四","廿五","廿六","廿七","廿八","廿九","三十" };

// 21世纪和20世纪C值
float C_value_21[] = { 3.87,18.73,5.63,20.646,4.81,20.1,5.52,21.04,5.678,21.37,7.108,22.83,7.5,23.13,7.646,23.042,8.318,23.438,7.438,22.36,7.18,21.94,5.4055,20.12 };
float C_value_20[] = { 4.6295,19.4599,6.3826,21.4155,5.59,20.888,6.318,21.86,6.5,22.2,7.928,23.65,28.35,23.95,8.44,23.822,9.098,24.218,8.218,23.08,7.9,22.6,6.11,20.84 };
float C_month[] = { 2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13 };

unsigned int sg_lunarCalendar[199] =//年的信息
{
    /* 1900年开始，我的日历要求1940-2040年 用不到
    0x04bd8,0x04ae0,0x0a570,0x054d5,0x0d260,0x0d950,0x16554,0x056a0,0x09ad0,0x055d2,
    0x04ae0,0x0a5b6,0x0a4d0,0x0d250,0x1d255,0x0b540,0x0d6a0,0x0ada2,0x095b0,0x14977,
    0x04970,0x0a4b0,0x0b4b5,0x06a50,0x06d40,0x1ab54,0x02b60,0x09570,0x052f2,0x04970,
    0x06566,0x0d4a0,0x0ea50,0x06e95,0x05ad0,0x02b60,0x186e3,0x092e0,0x1c8d7,*/

    0x0c950,/*1939年*/   /*查询公历1940年1月，农历其实是1939年*/
    0x0d4a0,0x1d8a6,0x0b550,0x056a0,0x1a5b4,0x025d0,0x092d0,0x0d2b2,0x0a950,0x0b557,
    0x06ca0,0x0b550,0x15355,0x04da0,0x0a5d0,0x14573,0x052d0,0x0a9a8,0x0e950,0x06aa0,
    0x0aea6,0x0ab50,0x04b60,0x0aae4,0x0a570,0x05260,0x0f263,0x0d950,0x05b57,0x056a0,
    0x096d0,0x04dd5,0x04ad0,0x0a4d0,0x0d4d4,0x0d250,0x0d558,0x0b540,0x0b5a0,0x195a6,
    0x095b0,0x049b0,0x0a974,0x0a4b0,0x0b27a,0x06a50,0x06d40,0x0af46,0x0ab60,0x09570,
    0x04af5,0x04970,0x064b0,0x074a3,0x0ea50,0x06b58,0x055c0,0x0ab60,0x096d5,0x092e0,
    0x0c960,0x0d954,0x0d4a0,0x0da50,0x07552,0x056a0,0x0abb7,0x025d0,0x092d0,0x0cab5,
    0x0a950,0x0b4a0,0x0baa4,0x0ad50,0x055d9,0x04ba0,0x0a5b0,0x15176,0x052b0,0x0a930,
    0x07954,0x06aa0,0x0ad50,0x05b52,0x04b60,0x0a6e6,0x0a4e0,0x0d260,0x0ea65,0x0d530,
    0x05aa0,0x076a3,0x096d0,0x04bd7,0x04ad0,0x0a4d0,0x1d0b6,0x0d250,0x0d520,0x0dd45,
    0x0b5a0,0x056d0,0x055b2,0x049b0,0x0a577,0x0a4b0,0x0aa50,0x1b255,0x06d20,0x0ada0
};



struct Datedata {
    int lyear[101];
    string lmonth[101];
    string lday[101];
};

extern Datedata date;

/**
 * 判断year年是否是闰年
 */
bool is_leap_year(int year)
{
    // 可以被4且100整除或者可以被400整除
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

// 函数声明
int get_days_of_lunar_month(int year, int month);
int get_nonth_of_leap_year(int year);
bool is_large_month_of_leap_year(int year);
int get_days_of_lunar_year(int year);
int get_days_of_month(int year, int month);
int get_days_to_1939(int year, int month, int day);
void gregorian_to_lunar(int year, int month, int day);
void get_date_by_solar_term(int year, const char* str);



// 获取农历月份的天数
int get_days_of_lunar_month(int year, int month)
{
    // 查表，根据大小月，计算农历月天数
    int bit = 1 << (16 - month);
    if ((sg_lunarCalendar[year - 1939]/*&0x0000FFFF*/ & bit) == 0)
        return 29;
    else
        return 30;
}

/**
 * 返回 润几月  0代表不闰
 */
int get_nonth_of_leap_year(int year)
{
    // 输出农历润几月
    int month = sg_lunarCalendar[year - 1939] & 0xF;
    return month;
}

/**
 * 判断润年闰月是大月还是小月
 */
bool is_large_month_of_leap_year(int year)
{
    // 查表找出是否为闰月 判断high是不是为0
    int high = (sg_lunarCalendar[year - 1939] >> 16);
    if (high == 0x00)
        return false;
    else
        return true;
}

// 判断某年农历多少天
int get_days_of_lunar_year(int year)
{
    int days = 0;
    // 农历十二个月天数
    for (int i = 1; i <= 12; i++)
    {
        days += get_days_of_lunar_month(year, i);
    }
    // 假如有闰月，加上闰月天数
    if (get_nonth_of_leap_year(year) != 0)
    {
        if (is_large_month_of_leap_year(year))
            days += 30;
        else
            days += 29;
    }
    return days;
}

/**
 * 获取year年month月有多少天
 */
int get_days_of_month(int year, int month)
{
    // 平年各月公历天数
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (is_leap_year(year) && month == 2)
        return 29;
    else
        return days[month - 1];
}

/**
 * 获取year年month月day日到1939年1月1日的天数
 */
int get_days_to_1939(int year, int month, int day)
{
    int days = 0;
    // 从1939年开始计算,直到year-1年,它们都是整数年
    for (int i = year - 1; i >= 1939; i--)
    {
        if (is_leap_year(i))
            days += 366;
        else
            days += 365;
    }
    // 计算year年1月到year年month-1月,它们是整数月
    for (int i = month - 1; i > 0; i--)
    {
        days += get_days_of_month(year, i);
    }
    // 计算year年month月1日到yera年month月day日天数
    days += day;
    return days - 1;
}


// 将公历转换为农历
void gregorian_to_lunar(int year, int month, int day) {
    int days = get_days_to_1939(year, month, day) - 48; // 减去修正值
    int lyear = 1939, lmonth = 1, lday = 1;

    // 找到农历年份
    while (days > get_days_of_lunar_year(lyear)) {
        days -= get_days_of_lunar_year(lyear);
        lyear++;
    }

    // 找到农历月份
    while (days > get_days_of_lunar_month(lyear, lmonth)) {
        days -= get_days_of_lunar_month(lyear, lmonth);
        lmonth++;
    }

    //在访问 lunarMonth 和 lunarDay 数组之前，加入索引范围检查
    if (month < 1 || month > 12) {
        cout << "无效的农历月份：" << month << endl;
        return;
    }
    if (day < 1 || day > 30) {
        cout << "无效的农历日期：" << day << endl;
        return;
    }

    lday = days; // 剩余的天数即为农历日
    date.lyear[lyear - 1940] = lyear;
    date.lmonth[lyear - 1940] = lunarMonth[lmonth];
    date.lday[lyear - 1940] = lunarDay[lday];
}

// 根据节气计算对应日期
void get_date_by_solar_term(int year, const char* str) {
    if (str == nullptr) {
        cout << "节气指针为空！" << endl;
        return;
    }
    int tmp = -1; // 节气索引
    const char* solar_terms[] = { "立春","雨水","惊蛰","春分","清明","谷雨","立夏","小满","芒种","夏至","小暑","大暑","立秋","处暑","白露","秋分","寒露","霜降","立冬","小雪","大雪","冬至","小寒","大寒" };

    for (int i = 0; i < 24; i++) {
        if (strcmp(str, solar_terms[i]) == 0) {
            tmp = i;
            break;
        }
    }
    if (tmp == -1) {
        cout << "节气输入错误！" << endl;
        return;
    }

    int month = C_month[tmp];
    int day;
    if (year >= 2000) {
        day = floor((year % 100) * 0.2422 + C_value_21[tmp]) - floor((year % 100) / 4);
    }
    else {
        day = floor((year % 100) * 0.2422 + C_value_20[tmp]) - floor((year % 100) / 4);
    }

    gregorian_to_lunar(year, month, day);
}

#endif


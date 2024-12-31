#ifndef LUNAR_TO_YEAR_H
#define LUNAR_TO_YEAR_H

#include <iostream>
#include <fstream>

using namespace std;


string lunarMonth[] = { " ","����","����","����","����","����","����","����","����","����","ʮ��","����","����" };
string lunarDay[] = { "��","һ","��","��","��","��","��","��","��","��","ʮ" };
string lunarDay2[] = { "��","ʮ","إ","ئ" };

/** ũ����ѯ��  ��Դ��https://www.jianshu.com/p/57e7bd43c00b
 *  Ox0c950     ��5��16����������20bit
 *  ��1λ       ��ʾ���������£�0������С�£�1���������
 *  ��2-4λ     ��ʾ12��������λ һλ��ʾһ�����Ǵ��»���С��
 *  ��5λ       ��ʾ���ĸ��£�0��ʾ����
 */
unsigned int sg_lunarCalendar[199] =
{
    /* 1900�꿪ʼ���ҵ�����Ҫ��1940-2040�� �ò���
    0x04bd8,0x04ae0,0x0a570,0x054d5,0x0d260,0x0d950,0x16554,0x056a0,0x09ad0,0x055d2,
    0x04ae0,0x0a5b6,0x0a4d0,0x0d250,0x1d255,0x0b540,0x0d6a0,0x0ada2,0x095b0,0x14977,
    0x04970,0x0a4b0,0x0b4b5,0x06a50,0x06d40,0x1ab54,0x02b60,0x09570,0x052f2,0x04970,
    0x06566,0x0d4a0,0x0ea50,0x06e95,0x05ad0,0x02b60,0x186e3,0x092e0,0x1c8d7,*/

    0x0c950,/*1939��*/   /*��ѯ����1940��1�£�ũ����ʵ��1939��*/
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




/** ͨʽ���ǹ�ʽ �����ʮ�Ľ���  ��ʽ��Դ��https://www.jianshu.com/p/1f814c6bb475*/
// 21����Cֵ
float C_value_21[] = { 3.87,18.73,5.63,20.646,4.81,20.1,5.52,21.04,5.678,21.37,7.108,22.83,7.5,23.13,7.646,23.042,8.318,23.438,7.438,22.36,7.18,21.94,5.4055,20.12 };
// 20����Cֵ
float C_value_20[] = { 4.6295,19.4599,6.3826,21.4155,5.59,20.888,6.318,21.86,6.5,22.2,7.928,23.65,28.35,23.95,8.44,23.822,9.098,24.218,8.218,23.08,7.9,22.6,6.11,20.84 };
// ����������
float C_month[] = { 2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13 };

/**
 * �ж�year���Ƿ�������
 */
bool is_leap_year(int year)
{
    // ���Ա�4��100�������߿��Ա�400����
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int get_days_of_lunar_month(int year, int month)
{
    // ������ݴ�С�£�����ũ��������
    int bit = 1 << (16 - month);
    if ((sg_lunarCalendar[year - 1939]/*&0x0000FFFF*/ & bit) == 0)
        return 29;
    else
        return 30;
}

/**
 * ���� ����  0������
 */
int get_nonth_of_leap_year(int year)
{
    // ���ũ������
    int month = sg_lunarCalendar[year - 1939] & 0xF;
    return month;
}

/**
 * �ж����������Ǵ��»���С��
 */
bool is_large_month_of_leap_year(int year)
{
    // ����ҳ��Ƿ�Ϊ���� �ж�high�ǲ���Ϊ0
    int high = (sg_lunarCalendar[year - 1939] >> 16);
    if (high == 0x00)
        return false;
    else
        return true;
}



/**
 * ��ȡyear��month���ж�����
 */
int get_days_of_month(int year, int month)
{
    // ƽ����¹�������
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (is_leap_year(year) && month == 2)
        return 29;
    else
        return days[month - 1];
}


/**
 * ��ȡyear��month��day�յ�1939��1��1�յ�����
 */
int get_days_to_1939(int year, int month, int day)
{
    int days = 0;
    // ��1939�꿪ʼ����,ֱ��year-1��,���Ƕ���������
    for (int i = year - 1; i >= 1939; i--)
    {
        if (is_leap_year(i))
            days += 366;
        else
            days += 365;
    }
    // ����year��1�µ�year��month-1��,������������
    for (int i = month - 1; i > 0; i--)
    {
        days += get_days_of_month(year, i);
    }
    // ����year��month��1�յ�yera��month��day������
    days += day;
    return days - 1;
}

// �ж�ĳ��ũ��������
int get_days_of_lunar_year(int year)
{
    int days = 0;
    // ũ��ʮ����������
    for (int i = 1; i <= 12; i++)
    {
        days += get_days_of_lunar_month(year, i);
    }
    // ���������£�������������
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
 * ���ũ������
 */
void print_lunar_date(int days)
{
    ofstream fout;
    fout.open("text.txt",ios::out|ios::app);
    if (!fout)
    {
        cout << "�ļ���ʧ��\n";
    }
    int year = 1939, month = 1, day = 1;
    // ����1939��1��1��������ũ��1938�꣬���Լ�ȥ48�죬��1939�����³�һ���㣬��Ϊ�����������㷶ΧΪ1940��-2040�� ���Կ�������
    days -= 48;
    // �жϼ�ȥ��һ����������᲻���Ǹ�ֵ�����Ǳ��ȥ������ũ����
    for (int i = 1939; (days - get_days_of_lunar_year(i)) > 0; i++)
    {
        days -= get_days_of_lunar_year(i);
        year = i + 1;
    }
    int num;
    int signal = 0;
    // �жϼ�ȥ��һ���������᲻���Ǹ�ֵ�������ũ���¼�1
    for (int j = 1; ((days - get_days_of_lunar_month(year, j)) > 0) && j < 12; j++)
    {
        days -= get_days_of_lunar_month(year, j);
        if (j == get_nonth_of_leap_year(year))
        {
            if (is_large_month_of_leap_year(year))
            {
                days -= 30;
                num = 30;
            }
            else
            {
                days -= 29;
                num = 29;
            }
        }
        // ����ȥũ���µ�ʱ�򣬼����Ϊ��ֵ����ô�ټӻ���
        if (days < 0)
        {
            // ũ�����±��
            signal = 1;
            days += num;
            month = j;
            break;
        }
        month = month + 1;
    }
    // ʣ����������ũ����
    day = days;
    fout << "\n" << year << "\t";
    if (signal == 1)
        fout << " ��";
    if (day > 0 && day <= 10)
    {
        fout << lunarMonth[month];
        fout << "��" << lunarDay[day];
    }
    else if (day > 10 && day < 20)
    {
        fout << lunarMonth[month];
        fout << "ʮ" << lunarDay[day % 10];
    }
    else if (day == 20)
    {
        fout << lunarMonth[month];
        fout << "��ʮ";
    }
    else if (day > 20 && day < 30)
    {
        fout << lunarMonth[month];
        fout << "إ" << lunarDay[day % 10];
    }
    else if (day == 30)
    {
        fout << lunarMonth[month];
        fout << "��ʮ";
    }
    fout.close();
}

/**
 * ��������պϷ���
 */
bool is_legal(int year, int month, int day)
{
    // ����Ҫ�ж� year��month��  �Ƿ�day�죬����4����30�죬����31���Ǵ����
    return !(year < 1939 || year>2041 || month < 0 || month>12 || day<0 || day>get_days_of_month(year, month));
}



/**
 * ��ӡũ��
 */
void gregorian_to_lunar(int year, int month, int day)
{
    if (!is_legal(year, month, day))
    {
        cout << "�������������ȷ��������ȷ�ԣ�" << endl;
        return;
    }
    int days = get_days_to_1939(year, month, day);
    // ����������ӡũ��
    print_lunar_date(days);
}



/**
 * ͨ����ݽ�������ȡ��Ӧ��������
 */
int get_date_by_solar_term(int year1, char* str)
{
    int year, month, day;
    year = year1;
    int tmp = -1;//��ʾ����˳��
    const char* temp[24] = { "����","��ˮ","����","����","����","����","����","С��","â��","����","С��","����","����","����","��¶","���","��¶","˪��","����","Сѩ","��ѩ","����","С��","��" };
    /*�Ƚ��ַ�����ֵtmp �磺0�ʹ�������*/
    for (int i = 0; i < 24; i++)
    {
        if (strcmp(str, temp[i]) == 0)
        {
            tmp = i;
            break;
        }
    }
    if (tmp == -1)
    {
        cout << "����ƴд����" << endl;
        return 1;
    }

    if (tmp == 0 || tmp == 1 || tmp == 22 || tmp == 23)
    {
        if (year >= 2000)
        {
            month = C_month[tmp];
            day = floor((year % 100) * 0.2422 + C_value_21[tmp]) - floor((year % 100 - 1) / 4);
        }
        else
        {
            month = C_month[tmp];
            day = floor((year % 100) * 0.2422 + C_value_20[tmp]) - floor((year % 100 - 1) / 4);
        }
    }
    else
    {
        if (year >= 2000)
        {
            month = C_month[tmp];
            day = floor((year % 100) * 0.2422 + C_value_21[tmp]) - floor((year % 100) / 4);
        }
        else
        {
            month = C_month[tmp];
            day = floor((year % 100) * 0.2422 + C_value_20[tmp]) - floor((year % 100) / 4);
        }
    }

    // �������
    if ((year == 2026 && tmp == 1) || (year == 1918 && tmp == 21) || (year == 2021 && tmp == 21) || (year == 2019 && tmp == 22))
    {
        day--;
    }
    if ((year == 2084 && tmp == 3) || (year == 1911 && tmp == 6) || (year == 2008 && tmp == 7) || (year == 1902 && tmp == 8) || (year == 1928 && tmp == 9) || (year == 1925 && tmp == 10) || (year == 2016 && tmp == 10) || (year == 1922 && tmp == 11) || (year == 2002 && tmp == 12) || (year == 1927 && tmp == 14) || (year == 1942 && tmp == 15) || (year == 2089 && tmp == 17) || (year == 2089 && tmp == 18) || (year == 1978 && tmp == 19) || (year == 2054 && tmp == 20) || (year == 1982 && tmp == 22) || (year == 2000 && tmp == 23) || (year == 2082 && tmp == 23))
    {
        day++;
    }
    if (C_month[tmp] > 12)
    {
        month = 1;
    }
    // ���ݹ�ʽ����������գ�����ת��Ϊũ��
    gregorian_to_lunar(year, month, day);
    return 0;
}


#endif // !LUNAR_TO_YEAR_H

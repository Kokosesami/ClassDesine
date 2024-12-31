#ifndef YEAR_TO_WHOLE_YEAR_H
#define YEAR_TO_WHOLE_YEAR_H

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>

#define Mon 1
#define Tues 2
#define Wed 3
#define Thur 4
#define Fri 5
#define Sat 6
#define Sun 0

#define January_days 31
#define February_days 28
#define March_days 31
#define April_days 30
#define May_days 31
#define June_days 30
#define July_days 31
#define August_days 31
#define September_days 30
#define October_days 31
#define November_days 30
#define December_days 31

#define first1month January_days
#define first2month January_days+February_days
#define first3month January_days+February_days+March_days
#define first4month January_days+February_days+March_days+April_days
#define first5month January_days+February_days+March_days+April_days+May_days
#define first6month January_days+February_days+March_days+April_days+May_days+June_days
#define first7month January_days+February_days+March_days+April_days+May_days+June_days \
+July_days
#define first8month January_days+February_days+March_days+April_days+May_days+June_days \
+July_days+August_days
#define first9month January_days+February_days+March_days+April_days+May_days+June_days \
+July_days+August_days+September_days
#define first10month January_days+February_days+March_days+April_days+May_days+June_days \
+July_days+August_days+September_days+October_days
#define first11month January_days+February_days+March_days+April_days+May_days+June_days \
+July_days+August_days+September_days+October_days+November_days

int known_weekday = Tues;
int known_year = 1901;
int konwn_month = 1;
int known_day = 1;

int day_count(int month)
{
    switch (month)
    {
    case 1: return 0; break;
    case 2: return first1month; break;
    case 3: return first2month; break;
    case 4: return first3month; break;
    case 5: return first4month; break;
    case 6: return first5month; break;
    case 7: return first6month; break;
    case 8: return first7month; break;
    case 9: return first8month; break;
    case 10: return first9month; break;
    case 11: return first10month; break;
    case 12: return first11month; break;
    }
}

void first_line_print(int month, int year)
{
    //printf("%20s %d \n",month_name(month),year);
    printf("%8d�� ", year);
    switch (month)
    {
    case 1:
        printf("һ��\n");
        break;
    case 2:
        printf("����\n");
        break;
    case 3:
        printf("����\n");
        break;
    case 4:
        printf("����\n");
        break;
    case 5:
        printf("����\n");
        break;
    case 6:
        printf("����\n");
        break;
    case 7:
        printf("����\n");
        break;
    case 8:
        printf("����\n");
        break;
    case 9:
        printf("����\n");
        break;
    case 10:
        printf("ʮ��\n");
        break;
    case 11:
        printf("ʮһ��\n");;
        break;
    case 12:
        printf("ʮ����\n");;
        break;
    default:
        break;
    }
}

/*����ʽ��ӡ��������*/
void week_print()
{
    //printf("%-6s%-6s%-6s%-6s%-6s%-6s%-6s\n","Sun.", "Mon.", "Tues.", "Wed.", "Thur.", "Fri.", "Sat.");
    printf("%-3s%-3s%-3s%-3s%-3s%-3s%-3s\n", "��", "һ", "��", "��", "��", "��", "��");
}

/*���������·�����֪����֮��ľ�������*/
int date_distance_count(int month, int year)
{
    int leap_year_count = 0;
    int i;
    int distance;

    if (year > known_year)
    {
        for (i = known_year; i < year; i++)
        {
            if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
            {
                leap_year_count++;
            }
        }

        if (month > 2)
        {
            if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            {
                leap_year_count++;
            }
        }
    }
    else
        if (year == known_year)
        {
            if (month > 2)
            {
                leap_year_count = 1;
            }
        }


    distance = (year - known_year) * 365 + leap_year_count + day_count(month);

    return distance;
}

/*ȷ�����·ݵ�һ�������ڼ�*/
int makesure_firstday_weekday(int month, int year)
{
    int date_distance = 0;
    int weekday;

    date_distance = date_distance_count(month, year);
    weekday = (known_weekday + date_distance) % 7;

    return weekday;
}

/*���δ�ӡ�����·ݵ�����*/
void print_in_turn(int month, int firstday, int year)
{
    int i = 1;
    int weekday;

    switch (firstday)
    {
    case Sun:
        break;
    case Mon:
        printf("%-3s", "");
        break;
    case Tues:
        printf("%-6s", "");
        break;
    case Wed:
        printf("%-9s", "");
        break;
    case Thur:
        printf("%-12s", "");
        break;
    case Fri:
        printf("%-15s", "");
        break;
    case Sat:
        printf("%-18s", "");
        break;
    }

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        for (i = 0; i < 31; i++)
        {
            weekday = (firstday + i) % 7;
            printf("%-3d", i + 1);

            if (weekday == Sat)
            {
                printf("\n");
            }
        }
        break;
    }
    case 2:
    {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) /*����*/
        {
            for (i = 0; i < 29; i++)
            {
                weekday = (firstday + i) % 7;
                printf("%-3d", i + 1);

                if (weekday == Sat)
                {
                    printf("\n");
                }
            }
            break;
        }
        else /*ƽ��*/
        {
            for (i = 0; i < 28; i++)
            {
                weekday = (firstday + i) % 7;
                printf("%-3d", i + 1);

                if (weekday == Sat)
                {
                    printf("\n");
                }
            }
            break;
        }

    }
    case 4:
    case 6:
    case 9:
    case 11:
    {
        for (i = 0; i < 30; i++)
        {
            weekday = (firstday + i) % 7;/*������������ڼ�*/
            printf("%-3d", i + 1);

            if (weekday == Sat)
            {
                printf("\n");/*�����������������*/
            }
        }
        break;
    }
    }
}

void date_print(int month, int year)
{
    int firstday;

    firstday = makesure_firstday_weekday(month, year);
    print_in_turn(month, firstday, year);
    printf("\n");
}

void main_month(int month, int year)
{
    first_line_print(month, year);
    week_print();
    date_print(month, year);
    printf("\n\n");
}

void main_calendar(int year)
{
    int i;
    for (i = 1; i <= 12; i++)
    {
        main_month(i, year);
    }
}




#endif

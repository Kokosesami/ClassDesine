#ifndef CALENDAR_PRINT_H
#define CALENDAR_PRINT_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;

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
#define first7month January_days+February_days+March_days+April_days+May_days+June_days +July_days
#define first8month January_days+February_days+March_days+April_days+May_days+June_days +July_days+August_days
#define first9month January_days+February_days+March_days+April_days+May_days+June_days +July_days+August_days+September_days
#define first10month January_days+February_days+March_days+April_days+May_days+June_days +July_days+August_days+September_days+October_days
#define first11month January_days+February_days+March_days+April_days+May_days+June_days +July_days+August_days+September_days+October_days+November_days

extern int known_weekday;
extern int known_year;
extern int known_month;
extern int known_day;

int day_count(int month);
void first_line_print(int month, int year);
void week_print();
int date_distance_count(int month, int year);
int makesure_firstday_weekday(int month, int year);
void print_in_turn(int month, int firstday, int year);
void date_print(int month, int year);
void main_month(int month, int year);
void main_calendar(int year);

#endif


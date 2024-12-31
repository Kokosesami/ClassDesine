#ifndef CASE_1_H
#define CASE_1_H


#include <iostream>
#include "DateUtils.h"
using namespace std;

// �ж��Ƿ�Ϊ����ĸ��������������ʾ����ʵ�ʿɽ�ϸ�׼ȷ�����Ĺ��������
bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// �������ʼ��ݵ�Ŀ����ݣ�������֮��������ݵ�������
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

    // ��ȡ��ǰϵͳʱ��
    Get_time(current_year, current_month, current_day);

    // ��ȡ�û���������ڣ����кϷ���У��
    do
    {
        cout << "���������ڣ���ʽ���� �� �գ���\n";
        do
        {
            cout << "�꣺" << endl;
            cin >> input_year;
            // ��������Ƿ�ʧ��
            if (cin.fail()) {
                system("cls");
                cout << "�������������һ��������" << endl;

            }
            else {
                break;
            }
        } while (true);
        do
        {
            cout << "�£�" << endl;
            cin >> input_month;
            // ��������Ƿ�ʧ��
            if (cin.fail()) {
                system("cls");
                cout << "�������������һ��������" << endl;

            }
            else
            {
                break;
            }
        } while (true);
        do
        {
            cout << "�գ�" << endl;
            cin >> input_day;
            // ��������Ƿ�ʧ��
            if (cin.fail())
            {
                system("cls");
                cout << "�������������һ��������" << endl;

            }
            else {
                break;
            }
        } while (true);
        if (!isValidDate(input_year, input_month, input_day))
        {
            system("cls");
            cout << "�������ݳ�����Χ�����������룺" << endl;
        }
    } while (!isValidDate(input_year, input_month, input_day));

    // �ֱ�����������ں͵�ǰ���ھ���������1��1�յ�������
    int input_total_days = totalDaysFromYearStart(input_year, input_month, input_day);
    int current_total_days = totalDaysFromYearStart(current_year, current_month, current_day);

    // ����������
    int days_diff = 0;
    if (input_year == current_year)
    {
        days_diff = abs(input_total_days - current_total_days);
    }
    else
    {
        if (input_year < current_year)
        {
            // �ȼ����м���ݵ�������
            days_diff = totalDaysBetweenYears(input_year, current_year - 2);
            // ���ϵ�ǰ����ѹ��������������ʣ������
            days_diff += current_total_days + (totalDaysFromYearStart(input_year, 12, 31) - input_total_days);
        }
        else
        {
            days_diff = totalDaysBetweenYears(current_year, input_year - 1);
            days_diff += input_total_days + (totalDaysFromYearStart(current_year, 12, 31) - current_total_days);
        }
    }
    cout << "���뵱ǰ������� " << days_diff << " �졣" << endl;

    // �����������������ڼ�
    int week_index = The_week(input_year, input_month, input_day);
    string week_days[] = { "������", "����һ", "���ڶ�", "������", "������", "������", "������" };
    cout << "����������� " << week_days[week_index] << "��" << endl;
    cout << "�밴������Է��ز˵�" << endl;
    _getch();
}


#endif // !CASE_1_H
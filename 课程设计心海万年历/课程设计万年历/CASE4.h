#ifndef CASE4_h
#define CASE4_h

#include <iostream>
#include "YearCalendarPrint.h"
using namespace std;

void case4()
{
	system("cls");
	int year = 0;
	do
	{
		cout << "������Ҫ��ѯ����ݣ�1940��2040����" << endl;
		cin >> year;
		// ��������Ƿ�ʧ��
		if (cin.fail())
		{
			system("cls");
			// �������״̬
			cin.clear();
			// ������뻺����
			cin.ignore();
		}
		if (year < 1940 || year>2040)
		{
			system("cls");
			cout << "���볬����Χ��������һ��1940��2040�����е����" << endl;
		}
		else
		{
			break;
		}
	} while (true);
	YearPrint(year);
}

#endif // !1


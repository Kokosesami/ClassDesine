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
		cout << "请输入要查询的年份（1940—2040）：" << endl;
		cin >> year;
		// 检测输入是否失败
		if (cin.fail())
		{
			system("cls");
			// 清除错误状态
			cin.clear();
			// 清空输入缓冲区
			cin.ignore();
		}
		if (year < 1940 || year>2040)
		{
			system("cls");
			cout << "输入超出范围！请输入一个1940—2040区间中的年份" << endl;
		}
		else
		{
			break;
		}
	} while (true);
	YearPrint(year);
}

#endif // !1


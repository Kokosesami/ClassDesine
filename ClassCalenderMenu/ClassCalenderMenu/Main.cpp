#include<iostream>
#include"Menu.h"
using namespace std;

int main() 
{
    int choice;
    showMenu(); // ��ʾ�˵�
    cin >> choice;

    switch (choice) 
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
        {
            int year;
            cout << "��������ݣ�";
            cin >> year;
            break;
        }
        case 0:
            cout << "�������˳���ллʹ�ã�" << endl;
            break;
        default:
            cout << "��Чѡ�������ѡ��" << endl;
            break;
    }
    return 0;
}
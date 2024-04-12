#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <iomanip>
using namespace std;

int GetMonthDay(int year, int month)
{
    int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        return 29;
    }
    else
    {
        return months[month];
    }
}
int main() {
    int N = 0;
    int year = 0;
    int month = 0;
    int day = 0;
    int addday = 0;
    cin >> N;
    while (N--) { // 注意 while 处理多个 case
        cin >> year >> month >> day >> addday;

        day += addday;
        while (day > GetMonthDay(year, month))
        {
            day -= GetMonthDay(year, month);
            month++;
            if (month == 13)
            {
                year++;
                month = 1;
            }
        }
        cout << year << "-" << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day << endl;
    }
}
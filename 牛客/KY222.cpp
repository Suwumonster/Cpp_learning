#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int y = 0;
    int n = 0;
    while (cin >> y >> n)
    {
        int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
        int i = 1;
        for (i = 1; i < 13; i++)
        {
            if (days[i] > n)
            {
                break;
            }
        }
        if (i > 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
        {
            int day = n - days[i - 1] - 1;
            int month = i;
            if (day == -1)
            {
                month -= 1;
                day = days[month] - 1 - days[month - 1];
            }
            cout << y << "-" << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day << endl;
        }
        else
        {
            cout << y << "-" << setfill('0') << setw(2) << i << "-" << setfill('0') << setw(2) << n - days[i - 1] << endl;
        }
    }

    return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
struct date
{
	int year;
	int month;
	int monthday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day;
}Date;
int main()
{
	int daynum = 0;
	int i = 0;
	cin >> Date.year;
	cin >> Date.month;
	cin >> Date.day;
	daynum = Date.day;
	if ( (Date.year % 4 == 0 && Date.year % 100 != 0) || Date.year % 400 == 0)
	{
		Date.monthday[1] = 29;
	}
	for (i = 0; i < Date.month - 1; i++)
	{
		daynum += Date.monthday[i];
	}
	cout << daynum << endl;
	return 0;
}
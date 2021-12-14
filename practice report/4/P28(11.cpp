#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//int days(int, int, int a[], int b[]);
//int day_m(int, int, int a[], int b[]);
//void Pr(int x, int y, int arr[]);
//int main()
//{
//	int year, month, day = 1, wday, totalday, count;
//	cin >> year >> month;
//	int arr1[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
//	int arr2[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	int month_day[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
//	totalday = days(year, month, arr1, arr2);
//	count = day_m(year, month, arr1, arr2);
//	wday = (year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + totalday) % 7;
//	Pr(count, wday, month_day);
//	return 0;
//}
//int days(int y, int m, int a[], int b[])//求该日期一年中的总天数
//{
//	int sum = 0, count;
//	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
//	{
//		for (count = 0; count < (m - 1); count++)
//		{
//			sum += a[count];
//		}
//		return sum + 1;
//	}
//	else
//	{
//		for (count = 0; count < (m - 1); count++)
//		{
//			sum += b[count];
//		}
//		return sum + 1;
//	}
//}
//int day_m(int y, int m, int a[], int b[])//求该月多少天
//{
//	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
//	{
//		return a[m - 1];
//	}
//	else
//	{
//		return b[m - 1];
//	}
//}
//void Pr(int x, int y, int arr[])//打印日历
//{
//	int count,i = 0;
//	cout << "SUN" << '\t'<<"MON"<<'\t'<<"TUE" << '\t'<< "WEN" << '\t' << "THU" << '\t' << "FRI" << '\t' << "SAT" << endl;
//	for (count = 0; count < y; count++)
//	{
//		cout << '\t';
//		i++;
//	}
//	for (count = 0; count < x; count++)
//	{
//		cout << arr[count];
//		i++;
//		if (i % 7 == 0)
//		{
//			cout << endl;
//		}
//		else
//		{
//			cout << '\t';
//		}
//	}
//}

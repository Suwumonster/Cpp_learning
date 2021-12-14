#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//int days(struct Date* p);
//int runnian(struct Date* p);
//struct Date//定义结构体
//{
//	int Year;
//	int Month;
//	int Day;
//};
//int main()
//{
//	struct Date time;
//	cin >> time.Year;
//	cin >> time.Month;
//	cin >> time.Day;
//	int day = 0;
//	day = days(&time) + runnian(&time);
//	cout << day;//输出总天数
//	return 0;
//}
//int days(struct Date * p)//除二月外的月份求和
//{
//	int num = 0, count;
//	for (count = 1; count < p->Month; count++)
//	{
//		if (count == 1 || count == 3 || count == 5 || count == 7 || count == 8 || count == 10 || count == 12)
//		{
//			num += 31;
//		}
//		else if (count == 4 || count == 6 || count == 9 || count == 11)
//		{
//			num += 30;
//		}
//	}
//	return num + p->Day;
//}
//int runnian(struct Date* p)//二月天数
//{
//	if (p->Month > 2)
//	{
//		if (p->Year % 400 == 0 || (p->Year % 100 != 0 && p->Year % 4 == 0))
//		{
//			return 29;
//		}
//		else
//		{
//			return 28;
//		}
//	}
//	else
//	{
//		return 0;
//	}
//}
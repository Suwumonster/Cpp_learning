#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
////判断一个数的各位之和是否为15,统计所有符合的三位数的个数
//int sum(int x)
//{
//	if (x > 9)
//	{
//		return x % 10 + sum(x / 10);
//	}
//	else
//	{
//		return x;
//	}
//}
//int sum15(int y)//judge if sum equal to 15
//{
//	if (sum(y) == 15)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int num, count = 1;
//	for (num = 100; num < 1000; num++)
//	{
//		if (sum15(num))
//		{
//			cout << num << endl;
//			count++;
//		}
//	}
//	cout << "符合各位数之和等于15的三位数个数是：" << count << endl;
//	return 0;
//}
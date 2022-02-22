#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
using namespace std;
void check(int* x, int y, int* p1, int* p2, int n)//算分数的函数
	//玩家猜的数、电脑给出的数、个数分、准确分、难度（位数）
{
	*x = 0;
mark:
	cout << "请猜数：" << endl;
	cin >> *x;
	*p1 = 0;
	*p2 = 0;
	int i,j;
	int temp = *x;//设置中间变量避免算分过程中把*x变成0
	int arr1[20] = { 0 };
	int arr2[20] = { 0 };
	if (temp < pow(10,n - 1) || temp >= pow(10, n))//检查输入数字、不正确输入将重新输入
	{
		cout << "你输入的数不是" << n << "位数，请重新输入！" << endl;
		goto mark;
	}
	for (i = n - 1; i >= 0; i--)//储存数字到数组中
	{
		arr1[i] = temp % 10;
		arr2[i] = y % 10;
		temp /= 10;
		y /= 10;
	}
	for (i = 0; i < n; i++)
	{
		if (arr1[i] == arr2[i])//计算准确分
		{
			(*p2)++;
		}
		for (j = 0; j < n; j++)//计算个数分
		{
			if (arr1[i] == arr2[j])
			{
				(*p1)++;
			}
		}
	}
}
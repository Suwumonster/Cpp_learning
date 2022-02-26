#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
//有一个整数 N，N 可以分解成若干个整数之和，问如何分解能使这些数的乘积最大。
//请编程，由键盘输入一个整数 N（N < 100），将 N 分解成若干个整数，输出这些数的乘
//	积 M，且保证 M 是最大的。
//	[算法分析]
//有数学知识可知，只有把 N 分成尽可能多的 3，他们的乘积才能最大，（ 当只剩
//下 4 时便不用再分了，因 4>3 * 1）
using namespace std;
int main()
{
	int n;
	cin >> n;
	int up = n / 3;//可以分为几个3
	int left = n % 3;//余数
	int sum;
	switch (n)
	{
	case 1://n为1的情况
		sum = 0;
		break;
	case 2://n为2的情况
		sum = 1;
		break;
	case 3://n为3的情况
		sum = 2;
		break;
	case 4://n为4的情况
		sum = 4;
		break;
	default:
		if (left != 0)//n%3余数不为0的情况
		{
			if( left != 1)//余数不为0且不为1的情况
			{
				sum = pow(3, up) * left;
			}
			else//余数为1的情况
			{
				sum = pow(3, up - 1) * 4;
			}
		}
		else//余数为0
		{
			sum = pow(3, up);
		}
		break;
	}
	cout << sum << endl;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
using namespace std;
//编程实现一个功能：统计指定n（1 < n < 10)位对称素数的个数，并输出其中最大的对称素数。
//    要求：1)定义一个函数int isPrime（long x)实现素数的检测；
//    2）定义一个函数bool isPalindrome(long x)实现对称数的检测。
//    函数的参数个数可以1个或多个，可以自定。
//    提示：
//    对称素数：一个整数m的逆序数就是m本身，则称m为对称数（即回文数）。一个整数m如果是对称数又是素数，则称m为对称素数。
//    例如：101、131、929等都是3位的对称素数，表现为左右对称。
int isPrime(long);
bool isPalindrome(long,int);
int main()
{
	int n = 0;//位数
	cin >> n;
	long m = pow(10, n) - 1;//n位数下最大的数
	while (1)
	{
		if (isPrime(m) == 1)//素数否？
		{
			if (isPalindrome(m, n) == 1)//对称否？
			{
				break;
			}
		}
		m--;//自减
	}
	cout << m << endl;
	return 0;
}
int isPrime(long x)//检验x是否为素数
{
	int i = 0;
	int prime = 1;//先假设是素数
	for (i = 2; i < x / 2; i++)
	{
		if ( x % i == 0)
		{
			prime = 0;//有1和本身以外的因数，不是素数
			break;
		}
	}
	return prime;//返回值，1真0假
}
bool isPalindrome(long x, int n)//数x，位数n
{
	int arr[10] = { 0 };
	int i = 0;
	long num = 0;//存逆序数
	long temp = x;//存x，用于后面与逆序数比较
	for (i = 0; x > 0; i++)//存各位上的数
	{
		arr[i] = x % 10;
		x /= 10;
	}//不用temp存x，这for结束x变0.
	for(i = 0;; i++)//将数赋给num
	{
		num = num + arr[i];
		n--;
		if (n == 0)
		{
			break;
		}
		num *= 10;
	}
	if (num == temp)//判断是否对称
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


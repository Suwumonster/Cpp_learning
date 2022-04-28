#include <iostream>
using namespace std;
char arr[16] = { 0 };
int Max = 0;
int check(int m,int n)
{
	if (arr[m] == 'X')
	{
		return 0;
	}
	arr[m] = '@';
	int num1 = 0;//棋子数
	int i;
	for (i = m/n*n; i < m/n*n+n; i++)//行检查
	{
		if (arr[i] == 'X')
		{
			num1 = 0;
		}
		else if (arr[i] == '@')
		{
			num1++;
		}
		if (num1 >= 2)
		{
			arr[m] = '.';
			return 0;
		}
	}
	num1 = 0;
	for (i = m%n; i < n * n; i += n)//列检查
	{
		if (arr[i] == 'X')
		{
			num1 = 0;
		}
		else if (arr[i] == '@')
		{
			num1++;
		}
		if (num1 >= 2)
		{
			arr[m] = '.';
			return 0;
		}
	}
	arr[m] = '.';
	return 1;
}
void dps(int m, int n, int num)
{
	if (m == n * n)
	{
		if (num > Max)
		{
			Max = num;
		}
		return ;
	}
	if ( check(m,n) )
	{
		arr[m] = '@';
		dps(m + 1, n, num + 1);
		arr[m] = '.';
	}
	dps(m + 1, n, num);
}
int main()
{
	int num = 0;
	int i = 0;
	int n;
	while (1)
	{
		Max = 0;
		num = 0;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		for (i = 0; i < n * n; i++)
		{
			cin >> arr[i];
		}
		dps(0,n, num);
		cout << Max << endl;
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 5000
#include <iostream>
using namespace std;
int arr[MAX][1001] = { 0 };
int len[MAX] = { 0 };
void add(int a[], int lena, int b[], int lenb, int c[], int &lenc)
{
	lenc = lena > lenb ? lena : lenb;
	int over = 0;
	for (int i = 0; i <= lenc; i++)
	{
		c[i] = a[i] + b[i] + over;
		over = c[i] / 10;
		c[i] = c[i] % 10;
	}
	if (c[lenc] != 0)
	{
		lenc++;
	}
}
void print(int n)
{
	for (int i = len[n] - 1; i >= 0; i--)
	{
		cout << arr[n][i];
	}
	cout << endl;
}
int main()
{
	int n;
	int maxn = 3;
	arr[1][0] = 1;
	arr[2][0] = 1;
	len[1] = 1;
	len[2] = 1;
	while (cin >> n)
	{
		if (n >= maxn)
		{
			for (int i = maxn; i <= n; i++)
			{
				add(arr[i - 2], len[i - 2], arr[i - 1], len[i - 1], arr[i], len[i]);
			}
		}
		print(n);
	}
	return 0;
}
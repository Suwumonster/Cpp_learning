#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int num(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n * num(n - 1);
	}
}
int sum(int x)
{
	int z = num(x);
	if (x == 1)
	{
		return 1;
	}
	else
	{
		return z + sum(x - 1);
	}
}
int main()
{
	int a = 0, y = 0;
	scanf("%d", &a);
	y = sum(a);
	printf("%d\n", y);
	return 0;
}
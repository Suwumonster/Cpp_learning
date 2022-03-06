#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void fun(int arr[]);
int main()
{
	int arr[7] = { 0 };
	fun(arr);
	return 0;
}
void fun(int arr[])
{
	int max = 0;
	int mark = 0;
	int i = 0;
	int a, b = 0;
	for (i = 0; i < 7; i++)
	{
		scanf("%d %d", &a, &b);
		arr[i] = a + b;
	}
	max = arr[6];
	for (i = 6;i >= 0; i--)
	{
		if (arr[i] > 8 && arr[i] >= max)
		{
			max = arr[i];
			mark = i + 1;
		}
	}
	printf("%d\n", mark);
}
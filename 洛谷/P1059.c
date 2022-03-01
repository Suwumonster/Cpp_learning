#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void sort(int, int arr[]);
void check(int*, int arr[]);
int main()
{
	int n = 0;
	int* p = &n;
	int i = 0;
	int arr[100] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(n, arr);
	check(p, arr);
	printf("%d\n", n);
	for (i = 0; i < n; i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", arr[i]);
	}
	printf("\n");
	return 0;
}
void sort(int n, int arr[])
{
	int i, j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if ( arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void check(int* p, int arr[])
{
	int i, j, k = 0;
	for (i = 0; i < *p; i++)
	{
		int count = 0;
		for (j = i + 1, k = j; j < *p; j++)
		{
			if (arr[j] != arr[i])
			{
				arr[k++] = arr[j];
			}
			else
			{
				count++;
			}
		}
		*p = *p - count;
	}
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void fun(float arr1[], int arr2[], int);
int compute(float);
int main()
{
	int i = 0;
	float arr1[20] = { 0 };//输入数组
	int arr2[20] = { 0 };//输出数组
	for (i = 0; ; i++)
	{
		scanf("%f", &arr1[i]);
		if (arr1[i] == 0)
		{
			break;
		}
	}
	fun(arr1, arr2, i);
	return 0;
}
void fun(float arr1[], int arr2[], int count)
{
	int i = 0;
	for (i = 0; i < count; i++)
	{
		arr2[i] = compute(arr1[i]);
		printf("%d card(s)\n", arr2[i]);
	}
}
int compute(float x)
{
	float sum = 0.00;
	int i = 0;
	for (i = 1;sum < x ;i++)
	{
		sum += 1.00 / (i + 1);
	}
	return i;
}
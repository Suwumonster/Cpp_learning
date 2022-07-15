#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int tarr[16][3];
int compute(int arr[], int tarr[][3], int x)
{
	return pow(arr[0] - tarr[x][0], 2) + pow(arr[1] - tarr[x][1], 2) + pow(arr[2] - tarr[x][2], 2);
}
int main()
{
	int i = 0;
	int m = 5;
	for (i = 0; i < 16; i++)
	{
		scanf("%d %d %d", &tarr[i][0], &tarr[i][1], &tarr[i][2]);
	}
	while (1)
	{
		int min;
		int arr[3];
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		if (arr[0] == -1 && arr[1] == -1 && arr[2] == -1)
		{
			break;
		}
		min = compute(arr, tarr, 0);
		int pos = 0;
		for (i = 1; i < 16; i++)
		{
			int temp = compute(arr, tarr, i);
			if (min > temp)
			{
				min = temp;
				pos = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", arr[0], arr[1], arr[2], tarr[pos][0], tarr[pos][1], tarr[pos][2]);
	}
	return 0;
}
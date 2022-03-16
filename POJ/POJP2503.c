#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
typedef struct sarr
{
	char e[11];
	char f[11];
}sarr;
struct sarr arr[100];
int cmp_str(const void * a, const void * b)
{
	return strcmp(((sarr*)a)->f, ((sarr*)b)->f);
}
int BinSearch(char arr1[], int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (strcmp(arr1, arr[mid].f) == 0)
		{
			return mid;
		}
		else if (strcmp(arr1, arr[mid].f) < 0)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}
int main()
{
	while (1)
	{
		char n = getchar();
		if (n == '\n')
		{
			break;
		}
		arr[count].e[0] = n;
		if (arr[count].e[1] != ' ')
		{
			scanf("%s", arr[count].e + 1);
		}
		scanf("%s", arr[count].f);
		getchar();
		count++;
	}
	qsort(arr, count, sizeof(sarr), cmp_str);
	int str[11];
	while (~scanf("%s", str))
	{
		int temp = BinSearch(str, 0, count - 1);
		if (temp == -1)
		{
			printf("eh\n");
		}
		else
		{
			printf("%s\n", arr[temp].e);
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct STR
{
	char str[51];
	int measure;
}STR;
int compute(char s[], int n);
int cmp(const void* a, const void* b);
int main()
{
	STR st[100];
	int i = 0;
	int n, m = 0;//n is length of str,m is str lines.
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%s", st[i].str);
		st[i].measure = compute(st[i].str, n);
	}
	qsort(st, m, sizeof(st[0]), cmp);
	for (i = 0; i < m; i++)
	{
		printf("%s\n", st[i].str);
	}
	return 0;
}
int compute(char s[], int n)
{
	int num = 0;
	int i, j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[i] > s[j])
			{
				num++;
			}
		}
	}
	return num;
}
int cmp(const void * a, const void * b)
{
	return ((STR*)a)->measure - ((STR*)b)->measure;
}
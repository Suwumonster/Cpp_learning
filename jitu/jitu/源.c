#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0, m = 1, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		m = m * i;
	}
	printf("%d\n", m);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n,i,s;
	s = 1;
	printf("请输出自然数n的大小：");
	scanf("%d", &n);
			for (i = 1;i <= n ; i++)
			{
				s = s * i;
			}
	printf("n! = %d\n", s);
}
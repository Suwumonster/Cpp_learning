#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct STU
{
	char name[16];
	int check;//1为报过名字不必再报，0为未报名字的
};

int main()
{
	STU st[64];
	int n, w, s = 0;//n为人数，w为从第几位开始报数，s为从w开始第几个需要报名字的
	int i = 0;
	int count = 1;//统计报数的次数
	int k = 0;//统计报过名字的次数
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", st[i].name);
		st[i].check = 0;
	}
	scanf("%d,%d", &w, &s);
	for (i = w - 1; k < n; i++)
	{
		if (i == n)
		{
			i = 0;
		}
		if (st[i].check == 0)
		{
			if (count % s == 0)
			{
				printf("%s\n", st[i].name);
				k++;
				st[i].check = 1;
			}
			count++;
		}

	}

	return 0;
}
#include <stdio.h>
int main()
{
	int length;
	int a[length];
	printf("请输入数组长度：(数组长度上限100)\n");
	scanf("%d", &length);
	printf("你输入的数组长度为:%d\n", length);
	int i, j, max;
	for (i = 0; i < length; i++)
	{
		printf("请输入a[%d]大小:\n", i);
		scanf("%d", &a[i]);
	}
	max = a[0];
	for (j = 0; j < length; j++)
	{
		if (max <= a[j])
		{
			max = a[j];
		}
	}
	printf("最大值max=%d\n", max);
	return 0;
}


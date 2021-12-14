#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//杨辉三角一维数组实现
int main()
{
	int data[30] = { 1 };
	
	int i, j;
	printf("1\n"); 
		for (i = 1; i < 6; i++)
		{
			for (j = i; j > 0; j--) //从后向前填，避免上一行的数据在使用前就被覆盖
			{
				data[j] += data[j - 1];
			}

			for (j = 0; j <= i; j++) //这一行填完就直接打印了。
			{
				printf("%d ", data[j]);
			}
			putchar('\n');
		}
		return 0;
}

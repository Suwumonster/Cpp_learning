#include <stdio.h>
int compute(int pre[]);
int main()
{
	int pre[12] = { 0 };
	printf("%d", compute(pre));
	return 0;
}
int compute(int pre[])
{
	int i = 0;
	int sum = 300;
	int save = 0;
	for(i = 0; i < 12; i++)
	{
		scanf("%d", &pre[i]);
	}
	for(i = 0; i < 12; i++)
	{
		if (sum - pre[i] < 0)
		{
			sum = -(i + 1);
			return sum;
		}
		else
		{
			sum -= pre[i];
			while (sum >= 100)
			{
				save += 100;
				sum -= 100;
			}
			sum += 300;
		}
	}
	return save*1.2 + sum - 300;
}
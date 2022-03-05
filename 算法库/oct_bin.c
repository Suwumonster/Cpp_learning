#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
void DecBinfun(int x);
int main()
{
	int x = 0;
	scanf("%d", &x);
	DecBinfun(x);
	return 0;
}
void DecBinfun(int x)
{
	int num[32] = { 0 };
	int i = 0;
	int flag = (x >= 0)? 0: 1;//0Õý1¸º
	x = (x >= 0) ? x: -x;
	for (i = 0;x;i++)
	{
		num[31 - i] = x % 2;
		x /= 2;
	}
	if (flag)
	{
		for (i = 1; i < 32 ; i++)//·´Âë
		{
			num[i] = (num[i] == 0)?1:0;
		}
	
		for (i = 31; i > 0; i--)//²¹Âë
		{
			if (num[i] == 0)
			{
				num[i] = 1;
				break;
			}
			else
			{
				num[i] = 0;
			}
		}

	}
	num[0] = flag;

	for (i = 0; i < 32; i++)
	{
		printf("%d", num[i]);
	}
	printf("\n");
}
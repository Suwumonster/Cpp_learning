#include <stdio.h>
int main()
{
	int k = 0;
	int n = 0;
	double sum = 1.0;
	scanf("%d", &k);
	for (n = 2;;n++)
	{
		sum += (1.0/n);
		if (sum > k)
		{
			break;
		}
	}
	printf("%d\n", n);
	return 0;
}

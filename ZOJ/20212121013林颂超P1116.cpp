#include <stdio.h>
int main()
{
	int arr[10001] = { 0 };
	int n = 0;
	int i,j = 0;
	int sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				sum++;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
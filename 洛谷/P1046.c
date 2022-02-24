#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int length = 0;
	int count = 0;
	for (i = 0;i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &length);
	for (i = 0;i < 10; i++)
	{
		if ((length + 30) >= arr[i])
		{
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
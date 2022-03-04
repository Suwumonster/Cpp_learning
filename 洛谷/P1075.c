#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int isPrime(int n);
int main()
{
	int n, i = 0;
	int a, b = 0;
	scanf("%d", &n);
	for (i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0 && isPrime(i) && isPrime(n/i))
		{
			printf("%d\n", i > n / i ? i : n / i);
		}
	}
	return 0;
}
int isPrime(int n)
{
	int isprime = 1;
	int i = 0;
	for (i = 2; i < sqrt(n);i++)
	{
		if (n % i == 0)
		{
			isprime = 0;
		}
	}
	return isprime;
}
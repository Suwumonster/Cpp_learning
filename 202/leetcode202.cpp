#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int num(int x)
{
    int z, i = 1;
    for (z = 10; z <= x; z *= 10)
    {
        i++;
    }
    z /= 10;
    if (x > 9)
    {
        return pow(x / z, 2) + num(x % z);
    }
    else
    {
        return pow(x, 2);
    }
}
int Happy(int n)
{
    do
    {
        n = num(n);
    }
    while (n > 9);
    if (n == 1 || n == 7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int m;
    scanf("%d", &m);
    printf("%d\n", Happy(m));
    return 0;
}
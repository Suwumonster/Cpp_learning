#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int a, b = 0;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        printf("%d\n", a + b);
    }
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
    int i = 0;
    char str[256];
    while (gets(str) && strcmp(str, "#") != 0)
    {
        int sum = 0;
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] != ' ')
            {
                sum += (i + 1) * (str[i] - 'A' + 1);
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
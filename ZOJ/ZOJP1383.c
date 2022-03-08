#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
    int count = 0;
    int i, j = 0;
    int arr[10] = { 0 };
    int bin[10][20] = { 0 };
    int pos[10] = { 0 };

    scanf("%d", &count);
    for (i = 0; i < count; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < count; i++)
    {
        int temp = arr[i];
        for (j = 0; temp != 0; j++)
        {
            bin[i][j] = temp % 2;
            temp /= 2;
        }
        pos[i] = j;
    }

    for (i = 0; i < count; i++)
    {
        for (j = 0; j < pos[i]; j++)
        {
            if (bin[i][j] == 1 && j != pos[i] - 1)
            {
                printf("%d ", j);
            }
            else if(bin[i][j] == 1 && j == pos[i] - 1)
            {
                printf("%d\n", j);
            }
        }
    }
    return 0;
}
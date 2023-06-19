#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3000000

long long count[100000] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    int num[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (num[i][j] < num[j][i])
            {
                num[i][j] = num[j][i];
            }
            else
            {
                num[j][i] = num[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }
}
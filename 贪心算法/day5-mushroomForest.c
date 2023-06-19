#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3000000

void sort(int price[], int mount[], int len)
{
    int i, j, tmp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (price[j] > price[j + 1])
            {
                tmp = price[j];
                price[j] = price[j + 1];
                price[j + 1] = tmp;
                tmp = mount[j];
                mount[j] = mount[j + 1];
                mount[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int n, m, h, b, q = 0, p = 0, rest = 0;
    scanf("%d%d%d%d", &n, &m, &h, &b);
    int price[n], mount[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &price[i], &mount[i]);
    }
    sort(mount, price, n);
    while (m != 0)
    {
        if (h + b > price[p])
        {
            if (m >= mount[p])
            {
                while (mount[p] != 0)
                {
                    m--;
                    mount[p]--;
                }
                rest++;
            }
            else
            {
                break;
            }
        }
        p++;
    }
    printf("%d", rest);
}
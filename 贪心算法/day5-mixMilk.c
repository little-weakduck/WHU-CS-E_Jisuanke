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
    int n, m, q = 0, i = 0, rest;
    long totalPrice = 0;
    scanf("%d%d", &n, &m);
    int price[m], mount[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &price[i], &mount[i]);
    }
    sort(price, mount, m);
    while (q + mount[i] <= n)
    {
        totalPrice += price[i] * mount[i];
        q += mount[i];
        i++;
    }
    rest = n - q;
    totalPrice += rest * price[i];
    printf("%ld", totalPrice);
}
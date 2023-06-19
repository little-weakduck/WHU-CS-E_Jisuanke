#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3000000

long long count[100000] = {0};

int main()
{
    long long n, m, a, b, c;
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        count[a] += c;
        count[b] += c;
    }
    long long max = 0;
    c = 0;
    for (int i = 0; i < n; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            c = i;
        }
    }
    printf("%lld", c);
}
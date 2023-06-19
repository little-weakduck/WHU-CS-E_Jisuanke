#include <stdio.h>
#include <string.h>
#define MAX 500

int main()
{
    int n, m, w;
    scanf("%d%d", &n, &m);
    w = n;
    int q[n], l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        q[i] = 1;
    }

    while (w != 1)
    {
        if (q[r] != -1)
        {
            l = (l + 1) % m;
            if (l == 0)
            {
                q[r] = -1;
                w--;
            }
            else
            {
                q[r] = l;
            }
        }
        r = (r + 1) % n;
    }
    for (int i = 0; i < n; i++)
    {
        if (q[i] != -1)
        {
            printf("%d", i + 1);
        }
    }
}
#include <stdio.h>
#include <string.h>
#define MAX 500

int haveSeven(int l)
{
    int a;
    while (l != 0)
    {
        a = l % 10;
        if (a == 7)
        {
            return 1;
        }
        l = l / 10;
    }
    return 0;
}

int main()
{
    int n, m, w, t;
    scanf("%d%d%d", &n, &m, &t);
    char name[n][21];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", name[i]);
    }
    w = n;
    int q[n], l = t - 1, r = m - 1;
    for (int i = 0; i < n; i++)
    {
        q[i] = 1;
    }

    while (w != 1)
    {
        if (q[r] != -1)
        {
            l++;
            if (l % 7 == 0)
            {
                q[r] = -1;
                w--;
            }
            else if (haveSeven(l))
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
            printf("%s", name[i]);
        }
    }
}
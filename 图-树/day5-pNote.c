#include <stdio.h>
#define MAX 1002
int edges[MAX][MAX];
int cnt[MAX];
int count;
int n;
int x, y;

void fun()
{
    scanf("%d", &n);

    for (int j = 1; j <= n; j++)
    {
        cnt[j] = 0;
        for (int k = 1; k < n; k++)
        {
            edges[j][k] = 0;
            edges[k][j] = 0;
        }
    }
    for (int j = 1; j < n; j++)
    {
        scanf("%d %d", &x, &y);
        edges[x][y] = 1;
        cnt[x]++;
        edges[y][x] = 1;
    }
    count = n;
    for (int j = 1; j <= n; j++)
    {
        for (int k = 1; k <= n; k++)
        {
            if (edges[j][k] == 1 || edges[k][j] == 1)
            {
                if (cnt[j] < cnt[k])
                {
                    count--;
                    break;
                }
            }
        }
    }
    printf("%d\n", count);
}

int main()
{
    int t;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        fun();
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int like[20][20];
int vis[20], ans, n;
int max[20];

int h(int now, int x)
{
    for (int i = x; i < n; i++)
    {
        now += max[i];
    }
    return now;
}

void dfs(int step, int sum)
{
    if (step == n)
    {
        ans = MAX(ans, sum);
        return;
    }
    if (ans > h(sum, step))
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(step + 1, sum + like[step][i]);
            vis[i] = 0;
        }
    }
}

int main()
{
    int q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        q = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &like[i][j]);
            q = MAX(q, like[i][j]);
        }
        max[i] = q;
    }
    dfs(0, 0);

    printf("%d", ans);
}
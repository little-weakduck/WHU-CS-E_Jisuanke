// DFS枚举，更改条件

#include <stdio.h>
#include <stdlib.h>

int n, k, B;
int comb[20];
int heights[20];
int ans = 2147483647;
void dfs(int x, int dep, int total)
{

    if (total >= B)
    {
        if (ans > total)
        {
            ans = total;
        }

        return;
    }
    if (x > n)
    {
        return;
    }
    comb[dep] = total;
    dfs(x + 1, dep + 1, total + heights[x]);
    dfs(x + 1, dep, total);
}

int main()
{
    scanf("%d%d", &n, &B);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &heights[i]);
    }
    dfs(0, 0, 0);
    printf("%d", ans - B);
}
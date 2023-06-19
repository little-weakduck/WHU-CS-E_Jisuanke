#include <stdio.h>
#include <stdlib.h>
int vis[7][7];
int ans = 0, n;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int in(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

int h()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == n - 1)
            {
                continue;
            }

            if (!vis[i][j] && (vis[i - 1][j] || !in(i - 1, j)) && (vis[i + 1][j] || !in(i + 1, j)) && (vis[i][j - 1] || !in(i, j - 1)) && (vis[i][j + 1] || !in(i, j + 1)))
            {
                return 0;
            }
        }
    }
    return 1;
}

void dfs(int step, int x, int y)
{
    vis[x][y] = 1;
    //printf("step:%d(%d,%d)", step, x, y);
    if (step == n * n - 1)
    {
        if (x == 0 && y == n - 1)
        {
            ans++;
        }
        return;
    }
    if (!h())
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (in(tx, ty) && !vis[tx][ty])
        {
            dfs(step + 1, tx, ty);
            vis[tx][ty] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(0, 0, 0);
    printf("%d", ans);
}
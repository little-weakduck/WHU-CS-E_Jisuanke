#include <stdio.h>
#include <string.h>
#define MAX 1001
int vis[MAX][MAX] = {0};
char maze[MAX][MAX];
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n, m;
int cnt = 0;

int in(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y)
{

    cnt++;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (in(tx, ty) && !vis[tx][ty] && maze[tx][ty] == '#')
        {
            dfs(tx, ty);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {

        scanf("%s", maze[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == '#' && !vis[i][j])
            {

                cnt = 0;
                dfs(i, j);
                if (cnt > ans)
                {
                    ans = cnt;
                }
            }
        }
    }
    printf("%d", ans);
}
#include <stdio.h>
#include <string.h>

#define MAX 500
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
    for (int i = 0; i < m; i++)
    {
        if (!vis[x][i] && maze[x][i] == '1')
        {
            dfs(x, i);
        }
        vis[x][i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i][y] && maze[i][y] == '1')
        {
            dfs(i, y);
        }
        vis[i][y] = 1;
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
            if (maze[i][j] == '1' && !vis[i][j])
            {

                ans++;
                dfs(i, j);
            }
        }
    }
    printf("%d", ans);
}

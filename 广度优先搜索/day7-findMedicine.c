#include <stdio.h>
int n, m, l, r;
char maze[110][110];
int vis[110][110];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int in(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}
struct node
{
    int x, y, d;
} q[10010];
int bfs(int sx, int sy)
{
    l = 0, r = 0;
    struct node t = {sx, sy, 0};
    q[r++] = t;
    vis[sx][sy] = 1;

    while (l < r)
    {
        struct node now = q[l++];

        if (maze[now.x][now.y] == '*')
        {
            return now.d;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = now.x + dir[i][0];
            int ty = now.y + dir[i][1];
            if (in(tx, ty) && maze[tx][ty] != '#' && !vis[tx][ty])
            {
                vis[tx][ty] = 1;
                struct node t = {tx, ty, now.d + 1};
                q[r++] = t;
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", maze[i]);
    }
    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == '@')
            {
                x = i;
                y = j;
                break;
            }
        }
    }
    printf("%d\n", bfs(x, y));
    return 0;
}
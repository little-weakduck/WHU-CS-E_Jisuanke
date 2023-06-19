#include <stdio.h>
#include <stdbool.h>
int n, m, T, k = 0, l, r;
#define maxn 17
#define MAX 70000 // 4^8=2^16=65538
char maze[maxn][maxn];
int vis[maxn][maxn][MAX];
int mc[maxn] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};
#define debug(x) printf("line %d, %s=%d\n", __LINE__, #x, x)
#define debug2(x) printf("line %d, %s=%c\n", __LINE__, #x, x)
int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
// URLD分别对应二进制数00 01 10 11

bool check_snake(char ch)
{
    return ch >= '1' && ch <= '9';
}

int T_init(int x, int y) // T的初始值
{
    int T = 0;
    for (int j = 1; j < k; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (maze[tx][ty] == maze[x][y] + 1)
            {
                T = (T << 2) + i;
                x = tx, y = ty;
                break;
            }
        }
    }
    return T;
}
struct node
{
    int x, y, d, t;
} q[maxn * maxn * 10];

int mcf(int b) // 2的b次方
{
    if (b < 0)
        return 1;
    return mc[b];
}
int Judge(int x, int y, int tx, int ty, int tt)
{ //判断走到这会不会碰到蛇身
    int d;
    for (int j = k - 2; j > 0; j--)
    {

        d = (tt >> (j * 2));        //每次取tt的前两位
        tt = tt & (mcf(j * 2) - 1); // tt删掉前两位

        x += dir[d][0];
        y += dir[d][1];
        if (x == tx && y == ty) //如果重合
            return 0;
    }
    return 1;
}
int bfs(int sx, int sy)
{
    l = 0, r = 0;
    struct node s = {sx, sy, 0, T};
    q[r++] = s;
    vis[sx][sy][T] = 1;
    while (l < r)
    {
        struct node now = q[l++];
        if (maze[now.x][now.y] == '@')
        {
            return now.d;
        }
        for (int i = 0; i < 4; i++)
        {
            if (i == (now.t >> (k + k - 4)))
                continue;
            int tx = now.x + dir[i][0];
            int ty = now.y + dir[i][1];
            if (0 <= tx && tx < n && 0 <= ty && ty < m && !vis[tx][ty][now.t] && maze[tx][ty] != '#' && Judge(now.x, now.y, tx, ty, now.t))
            {
                vis[tx][ty][now.t] = 1;                           //标记访问
                int dt = (now.t >> 2) + ((3 - i) << (k + k - 4)); //更新状态
                struct node s = {tx, ty, now.d + 1, dt};
                q[r++] = s;
            }
        }
    }
    return -1;
}

int bfs1(int sx, int sy)
{
    l = 0, r = 0;
    struct node t = {sx, sy, 0};
    q[r++] = t;
    vis[sx][sy][0] = 1;
    while (l < r)
    {
        struct node now = q[l++];
        if (maze[now.x][now.y] == '@')
        {
            return now.d;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = now.x + dir[i][0];
            int ty = now.y + dir[i][1];
            if (0 <= tx && tx < n && 0 <= ty && ty < m && maze[tx][ty] != '#' && !vis[tx][ty][0])
            {
                vis[tx][ty][0] = 1;
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
            if (check_snake(maze[i][j]))
            {
                int tem = maze[i][j] - '0';
                if (tem == 1)
                {
                    x = i;
                    y = j;
                }
                if (tem > k)
                    k = tem;
            }
        }
    }
    T = T_init(x, y);
    if (k != 1)
        printf("%d\n", bfs(x, y));

    else
        printf("%d\n", bfs1(x, y)); //特判
    return 0;
}

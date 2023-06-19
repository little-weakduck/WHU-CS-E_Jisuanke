#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct snake
{
    int x, y;
} snake[400][10];

struct node
{
    int x, y, snake_tail, step;
} q[400];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char map[16][16];
int n, m, length = 0, snake_num; //第几个状态的蛇
int vis[15][15];
int l, r;

bool is_continue(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        if (snake[snake_num][i].x == x && snake[snake_num][i].y == y)
        {
            return false;
        }
    }
    return true;
}

void copy_change_snake(int x, int y, int tail, int num)
{
    snake_num++;
    for (int i = 0; i < length; i++)
    {
        snake[snake_num][i].x = snake[num][i].x;
        snake[snake_num][i].y = snake[num][i].y;
    }
    snake[snake_num][tail].x = x;
    snake[snake_num][tail].y = y;
}

int bfs(int sx, int sy)
{
    l = 0, r = 0;
    struct node t = {sx, sy, length - 1, 0};
    q[r++] = t;
    vis[sx][sy] = 1;

    while (l < r)
    {
        struct node now = q[l++];

        if (map[now.x][now.y] == '*')
        {
            return now.step;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = now.x + dir[i][0];
            int ty = now.y + dir[i][1];
            if (map[tx][ty] != '#' && !vis[tx][ty] && is_continue(tx, ty))
            {
                vis[tx][ty] = 1;
                copy_change_snake(tx, ty, now.snake_tail, r);
                struct node t = {tx, ty, (now.snake_tail + length - 1) % length, now.step + 1};
                q[r++] = t;
            }
        }
    }
    return -1;
}

int main()
{
    int a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &map[i][j]);
            if (map[i][j] == '1')
            {
                a = i;
                b = j;
            }

            if (map[i][j] > '0' && map[i][j] <= '9')
            {
                length++;
                snake[0][(int)map[i][j] - '1'].x = i;
                snake[0][(int)map[i][j] - '1'].y = j;
                map[i][j] = '.';
            }
        }
    }
    printf("%d", bfs(a, b));
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int x, y, step, key;
} strnode;
int m, n, t;
int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char map[2001][2001];
int is[2001][2001][2];
strnode que[2000 * 2000 + 2];

int in(int dx, int dy)
{
    return dx >= 0 && dy >= 0 && dx < m && dy < n;
}

int bfs(int x, int y)
{
    memset(is, 0, sizeof(is));
    int head = 0, tail = 0, i = 0;
    que[tail].x = x;
    que[tail].y = y;
    que[tail].key = 0;
    que[tail++].step = 0;
    is[x][y][t] = 1;
    while (head < tail)
    {
        strnode temp = que[head++];
        if (map[temp.x][temp.y] == 'T' && temp.key)
        {
            return temp.step;
        }
        for (i = 0; i < 4; i++)
        {
            int dx = temp.x + d[i][0];
            int dy = temp.y + d[i][1];
            if (in(dx, dy))
            {
                if (map[dx][dy] == 'P' && !temp.key)
                {

                    que[tail].x = dx;
                    que[tail].y = dy;
                    que[tail].key = 1;
                    que[tail++].step = temp.step + 1;
                    is[dx][dy][temp.key] = 1;
                }
                else if (map[dx][dy] != '#' && !is[dx][dy][temp.key])
                {
                    que[tail].x = dx;
                    que[tail].y = dy;
                    que[tail].key = temp.key;
                    que[tail++].step = temp.step + 1;
                    is[dx][dy][temp.key] = 1;
                }
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d", &m, &n);
    int i = 0, j = 0;
    for (i = 0; i < m; i++)
    {
        scanf("%s", map[i]);
    }
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            if (map[i][j] == 'S')
                printf("%d", bfs(i, j));
        }
    return 0;
}

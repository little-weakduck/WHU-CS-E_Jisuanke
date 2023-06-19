#include <stdio.h>
int n, m, l, r, B;
char maze[110][110];
int vis[5001] = {0};
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int in(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}
struct node
{
    int x, d;
} q[1000000];
int bfs(int sx)
{

    l = 0, r = 0;
    struct node t = {sx, 0};
    vis[sx] = 1;
    q[r++] = t;
    while (1)
    {
        struct node now = q[l++];

        if (now.x == B)
        {
            return now.d;
        }
        for (int i = 0; i < 3; i++)
        {
            int tx = now.x;
            switch (i)
            {
            case 1:
                tx++;
                break;
            case 0:
                tx--;
                break;
            case 2:
                tx = tx * 2;
                break;
            }
            if (tx > -1 && tx <= n && !vis[tx])
            {
                vis[tx] = 1;
                struct node t = {tx, now.d + 1};
                q[r++] = t;
            }
        }
    }
    return -1;
}
int main()
{
    int A;
    scanf("%d%d%d", &n, &A, &B);

    printf("%d\n", bfs(A));
    return 0;
}
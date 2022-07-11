#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct edge
{
    int v, next;
} e[100000];
int p[100000], eid;
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y)
{
    insert(x, y);
    insert(y, x);
}
int n, m, q[10100], l, r;
int dis[100000];
void bfs(int s)
{
    memset(dis, -1, sizeof(dis));
    dis[s] = 1;
    l = r = 0;
    q[r++] = s;
    while (l < r)
    {
        int now = q[l++];
        for (int i = p[now]; ~i; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v] == -1)
            {
                dis[v] = dis[now] + 1;
                q[r++] = v;
            }
        }
    }
}
int main()
{
    memset(p, -1, sizeof(p));
    int time, start;
    scanf("%d%d%d", &n, &m, &start);
    scanf("%d", &time);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        insert2(u, v);
    }
    bfs(start);
    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        if (max < dis[i])
        {
            max = dis[i];
        }
    }
    printf("%d", max + time);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#define maxn 5000
#define maxm 101010

const int inf = 0x3f3f3f3f;

double min(double a, double b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

struct dot
{
    int x, y;
} dots[201];

double getLength(struct dot dot1, struct dot dot2)
{
    // printf("%d;%d;%d;%d;", dot1.x, dot1.y, dot2.x, dot2.y);
    double length = sqrt((dot1.x - dot2.x) * (dot1.x - dot2.x) + (dot1.y - dot2.y) * (dot1.y - dot2.y));
    // printf("%.2f", length);
    return length;
}

struct edge
{
    int v, next, f;
    double w;
} e[maxm * 2];
int p[maxn], eid, n, m, s, vis[maxn];
double d[maxn];
void insert(int u, int v, double w)
{
    struct edge t = {v, p[u], 1, w};
    e[eid] = t;
    p[u] = eid++;
}
void insert2(int u, int v, double w)
{
    insert(u, v, w);
    insert(v, u, w);
}

int main()
{
    scanf("%d%d", &n, &m); // s 是源点
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &dots[i ].x, &dots[i ].y);
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        insert2(u, v, getLength(dots[u - 1], dots[v - 1]));
    }
    memset(d, 0x3f, sizeof(d));
    d[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mind = inf;
        int u = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && d[j] < mind)
            {
                mind = d[j];
                u = j;
            }
        }
        if (mind == inf)
        {
            break;
        }
        vis[u] = 1;
        for (int j = p[u]; j != -1; j = e[j].next)
        {
            int v = e[j].v;
            d[v] = min(d[v], d[u] + e[j].w);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%.2f ", d[i]);
    }
    return 0;
}
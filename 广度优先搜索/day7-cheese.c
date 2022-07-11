// 朱文浩的答案

#include <stdio.h>
#include <string.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
struct node
{
    int v, next;
} e[1000001];
int p[1001], eid;
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
long long x[1001], y[1001], z[1001], H, R;
int n;
long long sqr(long long a)
{
    return a * a;
}
int check(int i, int j)
{
    return sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]) <= sqr(2 * R);
}
int q[10001], l, r, d[1001];
int bfs()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (check(i, j))
                insert2(i, j);
        }
    }
    memset(d, -1, sizeof(d));
    l = r = 0;
    for (int i = 0; i < n; i++)
    {
        if (z[i] >= -R && z[i] <= R)
        {
            q[r++] = i;
            d[i] = 1;
        }
    }
    while (l < r)
    {
        int now = q[l++];
        if (z[now] >= H - R && z[now] <= H + R)
        {
            return d[now];
        }
        for (int i = p[now]; ~i; i = e[i].next)
        {
            if (d[e[i].v] == -1)
            {
                d[e[i].v] = d[now] + 1;
                q[r++] = e[i].v;
            }
        }
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        memset(p, -1, sizeof(p));
        eid = 0;
        scanf("%d%lld%lld", &n, &H, &R);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
        }
        printf("%d\n", bfs());
    }
    return 0;
}
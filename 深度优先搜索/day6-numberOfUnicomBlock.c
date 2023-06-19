#include <stdio.h>
#include <string.h>
struct edge
{
    int v, next;
} e[100000];
int p[100000], eid, vis[100000];
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
void dfs(int u)
{
    vis[u] = 1;
    for (int i = p[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (!vis[v])
        {
            dfs(v);
        }
    }
}
int main()
{
    memset(p, -1, sizeof(p));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        insert2(u, v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i);
        }
    }
    printf("%d\n", cnt);
    return 0;
}
//改变搜索策略

//逆序排序+剪枝条

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int l[80];
int sum, n;
int ok;
void dfs(int id, int l1, int l2, int l3, int l4)
{
    if (id == n)
    {
        if (l1 == sum && l2 == sum && l3 == sum && l4 == sum)
        {
            puts("Yes");
            exit(0);
        }
        return;
    }
    if (l1 > sum || l2 > sum || l3 > sum || l4 > sum)
    {
        return;
    }

    dfs(id + 1, l1 + l[id], l2, l3, l4);
    dfs(id + 1, l1, l2 + l[id], l3, l4);
    dfs(id + 1, l1, l2, l3 + l[id], l4);
    dfs(id + 1, l1, l2, l3, l4 + l[id]);
}
int main()
{
    scanf("%d", &n);
    sum = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &l[i]);
        sum += l[i];
    }
    int tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (l[i] < l[j])
            {
                tmp = l[i];
                l[i] = l[j];
                l[j] = tmp;
            }
        }
    }

        ok = 0;
    if (sum % 4 != 0)
    {
        puts("No");
        return 0;
    }

    sum /= 4;

    dfs(1, l[0], 0, 0, 0);
    if (ok)
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
    return 0;
}
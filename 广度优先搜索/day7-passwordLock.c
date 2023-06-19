#include <stdio.h>
int n, m, l, r, B;
char maze[110][110];
int vis[10000] = {0};
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int password;
int in(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}
struct node
{
    int num, d;
} q[1000000];

int plus(int a, int b, int c, int d)
{
    return a * 1000 + b * 100 + c * 10 + d;
}

void seperate(int *n1, int *n2, int *n3, int *n4, int num)
{
    *n1 = num / 1000;
    *n2 = (num / 100) % 10;
    *n3 = (num / 10) % 10;
    *n4 = num % 10;
}

void add(int *n1)
{
    if (*n1 == 9)
    {
        *n1 = 1;
    }
    else
    {
        *n1 = *n1 + 1;
    }
}

void min(int *n1)
{
    if (*n1 == 1)
    {
        *n1 = 9;
    }
    else
    {
        *n1 = *n1 - 1;
    }
}

void exchage(int *n1, int *n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

int bfs(int sx)
{

    l = 0, r = 0;
    int n1, n2, n3, n4;
    struct node t = {sx, 0};
    vis[sx] = 1;
    q[r++] = t;
    while (l < r)
    {
        struct node now = q[l++];

        if (now.num == password)
        {
            return now.d;
        }
        for (int i = 0; i < 11; i++)
        {
            seperate(&n1, &n2, &n3, &n4, now.num);
            switch (i)
            {
            case 0:
                add(&n1);
                break;
            case 1:
                add(&n2);
                break;
            case 2:
                add(&n3);
                break;
            case 3:
                add(&n4);
                break;
            case 4:
                min(&n1);
                break;
            case 5:
                min(&n2);
                break;
            case 6:
                min(&n3);
                break;
            case 7:
                min(&n4);
                break;
            case 8:
                exchage(&n1, &n2);
                break;
            case 9:
                exchage(&n2, &n3);
                break;
            case 10:
                exchage(&n3, &n4);
                break;
            }
            int num = plus(n1, n2, n3, n4);
            if (!vis[num])
            {
                vis[num] = 1;
                struct node t = {num, now.d + 1};
                q[r++] = t;
            }
        }
    }
    return -1;
}
int main()
{
    int A;
    scanf("%d", &A);
    scanf("%d", &password);

    printf("%d\n", bfs(A));
    return 0;
}
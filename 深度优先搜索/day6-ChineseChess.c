#include <stdio.h>
#include <string.h>
#define MAX 1001
int vis[10][10] = {0};
char maze[10][10];
int dir[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, -1}, {-2, 1}};
int n, m;
int flag = 0;

int in(int x, int y)
{
    return 0 <= x && x < 10 && 0 <= y && y < 9;
}

void dfs(int x, int y)
{
    if (flag)
    {
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (maze[tx][ty] == 'T')
        {
            flag = 1;
            return;
        }

        if (in(tx, ty) && !vis[tx][ty] && maze[tx][ty] == '.')
        {
            dfs(tx, ty);
        }
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {

        scanf("%s", maze[i]);
    }
    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (maze[i][j] == 'S' && !vis[i][j])
            {
                dfs(i, j);
            }
        }
    }
    if (flag)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}
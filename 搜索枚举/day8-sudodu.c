// search from csdn
// link: https://blog.csdn.net/m0_63013068/article/details/123946516

#include <stdio.h>
#include <stdbool.h>
typedef long long ll;
bool vx[10][10]; //行情况
bool vy[10][10]; //列情况
bool vv[10][10]; //九宫格
char sd[10][10]; //字符串
bool finish = false;
void dfs(int x, int y)
{
  if (finish)
  {
    return;
  }
  if (x == 9)
  {
    finish = true;
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        printf("%c ", sd[i][j]);
      }
      printf("\n");
    }
    return;
  }
  if (y == 9)
  {
    dfs(x + 1, 0);
    return;
  }
  if (sd[x][y] != '*')
  {
    dfs(x, y + 1);
    return;
  }

  for (int i = 1; i <= 9; i++)
  {
    if (!vv[x / 3 * 3 + y / 3][i] && !vx[x][i] && !vy[y][i])
    {
      sd[x][y] = '0' + i;
      vy[y][i] = true;
      vv[x / 3 * 3 + y / 3][i] = true;
      vx[x][i] = true;
      dfs(x, y + 1);
      vv[x / 3 * 3 + y / 3][i] = false;
      vy[y][i] = false;
      sd[x][y] = '*';
      vx[x][i] = false;
    }
  }
}
int main()
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      scanf(" %c", &sd[i][j]);
    }
  }
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (sd[i][j] != '*')
      {
        vx[i][sd[i][j] - '0'] = true;
        vy[j][sd[i][j] - '0'] = true;
        vv[i / 3 * 3 + j / 3][sd[i][j] - '0'] = true;
      }
    }
  }
  dfs(0, 0);
  return 0;
}
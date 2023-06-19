//时间太长

#include <stdio.h>
#include <stdlib.h>

int sudoku[9][9];

int cantchange[9][9];

int square[9][9] = {0};

int line[9][9] = {0};
int row[9][9] = {0};

void printSudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int getSquare(int x, int y)
{
    return (x / 3) * 3 + y / 3;
}

int check(int i, int x, int y)
{
    int No = getSquare(x, y);
    return !square[No][i] && !row[x][i] && !line[y][i];
}

void dfs(int x, int y)
{
    if (x == 9 && y == 10)
    {
        printSudoku();
        exit(0);
    }
    for (int j = 1; j < 10; j++)
    {
        if (cantchange[x][y])
        {
            if (y == 9)
            {
                y = 0;
                x++;
            }
            dfs(x, y + 1);
        }

        if (check(j, x, y))
        {
            int No = getSquare(x, y);
            int flag = 0;
            square[No][j] = 1;
            row[x - 1][j] = 1;
            line[y - 1][j] = 1;
            if (y == 9)
            {
                y = 0;
                x++;
                flag = 1;
            }
            dfs(x, y + 1);
            if (flag)
            {
                square[No][j] = 0;
                row[x - 2][j] = 0;
                line[8][j] = 0;
            }
            else
            {
                square[No][j] = 0;
                row[x - 1][j] = 0;
                line[y - 1][j] = 0;
            }
        }
    }
}

int main()
{
    int tmp;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &tmp);
            if (tmp > 0 && tmp < 10)
            {
                sudoku[i][j] = tmp;
                cantchange[i][j] = 0;
                line[j][tmp] = 1;
                row[i][tmp] = 1;
            }
        }
    }
    dfs(1, 1);
}
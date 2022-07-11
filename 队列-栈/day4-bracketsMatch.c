#include <stdio.h>
#include <string.h>
#define MAX 50001

int stack[60000];
int top = -1;

void instack(int a)
{
    top++;
    stack[top] = a;
    return;
}

int outstack()
{
    if (top == -1)
    {
        return 0;
    }

    int a = stack[top];
    top--;
    return a;
}

int main()
{
    char string[MAX];
    int print[MAX][2];
    scanf("%s", string);
    int n = 1, q = 0, p;
    while (string[n - 1] != '\0')
    {
        if (string[n - 1] == '(')
        {
            instack(n);
        }
        else
        {
            p = outstack();
            if (p)
            {
                print[q][0] = p;
                print[q][1] = n;
                q++;
            }
            else
            {
                printf("No");
                return 0;
            }
        }
        n++;
    }
    if (top == -1)
    {
        printf("Yes\n");
    }
    else
    {

        printf("No");
        return 0;
    }

    for (int i = 0; i < q; i++)
    {
        printf("%d %d\n", print[i][0], print[i][1]);
    }
}
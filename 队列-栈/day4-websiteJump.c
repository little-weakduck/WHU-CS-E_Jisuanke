#include <stdio.h>
#include <string.h>
#define MAX 50001

int stack[60000] = {0};
int topMAX;
int top = -1;
char website[100000][100];
void instack(int a)
{
    top++;
    stack[top] = a;
    topMAX = top;
    return;
}

int outstack()
{

    if (top - 1 <= -1)
    {
        return 0;
    }
    top--;
    int a = stack[top];
    return a;
}
int goForwward()
{
    if (stack[top + 1] == 0 || top == topMAX)
    {
        return 0;
    }
    else
    {
        top++;
        return stack[top];
    }
}

int compare(char string[])
{
    if (strcmp(string, "VISIT") == 0)
    {
        return 1;
    }
    else if (strcmp(string, "BACK") == 0)
    {
        return 2;
    }
    else if (strcmp(string, "FORWARD") == 0)
    {
        return 3;
    }
    return 0;
}

int main()
{

    char string[10];
    int n, q = 1, step = 0;
    int print[MAX][2];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {

        scanf("%s", string);
        switch (compare(string))
        {
        case 1:
            scanf("%s", website[q]);
            printf("%s\n", website[q]);
            instack(q);

            q++;
            break;

        case 2:
            step = outstack();

            if (step)
            {
                printf("%s\n", website[step]);
            }
            else
            {
                printf("Ignore\n");
            }
            break;

        case 3:
            step = goForwward();

            if (step)
            {
                printf("%s\n", website[step]);
            }
            else
            {
                printf("Ignore\n");
            }
            break;
        }
    }
}
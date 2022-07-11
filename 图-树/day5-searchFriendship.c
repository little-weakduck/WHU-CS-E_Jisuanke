#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int graph[100][100] = {0};
char added[100][21] = {0};

int find(char name[])
{
    int i = 0;
    while (added[i][0] != '\0')
    {
        if (strcmp(added[i], name) == 0)
        {
            return i;
        }
        i++;
    }
    strcpy(added[i], name);
    return i;
}

void friend()
{
    int n, a, b;
    char name[21];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", name);
        a = find(name);
        scanf("%s", name);
        b = find(name);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
}

void isFriend()
{
    int n, a, b;
    char name[21];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", name);
        a = find(name);
        scanf("%s", name);
        b = find(name);
        if (graph[a][b] == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}

int main()
{
    friend();
    isFriend();
}
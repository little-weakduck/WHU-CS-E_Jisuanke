#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void InitList(node **L)
{
    (*L) = (node *)malloc(sizeof(node));
    (*L)->next = NULL;
}

void DispList(node *L)
{
    node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void AddNum(node *L, int n)
{
    node *tmp = L, *s;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    s = (node *)malloc(sizeof(node));
    s->data = n;
    s->next = NULL;
    tmp->next = s;
}

int main()
{
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    node *all[n];
    for (int i = 0; i < n; i++)
    {
        InitList(&all[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        AddNum(all[x - 1], y);
    }
    for (int i = 0; i < n; i++)
    {
        DispList(all[i]);
    }
}
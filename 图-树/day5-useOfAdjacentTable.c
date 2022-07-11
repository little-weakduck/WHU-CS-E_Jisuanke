#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct node
{
    int v;
    struct node *next;
} EdgeNode;

typedef struct
{
    int vertex;
    EdgeNode *edgenext;
} VertexNode;

typedef VertexNode AdjList[MAX];

typedef struct
{
    AdjList adjlist;
    int n, e;
} AdjMatrix;

// 生成临街表

void CreatGrapg(AdjMatrix *G)
{
    int i, j, k, w, v, a, b, c;
    EdgeNode *s;
    scanf("%d%d", &G->n, &G->e);
    for (int i = 0; i < G->n; i++)
    {
        G->adjlist[i].edgenext = NULL;
        G->adjlist[i].vertex = i;
    }

    for (int i = 0; i < G->e; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        s = (EdgeNode *)malloc(sizeof(EdgeNode));
        if (a)
        {
            s->v = c;
            s->next = G->adjlist[b].edgenext;
            G->adjlist[b].edgenext = s;
            s = (EdgeNode *)malloc(sizeof(EdgeNode));
            s->v = b;
            s->next = G->adjlist[c].edgenext;
            G->adjlist[c].edgenext = s;
        }
        else
        {
            s->v = c;
            s->next = G->adjlist[b].edgenext;
            G->adjlist[b].edgenext = s;
        }
    }
}

void DisGrapg(AdjMatrix *G)
{
    for (int i = 0; i < G->n; i++)
    {
        printf("%d:", i);
        while (G->adjlist[i].edgenext != NULL)
        {
            printf(" %d", G->adjlist[i].edgenext->v);
            G->adjlist[i].edgenext = G->adjlist[i].edgenext->next;
        }
        printf("\n");
    }
}
int main()
{
    AdjMatrix *G = (AdjMatrix *)malloc(sizeof(AdjMatrix));
    CreatGrapg(G);
    DisGrapg(G);
}
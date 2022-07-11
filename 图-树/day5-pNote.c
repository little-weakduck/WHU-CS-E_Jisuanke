// bug

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *parent;        //福清
    int childCount;             //度
    struct node *childs[10001]; //孩子节点
    int data;
} Node;

int total = 0;

void add(Node *root, int x, int y) //添加新的节点
{
    if (root == NULL)
    {
        return; //如果root是NULL 返回
    }

    if (root->data == x) // x是父亲节点，开始添加
    {
        Node *s = (Node *)malloc(sizeof(Node *));
        s->data = y;
        s->childCount = 0;
        s->parent = root;
        root->childs[root->childCount] = s;
        root->childCount++;
        return;
    }
    else
    {
        for (int i = 0; i < root->childCount; i++) //不是父亲节点，向孩子节点遍历
        {
            add(root->childs[i], x, y);
        }
    }
}

void findP(Node *root) //查找p
{
    if (root == NULL)
    {
        return;
    }
    if (root->parent == NULL || root->childCount >= root->parent->childCount)
    //如果没有父亲节点或者比父亲节点的度大
    {
        int flag = 1;
        for (int i = 0; i < root->childCount; i++) //是否比所有孩子节点的度大
        {
            if (root->childCount < root->childs[i]->childCount)
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            total++;
        }
    }
    for (int i = 0; i < root->childCount; i++)
    {
        findP(root->childs[i]); //向下遍历
    }
}

void Tree()
{
    int x, y, n;
    scanf("%d", &n);
    scanf("%d%d", &x, &y);
    Node *root;
    Node *s = (Node *)malloc(sizeof(Node));
    s->parent = NULL;
    s->data = x;
    s->childCount = 0;
    s->childs[0] = (Node *)malloc(sizeof(Node));
    s->childs[0]->data = y;
    s->childs[0]->childCount = 0;
    root = s;
    for (int i = 1; i < n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        add(root, x, y);
    }
    total = 0;
    findP(root);
    printf("%d\n", total);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        Tree();
    }
}
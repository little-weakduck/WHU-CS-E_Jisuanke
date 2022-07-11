#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} ListNode;
/**
 * 已经定义的 ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *next;
 * } ListNode;
 */
int linkedListCycleLength(ListNode *head) {
    if (head -> next == NULL) return 0;
    ListNode *s = head,*q = head -> next;
    int n = 1, isC = 0;
    while (s->next != NULL &&q->next != NULL&& q->next->next != NULL){
        if(s == q){
           isC = 1;
            break;
        }
        q = q ->next->next;
        s = s->next;
    }
    if (isC){
        s = s->next;
        while(s != q){
            s = s->next;
            n++;
        }
        return n;
    }
    else return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;
    ListNode *temp = head;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = x;
        temp->next->next = NULL;
        temp = temp->next;
    }
    int d;
    scanf("%d", &d);
    ListNode *Nth = head;
    while (d--) {
        Nth = Nth->next;
    }
    temp->next = Nth;
    temp = head;
    head = head->next;
    free(temp);
    printf("%d\n", linkedListCycleLength(head));
    return 0;
}
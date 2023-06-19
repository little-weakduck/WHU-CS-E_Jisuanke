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
ListNode* findIntersectionListNode(ListNode *head1, ListNode *head2) {
    int a = 0, b = 0;
    ListNode *tmp1 = head1, *tmp2 = head2;
    while(head1->next != NULL){
        a++;
        head1 = head1 -> next;
    }
    while(head2->next != NULL){
        b++;
        head2 = head2 -> next;
    }
    if(head1 != head2){
        return NULL;
    }
    int num = a - b;
    if(num > 0){
        for(int i = 0; i < num; i++)
            tmp1 = tmp1 -> next;
    }else if(num < 0){
        num = -num;
        for(int i = 0; i < num; i++)
            tmp2 = tmp2 -> next;
    }
    while( tmp1 != tmp2){
        tmp1 = tmp1 -> next;
        tmp2 = tmp2 -> next;
    }
    return tmp1;
}
int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;
    ListNode *temp = head;
    ListNode *ans = NULL;
    for (int i = 0; i < n; ++i) {
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = 0;
        temp->next->next = NULL;
        temp = temp->next;
        if (i == x) {
            ans = temp;
        }
    }
    temp = head;
    head = head->next;
    free(temp);
    ListNode *head2 = (ListNode*)malloc(sizeof(ListNode));
    head2->val = 0;
    head2->next = NULL;
    temp = head2;
    for (int i = 0; i < m; ++i) {
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = 0;
        temp->next->next = NULL;
        temp = temp->next;
    }
    temp->next = ans;
    temp = head2;
    head2 = head2->next;
    free(temp);
    temp = findIntersectionListNode(head, head2);
    if(temp == ans) {
        printf("Accept\n");
    } else {
        printf("Wrong answer\n");
    }
    return 0;
}
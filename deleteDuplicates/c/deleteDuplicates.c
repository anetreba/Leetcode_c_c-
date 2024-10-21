#include <stdio.h>
#include <stdlib.h>

 //Definition for singly-linked list.
typedef struct ListNode {
      int val;
      struct ListNode *next;
} ListNode;

void print_list(ListNode* head) {
    ListNode *tmp = head;
    
    printf("[");

    while(tmp) {
        printf("%i", tmp->val);
        tmp = tmp->next;
        if (tmp != NULL)
            printf(" ");
    }
    printf("]\n");
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !(head->next))
        return head;
    ListNode* prev = head;
    ListNode* curr = prev->next;
    ListNode* tmp = NULL;

    while (prev && prev->next) {
        curr = prev->next;
        if (prev->val == curr->val) {
            tmp = curr;
            prev->next = curr->next;
            free(tmp);
            tmp = NULL;
        }
        else
            prev = prev->next;
    }
    return head;
}

int main() {
    ListNode *lst1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *lst2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *lst3 = (ListNode *)malloc(sizeof(ListNode));
    // ListNode *lst4 = (ListNode *)malloc(sizeof(ListNode));
    // ListNode *lst5 = (ListNode *)malloc(sizeof(ListNode));
    lst1->val = 1;
    lst2->val = 1;
    lst3->val = 1;
    // lst4->val = 2;
    // lst5->val = 3;

    lst1->next = lst2;
    lst2->next = lst3;
    // lst3->next = lst4;
    // lst4->next = lst5;
    ListNode *res = deleteDuplicates(lst1);
    print_list(res);
    return 0;
}

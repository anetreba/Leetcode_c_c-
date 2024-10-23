#include <stdlib.h>
#include <stdio.h>

//Definition for a binary tree node.
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct ListNode {
      int val;
      int count;
      struct ListNode *next;
} ListNode;

void add_elem_to_list(struct ListNode** head, int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    if (*head)
       node->count = (*head)->count + 1; 
    else 
        node->count = 1;
    node->next = *head;
    *head = node;
}

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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void depth_first_search(struct TreeNode* root, struct ListNode** head) {
    if (root == NULL)
        return ;
    depth_first_search(root->left, head);
    if (root != NULL)
        add_elem_to_list(head, root->val);
    
    depth_first_search(root->right, head);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    ListNode* node;
    depth_first_search(root, &node);
    if (!node) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = node->count;
    int *res = (int *)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    ListNode* head = node;

    while (head) {
        res[*returnSize - 1 - i] = head->val;
        i++;
        node = head;
        head = head->next;
        node->next = NULL;
        free(node);
    }
    system("leaks a.out");
    return res;
}

int main() {
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *left = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *right = (TreeNode *)malloc(sizeof(TreeNode));

    root->val = 1;
    left->val = 3;
    right->val = 2;

    root->left = NULL;
    root->right = right;
    
    right->right = NULL;

    right->left = left;

    left->left = NULL;
    left->right = NULL;
    
    int returnSize = 0;
    int *result = inorderTraversal(root, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%i ", result[i]);
    }
    printf("\n");

    return 0;
}

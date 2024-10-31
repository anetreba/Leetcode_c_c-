#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q)
        return true;
    if ((!p && q) || (!q && p) || (p->val != q->val))
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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

    TreeNode *root1 = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *left1 = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *right1 = (TreeNode *)malloc(sizeof(TreeNode));

    root1->val = 1;
    left1->val = 3;
    right1->val = 2;

    root1->left = NULL;
    root1->right = right;
    
    right1->right = NULL;

    right1->left = left;

    left1->left = NULL;
    left1->right = NULL;

    if (isSameTree(root, root1))
        printf("True\n");
    else
        printf("False\n");
    
}

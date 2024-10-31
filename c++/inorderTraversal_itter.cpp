#include <vector>
#include <iostream>
#include <stack>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if (!root)
            return res;
        std::stack<TreeNode *> stack;
        TreeNode *curr = root;
        
        while (!(stack.empty()) || curr) {
            while (curr) {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};

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
    
    Solution s;
    std::vector<int> result = s.inorderTraversal(root);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

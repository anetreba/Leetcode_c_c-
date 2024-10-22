#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next))
            return head;
        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* tmp = nullptr;

        while (prev && prev->next) {
            curr = prev->next;
            if (prev->val == curr->val) {
                tmp = curr;
                prev->next = curr->next;
                delete tmp;
                tmp = nullptr;
            }
            else
                prev = prev->next;
        }
        return head;
    }
};

void print_list(ListNode* head) {
    ListNode *tmp = head;
    
    std::cout << "[";

    while(tmp) {
        std::cout << tmp->val;
        tmp = tmp->next;
        if (tmp != NULL)
            std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    ListNode *lst1 = new ListNode(1);
    ListNode *lst2 = new ListNode(1);
    ListNode *lst3 = new ListNode(1);

    lst1->next = lst2;
    lst2->next = lst3;
    Solution s;

    ListNode *res = s.deleteDuplicates(lst1);
    print_list(res);
    return 0;
}

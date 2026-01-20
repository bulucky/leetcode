#include <iostream>

#include "leetcode.hpp"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }
        
        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* temp = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (!list1) {
            temp->next = list2;
        }
        if (!list2) {
            temp->next = list1;
        }

        return dummy->next;
    }
};

int main(int argc, char const* argv[]) {
    ListNode* a3 = new ListNode(4, nullptr);
    ListNode* a2 = new ListNode(2, a3);
    ListNode* a1 = new ListNode(1, a2);

    ListNode* b3 = new ListNode(4, nullptr);
    ListNode* b2 = new ListNode(3, b3);
    ListNode* b1 = new ListNode(1, b2);

    Solution sol;
    ListNode* res = sol.mergeTwoLists(a1, b1);

    while (res) {
        std::cout << res->val << "\n";
        res = res->next;
    }

    
    return 0;
}
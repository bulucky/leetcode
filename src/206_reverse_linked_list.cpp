#include <iostream>
#include "leetcode.hpp"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* nhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return nhead;
    }
};

int main(int argc, char const* argv[]) {
    ListNode* a3 = new ListNode(3, nullptr);
    ListNode* a2 = new ListNode(2, a3);
    ListNode* a1 = new ListNode(1, a2);

    Solution sol;
    ListNode* res = sol.reverseList(a1);

    while (res) {
        std::cout << res->val << "\n";
        res = res->next;
    }

    return 0;
}
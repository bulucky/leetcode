#include <iostream>
#include "leetcode.hpp"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;
        ListNode* first = head;
        ListNode* second = nullptr;

        while (first && first->next) {
            second = first->next;
            ListNode* next = first->next->next;
            pre->next = second;
            second->next = first;
            first->next = next;
            pre = first;
            first = next;
        }

        return dummy->next;
    }
};

int main(int argc, char const* argv[]) {

    ListNode* a4 = new ListNode(4, nullptr);
    ListNode* a3 = new ListNode(3, a4);
    ListNode* a2 = new ListNode(2, a3);
    ListNode* a1 = new ListNode(1, a2);

    Solution sol;
    ListNode* res = sol.swapPairs(a1);

    while (res) {
        std::cout << res->val << "\n";
        res = res->next;
    }
    return 0;
}
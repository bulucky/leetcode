#include <iostream>
#include "leetcode.hpp"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main(int argc, char const* argv[]) {
    ListNode* a5 = new ListNode(5, nullptr);
    ListNode* a4 = new ListNode(4, a5);
    ListNode* a3 = new ListNode(3, a4);
    ListNode* a2 = new ListNode(2, a3);
    ListNode* a1 = new ListNode(1, a2);
    
    Solution sol;
    ListNode* res = sol.middleNode(a1);
    std::cout << res->val << "\n";

    return 0;
}
#include <iostream>
#include "leetcode.hpp"

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }

        return false;
    }
};

int main(int argc, char const* argv[]) {
    // ListNode* a4 = nullptr;
    // ListNode* a3 = nullptr;
    // ListNode* a2 = nullptr;
    // ListNode* a1 = nullptr;

    // a2 = new ListNode(2, a3);
    // a4 = new ListNode(-4, a2);
    // a3 = new ListNode(0, a4);
    // a1 = new ListNode(3, a2);

    // Solution sol;
    // bool res = sol.hasCycle(a1);
    // std::cout << res << "\n";

    return 0;
}
#include <iostream>
#include "leetcode.hpp"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;

        while (--n && fast) { fast = fast->next; }

        while (fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        // slow指向结点即为要删除结点
        // 处理结点数量与n相同情况
        if (pre == slow) { return head->next; }
        pre->next = slow->next;

        return head;
    }
};

int main(int argc, char const* argv[]) {
    // ListNode* a5 = new ListNode(5, nullptr);
    // ListNode* a4 = new ListNode(4, a5);
    // ListNode* a3 = new ListNode(3, a4);
    ListNode* a2 = new ListNode(2, nullptr);
    ListNode* a1 = new ListNode(1, a2);

    Solution sol;
    ListNode* res = sol.removeNthFromEnd(a1, 2);

    while (res) {
        std::cout << res->val << "\n";
        res = res->next;
    }

    return 0;
}
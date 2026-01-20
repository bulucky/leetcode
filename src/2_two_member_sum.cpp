#include <iostream>
#include "leetcode.hpp"

class Solution {
public:
    // O(max(M, N)) O(1)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }

        int l1_length = 0, l2_length = 0;
        ListNode *l1_temp = l1, *l2_temp = l2;
        while (l1_temp) {
            ++l1_length;
            l1_temp = l1_temp->next;
        }
        l1_temp = l1;
        while (l2_temp) {
            ++l2_length;
            l2_temp = l2_temp->next;
        }
        l2_temp = l2;
        // 保证l1的长度小于等于l2
        if (l1_length > l2_length) {
            ListNode* temp = l1_temp;
            l1_temp = l2_temp;
            l2_temp = temp;
        }

        // 以较长链表存储和
        ListNode* temp = l2_temp;
        int carry_falg = 0;
        ListNode* last_node = nullptr;
        while (l2_temp) {
            int sum_bit = 0;
            if (l1_temp) {
                sum_bit = l1_temp->val + l2_temp->val + carry_falg;
                l1_temp = l1_temp->next;
            } else {
                sum_bit = l2_temp->val + carry_falg;
            }
            carry_falg = 0;
            int this_bit = sum_bit % 10;
            carry_falg = sum_bit / 10;
            l2_temp->val = this_bit;
            last_node = l2_temp;
            l2_temp = l2_temp->next;
        }

        // 处理最后进位情况
        if (carry_falg) {
            last_node->next = new ListNode(carry_falg, nullptr);
        }

        return temp;
    }
};

int main(int argc, char const* argv[]) {
    ListNode* a7 = new ListNode(9, nullptr);
    ListNode* a6 = new ListNode(9, a7);
    ListNode* a5 = new ListNode(9, a6);
    ListNode* a4 = new ListNode(9, a5);
    ListNode* a3 = new ListNode(9, a4);
    ListNode* a2 = new ListNode(9, a3);
    ListNode* a1 = new ListNode(9, a2);

    ListNode* b4 = new ListNode(9, nullptr);
    ListNode* b3 = new ListNode(9, b4);
    ListNode* b2 = new ListNode(9, b3);
    ListNode* b1 = new ListNode(9, b2);

    Solution sol;
    ListNode* res = sol.addTwoNumbers(a1, b1);

    while (res) {
        std::cout << res->val << "\n";
        res = res->next;
    }
    return 0;
}
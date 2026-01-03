#include <vector>
#include <iostream>
#include <algorithm>
#include "leetcode.hpp"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverse(slow->next);
        slow->next = nullptr;
        while (second) {
            if (head->val != second->val) return false;
            else {
                second = second->next;
                head = head->next;
            }
        }

        return true;
    }

    ListNode* reverse(ListNode* node) {
        ListNode* pre = nullptr;
        ListNode* cur = node;
        while (cur) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        return pre;
    }
};

int main(int argc, char const* argv[]) {
    // ListNode* a4 = new ListNode(1, nullptr);
    // ListNode* a3 = new ListNode(2, a4);
    ListNode* a2 = new ListNode(2, nullptr);
    ListNode* a1 = new ListNode(1, a2);

    Solution sol;
    bool res = sol.isPalindrome(a1);
    std::cout << res << "\n";

    return 0;
}

// bool isPalindrome(ListNode* head) {
//     std::vector<int> vec_val;
//     while (head) {
//         vec_val.emplace_back(head->val);
//         head = head->next;
//     }

//     std::vector<int> re_vec_val = vec_val;
//     std::reverse(re_vec_val.begin(), re_vec_val.end());
//     if (re_vec_val == vec_val)
//         return true;
//     else
//         return false;
// }
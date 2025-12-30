#include <vector>
#include <iostream>
#include <algorithm>
#include "leetcode.hpp"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> vec_val;
        while (head) {
            vec_val.emplace_back(head->val);
            head = head->next;
        }

        std::vector<int> re_vec_val = vec_val;
        std::reverse(re_vec_val.begin(), re_vec_val.end());
        if (re_vec_val == vec_val)
            return true;
        else
            return false;
    }
};

int main(int argc,char const* argv[]) {
    ListNode* a4 = new ListNode(1, nullptr);
    ListNode* a3 = new ListNode(2, a4);
    ListNode* a2 = new ListNode(2, a3);
    ListNode* a1 = new ListNode(1, a2);

    Solution sol;
    bool res = sol.isPalindrome(a1);
    std::cout << res << "\n";

    return 0;
}
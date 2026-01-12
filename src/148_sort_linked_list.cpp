#include <vector>
#include <iostream>
#include <algorithm>
#include "leetcode.hpp"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        std::vector<int> node_val;
        ListNode* temp = head;
        while (temp) {
            node_val.emplace_back(temp->val);
            temp = temp->next;
        }

        std::sort(node_val.begin(), node_val.end());

        temp = head;
        for (const auto& val : node_val) {
            temp->val = val;
            temp = temp->next;
        }

        return head;
    }
};

int main(int argc, char const* argv[]) {

    ListNode* a4 = new ListNode(3, nullptr);
    ListNode* a3 = new ListNode(1, a4);
    ListNode* a2 = new ListNode(2, a3);
    ListNode* a1 = new ListNode(4, a2);

    Solution sol;
    ListNode* res = sol.sortList(a1);

    while (res) {
        std::cout << res->val << "\n";
        res = res->next;
    }
    return 0;
}
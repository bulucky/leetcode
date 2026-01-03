#include "leetcode.hpp"
#include <unordered_map>

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* circul = nullptr;
        std::unordered_map<ListNode*, int> node_map;

        while (head) {
            ++node_map[head];

            if (node_map[head] == 2) {
                circul = head;
                break;
            }

            head = head->next;
        }

        return circul;
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
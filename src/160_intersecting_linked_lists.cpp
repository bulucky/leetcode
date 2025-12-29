#include <iostream>
#include "leetcode.hpp"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        
        ListNode* A = headA;
        ListNode* B = headB;
        while (A != B) {
            A = A == nullptr ? headB : A->next;
            B = B == nullptr ? headA : B->next;
        }

        return A;
    }
};

int main(int argc, char const* argv[]) {
    Solution sol;

    ListNode* c3 = new ListNode(5, nullptr);
    ListNode* c2 = new ListNode(4, c3);
    ListNode* c1 = new ListNode(8, c2);
    ListNode* a2 = new ListNode(1, c1);
    ListNode* a1 = new ListNode(4, a2);
    ListNode* b3 = new ListNode(1, c1);
    ListNode* b2 = new ListNode(6, b3);
    ListNode* b1 = new ListNode(5, b2);

    ListNode* inter_node = sol.getIntersectionNode(a1, b1);
    std::cout << inter_node->val << "\n";

    delete b1;
    delete b2;
    delete b3;
    delete a1;
    delete a2;
    delete c1;
    delete c2;
    delete c3;

    return 0;
}
#include <iostream>
#include "leetcode.hpp"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        ListNode* pre_node = head;
        ListNode* head_temp = head->next;
        int pre_val = head->val;
        
        while(head_temp) {
            if(pre_val == head_temp->val && head_temp->next) {
                pre_node->next = head_temp->next;
                head_temp = head_temp->next;
            }else if(pre_val != head_temp->val) {
                pre_val = head_temp->val;
                pre_node = head_temp;
                head_temp = head_temp->next;
            }else {
                head_temp = nullptr;
                pre_node->next = head_temp;
            }
        }

        return head;
    } 
};

int main(int argc, char const* argv[])
{
    Solution sol;

    ListNode* e = new ListNode(3);
    ListNode* d = new ListNode(3, e);
    ListNode* c = new ListNode(2, d);
    ListNode* b = new ListNode(1, c);
    ListNode* a = new ListNode(1, b);


    ListNode* l = sol.deleteDuplicates(a);

    std::cout << l << std::endl;

    return 0;
}
#include <iostream>
#include "leetcode.hpp"
#include <vector>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        size_t l1_len = 0, l2_len = 0;
        ListNode* l;
        ListNode* l1_temp = l1;
        ListNode* l2_temp = l2;
        while(l1_temp->next) {
            l1_len++;
            l1_temp = l1_temp->next;
        }
        while(l2_temp->next) {
            l2_len++;
            l2_temp = l2_temp->next;
        }
        l1_temp = l1; l2_temp = l2;
        if(l1_len >= l2_len) {
            l = l1;
            ListNode* l_temp;
            std::vector<int> num_temp;
            std::vector<int> num_temp_add;
            num_temp_add.emplace_back(0);
            // while(l2_temp) {
            //     // if(l1_temp->val + l2_temp->val >= 10) {
            //     //     l_temp->next->val++;
            //     //     l_temp->val = l1_temp->val + l2_temp->val % 10;
            //     // }else {
            //     //     l_temp->val = l1_temp->val + l2_temp->val;
            //     // }
            //     l_temp = l_temp->next;
            //     l1_temp = l1_temp->next;
            //     l2_temp = l2_temp->next;
            // }
            for(size_t i = 0; i < l2_len; ++i) {
                num_temp.emplace_back(l1_temp->val + l2_temp->val);
                l1_temp = l1_temp->next;
                l2_temp = l2_temp->next;
            }
            for(size_t i = 0; i < l2_len; ++i) {
                if(num_temp[i] >= 10) {
                    num_temp_add.emplace_back(1);
                }else {
                    num_temp_add.emplace_back(0);
                }
            }
            l1_temp = l1; l2_temp = l2;
            

        }else {
            l = l2;
            ListNode* l_temp = l;
            while(l1_temp) {
                if(l1_temp->val + l2_temp->val >= 10) {
                    l_temp->next->val++;
                    l_temp->val = l1_temp->val + l2_temp->val % 10;
                }else {
                    l_temp->val = l1_temp->val + l2_temp->val;
                }
                l_temp = l_temp->next;
                l1_temp = l1_temp->next;
                l2_temp = l2_temp->next;
            }
        }
        return l;
    }
};



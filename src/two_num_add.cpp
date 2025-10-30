#include <vector>
#include <leetcode.hpp>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        std::vector<int> bits;
        int carry_flag = 0;

        while(l1 && l2) {
            int this_sum = l1->val + l2->val + carry_flag;
            int this_bit = this_sum % 10;
            carry_flag = this_sum / 10;

            bits.emplace_back(this_bit);

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 || l2 || carry_flag) {
            if(l1) {
                int this_sum = l1->val + carry_flag;
                int this_bit = this_sum % 10;
                carry_flag = this_sum / 10;
                bits.emplace_back(this_bit);
                l1 = l1->next;
            }else if(l2){
                int this_sum = l2->val + carry_flag;
                int this_bit = this_sum % 10;
                carry_flag = this_sum / 10;
                bits.emplace_back(this_bit);
                l2 = l2->next;
            }else {
                bits.emplace_back(carry_flag);
                carry_flag = 0;
            }
        }

        ListNode* l = new ListNode(bits[0]);
        ListNode* l_temp = l;
        for(int i = 1; i < bits.size(); ++i) {
            l_temp->next = new ListNode(bits[i]);
            l_temp = l_temp->next;
        }
        // ListNode* l_temp = nullptr;
        // ListNode** l = &l_temp;
        // for(const auto& bit : bits) {
        //     ListNode* node = new ListNode(bit);
        //     l_temp = node;
        //     l_temp = l_temp->next;
        // }

        return l;

    }
};

int main(int argc, char const* argv[])
{   
    Solution sol;

    ListNode* l1_7 = new ListNode(9);
    ListNode* l1_6 = new ListNode(9, l1_7);
    ListNode* l1_5 = new ListNode(9, l1_6);
    ListNode* l1_4 = new ListNode(9, l1_5);
    ListNode* l1_3 = new ListNode(9, l1_4);
    ListNode* l1_2 = new ListNode(9, l1_3);
    ListNode* l1_1 = new ListNode(9, l1_2);
    ListNode* l2_4 = new ListNode(9);
    ListNode* l2_3 = new ListNode(9, l2_4);
    ListNode* l2_2 = new ListNode(9, l2_3);
    ListNode* l2_1 = new ListNode(9, l2_2);

    sol.addTwoNumbers(l1_1, l2_1);

    return 0;
}
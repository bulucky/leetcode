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

/**
*思路:
*   1.两种情况(存在空链表与否) 存在空链表: 返回非空链表地址, 全空: 返回空指针
*   2.先判断两个链表长度,再依次判断两个节点元素的大小(小为先), 并以此元素创建新节点尾插至待返回链表
*   3.若存在其中一个链表已判断完所有节点,则将另一链表的的剩余节点直接尾插至待返回链表
*
*/  
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode l0(0, nullptr);
        ListNode* l_temp = &l0;
        
        // 存在空链表
        if(list1 == nullptr || list2 == nullptr) {
            if(!list1) {
                l_temp->next = list2;
            }else if(!list2) {
                l_temp->next = list1;
            }else {
                l_temp->next = nullptr;
            }
        }
        else{
            int len_list1 = 1;
            int len_list2 = 1;
            ListNode* list1_temp = list1;
            ListNode* list2_temp = list2;

            while(list1_temp->next) {
                list1_temp = list1_temp->next;
                len_list1++;
            }
            while(list2_temp->next) {
                list2_temp = list2_temp->next;
                len_list2++;
            }
            list1_temp = list1;
            list2_temp = list2;
            
            while(len_list1 >= 0 || len_list2 >= 0) {
                ListNode l_next_temp(0, nullptr);
                bool is_list1 = false;
                bool is_list2 = false;
                if(len_list1 && len_list2) {
                    int val1 = list1_temp->val;
                    int val2 = list2_temp->val;
                    if(val1 >= val2) {
                        l_next_temp.val = val2;
                        list2_temp = list2_temp->next;
                        is_list2 = true; 
                    }else {
                        l_next_temp.val = val1;
                        list1_temp = list1_temp->next;
                        is_list1 = true;
                    }
                }else if(len_list1 == 0) {
                    l_next_temp.next = list2_temp;
                }else if(len_list2 == 0) {
                    l_next_temp.next = list1_temp;
                }

                ListNode* l_temp_temp = l_temp;
                
                if(!len_list1 || !len_list2) {
                    while(l_temp_temp->next != nullptr) {
                        l_temp_temp = l_temp_temp->next;
                    }
                    if(l_temp_temp->next == nullptr) {
                        l_temp_temp->next = l_next_temp.next;
                    }
                    break;
                }else {
                    while(l_temp_temp->next != nullptr) {
                        l_temp_temp = l_temp_temp->next;
                    }
                    if(l_temp_temp->next == nullptr) {
                        // 新节点的内存需手动分配(堆内存)
                        l_temp_temp->next = new ListNode(l_next_temp.val);
                        if(is_list1) len_list1--;
                        else if(is_list2) len_list2--;
                        // std::cout << "debug" << std::endl;
                    }
                }
            }
        }
        ListNode* l = l_temp->next;
        return l;                                                  
    }
};

int main(int argc, char const* argv[]) 
{
    Solution sol;
    ListNode list1_node1(1);
    ListNode list1_node2(2);
    ListNode list1_node3(4);
    ListNode list2_node1(1);
    ListNode list2_node2(3);
    ListNode list2_node3(4);
    list1_node1.next = &list1_node2;
    list1_node2.next = &list1_node3;
    list2_node1.next = &list2_node2;
    list2_node2.next = &list2_node3;
    
    ListNode* l = sol.mergeTwoLists(&list1_node1, &list2_node1);
    std::cout << l << std::endl;

    return 0;
}
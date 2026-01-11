#include "leetcode.hpp"
#include <unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // 建立新旧节点映射
        std::unordered_map<Node*, Node*> node_map;
        Node* p_temp = head;
        while (p_temp) {
            Node* node = new Node(p_temp->val);
            node_map[p_temp] = node;
            p_temp = p_temp->next;
        }


        p_temp = head;
        while (p_temp) {                      
            node_map[p_temp]->next = node_map[p_temp->next];
            node_map[p_temp]->random = node_map[p_temp->random];
            p_temp = p_temp->next;
        }

        return node_map[head];
    }
};

int main(int argc, char const* argv[]) {
    Node* a2 = new Node(2);
    Node* a1 = new Node(1);
    a2->next = nullptr;
    a2->random = a2;
    a1->next = a2;
    a1->random = a2;

    Solution sol;
    Node* res = sol.copyRandomList(a1);

    delete a1;
    delete a2;
    return 0;
}
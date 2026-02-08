#include <vector>
#include <iostream>
#include "leetcode.hpp"

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        inorder_traversal(root);

        return res_;
    }

private:
    std::vector<int> res_ = {};

    void inorder_traversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorder_traversal(root->left);
        res_.push_back(root->val);
        inorder_traversal(root->right);
    }
};

int main(int argc, char const* argv[]) {
    Solution* sol = new Solution();

    TreeNode* a3 = new TreeNode(3);
    TreeNode* a2 = new TreeNode(2, a3, nullptr);
    TreeNode* a1 = new TreeNode(1, nullptr, a2);

    std::vector<int> res = sol->inorderTraversal(a1);

    for (const auto& a_res : res) {
        std::cout << a_res << "\n";
    }

    return 0;
}
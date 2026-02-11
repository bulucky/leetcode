#include <vector>
#include <iostream>
#include "leetcode.hpp"

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        lever_order(root, 0);

        return res_;
    }

private:
    std::vector<std::vector<int>> res_;

    void lever_order(TreeNode* root, int lever) {
        if (root == nullptr) {
            return;
        }
        if (lever >= res_.size()) {
            res_.emplace_back();
        }

        res_[lever].push_back(root->val);
        lever_order(root->left, lever + 1);
        lever_order(root->right, lever + 1);

    }
};

int main(int argc,char const* argv[]) {
    Solution* sol = new Solution();

    TreeNode* a5 = new TreeNode(7);
    TreeNode* a4 = new TreeNode(15);
    TreeNode* a3 = new TreeNode(20, a4,a5);
    TreeNode* a2 = new TreeNode(9);
    TreeNode* a1 = new TreeNode(3, a2, a3);

    std::vector<std::vector<int>> res = sol->levelOrder(a1);

    for (const auto& a_res : res) {
        for (const auto& a_a_res:a_res) {
            std::cout << a_a_res << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
#include <iostream>
#include <algorithm>
#include "leetcode.hpp"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter_of_BinaryTree(root);

        return res_;
    }

private:
    // 递归-- 节点左右子树深度和，并维护一个最大和
    int diameter_of_BinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_val = diameter_of_BinaryTree(root->left);
        int right_val = diameter_of_BinaryTree(root->right);

        if ((left_val + right_val) > res_) {
            res_ = left_val + right_val;
        }
        // res_ = std::max(res_, left_val + right_val);

        return left_val > right_val ? left_val + 1 : right_val + 1;
        // return std::max(left_val, right_val) + 1;
    }
    int res_ = 0;
};

int main(int argc, char const* arg[]) {
    Solution* sol = new Solution();

    // TreeNode* a5 = new TreeNode(5);
    // TreeNode* a4 = new TreeNode(4);
    // TreeNode* a3 = new TreeNode(3);
    // TreeNode* a2 = new TreeNode(2, a4, a5);
    // TreeNode* a1 = new TreeNode(1, a2, a3);

    // TreeNode* a8 = new TreeNode(8);
    // TreeNode* a7 = new TreeNode(7);
    // TreeNode* a6 = new TreeNode(6);
    // TreeNode* a5 = new TreeNode(5);
    // TreeNode* a4 = new TreeNode(4, a7, a8);
    // TreeNode* a3 = new TreeNode(3, a5, a6);
    // TreeNode* a2 = new TreeNode(2, a3, a4);
    // TreeNode* a1 = new TreeNode(1, a2, nullptr);

    TreeNode* a2 = new TreeNode(2);
    TreeNode* a1 = new TreeNode(1, a2, nullptr);

    int res = sol->diameterOfBinaryTree(a1);

    std::cout << res << "\n";

    delete sol;

    return 0;
}
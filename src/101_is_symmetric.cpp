#include <iostream>
#include "leetcode.hpp"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return is_symmetric(root->left, root->right);
    }

private:
    bool is_symmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left == nullptr || right == nullptr) {
            return false;
        } else if (left->val != right->val) {
            return false;
        } else {
            return is_symmetric(left->right, right->left) &&
                   is_symmetric(left->left, right->right);
        }
    }
};

int main(int argc, char const* argv[]) {
    Solution* sol = new Solution();

    // TreeNode* a7 = new TreeNode(3);
    // TreeNode* a6 = new TreeNode(4);
    // TreeNode* a5 = new TreeNode(4);
    // TreeNode* a4 = new TreeNode(3);
    // TreeNode* a3 = new TreeNode(2, a6, a7);
    // TreeNode* a2 = new TreeNode(2, a4, a5);
    // TreeNode* a1 = new TreeNode(1, a2, a3);

    TreeNode* a5 = new TreeNode(3);
    TreeNode* a4 = new TreeNode(3);
    TreeNode* a3 = new TreeNode(2, nullptr, a5);
    TreeNode* a2 = new TreeNode(2, nullptr, a4);
    TreeNode* a1 = new TreeNode(1, a2, a3);

    bool res = sol->isSymmetric(a1);

    std::cout << res << "\n";

    delete sol;

    return 0;
}
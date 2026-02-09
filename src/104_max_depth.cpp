#include <iostream>
#include <algorithm>
#include "leetcode.hpp"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return std::max(left, right) + 1;
    }
};

int main(int argc, char const* argv[]) {
    Solution* sol = new Solution();

    TreeNode* a5 = new TreeNode(7);
    TreeNode* a4 = new TreeNode(15);
    TreeNode* a3 = new TreeNode(20, a4, a5);
    TreeNode* a2 = new TreeNode(9);
    TreeNode* a1 = new TreeNode(3, a2, a3);

    int res = sol->maxDepth(a1);

    std::cout << res << "\n";

    delete sol;

    return 0;
}
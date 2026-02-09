#include "leetcode.hpp"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};

int main(int argc, char const* argv[]) {
    Solution* sol = new Solution();

    delete sol;

    return 0;
}
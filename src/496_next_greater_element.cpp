#include <stack>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> res(nums1.size(), -1);
        std::stack<int> s_i;
        for (int k = 0; k < nums1.size(); ++k) {
            int j = 0;
            for (; j < nums2.size(); ++j) {
                if (nums2[j] == nums1[k]) {
                    break;
                }
            }
            for (int i = nums2.size() - 1; i > j; --i) {
                if (nums2[i] >= nums2[j]) {
                    s_i.push(nums2[i]);
                }
                if (!s_i.empty()) {
                    res[k] = s_i.top();
                    s_i.pop();
                }
            }
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {

    Solution sol;
    // std::vector<int> nums1 = {4, 1, 2};
    // std::vector<int> nums2 = {1, 3, 4, 2};

    std::vector<int> nums1 = {2, 1, 3};
    std::vector<int> nums2 = {2, 3, 1};

    std::vector<int> res = sol.nextGreaterElement(nums1, nums2);
    for (const auto& a_res : res) {
        std::cout << a_res << "\n";
    }

    return 0;
}
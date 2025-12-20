#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> res;
        res.resize(nums.size(), 1);
        int pre_product = 1, suf_product = 1;

        // res 存储对应索引位置前缀积
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = pre_product;
            pre_product *= nums[i];
        }
        // res 乘对应后缀积
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] *= suf_product;
            suf_product *= nums[i];
        }

        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution sol;
    std::vector<int> nums = {-1, 1, 0, -3, 3};

    std::vector<int> res = sol.productExceptSelf(nums);

    for (const auto& num : res) {
        std::cout << num << "\n";
    }

    return 0;
}

// // timeout
// std::vector<int> productExceptSelf(std::vector<int>& nums) {
//     std::vector<int> res;
//     int pre_product = 1, suf_product = 1;

//     for (int i = 0; i < nums.size(); ++i) {
//         if (i == 0) pre_product = 1;
//         else
//             pre_product *= nums[i - 1];
//         for (int j = i + 1; j < nums.size(); ++j) {
//             suf_product *= nums[j];
//         }
//         res.emplace_back(pre_product * suf_product);
//         suf_product = 1;
//     }

//     return res;
// }
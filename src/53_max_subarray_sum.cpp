#include <vector>
#include <iostream>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int res = nums[0];
        int sub_sum = 0;

        for (const auto& num : nums) {
            if (sub_sum < 0) {
                sub_sum = 0;
            }
            sub_sum += num;
            res = std::max(res, sub_sum);
        }

        return res;
    }
};

int main(int argc, char const* argv[]) {

    Solution sol;
    std::vector<int> nums = {-2, -1};

    // int res = sol.maxSubArray(nums);
    std::cout << sol.maxSubArray(nums) << "\n";

    return 0;
}

// int maxSubArray(std::vector<int>& nums) {
//     if (nums.size() == 1) return nums[0];

//     int pre_sums = 0;
//     int min_pre_sums = INT16_MAX, max_pre_sums = INT16_MIN;
//     int min_index = 0, max_index = 0;
//     int res = 0;

//     for (int i = 0; i < nums.size(); ++i) {
//         if (pre_sums < min_pre_sums) {
//             min_pre_sums = pre_sums;
//             min_index = i;
//         } else if (pre_sums > max_pre_sums) {
//             max_pre_sums = pre_sums;
//             max_index = i;
//         }
//         pre_sums += nums[i];
//     }

//     for (int i = min_index; i <= max_index; ++i) {
//         if (i == max_index) {
//             res += (nums[i] > 0 ? nums[i] : 0);
//         } else {
//             res += nums[i];
//         }
//     }

//     if (max_index < min_index) {
//         return (nums[nums.size()-1] > 0 ? nums[min_index] : nums[max_index]);
//     }
//     return res;
// }
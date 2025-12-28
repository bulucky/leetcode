#include <vector>
#include <iostream>

class Solution {
public:
    // liudahu
    int firstMissingPositive(std::vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return res + 1;
    }
};

int main(int atgc, char const* argv[]) {
    Solution sol;

    std::vector<int> nums = {-2147483648};
    int res = sol.firstMissingPositive(nums);
    std::cout << res << "\n";

    return 0;
}

// // 结果只能在1~nums.size()
// // 存储nums所有正整数,从1开始遍历存储正整数,若存在则结果只能是存在数+1
// int firstMissingPositive(std::vector<int>& nums) {
//     std::unordered_map<int, int> positive_map;
//     int res = 1;
//     for (const auto& num : nums) {
//         if (num > 0 && num <= nums.size()) {
//             positive_map[num] = num;
//         }
//     }

//     for (int i = 0; i < positive_map.size(); ++i) {
//         if (positive_map.find(res) != positive_map.end()) {
//             ++res;
//         }
//     }

//     return res;
// }
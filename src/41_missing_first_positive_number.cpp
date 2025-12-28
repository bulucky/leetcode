#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    // 结果只能在1~nums.size()
    // 存储nums所有正整数,从1开始遍历存储正整数,若存在则结果只能是存在数+1
    int firstMissingPositive(std::vector<int>& nums) {
        std::unordered_map<int, int> positive_map;
        int res = 1;
        for (const auto& num : nums) {
            if (num > 0 && num <= nums.size()) {
                positive_map[num] = num;
            }
        }

        for (int i = 0; i < positive_map.size(); ++i) {
            if (positive_map.find(res) != positive_map.end()) {
                ++res;
            }
        }

        return res;
    }
};

int main(int atgc, char const* argv[]) {
    Solution sol;

    std::vector<int> nums = {7, 8, 9, 11, 12};
    int res = sol.firstMissingPositive(nums);
    std::cout << res << "\n";

    return 0;
}
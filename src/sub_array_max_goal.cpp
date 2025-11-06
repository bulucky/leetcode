#include <vector>
#include <iostream>
#include <unordered_set>

class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        std::unordered_set<int> window;
        int res = 0;
        int sums = 0;

        for(int left = 0, right = 0; right < nums.size(); ++right) {
            while(left < right && window.count(nums[right])) {
                window.erase(nums[left]);
                ++left;
            }
            window.insert(nums[right]);
            sums = 0;
            for(const auto& num : window) {
                sums += num;
            }
            res = std::max(res, sums);
        }

        return res;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;

    std::vector<int> nums = {5,2,1,2,5,2,1,2,5};
    int res = sol.maximumUniqueSubarray(nums);
    std::cout << res << std::endl;

    return 0;
}

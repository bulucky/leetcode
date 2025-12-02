#include "vector"
#include "unordered_map"

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int res = 0;
        int pre_sums = 0;
        std::unordered_map<int, int> pre_hash = {{0, 1}};

        // 前缀和
        for(const auto& num : nums) {
            pre_sums += num;
            if(pre_hash[pre_sums-k]) {
                res += pre_hash[pre_sums-k];
            }
            pre_hash[pre_sums]++;
        }

        return res;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    std::vector<int> nums = {1,1,1};
    int k = 2;

    int res = sol.subarraySum(nums, k);

    return 0;
}
#include <vector>
#include <algorithm>

class Solution {
public:
    // timeout
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> res;
        for(int i = 0; i <= nums.size()-k; ++i) {
            std::vector<int> win;
            for(int j = i; j < i+k; ++j) {
                win.emplace_back(nums[j]);
            }
            std::sort(win.begin(), win.end());
            res.emplace_back(win[k-1]);
        }

        return res;
    }
};

int main(int argc, char const* argv[]) 
{
    Solution sol;
    std::vector<int> nums = {1};
    int k = 1;

    std::vector<int> res = sol.maxSlidingWindow(nums, k);

    return 0;
}
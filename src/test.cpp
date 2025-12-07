#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> ans = nums;

        for(int i = 0, j = 0; j < n; i += 2, j += 1) {
            ans[i] = nums[j];
            ans[i+1] = nums[j+n];
        }
        // std::max(const Tp &a, const Tp &b)
        return ans;
    }
};

int main(int argc, char const* argv[])
{
    // Solution sol;
    // std::vector<int> nums = {2,5,1,3,4,7};
    
    // std::vector<int> res = sol.shuffle(nums, 3);
    int a = 2;
    while((--a) > 0) {
        std::cout << a << "\n";
    }

    return 0;
}
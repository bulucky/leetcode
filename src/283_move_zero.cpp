#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        if(nums.size() == 0) return;

        for(int f_r = 0, f_l = 0; f_r < nums.size(); ++f_r) {
            if(nums[f_r]) {
                int temp = nums[f_r];
                nums[f_r] = nums[f_l];
                nums[f_l] = temp;
                ++f_l;
            }
        }
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;

    std::vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);

    return 0;
}
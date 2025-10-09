#include <vector>
#include <iostream>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        
        if(nums.size() == 0) return 0;
        
        std::vector<int> nums_temp;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != val) {
                nums_temp.emplace_back(nums[i]);
            }
        }

        nums.resize(nums_temp.size());
        nums = nums_temp;

        return nums.size();
    }
};

int main(int argc, char const* argv[])
{
    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    
    Solution sol;
    std::cout << sol.removeElement(nums, 2) << std::endl;

    return 0;
}
#include <vector>
#include <iostream>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int index = -1;
        for(const auto& num : nums) {
            if(num < target) {
                index++;
            }
        }
        return index+1;
    }
};

int main(int argc, char const* argv[]) 
{
    Solution sol;

    std::vector<int> nums = {1,3,5,6};
    static const int target = 7;
    std::cout << sol.searchInsert(nums, target);

    return 0;
}
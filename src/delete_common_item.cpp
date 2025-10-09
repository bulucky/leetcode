#include <map>
#include <vector>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int num = 0;
        std::map<int, int> nums_map;
        
        for(int i = 0; i < nums.size(); ++i) {
            nums_map.insert({nums[i], nums[i]});
        }

        num = nums_map.size();
        nums.resize(0);

        for(const auto& pair : nums_map) {
            int num = pair.first;
            nums.push_back(num);
        }

        return num;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    
    int num = sol.removeDuplicates(nums);
    for(int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << std::endl;
    }

    return 0;
}
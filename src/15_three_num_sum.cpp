#include <vector>
#include <algorithm>

class Solution {
public:
    // liudahu
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        
        for(int a = 0; a < nums.size(); ++a) {
            if(a > 0 && nums[a] == nums[a-1]) {
                continue;
            }
            // 通过先确定一个数简化条件, 进而使用双指针
            for(int l = a+1, r = nums.size()-1; l < r;) {
                if(nums[a] + nums[l] + nums[r] == 0) {
                    res.emplace_back(std::vector<int>{nums[a], nums[l], nums[r]});
                    ++l;
                    while(l < r && nums[l] == nums[l-1]) {
                        ++l;
                    }
                }else if(nums[a] + nums[l] + nums[r] < 0) {
                    ++l;
                }else if(nums[a] + nums[l] + nums[r] > 0) {
                    --r;
                }
            }
        }

        return res;
    }
}; 

int main(int argc, char const* argv[])
{
    Solution sol;
    
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> res = sol.threeSum(nums);

    return 0;
}
#include <vector>
#include <iostream>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        int res = 0;
        std::unordered_set<int> uset_nums;
        for(const auto& num : nums) {
            uset_nums.emplace(num);
        }

        for(const auto& num : uset_nums) {
            // num前无连续元素,即序列开始
            if(uset_nums.find(num-1) == uset_nums.end()) {
                int len = 0;
                // 向后寻找连续元素
                while(uset_nums.find(num+len) != uset_nums.end()) {
                    ++len;
                }

                res = std::max(res, len);
            }
        }

        return res;
    }
    // // myself
    // int longestConsecutive(std::vector<int>& nums) {
    //     std::map<int, int> nums_map;
    //     int res = 0;
        
    //     for(const auto& num : nums) {
    //         nums_map.insert({num, num});
    //     }

    //     const auto iter = nums_map.begin();
    //     if(iter == nums_map.end()) return 0;

    //     int pre = (*iter).first;  
    //     int count = 1;
    //     bool one = true;

    //     for(const auto& pair : nums_map) {
    //         if(one) {
    //             one = false;
    //         }else {
    //             if(pair.first - pre == 1) {
    //                 pre = pair.first;
    //                 count++;
    //             }else {
    //                 count = 1;
    //                 pre = pair.first;
    //             }
    //         }
    //         res = std::max(res, count);
    //     }

    //     return res;
    // }
};

int main(int argc, char const* arg[])
{
    Solution sol;

    std::vector<int> nums = {100,4,200,1,3,2};
    int res = sol.longestConsecutive(nums);

    std::cout << res << std::endl;
    return 0;
}
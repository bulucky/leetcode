#include <chrono>
#include <vector>
#include <iostream>

using namespace std::chrono_literals;

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
    auto start = std::chrono::high_resolution_clock::now();
    int ret = sol.searchInsert(nums, target);
    auto end = std::chrono::high_resolution_clock::now();

    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << ret << "\n" <<"duration time: " << dur.count() << std::endl;

    return 0;
}
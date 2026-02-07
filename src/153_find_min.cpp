#include <vector>
#include <iostream>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[mid] && nums[right] < nums[mid]) {
                left = mid;
            } else if (nums[left] > nums[mid] && nums[right] > nums[mid]) {
                right = mid;
            } else {
                break;
            }
        }

        return std::min(nums[left], nums[right]);
    }
};

int main(int argc, char const* argv[]) {
    Solution* sol = new Solution();

    std::vector<int> nums = {3, 1, 2};
    int res = sol->findMin(nums);

    std::cout << res << "\n";

    return 0;
}
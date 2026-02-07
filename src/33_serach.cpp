#include <vector>
#include <memory>
#include <iostream>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[right] >= target && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const* argv[]) {
    std::unique_ptr<Solution> sol;

    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int res = sol->search(nums, 3);

    std::cout << res << "\n";

    return 0;
}
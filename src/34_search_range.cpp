#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return std::vector<int>{-1, -1};
        }

        std::vector<int> res{-1, -1};

        int left_1 = 0;
        int right_1 = nums.size() - 1;
        while (left_1 <= right_1) {
            int mid = left_1 + (right_1 - left_1) / 2;
            if (nums[mid] == target) {
                while (mid != 0 && nums[mid - 1] == target) {
                    --mid;
                }
                res[0] = mid;
                int left_2 = mid;
                int right_2 = nums.size() - 1;
                while (left_2 <= right_2) {
                    int mid = left_2 + (right_2 - left_2) / 2;
                    if (nums[mid] == target) {
                        while (mid != nums.size() - 1 && nums[mid + 1] == target) {
                            ++mid;
                        }
                        res[1] = mid;
                        return res;

                    } else if (nums[mid] > target) {
                        right_2 = mid - 1;
                    } else {
                        left_2 = mid + 1;
                    }
                }
            } else if (nums[mid] > target) {
                right_1 = mid - 1;
            } else {
                left_1 = mid + 1;
            }
        }

        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution sol;

    std::vector<int> nums = {5, 7, 7, 8, 8, 10};

    std::vector<int> res = sol.searchRange(nums, 6);
    for (const auto& a_res : res) {
        std::cout << a_res << "\n";
    }

    return 0;
}
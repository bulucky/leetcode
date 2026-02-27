#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int area = (right - left) * std::min(height[right], height[left]);
            res = std::max(res, area);
            // 移动短板
            if (height[left] < height[right]) ++left;
            else
                --right;
        }

        return res;
    }
    // int maxArea(std::vector<int>& height) {
    //     int res = 0;
    //     int left = 0;
    //     int right = height.size() - 1;
    //     while(right) {
    //         while(left < right) {
    //             int area = (right - left) * std::min(height[right], height[left]);
    //             res = std::max(res, area);
    //             ++left;
    //         }
    //         left = 0;
    //         --right;
    //     }

    //     return res;
    // }
};

int main(int argc, char const* argv[]) {
    Solution sol;

    std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // 2,3,4,5,18,17,6
    int res = sol.maxArea(heights);
    std::cout << res << "\n";

    return 0;
}
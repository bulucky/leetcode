#include <vector>
#include <iostream>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int index = m + n - 1;
        int i = m - 1, j = n - 1;

        while(i >= 0 && j >= 0) {
            if(nums1[i] >= nums2[j]) nums1[index--] = nums1[i--];
            else nums1[index--] = nums2[j--];
        }

        while(j >= 0) {
            nums1[index--] = nums2[j--];
        }
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    
    std::vector<int> nums1 = {-1,0,0,3,3,3,0,0,0};
    std::vector<int> nums2 = {1,2,2};

    sol.merge(nums1, 6, nums2, 3);

    for(const auto& num : nums1) {
        std::cout << num << std::endl;
    }
    
    return 0;
}
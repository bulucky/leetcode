#include <vector>
#include <iostream>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        int max_l = height[l], max_r = height[r];
        int water = 0;

        while(l <= r) {
            bool is_l_min = false;
            int min = 0;
            for(int i = 0; i < l; ++i) {
                max_l = std::max(max_l, height[i]);
            }
            for(int i = (height.size()-1); i > r; --i) {
                max_r = std::max(max_r, height[i]);
            }
            
            if(max_l < max_r) {
                min = max_l;
                is_l_min = true;
            }else {
                min = max_r;
                is_l_min = false;
            }
            
            if(is_l_min) {
                water = min - height[l];
                 ++l;
            }else{
                water = min - height[r];
                --r;
            } 
            if(water < 0) water = 0;
            res += water;
        }

        return res;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;

    std::vector<int> height = {2,0,2};
    int res = sol.trap(height);
    std::cout << res << std::endl;

    return 0;
}
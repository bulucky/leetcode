#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vc = {0, 0};
        size_t index_1;
        bool is_res = false;
        for(size_t i = 0; i < nums.size(); ++i) {
            index_1 = i;
            for(size_t i = index_1+1; i < nums.size(); ++i) {
                if(nums[index_1] + nums[i] == target) {
                    vc[0] = index_1;
                    vc[1] = i;
                    is_res = true;
                }
                if(is_res) break;
            }
            if(is_res) break;
        }
        return vc;
    }
};

int main(int argc, char const* argv[])
{
    vector<int> vc_t = {3,2,4};
    Solution sol;
    vector<int> vc_r = sol.twoSum(vc_t, 6);

    std::cout << vc_r[0] << vc_r[1] << std::endl;
    
    return 0;
}
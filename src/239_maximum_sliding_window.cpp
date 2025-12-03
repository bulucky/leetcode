#include <deque>
#include <vector>

class Solution {
public:
    // timeout
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> res;
        std::deque<int> dq;
        
        for(int i = 0; i < k; ++i) {
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.emplace_back(nums[dq.front()]); 
        
        for(int i = k; i < nums.size(); ++i) {
            while(!dq.empty() && dq.front() < i-k+1) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            res.emplace_back(nums[dq.front()]);
        }
    
        return res;
    }
};

int main(int argc, char const* argv[]) 
{
    Solution sol;
    std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    std::vector<int> res = sol.maxSlidingWindow(nums, k);

    return 0;
}

// std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
//     std::vector<int> res;
//     for(int i = 0; i <= nums.size()-k; ++i) {
//         std::vector<int> win;
//         for(int j = i; j < i+k; ++j) {
//             win.emplace_back(nums[j]);
//         }
//         std::sort(win.begin(), win.end());
//         res.emplace_back(win[k-1]);
//     }

//     return res;
// }
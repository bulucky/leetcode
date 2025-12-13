#include <deque>
#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int k_size = k % nums.size();
        std::deque<int> d_nums;

        d_nums.assign(nums.begin(), nums.end());
        std::deque<int> nums_k;

        while (--k_size >= 0) {
            nums_k.emplace_front(d_nums.back());
            d_nums.pop_back();
        }

        k_size = k % nums.size();
        while (--k_size >= 0) {
            d_nums.emplace_front(nums_k.back());
            nums_k.pop_back();
        }

        nums.assign(d_nums.begin(), d_nums.end());
    }
};

int main(int argc, char const* argv[]) {
    Solution sol;
    std::vector<int> nums = {1, 2};
    int k = 7;

    sol.rotate(nums, k);

    return 0;
}
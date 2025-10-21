#include <cmath>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        size_t nums = 1;
        for(int i = 0; i < digits.size(); ++i) {
            nums += (digits[i] * std::pow(10, digits.size()-1-i));
        }

        std::string nums_str = std::to_string(nums);
        std::vector<int> digits_one;
        
        for(const auto& num : nums_str) {
            digits_one.emplace_back(num-48);
        }

        return digits_one;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    std::vector<int> digits = {6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3};

    std::vector<int> ret_digits = sol.plusOne(digits);

    for(const auto& digit : ret_digits) {
        std::cout << digit;
    }

    return 0;

}
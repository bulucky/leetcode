#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        std::vector<int> nums;
        
        int index = 0;
        bool one_flag = false;
        for(const auto& c: s) {
            if(c != ' ') {
                index++;
                one_flag = false;
            }else if(!one_flag) {
                one_flag = true;
                nums.emplace_back(index);
                index = 0;
            }
            if(index != 0) {
                nums.emplace_back(index);
            }
        }

        nums[0] = nums[nums.size()-1];
        
        return nums[0];
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    std::string s = "   fly me   to   the moon  ";

    std::cout << sol.lengthOfLastWord(s) << std::endl;

    return 0;
}
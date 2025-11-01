#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> window;
        int length = 0;
        int res = 0;
        
        for(int left = 0, right = 0; right < s.size(); ++right) {
            while(left < right && window.count(s[right])) {
                window.erase(s[left]);
                ++left;
                --length;
            }
            window.insert(s[right]);
            ++length;
            res = std::max(res, length);
        }
        
        return res;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;

    std::string s = "pwwkew";
    int res = sol.lengthOfLongestSubstring(s);

    std::cout << res << std::endl;

    return 0;
}


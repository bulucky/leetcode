#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, char> hash_map;
        std::vector<int> sizes;

        char pre_char = '\0';
        for(int i = 0; i < s.size(); ++i) {
            if(hash_map.find(s[i]) == hash_map.end()) {
                hash_map.insert({s[i], s[i]});
                pre_char = s[i];
            }else {
                sizes.emplace_back(hash_map.size());
                hash_map.clear();
                if(pre_char == s[i]) {
                    hash_map.insert({s[i], s[i]});
                }
            }
        }
        sizes.emplace_back(hash_map.size());

        int max_size = sizes[0];
        for(const auto& size : sizes) {
            if(size > max_size) max_size = size;
        }

        return max_size;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;

    std::string s = "dvdf";
    int res = sol.lengthOfLongestSubstring(s);

    std::cout << res << std::endl;

    return 0;
}

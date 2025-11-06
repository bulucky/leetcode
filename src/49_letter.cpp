#include <map>
#include <string>
#include <vector>
// #include <iostream>


class Solution {
public:
    // timeout
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res;
        bool new_flag = true;

        for(const auto& str : strs) {
            new_flag = true;
            for(int i = 0; i < res.size(); ++i) {
                if(is_equal_map(res[i][0], str)) {
                    res[i].emplace_back(str);
                    new_flag = false;
                    break;
                }
            }
            if(new_flag) {
                res.resize(res.size()+1);
                res[res.size()-1].emplace_back(str);
            }
        }

        return res;
    }

    bool is_equal_map(const std::string res,const std::string str) {
        std::multimap<char, char> res_map;
        std::multimap<char, char> str_map;

        for(const auto& c : res) {
            res_map.insert({c, c});
        }
        for(const auto& c : str) {
            str_map.insert({c, c});
        }

        return res_map == str_map;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;

    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> res;

    res = sol.groupAnagrams(strs);
    // std::string a = "aat";
    // std::string b = "aet";

    // std::cout << sol.is_equal_map(a, b) << std::endl;

    return 0;
}
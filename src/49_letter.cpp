#include <string>
#include <vector>
#include <unordered_map>
// #include <iostream>


class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res; 
        // key(00..0)--val(str)
        std::unordered_map<std::string, std::vector<std::string>> str_map;

        for(const auto& str : strs) {
            // 统计str中字符出现的次数作为key
            // 若str == eat, 则count结果为(100010000000000000010000000000)
            std::string count(26, 0);
            for(const auto& c : str) {
                count[c - 'a'] += 1;
            }
            // 将其key对应str存入hash
            str_map[count].push_back(str);
        }

        for(const auto& pair : str_map) {
            res.emplace_back(pair.second);
        }
        
        return res;
    }
    // // timeout
    // std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    //     std::vector<std::vector<std::string>> res;
    //     bool new_flag = true;

    //     for(const auto& str : strs) {
    //         new_flag = true;
    //         for(int i = 0; i < res.size(); ++i) {
    //             if(is_equal_map(res[i][0], str)) {
    //                 res[i].emplace_back(str);
    //                 new_flag = false;
    //                 break;
    //             }
    //         }
    //         if(new_flag) {
    //             res.resize(res.size()+1);
    //             res[res.size()-1].emplace_back(str);
    //         }
    //     }

    //     return res;
    // }

    // bool is_equal_map(const std::string res,const std::string str) {
    //     std::multimap<char, char> res_map;
    //     std::multimap<char, char> str_map;

    //     for(const auto& c : res) {
    //         res_map.insert({c, c});
    //     }
    //     for(const auto& c : str) {
    //         str_map.insert({c, c});
    //     }

    //     return res_map == str_map;
    // }
};

int main(int argc, char const* argv[])
{
    Solution sol;

    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> res;

    res = sol.groupAnagrams(strs);

    return 0;
}
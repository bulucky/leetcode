#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string str_prefix;
        int min_str = strs[0].size();

        // 获取字符串数组中最短字符串作为判断长度
        for(int i = 0; i < strs.size(); ++i) {
            if(strs[i].size() < min_str) min_str = strs[i].size();
        }
        if(min_str == 0) {
            str_prefix = "";
        }else {
            // 公共前缀只判断最短字符串长度即可
            for(int i = 0; i < min_str; ++i) {
                // 假设数组中第一个字符串字符存在公共前缀
                bool is_prefix = true;
                char prefix = strs[0][i];
                // 将其与数组中剩余字符串的字符进行比较
                for(int j = 1; j < strs.size(); ++j) {
                    if(prefix != strs[j][i]) is_prefix = false;
                }
                // 出现不一致即退出循环不再判断后续
                if(is_prefix) str_prefix.push_back(prefix);
                else break;
            }
        }

        return str_prefix;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    std::vector<std::string> strs = {"flower","flow","flight"};
    // std::cout << strs.size() << std::endl;
    std::cout << sol.longestCommonPrefix(strs) << std::endl;

    return 0;
}
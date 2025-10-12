#include <chrono>
#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // 用于记录所有haystack首字符匹配索引
        std::vector<int> indexs;
        int r_index = -1; 
        
        if(!needle.size()) {
            return r_index;
        }

        char head = needle[0];
        // 记录所有索引
        for(int i = 0; i < haystack.size(); ++i) {
            if(haystack[i] == head) {
                indexs.emplace_back(i);
            }
        }
        
        // 未找到索引
        if(!indexs.size()) {
            return r_index;
        }

        // 存在索引, 依次比较, 以needle为标准
        for(auto& index : indexs) {
            for(int j = 0; j < needle.size(); ++j) {
                if(haystack[index+j] != needle[j]) {
                    index = -1;
                    break;
                }
            }    
        }

        for(const auto& index: indexs) {
            if(index != -1) {
                r_index = index;
                break;
            }
        }

        return r_index;
    }
};

int main(int argc, char const* argv[]) 
{
    Solution sol;
    std::string haystack = "mississippi", needle = "issip";

    auto start = std::chrono::high_resolution_clock::now();
    int ret = sol.strStr(haystack, needle);
    auto end = std::chrono::high_resolution_clock::now();

    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << ret << "\n" <<"duration time: " << dur.count() << std::endl;

    return 0;
}
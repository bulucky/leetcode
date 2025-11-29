#include "vector"
#include "string"
#include "unordered_map"

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> res;
        int l = 0, r = 0;
        std::unordered_map<char, int> window, map_p;
        int match_count = 0;

        for(const auto& c : p) {
            map_p[c]++;
        }

        // 维护match_count
        while(r < s.size()) {
            char c_r = s[r];
            ++r;
            // 异位词字符
            if(map_p.count(c_r)) {
                window[c_r]++;
                // 字符数量一致
                if(map_p[c_r] == window[c_r]) {
                    ++match_count;
                }
            }

            // 窗口大小等于异位词个数
            if(r - l == p.size()) {
                // 判断是否属于异位词
                if(match_count == map_p.size()) {
                    res.emplace_back(l);
                }
                // 滑动窗口
                char c_l = s[l];
                ++l;
                if(map_p.count(c_l)) {
                    if(map_p[c_l] == window[c_l]) {
                        --match_count;
                    }
                    window[c_l]--;
                }
            }
        }
        
        return res;
    }
};

int main(int argc, char const* argv[]) 
{
    Solution sol;
    std::string s = "baa";
    std::string p = "aa";

    std::vector<int> res = sol.findAnagrams(s, p);

    return 0;
}

// // timeout
// class Solution {
// public:
//     std::vector<int> findAnagrams(std::string s, std::string p) {
//         std::vector<int> res;
//         int num = p.size();
//         int l = 0, r = l + num;
//         std::map<std::string, std::string> map_p = {{p, p}};

//         while(r <= s.size()) {
//             std::string sub_s;
//             for(int i = l; i < r; ++i) {
//                 sub_s += s[i];
//             }
//             std::sort(sub_s.begin(), sub_s.end());
//             // 属于异位词
//             if(map_p.find(sub_s) != map_p.end()) {
//                 res.emplace_back(l);
//             }
//             ++l;
//             ++r;
//         }

//         return res;
//     }
// };
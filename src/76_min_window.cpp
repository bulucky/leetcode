#include <chrono>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    // liudahu
    std::string minWindow(std::string &s, std::string &t) {
        if (!s.size() || !t.size()) {
            return "";
        }

        std::unordered_map<char, int> match_c;
        std::unordered_map<char, int> win_c;
        for (const auto &c : t) {
            ++match_c[c];
        }
        int l = 0, r = 0;
        int start = 0, sub_len = INT_MAX;
        int match_size = match_c.size();
        int win_size = 0;

        while (r < s.size()) {
            if (match_c.count(s[r])) {
                ++win_c[s[r]];
                if (match_c[s[r]] == win_c[s[r]]) {
                    ++win_size;
                }
            }
            while (win_size == match_size) {
                if (r - l + 1 < sub_len) {
                    sub_len = r - l + 1;
                    start = l;
                }
                if (match_c.count(s[l])) {
                    --win_c[s[l]];
                    if (match_c[s[l]] > win_c[s[l]]) {
                        --win_size;
                    }
                }
                ++l;
            }
            ++r;
        }

        if (sub_len == INT_MAX) return "";
        return s.substr(start, sub_len);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    std::string s = "aa";
    std::string t = "aa";

    auto start_time = std::chrono::steady_clock::now();
    std::string res = sol.minWindow(s, t);
    auto end_time = std::chrono::steady_clock::now();

    auto ms = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "run time =" << ms.count() << "\n";

    return 0;
}

// std::string minWindow(std::string& s, std::string& t) {
//     std::unordered_map<char, int> match_c;
//     std::unordered_map<char, int> win_c;
//     std::string res = s;
//     std::string temp_res;
//     bool sub_s_flag = false;
//     int l = 0, r = 0;
//     int match_size = t.size();
//     int win_size = 0;

//     if(t.size() > s.size()) return "";
//     else if(s.size() == t.size()) {
//         std::string temp_s = s;
//         std::string temp_t = t;
//         std::sort(temp_s.begin(), temp_s.end());
//         std::sort(temp_t.begin(), temp_t.end());
//         if(temp_s != temp_t) {
//             sub_s_flag = true;
//             return "";
//         }
//     }

//     for(const auto& c : t) {
//         match_c[c]++;
//     }

//     while(r < s.size()) {
//         if(match_c.count(s[r])) {
//             win_c[s[r]]++;
//             win_size = 0;
//             for(const auto& c : t) {
//                 if(win_c[c] >= match_c[c]) {
//                     ++win_size;
//                 }
//             }
//         }
//         while(win_size == match_size && l <= r) {
//             temp_res.assign(s.begin()+l, s.begin()+1+r);
//             if(temp_res.size() <= res.size()) {
//                 res = temp_res;
//                 sub_s_flag = true;
//             }
//             if(match_c.count(s[l])) {
//                 if((--win_c[s[l]]) < match_c[s[l]]) {
//                     --win_size;
//                     ++l;
//                     break;
//                 }
//             }
//             ++l;
//         }
//         ++r;
//     }

//     if(!sub_s_flag) res = "";
//     return res;
// }
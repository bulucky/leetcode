#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string& s, std::string& t) {
        if(t.size() > s.size()) return "";

        std::unordered_map<char, int> match_c;
        std::unordered_map<char, int> win_c;
        std::string res = s;
        std::string temp_res;
        int l = 0, r = 0;
        int match_size = t.size();
        int win_size = 0;

        for(const auto& c : t) {
            match_c[c]++;
        }

        while(r < s.size()) {
            if(match_c.count(s[r])) {
                win_c[s[r]]++;
                win_size = 0;
                for(const auto& c : t) {
                    if(win_c[c] >= 1) {
                        ++win_size;
                    }
                }
            }
            while(win_size == match_size && l < r) {
                temp_res.assign(s.begin()+l, s.begin()+1+r);
                if(temp_res.size() < res.size()) {
                    res = temp_res;
                }
                if(match_c.count(s[l])) {
                    if((--win_c[s[l]]) < 1) {
                        --win_size;
                        ++l;
                        break;
                    } 
                }
                ++l;
            }
            ++r;
        }

        return res;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    std::string s = "a";
    std::string t = "aa";

    std::string res = sol.minWindow(s, t);

    return 0;
}
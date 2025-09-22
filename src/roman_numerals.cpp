#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        int s_int = 0;
        std::vector<int> vc;
        std::unordered_map<char, int> roman_num_map;
        roman_num_map.insert({'I', 1});
        roman_num_map.insert({'V', 5});
        roman_num_map.insert({'X', 10});
        roman_num_map.insert({'L', 50});
        roman_num_map.insert({'C', 100});
        roman_num_map.insert({'D', 500});
        roman_num_map.insert({'M', 1000});

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'X' || s[i] == 'C' || s[i] == 'I') {
                if(s[i] == 'I') {
                    if(i < s.size()) {
                        if(s[i+1] == 'V' || s[i+1] == 'X') {
                            if(s[i+1] == 'V') {
                                s_int += 4;
                            }else if(s[i+1] == 'X') {
                                s_int += 9;
                            }
                            vc.emplace_back(i);
                            vc.emplace_back(i+1);
                        }
                    }
                }else if(s[i] == 'X') {
                    if(i < s.size()) {
                        if(s[i+1] == 'L' || s[i+1] == 'C') {
                            if(s[i+1] == 'L') {
                                s_int += 40;
                            }else if(s[i+1] == 'C') {
                                s_int += 90;
                            }
                            vc.emplace_back(i);
                            vc.emplace_back(i+1);
                        }
                    }
                }else if(s[i] == 'C') {
                    if(i < s.size()) {
                        if(s[i+1] == 'D' || s[i+1] == 'M') {
                            if(s[i+1] == 'D') {
                                s_int += 400;
                            }else if(s[i+1] == 'M') {
                                s_int += 900;
                            }
                            vc.emplace_back(i);
                            vc.emplace_back(i+1);
                        }
                    }
                }
            }
        }
        for(int i = 0; i < s.size(); ++i) {
            bool s_ok = true;
            if(vc.size()) {
                for(int j = 0; j < vc.size(); ++j) {
                    if(i == vc[j]) {
                        s_ok = false;
                    }
                }
                if(s_ok) {
                    s_int += roman_num_map[s[i]];
                } 
            }else {
                s_int += roman_num_map[s[i]];
            }
        }
        return s_int;
    }
};

int main(int argc, char const* argv[]) 
{
    std::string s = "III";
    Solution sol;
    std::cout << sol.romanToInt(s) << std::endl; 
    return 0;
}
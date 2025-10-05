#include <deque>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool is_valid = true;
        std::deque<char> deq;
        std::unordered_map<char, char> paren_map;
        paren_map.insert({'(', ')'});
        paren_map.insert({'{', '}'});
        paren_map.insert({'[', ']'});
        
        std::unordered_map<char, int> char_index;

        // 字符个数为奇数, false
        if(s.size() % 2 != 0) {
            is_valid = false;
        }else {

            for(int i = 0; i < s.size(); ++i) {
                char_index.insert({s[i], i});
            }
            for(int i = 0; i < s.size(); ++i) {
                
                int c_index = 0;
                if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                    char c_pair = paren_map[s[i]];
                    if(char_index.count(c_pair) == 0) {
                        is_valid = false;
                        break;
                    }else if(char_index.count(c_pair) >= 1) {
                        for(int j = 0; j < char_index.count(c_pair); ++j) {
                            c_index = char_index[paren_map[s[i]]];
                        }
                    }
                }
                
                
                if(((c_index - i) % 2 == 1 ) && i < c_index) {
                    is_valid = true;
                }else {
                    is_valid = false;
                    // break;
                }
            }
        }

        return is_valid;
    }
};

int main(int argc, char const* argv[]) 
{
    // std::string s = "hello";
    // std::deque<char> deq;
    // for(int i = 0; i < s.size(); ++i) {
    //     deq.emplace_back(s[i]);
    // } 
    // char f_c = s.front();
    // char f_i = s.back();
    
    // std::cout << f_c << f_i << std::endl;


    Solution sol;
    std::string s = "(([]){})";

    std::cout << sol.isValid(s) << std::endl;

    // std::unordered_map<char, char> paren_map;
    // paren_map.insert({'(', ')'});
    // paren_map.insert({'{', '}'});
    // paren_map.insert({'[', ']'});

    // std::cout << paren_map['('] << std::endl;

    return 0;
}
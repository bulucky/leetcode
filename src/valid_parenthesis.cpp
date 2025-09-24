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

        // 字符个数为奇数, false
        if(s.size() % 2 != 0) {
            is_valid = false;
        }else {
            for(int i = 0; i < s.size(); ++i) {
                deq.emplace_back(s[i]);
            }
            for(int i = 0; i < s.size()/2; ++i) {   
                char f_c_1 = deq.front(); deq.pop_front();
                char i_c_1 = deq.back(); deq.pop_back();
                if(paren_map[f_c_1] != i_c_1) {
                    if(i+1 < s.size()/2) {
                        char f_c_2 = deq.front(); deq.pop_front();
                        char i_c_2 = deq.back(); deq.pop_back();
                        if((paren_map[f_c_1] != f_c_2) || (paren_map[i_c_2] != i_c_1)) {
                            is_valid = false;
                        }
                        break;
                    }
                    is_valid = false;
                    break;
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
    std::string s = "()[]";

    std::cout << sol.isValid(s) << std::endl;

    // std::unordered_map<char, char> paren_map;
    // paren_map.insert({'(', ')'});
    // paren_map.insert({'{', '}'});
    // paren_map.insert({'[', ']'});

    // std::cout << paren_map['('] << std::endl;

    return 0;
}
#include <stack>
#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string& s) {
        if (s.size() % 2 != 0) {
            return false;
        }

        std::unordered_map<char, char> brackets = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        std::stack<char> right_brackets;
        for (const auto& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                right_brackets.emplace(brackets[c]);
            } else {
                if (right_brackets.empty() || c != right_brackets.top()) {
                    return false;
                }
                right_brackets.pop();
            }
        }

        if (right_brackets.empty()) {
            return true;
        } else {
            return false;
        }
    }
};


int main(int argc, char const* argv[]) {
    std::string s = "){";

    Solution sol;
    bool res = sol.isValid(s);
    std::cout << res << "\n";

    return 0;
}
#include <stack>
#include <string>
#include <iostream>

class Solution {
public:
    std::string decodeString(std::string& s) {
        std::stack<std::string> stack_s;
        std::string res_s;

        for (const auto& c : s) {
            if (c != ']') {
                std::string temp;
                temp += c;
                stack_s.push(temp);
            } else {
                std::string temp_s;
                while (stack_s.top() != "[") {
                    temp_s.insert(0, stack_s.top());
                    stack_s.pop();
                }
                // '['
                stack_s.pop();
                std::string temp_num;
                while (!stack_s.empty() && std::isdigit(stack_s.top()[0])) {
                    temp_num.insert(0, stack_s.top());
                    stack_s.pop();
                }
                int cnt = std::stoi(temp_num);
                std::string temp_ss;
                while (cnt--) {
                    temp_ss += temp_s;
                }
                stack_s.push(temp_ss);
            }
        }

        while (!stack_s.empty()) {
            res_s.insert(0, stack_s.top());
            stack_s.pop();
        }
        return res_s;
    }
};

int main(int argc, char const* argv[]) {
    Solution sol;
    std::string s = "3[a2[c]]";
    // std::string s = "3[a]2[bc]";

    std::string res = sol.decodeString(s);
    std::cout << res << "\n";

    return 0;
}

// shit
// class Solution {
// public:
//     std::string decodeString(std::string& s) {
//         std::stack<int> nums;
//         std::stack<std::stack<std::string>> stack_strings;

//         bool is_close = false;
//         std::string s_s;
//         std::string res_s;

//         for (const auto& c : s) {
//             if (c >= 48 && c <= 57) {
//                 nums.push(c - 48);
//                 if (!stack_strings.empty()) {
//                     auto& stack_top = stack_strings.top();
//                     if (!s_s.empty()) {
//                         stack_top.push(s_s);
//                         s_s.clear();
//                     }
//                 }
//                 if (!is_close) {
//                     stack_strings.emplace();
//                 }
//             } else if (c == '[') {
//                 is_close = false;
//             } else if (c == ']') {
//                 is_close = true;
//                 auto& stack_top = stack_strings.top();
//                 if (!s_s.empty()) {
//                     stack_top.push(s_s);
//                     s_s.clear();
//                 }
//             } else {
//                 s_s += c;
//             }
//         }

//         if (!s_s.empty()) {
//             stack_strings.emplace();
//             auto& stack_top = stack_strings.top();
//             stack_top.push(s_s);
//             s_s.clear();
//         }

//         // shit
//         while (!nums.empty()) {
//             int num = nums.top();
//             nums.pop();

//             // std::string temp_s;
//             auto& stack_s = stack_strings.top();
//             if (!stack_s.empty()) {
//                 res_s.insert(0, stack_s.top());
//                 stack_s.pop();
//             }

//             while (--num) {
//                 res_s.insert(0, res_s);
//             }
//         }

//         return res_s;
//     }
// };
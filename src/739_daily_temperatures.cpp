#include <stack>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> res;
        std::stack<int> stack_i;
        stack_i.push(-1);
        for (int i = 0; i < temperatures.size(); ++i) {
            int j = i + 1;
            while (j < temperatures.size() && temperatures[i] >= temperatures[j]) {
                ++j;
            }
            // 直到结束未找到更高温度
            if (j == temperatures.size()) {
                res.push_back(0);
            } else {
                res.push_back(j - stack_i.top() - 1);
            }

            stack_i.push(i);
        }

        return res;
    }
};

int main(int argc, char const* argv[]) {

    Solution sol;
    // std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    // std::vector<int> temperatures = {30,40,50,60};
    // std::vector<int> temperatures = {30,60,90};
    std::vector<int> temperatures = {89,62,70,58,47,47,46,76,100,70};

    std::vector<int> res = sol.dailyTemperatures(temperatures);
    for (const auto& a_res : res) {
        std::cout << a_res << "\n";
    }

    return 0;
}
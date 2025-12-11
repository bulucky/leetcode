#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> res;

        std::sort(intervals.begin(), intervals.end(),
                  [](const std::vector<int>& front, const std::vector<int>& back) -> bool {
                      return back[0] > front[0];
                  });

        std::vector<int> pre_sub = {INT_MIN, INT_MIN};
        for (const auto& sub : intervals) {
            // 存在重叠区间
            if (sub[0] <= pre_sub[1]) {
                if (!res.size()) res.emplace_back(sub);
                if(sub[1] > pre_sub[1]) res[res.size() - 1][1] = sub[1];
                pre_sub = res[res.size()-1];
            } else {
                res.emplace_back(sub);
                pre_sub = sub;
            }
        }

        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution sol;

    // std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // std::vector<std::vector<int>> intervals = {{1, 4}, {0, 4}};
    std::vector<std::vector<int>> intervals = {{2,3},{4,5},{6,7},{8,9},{1,10}};
    // std::vector<std::vector<int>> intervals = {{1, 4}, {4, 5}};

    std::vector<std::vector<int>> res = sol.merge(intervals);

    return 0;
}
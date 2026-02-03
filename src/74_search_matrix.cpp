#include <vector>
#include <iostream>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            // 矩阵与矩阵拼接的一维数组的索引关系
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};

int main(int argc, char const* argv[]) {
    Solution sol;
    std::vector<std::vector<int>> matrix = {{1, 3, 5, 7},
                                            {10, 11, 16, 20},
                                            {23, 30, 34, 60}};
    
    bool res = sol.searchMatrix(matrix, 3);
    std::cout << res << "\n";

    return 0;
}

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.begin()->size();
        std::vector<int> result;

        for (int d = 0; d < m + n - 1; d++) {
            int row = (d < m) ? d : (m - 1);
            int col = d - row;
            while (row >= 0 && row < m && col < n) {
                std::cout << "matrix[" << row << "]"
                          << "[" << col << "]: "
                          << matrix[row][col] << "\n";
                row--, col++;
            }
            std::cout << std::endl;

            if (d % 2) {
                std::cout << "change direction" << std::endl;
            }
        }

        return result;
    }
};

void PrintVector(const std::vector<int> &nums) {
    for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20}
    };
    Solution solution;
    auto result = solution.findDiagonalOrder(matrix);
    PrintVector(result);

    return 0;
}

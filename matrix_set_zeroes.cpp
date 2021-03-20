#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.begin()->size();
        std::vector<int> rows, columns;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }
        for (auto i : rows) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
        for (auto i : columns) {
            for (int j = 0; j < m; j++) {
                matrix[j][i] = 0;
            }
        }
    }
};

int main(int argc, char const* argv[]) {
    std::vector<std::vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    std::vector<std::vector<int>> expect = {
        {0,0,0,0},
        {0,4,5,0},
        {0,3,1,0}
    };

    Solution solution;
    solution.setZeroes(matrix);
    if (matrix != expect) {
        return 1;
    }

    return 0;
}

#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.begin()->size();

        int first_row_has_zero = 0;
        int first_col_has_zero = 0;

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                first_row_has_zero = 1;
                break;
            }
        }

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                first_col_has_zero = 1;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (first_row_has_zero == 1) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if (first_col_has_zero == 1) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

struct TestData {
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> expected;
};

std::vector<TestData> TestCase() {
    return {
        {
            {
                {0,1,2,0},
                {3,4,5,2},
                {1,3,1,5}
            },
            {
                {0,0,0,0},
                {0,4,5,0},
                {0,3,1,0}
            }
        },
        {
            {
                {1,0,3}
            },
            {
                {0,0,0}
            }
        }
    };
}

int main(int argc, char const* argv[]) {
    Solution solution;
    for (auto &test : TestCase()) {
        solution.setZeroes(test.matrix);
        if (test.matrix != test.expected) {
            return 1;
        }
    }

    return 0;
}

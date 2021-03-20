#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        auto comp = [](const std::vector<int>& x, const std::vector<int>& y) {
             return x[0] < y[0];
        };
        std::sort(intervals.begin(), intervals.end(), comp);

        int last = -1;
        std::vector<std::vector<int>> merged;
        for (const auto& interval : intervals) {
            if (last < 0 || merged[last][1] < interval[0]) {
                merged.push_back(interval);
                last++;
            } else {
                merged[last][1] = std::max(merged[last][1], interval[1]);
            }
        }
        return merged;
    }
};

int main(int argc, char const* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> intervals = {{1,4},{2,3}};
    decltype(intervals) expect = {{1,4}};
    auto actual = solution.merge(intervals);
    if (actual != expect) {
        return 1;
    }
    return 0;
}

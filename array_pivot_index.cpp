#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }

        int left_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (left_sum == (sum - left_sum - nums[i])) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {-1,-1,-1,-1,-1,0};
    std::cout << solution.pivotIndex(nums) << std::endl;
    return 0;
}

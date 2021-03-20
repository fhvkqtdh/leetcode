#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int i = (left + right) / 2;
            if (nums[i] == target) {
                return i;
            } else if (nums[i] < target) {
                left = i + 1;
            } else {
                right = i;
            }
        }
        return right;
    }
};

int main(int argc, char const* argv[]) {
    int target = 7;

    if (argc > 1) {
        target = atoi(argv[1]);
    }

    Solution solution;
    std::vector<int> nums = {1,3,5,6};
    std::cout << solution.searchInsert(nums, target) << std::endl;
    return 0;
}

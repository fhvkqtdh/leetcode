#include <iostream>
#include <vector>

class Solution {
public:
    // 左右双指针, 依次找到绝对值最大的那一个
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> result;
        result.resize(nums.size());

        int left = 0;
        int right = result.size() - 1;
        int pos = right;
        while (left <= right) {
            if (abs(nums[left]) <= abs(nums[right])) {
                result[pos] = nums[right] * nums[right];
                right--;
            } else {
                result[pos] = nums[left] * nums[left];
                left++;
            }
            pos--;
        }

        return result;
    }
};

int main() {
    std::vector<int> nums = {-5,-3,-2,-1};
    std::vector<int> result = Solution().sortedSquares(nums);
    for (auto item : result) {
        std::cout << item << ", ";
    }
    return 0;
}

#include <iostream>
#include <vector>

// 重要的是区间的定义, 每一次边界的处理都要坚持根据区间的定义来操作
// 第一种: 全闭区间, [left, right]
// 第二种: 左开右闭, [left, right)

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid;
        while (left < right) {
            mid = (left + right - 1) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return -1;
    }
};

int main() {
    std::vector<int> nums = {-1,0,5};
    int result = Solution().search(nums, -1);
    std::cout << result << std::endl;
    return 0;
}

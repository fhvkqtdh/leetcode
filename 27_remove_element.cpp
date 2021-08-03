#include <iostream>
#include <vector>

class Solution {
public:
    // 左右双指针法
    int removeElement(std::vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }

        return right;
    }

    // 快慢指针法
    int removeElement2(std::vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

int main() {
    std::vector<int> nums = {2,2,3};
    int len = Solution().removeElement(nums, 2);
    std::cout << len << std::endl;
    return 0;
}

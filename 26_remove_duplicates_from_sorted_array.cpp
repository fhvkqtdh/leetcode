#include <iostream>
#include <vector>

class Solution {
public:
    // 快慢双指针法
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int slow = 0;
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                nums[++slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};

int main() {
    std::vector<int> nums = {1,2,2,2,3,3};
    int len = Solution().removeDuplicates(nums);
    std::cout << len << std::endl;
    return 0;
}

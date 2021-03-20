#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, size_t> records;
        size_t size = nums.size();
        for (size_t i = 0; i < size; i++) {
            int num = nums[i];
            auto iter = records.find(target - num);
            if (iter != records.end()) {
                result.push_back(iter->second);
                result.push_back(i);
                return result;
            }

            records.insert(std::make_pair(num, i));
        }
        return result;
    }

    void printResult(const vector<int> &result) {
        std::cout << "[";
        for (size_t i = 0; i != result.size(); i++) {
            std::cout << i;
            if (i != result.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2,7,11,15};
    int target = 9;
    std::vector<int> result;

    result = solution.twoSum(nums, target);
    solution.printResult(result);

    return 0;
}

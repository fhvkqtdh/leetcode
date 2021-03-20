#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s);
};

int Solution::lengthOfLongestSubstring(string s) {
    int pos[256];
    for (int i = 0; i < 256; i++) {
        pos[i] = -1;
    }

    int size = s.size();
    int max = 0;
    int i = -1;
    for (int j = 0; j < size; j++) {
        int c = s[j];
        if (pos[c] > i) {
            i = pos[c];
        } else if (j - i > max) {
            max = j - i;
        }

        pos[c] = j;
    }

    return max;
}

int main() {
    Solution solution;
    std::vector<std::string> data{
        "abcabcbb", "abcd", "pwwekw", "aab"
    };
    for (const auto &s : data) {
        int result = solution.lengthOfLongestSubstring(s);
        std::cout << s << ": " << result << std::endl;
    }

    return 0;
}

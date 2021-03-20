#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[256];
        for (int i = 0; i < 256; i++) {
            pos[i] = -1;
        }

        int size = s.size();
        int max = 0;
        int i = 0;
        for (int j = 0; j < size; j++) {
            char c = s[j];
            if (pos[c] == -1) {
                pos[c] = j;
                continue;
            }

            if (j - i > max) {
                max = j - i;
            }

            for ( ; i <= pos[c]; i++) {
                pos[s[i]] = -1;
            }
            pos[c] = j;
        }

        if (size - i > max) {
            max = size - i;
        }

        return max;
    }
};

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

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int records[256];
        int index = 0;
        int start = 0;
        int length = 0;
        int maxLength = 0;

        for (int i = 0; i != 256; i++) {
            records[i] = -1;
        }

        for (index = 0; index != s.size(); index++) {
            int ch = static_cast<unsigned char>(s[index]);
            if (records[ch] >= 0) {
                length = index - start;
                if (length > maxLength)
                    maxLength = length;
                for ( ; start != records[ch]; start++) {
                    int tmp = static_cast<unsigned char>(s[start]);
                    records[tmp] = -1;
                }
                start++;
            }
            records[ch] = index;
        }
        length = index - start;
        if (length > maxLength)
            maxLength = length;
        return maxLength;
    }
};

int main() {
    Solution solution;

    int result = solution.lengthOfLongestSubstring("abcabcbb");
    std::cout << "result: " << result << std::endl;

    result = solution.lengthOfLongestSubstring("abcd");
    std::cout << "result: " << result << std::endl;
    
    return 0;
}

#include <vector>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // 小于0的数, 一定不是
        if (x < 0) {
            return false;
        }

        // 个位数为0的数, 一定不是
        if (x != 0 && x % 10 == 0) {
            return false;
        }

        int reverse = 0;
        while (x > reverse) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }

        return (x == reverse) || (x == reverse / 10);
    }
};

int main()
{
    return 0;
}

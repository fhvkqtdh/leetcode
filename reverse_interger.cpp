#include <climits>

class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        while (x)
        {
            int pop = x % 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;

            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;

            rev *= 10;
            rev += pop;

            x /= 10;
        }
        return rev;
    }
};

int main()
{
    return 0;
}

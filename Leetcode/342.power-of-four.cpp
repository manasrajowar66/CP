/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == INT_MIN)
            return false;
        return (((n & (n - 1)) == 0) && (n % 3 == 1));
    }
};
// @lc code=end
